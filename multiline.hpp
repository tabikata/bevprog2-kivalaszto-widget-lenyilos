#ifndef MULTILINE_HPP
#define MULTILINE_HPP

#include "widgets.hpp"

class MultiLine: public Widget
{
private:
    std::vector<std::string> lines_;
    int line_number;
    int first_line;

public:
    MultiLine(Application *, int, int, int, int);
    void draw() override;
    void handle(genv::event) override;

    void load(std::string);
    void scroll_up();
    void scroll_down();
};

#endif // MULTILINE_HPP
