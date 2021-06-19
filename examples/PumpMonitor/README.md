# PumpMonitor

**PumpMonitor** is a real life fully featured example of using **emToile** to display **MQTT** value. I made it to test if I can guess my pool's pump health by it's electricity consumption.
As it was so easy to implement, I added as well photovoltaic production and global electrictiy consumption.

It features :
------

* **asynchoneous MQTT** handling (using [async-mqtt-client](https://github.com/marvinroger/async-mqtt-client) and [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) )
* **autoreconnect**
* LVGL's **tabview**, **chart** and **styles**

It was developped and tested on my ESP32 based **LilyPi**

Result :
------

![PumpMonitor's screenshot](https://github.com/destroyedlolo/emToile/blob/PumpMonitor/examples/PumpMonitor/PumpMonitor.jpg)

* **Red** line shows short term value, each value represent 1 second
* **Green** long term trend based on the maximum value reached every minute.
