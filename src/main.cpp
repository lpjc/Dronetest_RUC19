#include <Arduino.h>
#include <Drone.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <sstream>

const char * ssid = "TELLO-FE2F96"; 
const char * password = "";
const int udpPortListen = 8889; 
    
int dronestate = 0;
int buttonState = 0;  
int lastButtonState = 0;
int currentPad = 0;
int droneReady = 0;

String response;

int potArr[4];

int potPinArr[4] = {33, 32, 0, 0}; // Potentiometer Pins in order: 1,2,3,4...

const int buttonPin = 2;  // TÆNDSLUK INPUT KNAP

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

        drone.begin();  // drone initialize only if wifi is connected
    
        udp2.onPacket([](AsyncUDPPacket packet) { 

            String s((char*)packet.data()); // laver string s ud af chars i packet.data()
            s = s.substring(0, packet.length()); // klipper støj
            s.trim(); //fjerner whitespace

            Serial.println("HER ER DATA FRA DRONE: ");
            Serial.println(s);

            response = s;
                
        });
    }
}

void loop()
{
    for (int i = 0; i < 5; i++){ // assigns maps our Potentiometer pin values into the potentiometer Array

        potArr[i] = map(analogRead(potPinArr[i]), 0, 4095, 200, 0);

    }

    buttonState = digitalRead(buttonPin);

    if (buttonState != lastButtonState) { // LIFTOFF KNAP
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
    
    if (response = "ok"){
    
        droneReady = true;
    
    }
    
    Serial.println(response);
    
    if ((dronestate = true) && (droneReady = true)) { // if the drone in the air?
        for (int i; potArr[i] > 80; i++){

            droneReady = false;
            response = "not ready";

            if (i = 0){ // første gang loopet kører skal vi have et Go statement.
                drone.fixedGoM1();
                delay(5000);
            }

            drone.jump(90, 0, 50, 30, 0, i+1, i+2);

        }
    }
}

 