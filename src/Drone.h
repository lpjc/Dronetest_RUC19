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
        //  following based on distance(dist)
        void left(int dist);
        void right(int dist);
        void forward(int dist);
        void back(int dist);
        
    private:

};