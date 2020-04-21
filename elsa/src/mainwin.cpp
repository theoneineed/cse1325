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
#include "ram.h"
#include <string>
#include <sstream>
#include <fstream>

Mainwin::Mainwin(){

  // /////////////////
  // G U I   S E T U P
  // /////////////////
  store=new Store();
  set_default_size(450,550); //going crazy over here LOL
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

  Gtk::MenuItem *menuitem_test = Gtk::manage(new Gtk::MenuItem("_Test", true));
  menuitem_test->signal_activate().connect([this] {
      Store* store[] = {
        new Customer();
          };

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

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);




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

  // S A V E   G A M E
  // Save submenu goes under FILE menu
   Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
  menuitem_save->signal_activate().connect([this] {this->on_save_click();});
  filemenu->append(*menuitem_save);

  // // Save As... to the File menu
  Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
  menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
  filemenu->append(*menuitem_save_as);

// O P E N
//load the saved file
Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
menuitem_open->signal_activate().connect([this] {this->on_open_click();});
filemenu->append(*menuitem_open);


  //now adding new store under File menu
  Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
  new_store_button->set_tooltip_markup("Create a new store, discarding any in progress");
  new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
  toolbar->append(*new_store_button);



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

  // RAM
  Gtk::MenuItem *menuitem_view_ram = Gtk::manage(new Gtk::MenuItem("Ram", true));
  menuitem_view_ram->signal_activate().connect([this] {this->on_view_ram_click();});
  viewmenu->append(*menuitem_view_ram);


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


  //     Q U I T
  // Push the quit botton all the way to the right by setting set_expand true
  Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
  sep->set_expand(true);
  toolbar->append(*sep);

  // Add a icon for quitting
  Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
  quit_button->set_tooltip_markup("Exit");
  quit_button->signal_clicked().connect([this] {this->on_quit_click();});
  toolbar->append(*quit_button);

  // /////////////////////////// ////////////////////////////////////////////
  // label is the box where all the strings show up. So, we need to manage it for the
  //sake of erasing heap after it is closed and hexpand and vexpand expand the label
  //horizontallu and vertically so that menu transforms accorsingly.
  // Provide a text entry box to show the remaining sticks
  data= Gtk::manage(new Gtk::Label());
  data->set_hexpand(true);
  data->set_vexpand(true);
  vbox->add(*data);

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

  //Start a new STORE
  on_new_store_click();

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

//Now, I will go through all the methods being called above and it can be done by looking at the .h file

//So, copy paste commands from the .h file and then fill'em up with sweet delic codes

void Mainwin::on_new_store_click()
{
  store= new Store();
}




void Mainwin::on_save_click(){

    if (filename.length()==0){
        on_save_as_click();
    }
    else{
      std::ofstream ofs{filename};
      store->save(ofs);
    }
        msg->set_text("Saved to designated directory.");
}


void Mainwin::on_save_as_click(){
Gtk::FileChooserDialog dialog("Please choose a file",
Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);


auto filter_elsa = Gtk::FileFilter::create();
filter_elsa->set_name("ELSA Files");
filter_elsa->add_pattern("*.elsa");
dialog.add_filter(filter_elsa);

auto filter_any = Gtk::FileFilter::create();
filter_any->set_name("Any Files");
filter_any->add_pattern("*");
dialog.add_filter(filter_any);

dialog.set_filename("default.elsa");

dialog.add_button("_Cancel",0);
dialog.add_button("_save",1);

int result = dialog.run();

if (result == 1){
    try{
        std::ofstream ofs{dialog.get_filename()};
        store->save(ofs);
         filename = dialog.get_filename();
        }
        catch(std:: exception e){
            Gtk::MessageDialog{*this, "Saving failed"}.run();

        }
}

}

//
// void Mainwin::on_button_click() {
//     Gtk::MessageDialog{*this, "Ouch!"}.run();
// }



void Mainwin::on_open_click(){
 Gtk::FileChooserDialog dialog("Select a file to open", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);


auto filter_elsa = Gtk::FileFilter::create();
filter_elsa->set_name("ELSA Files");
filter_elsa->add_pattern("*.elsa");
dialog.add_filter(filter_elsa);

auto filter_any = Gtk::FileFilter::create();
filter_any->set_name("Any Files");
filter_any->add_pattern("*");
dialog.add_filter(filter_any);

dialog.set_filename("default.elsa");

dialog.add_button("_Cancel",0);
dialog.add_button("_Open",1);

int result = dialog.run();

if (result == 1){
    try{
        delete store;
        std::ifstream ifs{dialog.get_filename()};
        filename  = dialog.get_filename();
        if(ifs){store= new Store(ifs);}
        }
        catch(std:: exception e){
            Gtk::MessageDialog{*this, "failed to open ELSA file."}.run();

        }
}


}



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

void Mainwin::on_view_ram_click()
{
  std::ostringstream os ;
  os <<"Ram:\n";
  for(int i=0; i<Ram.size(); ++i)
      {os << i << ") " << store->Ram(i) << "\n";}
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


  //set_msg("With that, we got new order placed!!");

};

void Mainwin::on_insert_customer_click()
{
  std::string name = get_string("Name of the customer? ");
  if(name.size())
  {
    std::string phone = get_string("Enter your phone number(no area code reqd.)? ");
    std::string email = get_string("Enter email of customer (xxx@domain.com)? ");
    Customer customer{name, phone, email};
    store->add_customer(customer);
  }
  set_msg("New Customer added...");
};



std::string Mainwin::get_string(std::string prompt)
{

  EntryDialog edialog{*this, "Please enter a string...", true};
  edialog.set_secondary_text(prompt, true);
  edialog.set_text(" ");
  edialog.run();
  std::string output = edialog.get_text();
  return output;
};



double Mainwin::get_double(std::string prompt)
{

  EntryDialog edialog{*this, prompt, true};

  edialog.set_text(" ");
  edialog.run();
  std::string output = edialog.get_text();
  return std::stod(output);

};



int Mainwin::get_int(std::string prompt)
{
  EntryDialog edialog{*this,prompt, true};
  edialog.set_text(" ");
  edialog.run();
  std::string output = edialog.get_text();
  return std::stoi(output);
};



void Mainwin::set_data(std::string s)
{
  data->set_markup(s);
};



void Mainwin::set_msg(std::string s)
{
  msg->set_markup(s);
};



  void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("Project_ELSA_CSE1325");
    auto logo = Gdk::Pixbuf::create_from_file("ELSA.PNG");
    dialog.set_logo(logo);
    dialog.set_version("Version0_0_1");
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Nabin Chapagain"};
    dialog.set_authors(authors);
    // std::vector< Glib::ustring > artists = {
    //   "Logo from pixabay, liscenced for free use https://pixabay.com/vectors/frozen-elsa-cold-disney-princess-2267127/"};
    //   dialog.set_artists(artists);
      dialog.run();
    }
