#include <Arduino.h>
#include <Drone.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <sstream>

const char * ssid = "TELLO-FE2F96"; // SKAL DETTE MÅSKE VÆRE I VORES DRONE_CLASS?
const char * password = "";
const int udpPortListen = 8889; // LYTTE PORT
    
int dronestate = 0;
int buttonState = 0;  
int lastButtonState = 0;
int pot1Value = 0;
int currentPad = 0;

// PINS
const int buttonPin = 2;  // TÆNDSLUK INPUT KNAP
const int pot1Pin = 33; // Potentiometer1 Read

AsyncUDP udp2; // ændret navn da den ellers lavede ged i Drone class
Drone drone;

void setup()
{
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) { // if intet connected wifi
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    if(udp2.listen(udpPortListen)) { // hvis connected wifi
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
        // INSERT DRONE INITIALIZE HER
        drone.begin();  
        udp2.onPacket([](AsyncUDPPacket packet) { 

            String s((char*)packet.data()); // laver string s ud af chars i packet.data()
           // s = s.substring(0, packet.length()); // klipper støj
           // s.trim(); //fjerner whitespace

            Serial.println(s);
            
        });
    }
}

void loop()
{

    buttonState = digitalRead(buttonPin);

     if (buttonState != lastButtonState) {

         if (buttonState == HIGH) {

             if (dronestate == 0) 
            {
                dronestate = 1;
                drone.liftOff();
            } else {
                dronestate = 0;
                drone.land();
            }   
        }
        lastButtonState = buttonState;
        delay(50);
    } 
    pot1Value = map(analogRead(pot1Pin), 0, 2200, 200, 0); // HER SKAL DER NOGET MED pot1
   // Serial.println("pot1Value: ");
   // Serial.print(pot1Value);

    if (pot1Value > 100 && currentPad < 1) { 
        ++currentPad; 
        drone.fixedGoM4();
        delay(5000); // MILLIS ?!
        drone.fixedJumpM4M1();
        delay(5000);
        Serial.println("CURRENT PAD: ");
        Serial.print(currentPad);
        // KAN VI LAVE ET SKALERBART LOOT?
        // Således at det er i++ hele tiden tilsvarende næste missionpad
    }
    
  //  Serial.println("dronestate: ");
  //  Serial.print(dronestate);

}

 