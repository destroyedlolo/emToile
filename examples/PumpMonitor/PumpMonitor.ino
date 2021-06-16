/*******************************
*
* Monitor pool pump consumption
*
* Network code came from async-mqtt-client's example
*
********************************/

#include "config.h" // Tune this file as per your target device

#include <freertos/FreeRTOS.h>
#include <esp_task_wdt.h>	// Watchdog
#include <rom/rtc.h>	// RTC wakeup code
#include <freertos/timers.h>

#include <WiFi.h>
#include <AsyncMqttClient.h>

#include <TabView.h>
#include <Page.h>
#include <Label.h>


	/* 
	 * Include my own home network definition 
	 * ...
	 */
/*
#if defined __has_include
#	if __has_include(<Maison.h>)
#		include <Maison.h>
#	endif
#endif
*/

/* well, __has_include() seems not working with Arduino IDE.
 * comment tout this include and define your granting bellow
 */
#include <Maison.h>

	/*
	 * ... otherwise, define yours
	 */
#ifndef WIFI_SSID
#	define WIFI_SSID "YourSSID"
#	define WIFI_PASSWORD "YourPassword"

#	define BROKER_HOST "Broker_Host_OrIP"
#	define BROKER_PORT 1883
#endif


	/****
	* GUI objects
	*****/

TTGOClass *ttgo;

TabView	*tv;

Style *mainStyle;
Style *selectorStyle;

	/* Tab to display power usage */
class PTab : public Page {
	Label *title;
	const char *icn;
	String tab_title;
	uint16_t id;

public :
	
		/* Constructor
		 * lv_obj_t *np : new page object pointer from TileView
		 * const char * const icon	: icon to add to the tab name, including space
		 * uint16_t aidx : index in the tabview
		 * const char *title
		 */
	PTab( lv_obj_t *np, const char * const aicn, uint16_t aidx, const char *atitle ) : 
	Page( np, true ), icn(aicn), id(aidx) {
		this->title = new Label( **this );
		this->title->Align( LV_ALIGN_IN_TOP_MID );	// in the middle of the page
		this->title->AutoRealign( true );		// to ensure the alignment is correct
		this->title->setTextStatic( atitle );
	}

		/* Change the title as per received value */
	void setText( const char *val ){
		this->tab_title = icn;
		this->tab_title += val;

		tv->setTabName( this->id, (char *)this->tab_title.c_str() );
	}
};

PTab *production, *consommation, *pump;

	/****
	* This app own information
	*****/

// Topic to monitor
struct {
	const char * const TOPIC;
	PTab *&lbl;
} topics[] = {
	{ "TeleInfo/Production/values/PAPP", production },
	{ "TeleInfo/Consommation/values/PAPP", consommation },
	{ "TeleInfo/PompePiscine/values/PAPP", pump},
};

	/****
	 * Network
	 ****/
	
AsyncMqttClient mqttClient;
TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer;

void WiFiEvent(WiFiEvent_t event) {
	Serial.printf("[WiFi-event] event: %d\n", event);
	switch(event) {
	case SYSTEM_EVENT_STA_GOT_IP:
		Serial.println("WiFi connected");
		Serial.println("IP address: ");
		Serial.println(WiFi.localIP());
		connectToMqtt();
		break;
	case SYSTEM_EVENT_STA_DISCONNECTED:
		Serial.println("WiFi lost connection");
		xTimerStop(mqttReconnectTimer, 0); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
		xTimerStart(wifiReconnectTimer, 0);
		break;
	default :
		break;
	}
}

void connectToWifi(){
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void connectToMqtt(){
  Serial.println("Connecting to MQTT...");
  mqttClient.connect();
}

void onMqttConnect(bool ){
	for(int i = 0; i < sizeof(topics)/sizeof(topics[1]); i++){
  		Serial.print("Registering : ");
		Serial.println(topics[i].TOPIC);
		mqttClient.subscribe(topics[i].TOPIC, 0);
	}
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  Serial.println("Disconnected from MQTT.");

  if (WiFi.isConnected())
    xTimerStart(mqttReconnectTimer, 0);
}

void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total){
	char t[len+1];
	strncpy(t, payload, len);
	t[len] = 0;

	Serial.print("topic: ");
	Serial.print(topic);
	Serial.print(" > ");
	Serial.println(t);

	for(int i = 0; i < sizeof(topics)/sizeof(topics[1]); i++){
		if(!strcmp( topic, topics[i].TOPIC)){
			topics[i].lbl->setText( t );
			break;
		}
	}
}

