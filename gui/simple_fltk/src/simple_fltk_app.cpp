#include "simple_fltk.h"

using fltk_gui::sum_callback;

using fltk_gui::subs_callback;

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(400, 300, "FLTK Simple App");

    // Create a text field (input result) at position (50, 50) with width 300 and height 30
    Fl_Input* input1 = new Fl_Input(50, 50, 300, 30, "Input first number:");

    // Create a text field (input result) at position (50, 50) with width 300 and height 30
    Fl_Input* input2 = new Fl_Input(50, 100, 300, 30, "Input second number:");

    // Create a static text result
    Fl_Box* result = new Fl_Box(100, 150, 200, 30, "Result:");
    result->box(FL_UP_BOX);
    result->labelfont(FL_BOLD);
    result->labelsize(14);
    result->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    fltk_gui::UserWidgets widgets {input1, input2, result};

    Fl_Button* sumButton = new Fl_Button(50, 200, 300, 30, "Sum (a+b)");

    Fl_Button* subsButton = new Fl_Button(50, 250, 300, 30, "Subs (a - b)");

    // Assign the callback to the sumButton, passing the input field as data
    sumButton->callback(sum_callback, &widgets);

    subsButton->callback(subs_callback, &widgets);

    window->end();

    window->show(argc, argv);

    return Fl::run();
}
