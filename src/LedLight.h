#include <string>
using namespace std;

class LedLight
{
    public:
        int pinNumber;
        LedLight(int pn); 
        void on();
        void off();
        void blink(int pace);
    private:
        
};