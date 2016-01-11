#ifndef MOABCOMMANDHANDLER_HPP
#define MOABCOMMANDHANDLER_HPP

#include "CubitCommandInterface.hpp"

/*!
 * \brief The Moabconvertcommand class reimplements the "version" command to
 * display information about the version of MyPlugin in addition to the
 * version information displayed by Trelis.
 */
class MoabCommandHandler : public CubitCommand
{
public:
  MoabCommandHandler();
  ~MoabCommandHandler();

  std::vector<std::string> get_syntax();
  std::vector<std::string> get_syntax_help();
  std::vector<std::string> get_help();
  bool execute(CubitCommandData &data);
};

#endif // MOABCOMMANDHANDLER_HPP
