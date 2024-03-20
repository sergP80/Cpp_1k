#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

namespace fltk_gui {

    struct UserWidgets {
        Fl_Input* first;
        Fl_Input* second;
        Fl_Box* output;
    };

    void sum_callback(Fl_Widget* /*widget*/, void* pwdg);

    void subs_callback(Fl_Widget* /*widget*/, void* pwdg);
}