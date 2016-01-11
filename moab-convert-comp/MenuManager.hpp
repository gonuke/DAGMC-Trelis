/*!
 *  \file MenuManager.hpp
 *  \brief
 *    Provides an example of how to create menus and menu items using
 *    the Claro framework.
 *  \author Michael Plooster
 *  \date 11 Feb 2014
 */

#ifndef MENUMANAGER_HPP
#define MENUMANAGER_HPP

#include <QObject>

class MenuManager : public QObject
{
  Q_OBJECT

public:
  MenuManager(QObject* parent = 0);
  ~MenuManager();

  // Provides an example of creating your own menu.
  void setup_moab_menu();

  // Provides an example of how to remove your menu items.
  void remove_moab_menu();

public slots:
  void moabConvert_triggered();

private:
  bool menuInitialized;

};

#endif // MENUMANAGER_HPP
