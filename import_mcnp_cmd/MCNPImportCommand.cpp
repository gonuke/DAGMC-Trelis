#include "MCNPImportCommand.hpp"
#include "CubitInterface.hpp"

#include "MCNPInput.hpp"

// Missing elements from MCNP2CAD


#define CHK_IGEOM_ERR_RET(A,B)  if (iBase_SUCCESS  != (B)) { \
  message << (A) << (B) << std::endl;                                   \
  CubitInterface::get_cubit_message_handler()->print_message(message.str().c_str()); \
  return false;                                                         \
  }

#define CHK_IGEOM_ERR_RET_IGEOM(A,B)  if (iBase_SUCCESS != (B)) { \
  message << (A) << (B) << std::endl;                                   \
  return (B);                                                           \
  }


MCNPImportCommand::MCNPImportCommand()
{
  tag_materials = true;
  tag_importance = true;
  tag_cell_IDs = true;
  make_graveyard = true;
  infinite_lattice_extra_effort = false;
}

MCNPImportCommand::~MCNPImportCommand()
{}

std::vector<std::string> MCNPImportCommand::get_syntax()
{
  // Define the syntax for the command. Note the syntax is a modified BNF
  // format. Full documentation on the command specification syntax can be
  // found in the documentation.
  std::string syntax =
      "import mcnp "
      "<string:label='filename',help='<filename>'> "
      "[ignore_materials] [ignore_importances] [ignore_cell_IDs] [no_graveyard] "
      "[infinite_lattice_extra_effort]";

  std::vector<std::string> syntax_list;
  syntax_list.push_back(syntax);

  return syntax_list;
}

/** Return the version string
 *
 * Return only numbers ("1.2.3") if full is false, else dated format
 */

std::string trelis_import_mcnp_version( bool full ){
  std::stringstream str;
  str << (full ? "Trelis MCNP Importer version " : "")
      << TRELIS_IMPORT_MCNP_VERSION_MAJOR << "." 
      << TRELIS_IMPORT_MCNP_VERSION_MINOR << "." 
      << TRELIS_IMPORT_MCNP_VERSION_REV;
  if(full)
      str << "\nCompiled on " << __DATE__ << " at " << __TIME__ ;
  return str.str();
}

std::vector<std::string> MCNPImportCommand::get_syntax_help()
{
  std::vector<std::string> help;
  return help;
}

std::vector<std::string> MCNPImportCommand::get_help()
{
  std::vector<std::string> help  = trelis_import_mcnp_version();
  return help;
}

bool MCNPImportCommand::execute(CubitCommandData &data)
{

  message.str("");

  bool result = true;

  result = parse_options(data);

  std::string filename;
  data.get_string("filename",filename);

  std::ifstream input(filename.c_str(), std::ios::in );
  if( !input.is_open() ){
    message << "Error: couldn't open file \"" << filename << "\"" << std::endl;
    return false;
  }

  InputDeck& deck = InputDeck::build(input);

  iGeom_Instance igm;
  int igm_result;

  iGeom_newGeom( "", &igm, &igm_result, 0 );
  CHK_IGEOM_ERR_RET( igm_result, "Initializing iGeom");

  GeometryContext context( igm, deck );
  context.createGeometry();

  teardown();
  
  return result;
}

bool MCNPImportCommand::parse_options(CubitCommandData &data)
{

  // read parsed command for options
  tag_materials = !data.find_keyword("ignore_materials");
  if (!tag_materials)
    message << "Geometry will not include material tags" << std::endl;
  tag_importances = !data.find_keyword("ignore_importances");
  if (!tag_importances)
    message << "Geometry will not include importance tags" << std::endl;
  tag_cell_IDs = !data.find_keyword("ignore_cell_IDs");
  if (!tag_cell_IDs)
    message << "Volumes and surfaces will not be tagged with MCNP IDS" << std::endl;
  make_graveyard = !data.find_keyword("no_graveyard");
  if (!make_graveyard)
    message << "No graveyard will be automatically generated" << std::endl;
  infinite_lattice_extra_effort = !data.find_keyword("infinite_lattice_extra_effort");

  CubitInterface::get_cubit_message_handler()->print_message(message.str().c_str()); 
  message.str("");

}



void MCNPImportCommand::teardown()
{

  CubitInterface::get_cubit_message_handler()->print_message(message.str().c_str()); 
  message.str("");

}


