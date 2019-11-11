#include <Arduino.h>
#include <Drone.h>
#include <string>
#include "WiFi.h"
#include "AsyncUDP.h"

AsyncUDP udp;
WiFiUDP udpSender;

const int udpPort = 8889; // drone port TIL drone
const String droneIP = "192.168.10.1"; // drone IP

using namespace std;
// namespace
   
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
        delay(500);
        sendMessage(droneIP, udpPort, "mon"); // turns on mission pad 
    }

    void Drone::liftOff()
    {
        sendMessage(droneIP, udpPort, "takeoff");
    }

    void Drone::land()
    {
        sendMessage(droneIP, udpPort, "land");
    }

    void Drone::go(int x, int y, int z, int speed, int misPad)
    {

        String go = "go " + x;
        go += " " + y;
        go += " " + z; 
        go += " " + speed;
        go += "mid" + misPad;
        
        sendMessage(droneIP, udpPort, go);
        
    }

    void Drone::jump(int x, int y, int z, int speed, int yaw, int misPadStart, int misPadEnd)
    {    
        String jump = "jump " + x;
        jump += " " + y;
        jump += " " + z; 
        jump += " " + speed;
        jump += " " + 0;
        jump += " mid" + misPadStart;
        jump += " mid" + misPadEnd;

        sendMessage(droneIP, udpPort, jump);
    }

    // FIXED JUMPS / GO

        void Drone::fixedGoM1()
        {
            sendMessage(droneIP, udpPort, "go 0 0 100 50 m1");
        }

        void Drone::fixedJumpM4M1()
        {
            sendMessage(droneIP, udpPort, "jump 90 0 50 30 0 m4 m1");
        }

        void Drone::fixedJumpM1M2(string messageJumpM1M2)
        {
            sendMessage(droneIP, udpPort, "jump 90 0 50 30 0 m1 m2");
        }

        void Drone::fixedJumpM2M3(string messageJumpM2M3)
        {
            sendMessage(droneIP, udpPort, "jump 90 0 50 30 0 m2 m3");
        }

        void Drone::fixedJumpM3M4(string messageJumpM3M4)
        {
            sendMessage(droneIP, udpPort, "jump 90 0 50 30 0 m3 m4");
        }
