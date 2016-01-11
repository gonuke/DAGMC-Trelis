/*!
 *  \file MyComp.cpp
 *  \brief
 *    Provides an example of creating a custom component.
 *  \author Michael Plooster
 *  \date 11 Feb 2014
 */

#include "MyComp.hpp"
#include "MenuManager.hpp"

#include "Claro.hpp"
#include <QAction>
#include <vector>


// Default constructor. Remember to include the component name (should match
// the module name in mycomp.i).
MyComp::MyComp() :
  Component("mycomp"),
  myMenus(NULL)
{}

MyComp::~MyComp()
{
  if(myMenus)
    delete myMenus;
}

void MyComp::start_up(int withGUI)
{
  if(withGUI)
  {
    if(!myMenus)
      myMenus = new MenuManager;

    myMenus->setup_moab_menu();
  }

}

void MyComp::clean_up()
{
  if(myMenus)
    myMenus->remove_moab_menu();
}

