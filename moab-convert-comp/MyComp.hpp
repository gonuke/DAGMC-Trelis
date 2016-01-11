/*!
 *  \file MyComp.hpp
 *  \brief
 *    Provides an example of creating a custom component.
 *  \author Michael Plooster
 *  \date 11 Feb 2014
 */

#ifndef MYCOMP_HPP
#define MYCOMP_HPP

#include "Component.hpp"

class MenuManager;

class MyComp : public Component
{
public:
  MyComp();
  ~MyComp();

  // Methods inherited from Component
  void start_up(int withGUI);
  void clean_up();

private:

  MenuManager* myMenus;

};

#endif // MYCOMP_HPP
