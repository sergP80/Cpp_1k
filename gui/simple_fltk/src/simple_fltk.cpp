#include "simple_fltk.h"

namespace fltk_gui {
    // Callback function for the sum button
    void sum_callback(Fl_Widget* /*widget*/, void* pwdg) {
        auto pWidgets = static_cast<fltk_gui::UserWidgets*>(pwdg);

        try
        {
            double in1 = std::stod(pWidgets->first->value());

            double in2 = std::stod(pWidgets->second->value());

            auto result = in1 + in2;

            {
                std::stringstream  sin;
                sin << std::fixed << std::setprecision(3) << result;

                auto str_value = sin.str();

                pWidgets->output->label(str_value.c_str());
            }

        }
        catch (const std::exception& e)
        {
            fl_alert("Error during sum: %s", e.what());
        }
    }

// Callback function for the sum button
    void subs_callback(Fl_Widget* /*widget*/, void* pwdg) {
        auto pWidgets = static_cast<fltk_gui::UserWidgets*>(pwdg);

        try
        {
            double in1 = std::stod(pWidgets->first->value());

            double in2 = std::stod(pWidgets->second->value());

            auto result = in1 - in2;

            {
                std::stringstream  sin;
                sin << std::fixed << std::setprecision(3) << result;

                auto str_value = sin.str();

                pWidgets->output->label(str_value.c_str());
            }

        }
        catch (const std::exception& e)
        {
            fl_alert("Error during subs: %s", e.what());
        }
    }
}