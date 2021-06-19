#ifndef KIVALASZTO_HPP
#define KIVALASZTO_HPP

#include "widgets.hpp"

class Kivalaszto: public Widget
{
protected:
    int meret; //lenyitaskor megjelenitheto elem darabszam //option_number
    std::vector<std::string> lehetosegek; //options
    int aktualis;
    bool levanegordulve;
    genv::color hatter;
    int first_option;

public:
    Kivalaszto(Application *, int, int, int, int, int, std::vector<std::string>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual bool lenyit(int, int);
    virtual bool valasztas(int, int);
    virtual void valaszt(int, int);
    virtual std::string value(); //aktuális (kiválasztott) elem
    virtual void scroll_up();
    virtual void scroll_down();
};

#endif // KIVALASZTO_HPP
