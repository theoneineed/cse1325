#include "mainwin.h"
#include <gtkmm.h>

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.elsa.v0_0_1");
    Mainwin win;
    return app->run(win);
}
