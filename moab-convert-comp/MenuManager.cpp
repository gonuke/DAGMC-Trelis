/*!
 *  \file MenuManager.cpp
 *  \brief
 *    Provides an example of how to create menus and menu items using
 *    the Claro framework.
 *  \author Michael Plooster
 *  \date 11 Feb 2014
 */

#include "MenuManager.hpp"
#include "Claro.hpp"
#include "CommandWindow.hpp"

#include <QAction>
#include <vector>

#include "cmd/MoabCommandExecution.hpp"

MenuManager::MenuManager(QObject *parent) :
  QObject(parent),
  menuInitialized(false)
{}

MenuManager::~MenuManager()
{}

// This function will create the "MOAB Menu" menu, with a list of actions that
// are useful for MyComp.
void MenuManager::setup_moab_menu()
{
  if(menuInitialized)
    return;

  std::vector<QAction*> menu_list;

  // Create the QActions and connect them to the appropriate slots.
  QAction* action = new QAction(this);
  action->setText(tr("MOAB Convert"));
  connect(action, SIGNAL(triggered()),
          this, SLOT(moabConvert_triggered()));

  menu_list.push_back(action);

  Claro* gui = Claro::instance();
  if(gui)
  {
    // Add the item to our menu. Note that if the named menu does not exist,
    // Claro will create it for us.
    gui->add_to_menu(tr("&MOAB Menu"), menu_list, "mycomp");

    menuInitialized = true;
  }
  else
  {
    for(size_t i = 0; i < menu_list.size(); i++)
      delete menu_list[i];
  }
}

void MenuManager::remove_moab_menu()
{
  // Remove all of our menu items.
  Claro* gui = Claro::instance();
  if(gui)
  {
    // Items are removed based on the component name
    gui->remove_menu_items("mycomp");

    menuInitialized = false;
  }
}

void MenuManager::moabConvert_triggered()
{
  MoabCommandExecute();
}

