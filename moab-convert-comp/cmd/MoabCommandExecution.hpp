#include <moab/MOABConfig.h>
#include "moab/Core.hpp"

using namespace moab;

Core mb;

bool MoabCommandExecute(std::string infile, std::string outfile)
{

  mb.load_file(infile.c_str());

  mb.write_file(outfile.c_str());

  return true;
}

