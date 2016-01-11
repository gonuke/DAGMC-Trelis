#include "MoabCommandHandler.hpp"
#include "MoabCommandExecution.hpp"

MoabCommandHandler::MoabCommandHandler()
{}

MoabCommandHandler::~MoabCommandHandler()
{}

std::vector<std::string> MoabCommandHandler::get_syntax()
{
  std::vector<std::string> syntax_list;
  syntax_list.push_back("mbconvert");

  return syntax_list;
}

std::vector<std::string> MoabCommandHandler::get_syntax_help()
{
  std::vector<std::string> help;
  return help;
}

std::vector<std::string> MoabCommandHandler::get_help()
{
  std::vector<std::string> help;
  return help;
}

bool MoabCommandHandler::execute(CubitCommandData &data)
{
  return MoabCommandExecute();
}
