#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include <vector>

using namespace std;

class Connector
{
public:
    virtual vector<string> getTableList() = 0;
};

#endif
