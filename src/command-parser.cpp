#include <iostream>

#include "command-parser.h"
#include "init.h"
#include "mysql-connector.h"
#include "tinyxml2.h"
#include "config.h"

using namespace tinyxml2;
using namespace std;

CommandParser* CommandParser::instance = nullptr;

CommandParser::CommandParser(boost::program_options::variables_map varMap, char* subCmd)
{
    if(strcmp(subCmd, "init") == 0) {
        string host = varMap["host"].as<string>();
        string username = varMap["username"].as<string>();
        string password = varMap["password"].as<string>();
        string type = varMap["type"].as<string>();
        string dbName = varMap["name"].as<string>();

        new Init(&host[0u], &username[0u], &password[0u], &type[0u], &dbName[0u]);
    } else if(strcmp(subCmd, "list-tables") == 0) {
        XMLDocument* xmlDoc = new XMLDocument();
        xmlDoc->LoadFile("config.xml");

        Config* config = new Config(xmlDoc);
        vector<string> tableList;

        if(strcmp(config->getType(), "mysql") == 0) {
            MysqlConnector* mysql = MysqlConnector::getInstance(config);
            tableList = mysql->getTableList();
        }

        for(int i = 0; i < tableList.size(); i++) {
            cout << tableList.at(i) << endl;
        }
    }
}

CommandParser* CommandParser::getInstance(boost::program_options::variables_map varMap, char* subCmd)
{
    if(CommandParser::instance == nullptr) {
        CommandParser::instance = new CommandParser(varMap, subCmd);
    }

    return CommandParser::instance;
}
