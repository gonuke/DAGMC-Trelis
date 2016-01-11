/*!
 *  \file MyComp.cpp
 *  \brief
 *    Provides an example of creating a custom component.
 *  \author Michael Plooster
 *  \date 11 Feb 2014
 */

#include "MyComp.hpp"

// Default constructor. Remember to include the component name (should match
// the module name in mycomp.i).
MyComp::MyComp() :
  Component("mycomp")
{}

MyComp::~MyComp()
{
}

void MyComp::start_up(int withGUI)
{
  if(withGUI)
  {
  }

}

void MyComp::clean_up()
{
}

