#include "kivalaszto_.hpp"

using namespace genv;

Kivalaszto_::Kivalaszto_(Application * parent_, int x_, int y_, int sx_, int sy_, std::vector<std::string> options_)
            : Widget(parent_, x_, y_, sx_, sy_), options(options_),
            first_option(0), bckgrnd(255, 255, 255)
{
    line_height = gout.cascent()+gout.cdescent()+5;
    option_number = (sy-5) / line_height;

    if (options.size() > 0)
    {
        selected = 0;
    }
    else
    {
        selected = -1;
    }
}

void Kivalaszto_::draw()
{
    gout << color(255, 255, 255) << move_to(x, y) << box(sx, sy);

    for (int i=0; i<std::min(option_number, int(options.size())); i++)
    {
        if (i == selected)
            bckgrnd = color(200, 200, 200);
        else
            bckgrnd = color(255, 255, 255);
        gout << bckgrnd << move_to(x, y + line_height*i) << box(sx, line_height)
            << color(0, 0, 0)
            << move_to(x+10, y + line_height*i +2) << text(options[first_option+i]);
    }
}

void Kivalaszto_::handle(event ev)
{
    if ((ev.type == ev_mouse and ev.button == btn_wheelup) or (ev.type == ev_key and ev.keycode == key_up))
    {
        scroll_up();
    }
    else if ((ev.type == ev_mouse and ev.button == btn_wheeldown) or (ev.type == ev_key and ev.keycode == key_down))
    {
        scroll_down();
    }
    else if (ev.type == ev_mouse and ev.button == btn_left and selection(ev.pos_x, ev.pos_y))
    {
        select(ev.pos_x, ev.pos_y);
    }
}

bool Kivalaszto_::selection(int mouse_x, int mouse_y)
{
    return mouse_x > x and mouse_x < x+sx
        and mouse_y > y and mouse_y < y + line_height*std::min(option_number, int(options.size()));
}

void Kivalaszto_::select(int mouse_x, int mouse_y)
{
    for (int i=0; i<options.size(); i++)
    {
        if (mouse_y > y + line_height*i and mouse_y < y + line_height*(i+1))
        {
            selected = i;
        }
    }
}

std::string Kivalaszto_::value()
{
    if (selected >= 0)
    {
        return options[selected];
    }
    else
    {
        return "";
    }
}

void Kivalaszto_::scroll_down()
{
    if (selected+1 < options.size())
    {
        if (selected == first_option+option_number)
        {
            first_option = std::min(int(options.size()-option_number+1), first_option+1);
        }
        selected++;
    }
    else
    {
        first_option = 0;
        selected = 0;
    }
}

void Kivalaszto_::scroll_up()
{
    if (selected-1 >= 0)
    {
        if (selected == first_option)
        {
            first_option = std::max(0, first_option-1);
        }
        selected--;
    }
    else
    {
        first_option = options.size()-option_number;
        selected = options.size()-1;
    }
}
