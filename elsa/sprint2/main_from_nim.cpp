#include "mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.ELSA.v0_0_1");
    //I have changed version name and numer after copying from nim
    Mainwin win;
    return app->run(win);
}
