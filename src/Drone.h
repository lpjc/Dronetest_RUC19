#include <string>
using namespace std;

class Drone
{
    public:
        Drone();
        void begin();
        void stop();
        void speed(int speed);
        void liftOff();
        void land();
        void up();
        void down();    

        void left(int dist);
        void right(int dist);
        void forward(int dist);
        void back(int dist);
        
        void go(int x, int y, int z, int speed, int misPad);
        void jump(int x, int y, int z, int speed, int yaw, int misPadStart, int misPadEnd);

        void fixedGoM4();
        void fixedJumpM4M1();
        void fixedJumpM1M2(string messageJumpM1M2);
        void fixedJumpM2M3(string messageJumpM2M3);
        void fixedJumpM3M4(string messageJumpM3M4);

    private:

};