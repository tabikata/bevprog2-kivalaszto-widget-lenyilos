#include "application.hpp"
#include "kivalaszto.hpp"

using namespace std;
using namespace genv;

class MyApplication: public Application
{
private:
    Kivalaszto * kivalaszto;

public:
    MyApplication(int width, int height): Application(width, height)
    {
        kivalaszto = new Kivalaszto(this, 20, 20, 400, 30, 5, {"egy", "ketto", "harom", "negy", "ot", "hat"});
    }

    void action(string id)
    {
        if (id == "enter")
        {
            cout << kivalaszto->value() << endl;
        }
    }
};

int main()
{
    MyApplication app(600, 600);
    app.event_loop();

    return 0;
}
