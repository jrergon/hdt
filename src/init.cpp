#include "init.h"
#include "config.h"
#include "filesystem.h"

#include <iostream>

using namespace std;

Init::Init(char* host, char* username, char* password, char* dbType, char* dbName)
{
    Config* config = new Config(host, username, password, dbType, dbName);
    FileSystem fileSystem;

    bool status = fileSystem.createXmlFile(config->toFileContent(), "config.xml");

    if(status) {
        cout << "HDT project initialized successfully" << endl;
    }else {
        cout << "An error occured" << endl;
    }
}
