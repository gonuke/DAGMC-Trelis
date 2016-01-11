#ifndef MYCMD_HPP
#define MYCMD_HPP

#include "CubitCommandInterface.hpp"
#include "CubitPluginExport.hpp"

/*!
 * \brief The MyCmd class derives from CubitCommandInterface
 * which gives access to the parser and allows you to implement
 * your own commands.
 */
class MyCmd : public CubitCommandInterface
{
public:
  MyCmd();
  ~MyCmd();

  //! Used to get a list of unique keys that identify the commands this plugin
  //! will create.
  std::vector<std::string> get_keys();

  //! Returns the command corresponding to 'key'.
  CubitCommand* create_command(const std::string &key);
};

//! This macro is required to identify this as a valid Cubit plugin. The plugin
//! will NOT be loaded if this macro is not present.
CUBIT_PLUGIN(MyCmd)

#endif // MYCMD_HPP
