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

#include <Button.h>
#include <Image.h>
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

Style *mainStyle;
Style *selectorStyle;

class figure {
	Button	*button;
	Image	*icon;
	Label 	*value;

public :
	figure( const char *const icn, Style *style, lv_align_t aln, const figure *base=NULL ){
		this->button = new Button( lv_scr_act() );
		this->button->addStyle( style );
		this->button->setLayout( LV_LAYOUT_ROW_MID );	// child are horizontally aligned
		this->button->Align( aln, base ? base->button->getMyself() : NULL );

		this->icon = new Image( this->button );
		this->icon->addStyle( style );
		this->icon->Set( icn );
		this->icon->setClickable( false );

		this->value = new Label( this->button );
		this->value->addStyle( style );
		this->value->setWidth( 75 );
		this->value->textAlign( LV_LABEL_ALIGN_RIGHT );
		this->value->setLongTextMode( LV_LABEL_LONG_BREAK );
		this->value->setClickable( false );
	}
};

class figure *production, *consommation, *pump;

Label *lbl_production;
Label *lbl_consommation;
Label *lbl_pump;

	/****
	* This app own information
	*****/

// Topic to monitor
struct {
	const char * const TOPIC;
	Label *&lbl;
} topics[] = {
	{ "TeleInfo/Production/values/PAPP", lbl_production },
	{ "TeleInfo/Consommation/values/PAPP", lbl_consommation },
	{ "TeleInfo/PompePiscine/values/PAPP", lbl_pump},
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
	Serial.println(topic);
	Serial.print("> ");
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
	mainStyle->setBgGradColor( LV_COLOR_NAVY );
	mainStyle->setBgGradDir( LV_GRAD_DIR_VER );

	lv_obj_add_style( lv_scr_act(), LV_OBJ_PART_MAIN, mainStyle->getStyle() );

	selectorStyle = new Style();
selectorStyle->setBgColor( LV_COLOR_BLACK ); // Test only
	selectorStyle->setRadius( 3 );
	selectorStyle->setPadding( 2 );
	selectorStyle->setTextColor( LV_COLOR_WHITE );
	selectorStyle->seTexttFont( &lv_font_montserrat_28 );
	
	production = new figure( LV_SYMBOL_HOME, selectorStyle, LV_ALIGN_IN_BOTTOM_RIGHT );
	consommation = new figure( LV_SYMBOL_CHARGE, selectorStyle, LV_ALIGN_OUT_TOP_MID, production );
	pump = new figure( LV_SYMBOL_SETTINGS, selectorStyle, LV_ALIGN_OUT_TOP_MID, consommation );

	lbl_production = new Label( lv_scr_act() );
	lbl_production->setLongTextMode( LV_LABEL_LONG_BREAK );
	lbl_production->setWidth( 50 );
	lbl_production->textAlign( LV_LABEL_ALIGN_RIGHT);
	lbl_production->Align( LV_ALIGN_IN_TOP_RIGHT );

	lbl_consommation = new Label( lv_scr_act() );
	lbl_consommation->setLongTextMode( LV_LABEL_LONG_BREAK );
	lbl_consommation->setWidth( 50 );
	lbl_consommation->seTexttFont( &lv_font_montserrat_28 );
	lbl_consommation->textAlign( LV_LABEL_ALIGN_RIGHT);
	lbl_consommation->Align( LV_ALIGN_OUT_BOTTOM_MID, lbl_production );

	lbl_pump = new Label( lv_scr_act() );
	lbl_pump->setLongTextMode( LV_LABEL_LONG_BREAK );
	lbl_pump->setWidth( 50 );
	lbl_pump->textAlign( LV_LABEL_ALIGN_RIGHT);
	lbl_pump->Align( LV_ALIGN_OUT_BOTTOM_MID, lbl_consommation );

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
