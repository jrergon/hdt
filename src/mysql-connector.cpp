#include "mysql-connector.h"

#include <iostream>

MysqlConnector* MysqlConnector::instance = nullptr;
sql::Connection* MysqlConnector::connection = nullptr;

MysqlConnector* MysqlConnector::getInstance(Config* config)
{
    if(MysqlConnector::instance == nullptr) {
        MysqlConnector::instance = new MysqlConnector(config);
    }

    return MysqlConnector::instance;
}

MysqlConnector::MysqlConnector(Config* config)
{
    this->config = config;

    if(MysqlConnector::connection) {
        return;
    }

    try {
        sql::Driver* driver = get_driver_instance();
        this->connection = driver->connect(config->getHost(), config->getUsername(), config->getPassword());
    } catch (sql::SQLException &e) {
        cout << e.what() << endl;
    }
}

vector<string> MysqlConnector::getTableList()
{
    vector<string> tableList;
    MysqlConnector::connection->setSchema("information_schema");

    sql::PreparedStatement* stmt = MysqlConnector::connection->prepareStatement(
        "SELECT * FROM tables WHERE table_schema = ?"
    );
    stmt->setString(1, config->getDbName());
    stmt->execute();
    sql::ResultSet* result = stmt->getResultSet();

    while(result->next()) {
        tableList.push_back(result->getString("table_name"));
    }

    delete result;
    delete stmt;

    return tableList;
}
