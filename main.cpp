#include "application.hpp"
#include "kivalaszto.hpp"
#include "kivalaszto_.hpp"

using namespace std;
using namespace genv;

class MyApplication: public Application
{
private:
    //Kivalaszto * kivalaszto;
    Kivalaszto_ * kivalaszto_;

public:
    MyApplication(int width, int height): Application(width, height)
    {
        //kivalaszto = new Kivalaszto(this, 20, 20, 400, 30, 5, {"egy", "ketto", "harom", "negy", "ot", "hat"});
        kivalaszto_ = new Kivalaszto_(this, 50, 50, 400, 100, {"egy", "ketto", "harom", "negy", "ot", "hat", "het", "nyolc"});
    }

    void action(string id)
    {
        if (id == "enter")
        {
            cout << kivalaszto_->value() << endl;
        }
    }
};

int main()
{
    MyApplication app(600, 600);
    app.event_loop();

    return 0;
}
