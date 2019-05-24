#include <iostream>
#include <boost/program_options.hpp>

#include "command-parser.h"

using namespace std;

namespace
{
  const size_t ERROR_IN_COMMAND_LINE = 1;
  const size_t SUCCESS = 0;
}

int main(int argc, char* argv[])
{
    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
      ("help,h", "list available subcommands")
      ("init,i", "initialize new hdt project")
      ("host,h", po::value<string>(), "host address of rdbms")
      ("username,u", po::value<string>(), "username to authenticate")
      ("password,p", po::value<string>(), "password of authenticated user")
      ("type,t", po::value<string>(), "type of rdbms");

    po::variables_map varMap;

    try {
        po::store(po::parse_command_line(argc, argv, desc), varMap);

        po::notify(varMap);
        CommandParser::getInstance(varMap, argv[1]);
    } catch(po::error& e) {
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
      std::cerr << desc << std::endl;
      return ERROR_IN_COMMAND_LINE;
    }

    return SUCCESS;
}