void setup(){
	Serial.begin(115200);

	Serial.printf("Configure watchdog to 30s: %d\n", esp_task_wdt_init( 30, true ) );
	Serial.print("Wakeup raison : ");
	switch( rtc_get_reset_reason(0) ){
	case POWERON_RESET :
		Serial.println("Power on");
		break;
	case SW_RESET :
		Serial.println("Software");
		break;
	case OWDT_RESET :
		Serial.println("Legacy Watch dog");
		break;
	case DEEPSLEEP_RESET :
		Serial.println("Deep Sleep");
		break;
	case SDIO_RESET :
		Serial.println("SLC");
		break;
	case TG0WDT_SYS_RESET :
		Serial.println("Timer Group0 Watch dog");
		break;
	case TG1WDT_SYS_RESET :
		Serial.println("Timer Group1 Watch dog");
		break;
	case RTCWDT_SYS_RESET :
		Serial.println("RTC Watch dog digital");
		break;
	case INTRUSION_RESET :
		Serial.println("Instrusion tested to reset");
		break;
	case TGWDT_CPU_RESET :
		Serial.println("Time Group");
		break;
	case SW_CPU_RESET :
		Serial.println("Software");
		break;
	case RTCWDT_CPU_RESET :
		Serial.println("RTC Watch dog");
		break;
	case EXT_CPU_RESET :
		Serial.println("reseted by PRO CPU");
		break;
	case RTCWDT_BROWN_OUT_RESET :
		Serial.println("vdd voltage is not stable");
		break;
	case RTCWDT_RTC_RESET :
		Serial.println("RTC Watch dog reset digital core and rtc module");
		break;
	default :
		Serial.println("Who know ...");
	}

		/****
		* GUI initialisation
		*****/

	ttgo = TTGOClass::getWatch();
	ttgo->begin();

	ttgo->lvgl_begin();
	ttgo->lvgl_whirling(3);	// power connector is on top

	ttgo->openBL();	// Turn on the backlight

		/****
		* Build the GUI
		*****/
	mainStyle = new Style();
	mainStyle->setBgColor( LV_COLOR_BLACK );
	mainStyle->setBgGradStart( 50 );
	mainStyle->setBgGradColor( LV_COLOR_NAVY );
	mainStyle->setBgGradDir( LV_GRAD_DIR_VER );
	mainStyle->setTextColor( LV_COLOR_WHITE );
	mainStyle->seTexttFont( &lv_font_montserrat_28 );

	tv = new TabView( lv_scr_act() );	// Create the TabView
	tv->addStyle( mainStyle );
	tv->setBgColor( LV_COLOR_NAVY, LV_TABVIEW_PART_TAB_BG );
	tv->setBgGradColor( LV_COLOR_BLACK, LV_TABVIEW_PART_TAB_BG );
	tv->setBgGradDir( LV_GRAD_DIR_VER, LV_TABVIEW_PART_TAB_BG );
	tv->setTextColor( LV_COLOR_SILVER, LV_TABVIEW_PART_TAB_BG  );
	tv->seTexttFont( &lv_font_montserrat_22, LV_TABVIEW_PART_TAB_BG );
	tv->setPadding( 5,5,5,5, LV_TABVIEW_PART_TAB_BTN  );
	tv->setTextColor( LV_COLOR_YELLOW, LV_TABVIEW_PART_TAB_BTN, LV_STATE_CHECKED );

	production = new PTab( tv->AddTab( LV_SYMBOL_HOME " Prod" ), LV_SYMBOL_HOME " ", 0, "Production" );
	consommation = new PTab( tv->AddTab( LV_SYMBOL_CHARGE " Consn" ), LV_SYMBOL_CHARGE " ", 1, "Consommation" );
	pump = new PTab( tv->AddTab( LV_SYMBOL_SETTINGS " Pompe" ), LV_SYMBOL_SETTINGS " ", 2, "Pompe" );


		/****
		* Network
		*****/

	mqttReconnectTimer = xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
	wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));
	WiFi.onEvent(WiFiEvent);

	mqttClient.onConnect(onMqttConnect);
	mqttClient.onDisconnect(onMqttDisconnect);
  	mqttClient.onMessage(onMqttMessage);
	mqttClient.setServer(BROKER_HOST, BROKER_PORT);
	
	connectToWifi();

		/****
		* Completed
		*****/

	Serial.printf("Total heap: %d\n", ESP.getHeapSize());
    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %d\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %d\n", ESP.getFreePsram());

	Serial.println("\nInitialisation completed");
}

void loop(){
	lv_task_handler();
	delay( 5 );
}
