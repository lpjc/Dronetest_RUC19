#include <Arduino.h>
#include <Drone.h>
#include <string>
#include "WiFi.h"
#include "AsyncUDP.h"

AsyncUDP udp;
WiFiUDP udpSender;

const int udpPort = 8889; // drone port
const String droneIP = "192.168.10.1"; // drone IP

using namespace std;
   
    Drone::Drone()
    {

    }

    void sendMessage(String ip, int port, String message)   
    {
        udpSender.beginPacket(ip.c_str(), port);
        udpSender.printf(message.c_str());
        udpSender.endPacket();    
    }

    void Drone::begin()
    {
        sendMessage(droneIP, udpPort, "command");
    }

    void Drone::liftOff()
    {
        sendMessage(droneIP, udpPort, "takeoff");
    }

    void Drone::land()
    {
        sendMessage(droneIP, udpPort, "land");
    }

