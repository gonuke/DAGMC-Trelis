#include "CubitInterface.hpp"
#include "CubitMessageHandler.hpp"

bool MoabCommandExecute()
{
  CubitMessageHandler* console = CubitInterface::get_cubit_message_handler();
  
  std::string output;
  
  output = "will execute MOAB converstion here\n";
  console->print_message(output.c_str());
  
  return true;
}
