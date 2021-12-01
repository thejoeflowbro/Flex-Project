#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <Arduino_JSON.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <HTTPClient.h>
#include <WiFiManager.h>

// Data wire is connected to GPIO 4
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Variables to store temperature values
String temperatureF = "";
String temperatureC = "";
String temperatureF1 = "";
String temperatureC1 = "";
String temperatureC2 = "";
String temperatureF2 = "";
// String temperatureF3 = "";
// String temperatureC3 = "";
// String temperatureF4 = "";
// String temperatureC4 = "";
// String temperatureF5 = "";
// String temperatureC5 = "";
// String temperatureF6 = "";
// String temperatureC6 = "";
// String temperatureF7 = "";
// String temperatureC7 = "";
// String temperatureF8 = "";
// String temperatureC8 = "";
// String temperatureF9 = "";
// String temperatureC9 = "";
// String temperatureF10 = "";
// String temperatureC10 = "";
// String temperatureF11 = "";
// String temperatureC11 = "";

// Timer variables
unsigned long lastTime = 0;  
unsigned long timerDelay = 30000;

// Replace with your network credentials
// const char* ssid = "OmniEnergy";
// const char* password = "Kilowattuur";

  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

//Your Domain name with URL path or IP address with path
String serverName = "http://flexgreen.eu/temperature_register";

// Create AsyncWebServer object on port 80
AsyncWebServer server2(80);
WiFiServer server(80);

// Variable to store the HTTP request
String header;

String readDSTemperatureC() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempC); 
  return String(tempC);
}

String readDSTemperatureF() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempF = sensors.getTempFByIndex(0);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempF); 
  return String(tempF);
}

String readDSTemperatureC1() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempC1 = sensors.getTempCByIndex(1);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempC1); 
  return String(tempC1);
}

String readDSTemperatureF1() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempF1 = sensors.getTempFByIndex(1);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempF1); 
  return String(tempF1);
}

String readDSTemperatureC2() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempC2 = sensors.getTempCByIndex(2);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempC2); 
  return String(tempC2);
}

String readDSTemperatureF2() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempF2 = sensors.getTempFByIndex(2);
    Serial.print("Temperature Celsius: ");
    Serial.println(tempF2); 
  return String(tempF2);
}

// String readDSTemperatureC3() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC3 = sensors.getTempCByIndex(3);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC3); 
//   return String(tempC3);
// }

// String readDSTemperatureF3() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF3 = sensors.getTempFByIndex(3);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF3); 
//   return String(tempF3);
// }

// String readDSTemperatureC4() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC4 = sensors.getTempCByIndex(4);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC4); 
//   return String(tempC4);
// }

// String readDSTemperatureF4() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF4 = sensors.getTempFByIndex(4);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF4); 
//   return String(tempF4);
// }

// String readDSTemperatureC5() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC5 = sensors.getTempCByIndex(5);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC5); 
//   return String(tempC5);
// }

// String readDSTemperatureF5() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF5 = sensors.getTempFByIndex(5);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF5); 
//   return String(tempF5);
// }

// String readDSTemperatureC6() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC6 = sensors.getTempCByIndex(6);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC6); 
//   return String(tempC6);
// }

// String readDSTemperatureF6() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF6 = sensors.getTempFByIndex(6);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF6); 
//   return String(tempF6);
// }

// String readDSTemperatureC7() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC7 = sensors.getTempCByIndex(7);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC7); 
//   return String(tempC7);
// }

// String readDSTemperatureF7() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF7 = sensors.getTempFByIndex(7);

//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF7); 
//   return String(tempF7);
// }

// String readDSTemperatureC8() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC8 = sensors.getTempCByIndex(8);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC8); 
//   return String(tempC8);
// }

// String readDSTemperatureF8() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF8 = sensors.getTempFByIndex(8);

//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF8); 

//   return String(tempF8);
// }

// String readDSTemperatureC9() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC9 = sensors.getTempCByIndex(9);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC9); 
//   return String(tempC9);
// }

// String readDSTemperatureF9() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF9 = sensors.getTempFByIndex(9);

//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF9); 

//   return String(tempF9);
// }

// String readDSTemperatureC10() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC10 = sensors.getTempCByIndex(10);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC10); 
//   return String(tempC10);
// }

// String readDSTemperatureF10() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF10 = sensors.getTempFByIndex(10);

//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF10); 

//   return String(tempF10);
// }

// String readDSTemperatureC11() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempC11 = sensors.getTempCByIndex(11);
//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempC11); 
//   return String(tempC11);
// }

// String readDSTemperatureF11() {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures(); 
//   float tempF11 = sensors.getTempFByIndex(11);

//     Serial.print("Temperature Celsius: ");
//     Serial.println(tempF11); 

//   return String(tempF11);
// }

