#include "MoabCommandHandler.hpp"
#include "MoabCommandExecution.hpp"

MoabCommandHandler::MoabCommandHandler()
{}

MoabCommandHandler::~MoabCommandHandler()
{}

std::vector<std::string> MoabCommandHandler::get_syntax()
{
  std::string syntax = 
    "mbconvert "
    "<string:label='infile', help='<infile>'> "
    "<string:label='outfile', help='<outfile>'>";

  std::vector<std::string> syntax_list;
  syntax_list.push_back(syntax);

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
  std::string infile;
  data.get_string("infile", infile);
  
  std::string outfile;
  data.get_string("outfile", outfile);

  return MoabCommandExecute(infile,outfile);
}
