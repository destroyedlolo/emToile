/************************************************
*		Test emToile example
*
*	Copyright 2020 Laurent Faillie (destroyedlolo)
*
*	Follow me on twitter : @DestroyedLolo
 ************************************************/

#include "config.h" // Tune this file as per your target device

#include <freertos/FreeRTOS.h>
#include <esp_task_wdt.h>	// Watchdog
#include <rom/rtc.h>	// RTC wakeup code

extern void start_gui( void );

	/****
	* Shared object
	*****/

TTGOClass *ttgo;


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
		* Handle the watch
		*****/

	ttgo = TTGOClass::getWatch();
	ttgo->begin();			// start peripherals
	
	ttgo->lvgl_begin();
	ttgo->lvgl_whirling(3);	// power connector is on top

	ttgo->openBL();	// Turn on the backlight

	start_gui();

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
    delay(5);
}

