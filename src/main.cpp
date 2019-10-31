#include <Arduino.h>
#include <Drone.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>

const char * ssid = "TELLO-FE2F96";
const char * password = "";
const int udpPortMirror = 8890; // ændret navn da den ellers lavede ged i Drone class
 // TJEK OM DEN OVERSTÅENDE SKAL ÆNDRES TIL 8890 FOR AT LYTTE!
const int buttonPin = 2; 
// const String droneIP = "192.168.10.1"; INDE I DRONE CLASS NU      
int dronestate = 0;
int buttonState = 0;  
int lastButtonState = 0;

AsyncUDP udp2; // ændret navn da den ellers lavede ged i Drone class
Drone drone;

// void sendMessage(String ip, int port, String message)
// {
//    udpSender.beginPacket(ip.c_str(), port);
//    udpSender.printf(message.c_str());
//    udpSender.endPacket();    
// }

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
    if(udp2.listen(udpPortMirror)) { // hvis connected wifi
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
        // INSERT DRONE INITIALIZE HER
        drone.begin();
        udp2.onPacket([](AsyncUDPPacket packet) { // ON PACKET
            Serial.print("UDP Packet Type: ");
            Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
            Serial.print(", From: ");
            Serial.print(packet.remoteIP());
            Serial.print(":");
            Serial.print(packet.remotePort());
            Serial.print(", To: ");
            Serial.print(packet.localIP());
            Serial.print(":");
            Serial.print(packet.localPort());
            Serial.print(", Length: ");
            Serial.print(packet.length());
            Serial.println(", Data: ");
            Serial.write(packet.data(), packet.length());
            Serial.println();
            //reply to the client
            packet.printf("Got %u bytes of data", packet.length());

            // sendMessage(droneIP, udpPort, "command");
            // is now from drone class as the "init" method

            // // make a string from the data
            // String s((char*)packet.data());
            // //packet.print(s.c_str());

            // if (s.equals("who are you")) packet.print("I am your ESP32 :-)");

            // //send reply
            // // sendMessage(packet.remoteIP().toString(), udpPort, "reply from esp32");
            
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
        //delay(50);
    } 
    Serial.println(dronestate);
}

 