// Replaces placeholder with DS18B20 values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATUREC"){
    return temperatureC;
  }
  if(var == "TEMPERATUREF"){
    return temperatureF;
  }
    if(var == "TEMPERATUREC1"){
    return temperatureC1;
  }
    if(var == "TEMPERATUREF1"){
    return temperatureF1;
  }
    if(var == "TEMPERATUREC2"){
    return temperatureC2;
  }
    if(var == "TEMPERATUREF2"){
    return temperatureF2;
  }
  //   if(var == "TEMPERATUREC3"){
  //   return temperatureC3;
  // }
  //     if(var == "TEMPERATUREF3"){
  //   return temperatureF3;
  // }
  //   if(var == "TEMPERATUREC4"){
  //   return temperatureC4;
  // }
  //     if(var == "TEMPERATUREF4"){
  //   return temperatureF4;
  // }
  //   if(var == "TEMPERATUREC5"){
  //   return temperatureC5;
  // }
  //     if(var == "TEMPERATUREF5"){
  //   return temperatureF5;
  // }
  //   if(var == "TEMPERATUREC6"){
  //   return temperatureC6;
  // }
  //     if(var == "TEMPERATUREF6"){
  //   return temperatureF6;
  // }
  //   if(var == "TEMPERATUREC7"){
  //   return temperatureC7;
  // }
  //     if(var == "TEMPERATUREF7"){
  //   return temperatureF7;
  // }
  //   if(var == "TEMPERATUREC8"){
  //   return temperatureC8;
  // }
  //     if(var == "TEMPERATUREF8"){
  //   return temperatureF8;
  // }
  //   if(var == "TEMPERATUREC9"){
  //   return temperatureC9;
  // }
  //     if(var == "TEMPERATUREF9"){
  //   return temperatureF9;
  // }
  //   if(var == "TEMPERATUREC10"){
  //   return temperatureC10;
  // }
  //     if(var == "TEMPERATUREF10"){
  //   return temperatureF10;
  // }
  //   if(var == "TEMPERATUREC11"){
  //   return temperatureC11;
  // }
  //     if(var == "TEMPERATUREF11"){
  //   return temperatureF11;
  // }
  return String();
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  String ssid = "FlexGreen-Temp";

    // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("FlexGreen-Temp", "FlexGreen");

  //start SPIFFS
  SPIFFS.begin();

  // Start up the library
  sensors.begin();

  temperatureC = readDSTemperatureC();
  temperatureF = readDSTemperatureF();
  temperatureC1 = readDSTemperatureC1();
  temperatureF1 = readDSTemperatureF1();
  temperatureC2 = readDSTemperatureC2();
  temperatureF2 = readDSTemperatureF2();
  // temperatureC3 = readDSTemperatureC3();
  // temperatureF3 = readDSTemperatureF3();
  // temperatureC4 = readDSTemperatureC4();
  // temperatureF4 = readDSTemperatureF4();
  // temperatureC5 = readDSTemperatureC5();
  // temperatureF5 = readDSTemperatureF5();
  // temperatureC6 = readDSTemperatureC6();
  // temperatureF6 = readDSTemperatureF6();
  // temperatureC7 = readDSTemperatureC7();
  // temperatureF7 = readDSTemperatureF7();
  // temperatureC8 = readDSTemperatureC8();
  // temperatureF8 = readDSTemperatureF8();
  // temperatureC9 = readDSTemperatureC9();
  // temperatureF9 = readDSTemperatureF9();
  // temperatureC10 = readDSTemperatureC10();
  // temperatureF10 = readDSTemperatureF10();
  // temperatureC11 = readDSTemperatureC11();
  // temperatureF11 = readDSTemperatureF11();
    // Connect to Wi-Fi
  // WiFi.begin(ssid, password);
  // Serial.println("Connecting to WiFi");
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println();
  
  // // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server2.on("/", HTTP2_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server2.on("/temperaturec", HTTP2_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", temperatureC.c_str());
  });

  server2.on("/temperaturef", HTTP2_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", temperatureF.c_str());
  });

  // Route to load css files
  server2.on("/style.css", HTTP2_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });
  
  // Route to load javscript files
  server2.on("/script.js", HTTP2_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server2.on("/FlexGreenLogo.png", HTTP2_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/FlexGreenLogo.png", "image/png");
  });

  server2.on("/FlexGreenFavicon.png", HTTP2_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/FlexGreenFavicon.png", "image/png");
  });

  // Start server
  server2.begin();
}

void loop() {

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
          }
        }
      }
    }
  }

    if ((millis() - lastTime) > timerDelay) {
    temperatureC = readDSTemperatureC();
    temperatureC1 = readDSTemperatureC1();
    temperatureC2 = readDSTemperatureC2();
    // temperatureC3 = readDSTemperatureC3();
    // temperatureC4 = readDSTemperatureC4();
    // temperatureC5 = readDSTemperatureC5();
    // temperatureC6 = readDSTemperatureC6();
    // temperatureC7 = readDSTemperatureC7();
    // temperatureC8 = readDSTemperatureC8();
    // temperatureC9 = readDSTemperatureC9();
    // temperatureC10 = readDSTemperatureC10();
    // temperatureC11 = readDSTemperatureC11();

  //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + "?sensor1=sens1&temp1=" + temperatureC + "&sensor2=sens2&temp2=" + temperatureC1 + "&sensor3=sens3&temp3=" + temperatureC2;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  } 
}
