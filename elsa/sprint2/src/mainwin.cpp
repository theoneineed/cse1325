/*

|
|   copied this from nim,
|   need to update the variables as required by this application
|

*/

#include "mainwin.h"
#include <iostream> // for std::cerr logging
#include "store.h"
#include "entrydialog.h"
#include <string>

Mainwin::Mainwin(){

  // /////////////////
  // G U I   S E T U P
  // /////////////////
  store=new Store();
  set_default_size(850, 1200); //going crazy over here LOL
  set_title("Project_ELSA_CSE1325");

  // Put a vertical box container as the Window contents
  Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
  add(*vbox);

  // /////// ////////////////////////////////////////////////////////////////
  // M E N U
  // Add a menu bar as the top item in the vertical box
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
  // vbox->add(*menubar);



  //need to notice from the diagram givem, we need file, view, insert and help as menu items


  //     F I L E
  // Create a File menu and add to the menu bar
  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

  //     H E L P
  // Create a Help menu and add to the menu bar
  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  //    V I E w
  Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(*viewmenu);
  //literally just copy pasted the format from help and changed the name to corresponding items


  //    I N S E R T
  Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
  menubar->append(*menuitem_insert);
  Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
  menuitem_insert->set_submenu(*insertmenu);


  /* -- - - - - - - - - - - - - - - -These go inside menu items - - - - - - - - - - - - - - - - - - - - - - */



  //goes under Help
  //           A B O U T
  // Append About to the Help menu
  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
  menuitem_about->signal_activate().connect([this] {this->on_about_click();});
  helpmenu->append(*menuitem_about);



  //goes under File
  //         Q U I T
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
  filemenu->append(*menuitem_quit);





  // goes under view
  //it is just customer, peripheral, desktop, order under view section

  //Peripheral
  Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("Peripheral", true));
  menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
  viewmenu->append(*menuitem_view_peripheral);


  //desktop
  Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
  menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
  viewmenu->append(*menuitem_view_desktop);


  // Order
  Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("Order", true));
  menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
  viewmenu->append(*menuitem_view_order);


  // Customer
  Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
  menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
  viewmenu->append(*menuitem_view_customer);

  /*
******************************************************************************************
                                  **************************
*****************************************************************************************
  */





  //goes under insert
  //which is again, Customer, Peripheral, Desktop, order

  // Customer
  Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
  menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
  insertmenu->append(*menuitem_insert_customer);


  // Peripheral
  Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("Peripheral", true));
  menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
  insertmenu->append(*menuitem_insert_peripheral);


  // Desktop
  Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
  menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_insert_desktop);

  // Order
  Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("Order", true));
  menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
  insertmenu->append(*menuitem_insert_order);


/*
************************************************************************************************************
                                          ********************************************************
******************************************************************************************************************

*/



  // ///////////// //////////////////////////////////////////////////////////
  // T O O L B A R
  // Add a toolbar to the vertical box below the menu
  Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
  vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
  // vbox->add(*toolbar);














  //     Q U I T
  // Push the quit botton all the way to the right by setting set_expand true
  Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
  sep->set_expand(true);
  toolbar->append(*sep);

  // Add a icon for quitting
  Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
  quit_button->set_tooltip_markup("Exit game");
  quit_button->signal_clicked().connect([this] {this->on_quit_click();});
  toolbar->append(*quit_button);

  // /////////////////////////// ////////////////////////////////////////////
  // label is the box where all the strings show up. So, we need to manage it for the
  //sake of erasing heap after it is closed and hexpand and vexpand expand the label
  //horizontallu and vertically so that menu transforms accorsingly.
  // Provide a text entry box to show the remaining sticks
  bucket = Gtk::manage(new Gtk::Label());
  bucket->set_hexpand(true);
  bucket->set_vexpand(true);
  vbox->add(*bucket);

  //now, to contain horizontal box inside a vertical box
  Gtk::Box *hbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
  msg = Gtk::manage(new Gtk::Label());
  msg->set_hexpand(true);
  hbox->add(*msg);
  vbox->add(*hbox);
  //vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
  // vbox->add(*msg);

  // Make the box and everything in it visible
  vbox->show_all();

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

//Now, I will go through all the methods being called above and it can be done by looking at the .h file

//So, copy paste commands from the .h file and then fill'em up with sweet delic codes

void Mainwin::on_quit_click()
{
  close();
}

void Mainwin::on_view_peripheral_click()
{

  std::ostringstream os ;
  os <<"Peripheral:\n";
  for(int i=0; i<store->num_options(); ++i)
    os << i << ") " << store->option(i) << "\n";

  set_data(os.str());
};
void Mainwin::on_view_desktop_click()
{
  std::ostringstream os ;
  os <<"Desktop:\n";
  for(int i=0; i<store->num_desktops(); ++i)
      os << i << ") " << store->desktop(i) << "\n";

  set_data(os.str());
};



void Mainwin::on_view_order_click()
{
  std::ostringstream os ;
  os <<"Order:\n";
  for(int i=0; i<store->num_orders(); ++i)
      {os << i << ") " << store->order(i) << "\n";}
  set_data(os.str());
};


void Mainwin::on_view_customer_click()
{

      std::ostringstream os ;
      os <<"Customer:\n";
      for(int i=0; i<store->num_customers(); ++i)
          os << i << ") " << store->customer(i) << "\n";

      set_data(os.str());

};



void Mainwin::on_insert_peripheral_click()
{

      std::string name = get_string("Peripheral item name? ");
      double cost= get_double("Price?");
      Options option{name, cost};
      store->add_option(option);

      set_msg("New Peripheral received!");
};



