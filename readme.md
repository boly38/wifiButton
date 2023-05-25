# WifiButton project

## Introduction

The goal of this project is to figure out how to use the ESP8266 board to create a simple WiFi button.

![ESP 8266 WiFi card](./doc/images/esp8266WiFi_CH340G.JPG)

In the manner of a tutorial, step by step, let's learn together with this project to allow us to understand how to create this button.

- One constraint: each help page must be easy to understand for NooB, accept a simple introduction, a fairly simple sample, and instructions for the next step ^^.

- If you think a step is not clear enough or has problems, please report it or contribute.

## Steps to follow

- [step 0) setup hardware : ESP8266 card driver](./doc/00_setupDriver.md)
- [step 1) configure Arduino IDE for ESP8266](./doc/10_setupIDE.md) (mvp code inside)
- [step 2) flash the on-board LED](./doc/20_flashLed.md) (blink code inside)
- [step 3) the RESET action](./doc/30_reset.md)
- [step 4) entering deep sleep mode](./doc/40_deepSleep.md)
- [step 5) connect to the local WiFi](./doc/50_wifiConnect.md)

- *(work in progress to complete this project)*

[//]: <> (- [step 6\) send a discord message](./doc/60_postDiscord.md\))
[//]: <> (- [step 7\) complete button program](./doc/70_completeProgram.md\))
[//]: <> (- global hard configuration ?)

## How to contribute to the `wifiButton` project ?

Contributions are welcome.

I am a beginner in electronics, a little less in development. However, errors or simplifications can occur at all levels. Feel free to add your grain of salt. Be critical and constructive with tickets or pull requests.

As I'm not an expert at all, I rely on some Internet [sources](./doc/99_external_resources.md) and it's possible to encounter some error or `TODO` in some pages: you could provide more details to correct or complete them.