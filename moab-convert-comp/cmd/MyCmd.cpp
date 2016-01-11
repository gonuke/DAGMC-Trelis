#include "MyCmd.hpp"
#include "MoabCommandHandler.hpp"

MyCmd::MyCmd()
{}

MyCmd::~MyCmd()
{}

std::vector<std::string> MyCmd::get_keys()
{
  std::vector<std::string> keys;
  keys.push_back("MoabCommandHandler");

  return keys;
}

CubitCommand* MyCmd::create_command(const std::string &key)
{
  // NOTE: The internals of Trelis will take owernship of the command,
  // and delete it when it is time to clean up.

  if(key == "MoabCommandHandler")
    return new MoabCommandHandler();

  return NULL;
}