void Mainwin::on_insert_desktop_click()
{
  int desktop = store->new_desktop();
      while(true) {
          std::ostringstream os;
          os << store->desktop(desktop) << "\n\n";
          for(int i=0; i<store->num_options(); ++i)
             os << i << ") " << store->option(i) << '\n';
          os << "\nEnter the code for peripheral you want (-1 when done)? ";
          int option = get_int(os.str());
          if(option == -1) break;
          try {
              store->add_option(option, desktop);
          } catch(std::exception& e) {
                  Gtk::MessageDialog mdialog{*this, "Not valid. Try again later.\n\n"};
              ;
          }
      }
      set_msg("Desktop added!\n");
};



void Mainwin::on_insert_order_click()
{

  int customer = -1;
  int order    = -1;
  int desktop  = -1;
  try {
    on_view_customer_click();
    customer = get_int("Customer (ID)? ");
    std::ostringstream os;
    order = store->new_order(customer);
    os << "Order " << order
    << " ordered by Customer :" << store->customer(customer) << std::endl;
    desktop = 0;
  } catch(std::exception& e) {
    std::ostringstream ost;

    ost << "Error in order handling.  " << customer << " ####\n\n";
    Gtk::MessageDialog mdialog{*this, ost.str()};
  }

  while(desktop >= 0) {
    on_view_desktop_click();
    desktop = get_int("Desktop (-1 when done)? ");

    if(desktop == -1) break;
    try {
      store->add_desktop(desktop, order);
    } catch (std::exception& e) {
      std::ostringstream ost;
      ost<< "-----Can't add the desktop  " << desktop  << " TO ORDER " << order << std::endl;
      Gtk::MessageDialog mdialog{*this, ost.str()};
      desktop = 0;
    }
  }

  if(order >= 0){

    std::ostringstream ooo;
    ooo << "\n++++ Order " << order << " Placed ++++\n" << store->order(order);
    Gtk::MessageDialog mdialog{*this, ooo.str()};
    set_msg("Order placed");
  }


  set_msg("With that, we got new order placed!!");

};
//update now

void Mainwin::on_insert_customer_click()
{

};



void Mainwin::on_about_click()
{

};



std::string Mainwin::get_string(std::string prompt)
{

};



double Mainwin::get_double(std::string prompt)
{

};



int Mainwin::get_int(std::string prompt)
{

};



void Mainwin::set_data(std::string s)
{

};



void Mainwin::set_msg(std::string s)
{

};





void Mainwin::on_button_click(int button) {
  try {
    // Catch the "impossible" out of sticks exception
    nim->take_sticks(button);
    set_sticks();
  } catch(std::exception& e) {
    sticks->set_markup("<b>FAIL:</b> " + std::string{e.what()} + ", start new game");
  }
}

// void Mainwin::on_computer_player_click() {
//   set_sticks();
// }
//
// void Mainwin::on_new_game_click() {
//   delete nim;
//   nim = new Nim();
//   set_sticks();
// }
//
// void Mainwin::on_quit_click() {
//   close();
// }
//
// void Mainwin::on_rules_click() {
//   Glib::ustring s = R"(
//     <span size='24000' weight='bold'>The Rules of Nim</span>
//     <span size='large'>Copyright 2017-2020 by George F. Rice - CC BY 4.0</span>
//
//     The two players alternate taking 1 to 3 sticks from the pile. The goal is to force your opponent to take the last stick (called misère rules).
//
//     If the computer button is up, it's a two player game. If down, the computer is always Player 2.)";
//     Gtk::MessageDialog{*this, s, true}.run(); // 'true' as 3rd parameter enables Pango markup
//   }

  void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("Nim");
    auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
      "Logo by M0tty, licensed under CC BY-SA 3.0 https://commons.wikimedia.org/wiki/File:Pyramidal_matches.svg",
      "Robot by FreePik.com, licensed for personal and commercial purposes with attribution https://www.freepik.com/free-vector/grey-robot-silhouettes_714902.htm"};
      dialog.set_artists(artists);
      dialog.run();
    }

    // /////////////////
    // U T I L I T I E S
    // /////////////////

    void Mainwin::set_sticks() {
      // s collects the status message
      Glib::ustring s = "";

      // If the robot is enabled and it's their turn, move the robot
      if (nim->sticks_left() > 0) {
        if (computer_player->get_active() && nim->current_player() == 2) {
          int move = 1;
          try {
            move = nim->optimal_move();      // "Impossible" exception warning
          } catch(std::exception& e) {         // If it happens, log an error
            std::cerr << "Invalid optimal move: " << e.what() << std::endl;
          }
          s += "Robot plays " + std::to_string(move) + ", ";
          nim->take_sticks(move);
        }
      }

      // Report who's turn it is, or (if all sticks gone) who won
      if (nim->sticks_left() > 0) {
        s += "Player " + std::to_string(nim->current_player()) + "'s turn";
      } else {
        s += "<span size='16000' weight='bold'>Player "
        +  std::to_string(3-nim->current_player())
        +  " wins!</span>";
      }

      // Display the collected status on the status bar
      msg->set_markup(s);

      // Update the visual display of sticks
      s = "<span size='24000' weight='bold'>";
      for(int i=0; i<nim->sticks_left(); ++i) s.append("| ");
      s.append("</span>  (" + std::to_string(nim->sticks_left()) + " sticks)");
      sticks->set_markup(s);

      // Set sensitivity of the human stick selectors so user can't make an illegal move
      button1->set_sensitive(nim->sticks_left() > 0);
      button2->set_sensitive(nim->sticks_left() > 1);
      button3->set_sensitive(nim->sticks_left() > 2);
    }
