[< home](../readme.md)

[< previous: 4: deepSleep](./40_deepSleep.md) | 5: wifi connect

## Introduction

Goal of this page is to understand how to connect your board to the Wi-Fi :
- connect to Wi-Fi: what's that ?
- initialize Wi-Fi connection and get a google page with code.


## connect to Wi-Fi: what's that ?

Wi-Fi aka. "wireless fidelity" is a system used for connecting computers and other electronic equipment to the internet without using wires. 

So like a computer is able to connect to the Internet via an internal Wi-Fi board,
the ESP8266 CARD includes a Wi-Fi chipset and a SDK (code instruction) to :
- set Wi-Fi configuration
- connect to or disconnect from the Wi-Fi
- query the Wi-Fi status (ex. connection failed, connected, not connected ...).

Once the wifi state is connected, your code could contain some Internet based order with success: ex. use an "http client" (library) to "GET" a web page content.

## Connect to the Internet to get a Google Page !

Here is a short step-by-step tutorial to implement the following functions:
- setup Wi-Fi configuration
- ask to connect
- wait while status is "connected"
- get a google page content
- ask to disconnect

### Setup Wi-Fi configuration

To make it short in the current context, there is only 2 parameters to configure Wi-Fi : 
- `WIFI_SSID` : a unique string to identify your network and not that of the neighbor,
- `WIFI_SECRET` : a secret string to allow only you and your family to use your network (and prevent neighbor use ^^),

In the code, we just prepare two constant to support this config like this:
````c
#define WIFI_SSID "DE45YYYYTO"
#define WIFI_SECRET "Thi$$_IsSuperSecret"
````

NB: you could get your Wi-Fi SSID and SECRET from your Internet provider (and/or from your Internet Box).

### Ask to connect
To ask the chipset to establish a link with your network, just send the config to the SDK.

Import sdk library at the beginning of your program
````c
#include <ESP8266WiFi.h>
````

Add later a command to connect
````c
  WiFi.begin(WIFI_SSID, WIFI_SECRET);
````

### Wait while status is "connected"

The ESP Wi-Fi SDK provide a command to query the current WFi status.
````c
   WiFi.status()
````

And if you go deep in the library source code (<btn>shift</btn> + clic on `status()`), you can see the return structure of this command:
````c
  wl_status_t status();
  
# from wl_definitions.h
typedef enum {
    WL_NO_SHIELD        = 255,   // for compatibility with Wi-Fi Shield library
    WL_IDLE_STATUS      = 0,
    WL_NO_SSID_AVAIL    = 1,
    WL_SCAN_COMPLETED   = 2,
    WL_CONNECTED        = 3,
    WL_CONNECT_FAILED   = 4,
    WL_CONNECTION_LOST  = 5,
    WL_WRONG_PASSWORD   = 6,
    WL_DISCONNECTED     = 7
} wl_status_t;
````

That's so cool to get this kind of details ! But in fact, in reality, if your board is unable to connect, you will not get something to do.. so very often the only state used is `WL_CONNECTED`.

So here is a full sample to wait an Internet connection:

````c
void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_SECRET);
  int attempt = 0, maxAttempt = 20;
  if (SERIAL_LOG) Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED && attempt++ < maxAttempt) {
    delay(300);
    if (SERIAL_LOG) Serial.print(".");
    if (SERIAL_LOG) Serial.print(attempt);
  }
  if (WiFi.status() != WL_CONNECTED) {
    if (SERIAL_LOG) Serial.print("NOT CONNECTED !!");
    if (SERIAL_LOG) Serial.print(WiFi.status());
  }
}
````
You may notice here that we will try to ask `CONNECTED` state with following behavior:
- configure
- ask state,
- if not `CONNECTED`, wait 300ms, ask state,
- if not `CONNECTED`, wait 300ms, ask state,
- (... repeat this) max 20 times
- if not `CONNECTED`, then report that we are not connected and what current Wi-Fi status (int) is.

Option: ask yourself about "Why a max repeat limit" design ?

### Get a Google page content

It's now time to use our Internet connection to get content from the WWWeb.

We will use a http client library to get a web page.

Import sdk libraries at the beginning of your program, plus set a given web page url.
````c
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

#define WEBPAGE_URL   "https://www.google.fr"
````

Add later a function to GET webpage content
````c
void getGooglePage() {
  if ((WiFi.status() != WL_CONNECTED)) {
    if (SERIAL_LOG) Serial.print("Oops, you're not connected\n");
    return;
  }

  if (SERIAL_LOG) Serial.println("getGooglePage()");

  // create an https client
  std::unique_ptr<BearSSL::Wi-FiClientSecure> client(new BearSSL::Wi-FiClientSecure);
  
  // OPTION: uncomment to ignore the SSL certificate - this is a security issue
  // client->setInsecure();

  HTTPClient https;
  
  // configure target url
  https.begin(*client, WEBPAGE_URL);
  
  // OPTION: uncomment to add some request headers
  // https.addHeader("User-Agent", "ESP8266Wi-Fi board MVP");

  if (SERIAL_LOG) Serial.print("[HTTPS] GET " + WEBPAGE_URL + "\n");
  int httpCode = https.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    if (SERIAL_LOG) Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

    // file found at server
    if (SERIAL_LOG && (httpCode == HTTP_CODE_OK || httpCode == 400)) {
      const String& payload = https.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");
    }
  } else if (SERIAL_LOG) {
    Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
  }

  // close https client
  https.end();
}
````