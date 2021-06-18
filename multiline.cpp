#include "multiline.hpp"

using namespace genv;

MultiLine::MultiLine(Application * parent, int x, int y, int sx, int sy)
        : Widget(parent, x, y, sx, sy), first_line(0)
{
    line_number = (_size_y - 5) / (gout.cascent() + gout.cdescent() + 5); // a sorok száma amit teljes egészében meg tudunk jeleníteni
}

void MultiLine::load(std::string filename)
{
    for (int i=0; i<lines_.size(); i++)
    {
        lines_.erase(lines_.begin()+i);
    }

    std::ifstream befajl(filename);

    if (!befajl.good())
    {
        std::cout << "baj van" << std::endl;
    }

    while (befajl.good())
    {
        std::string uj_sor;
        getline(befajl, uj_sor);
        lines_.push_back(uj_sor);
    }

    //std::cout << lines_.size() << std::endl;

    befajl.close();
}


void MultiLine::draw()
{
    gout << color(255, 255, 255) << move_to(_x, _y) << box(_size_x, _size_y);

    int line_height = gout.cascent() + gout.cdescent() + 5;

    for (size_t i=0; i<std::min(int(lines_.size()), line_number); i++)
    {
        gout << color(0, 0, 0) << move_to(_x + 5, _y + line_height*(i+1)) << text(lines_[first_line+i]);
    }
}

void MultiLine::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_wheeldown)
            scroll_down();
        else if (ev.button == btn_wheelup)
            scroll_up();
    }
}

void MultiLine::scroll_down()
{
    first_line = std::min(int(lines_.size()-line_number+1), first_line+1);
}

void MultiLine::scroll_up()
{
    first_line = std::max(0, first_line-1);
}
