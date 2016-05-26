#ifndef MYIMPORTCOMMAND_HPP
#define MYIMPORTCOMMAND_HPP

#include "CubitCommandInterface.hpp"
#include "CubitMessageHandler.hpp"


/*!
 * \brief The MCNPImportCommand class implements all the steps necessary
 * to load faceted data into a MOAB instance and export as a MOAB mesh.
 */
class MCNPImportCommand: public CubitCommand
{
public:
  MCNPImportCommand();
  ~MCNPImportCommand();

  std::vector<std::string> get_syntax();
  std::vector<std::string> get_syntax_help();
  std::vector<std::string> get_help();
  bool execute(CubitCommandData &data);

protected:

  bool MCNPImportCommand::parse_options(CubitCommandData &data)
  void teardown();

private:

  std::ostringstream message;

  // options
  bool tag_materials, tag_importance, tag_cell_IDs, make_graveyard, infinite_lattice_extra_effort;


};

#endif // MYIMPORTCOMMAND_HPP
