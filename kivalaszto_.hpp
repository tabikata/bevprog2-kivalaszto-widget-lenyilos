#ifndef KIVALASZTO__HPP
#define KIVALASZTO__HPP

#include "widgets.hpp"

class Kivalaszto_: public Widget
{
protected:
    std::vector<std::string> options;
    int option_number; //megjelenitheto elem darabszam
    int first_option;
    int selected; //aktualis
    genv::color bckgrnd;
    int line_height;

public:
    Kivalaszto_(Application *, int, int, int, int, std::vector<std::string>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual bool selection(int, int);
    virtual void select(int, int);
    virtual std::string value();
    virtual void scroll_up();
    virtual void scroll_down();
};

#endif // KIVALASZTO__HPP
