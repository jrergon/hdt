#ifndef MYSQL_CONNECTOR_H
#define MYSQL_CONNECTOR_H

#include "connector.h"
#include "config.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class MysqlConnector : public Connector
{
public:
    static MysqlConnector* getInstance(Config* config);
    vector<string> getTableList();
private:
    MysqlConnector(Config* config);

    Config* config;
    static MysqlConnector* instance;
    static sql::Connection* connection;
};

#endif
