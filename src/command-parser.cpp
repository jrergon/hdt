#include <iostream>

#include "command-parser.h"
#include "init.h"

using namespace std;

CommandParser* CommandParser::instance = nullptr;

CommandParser::CommandParser(boost::program_options::variables_map varMap, char* subCmd)
{
    if(strcmp(subCmd, "init") == 0) {
        string host = varMap["host"].as<string>();
        string username = varMap["username"].as<string>();
        string password = varMap["password"].as<string>();
        string type = varMap["type"].as<string>();

        new Init(&host[0u], &username[0u], &password[0u], &type[0u]);
    }
}

CommandParser* CommandParser::getInstance(boost::program_options::variables_map varMap, char* subCmd)
{
    if(CommandParser::instance == nullptr) {
        CommandParser::instance = new CommandParser(varMap, subCmd);
    }

    return CommandParser::instance;
}
