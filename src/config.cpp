#include "config.h"

Config::Config(char* host, char* username, char* password, char* type, char* dbName)
{
    this->host = host;
    this->username = username;
    this->password = password;
    this->type = type;
    this->dbName = dbName;
}

Config::Config(XMLDocument* xmlDoc)
{
    XMLNode* configNode = xmlDoc->FirstChild();
    this->host = (char*)configNode->FirstChildElement("Host")->GetText();
    this->username = (char*)configNode->FirstChildElement("Username")->GetText();
    this->password = (char*)configNode->FirstChildElement("Password")->GetText();
    this->type = (char*)configNode->FirstChildElement("Type")->GetText();
    this->dbName = (char*)configNode->FirstChildElement("Name")->GetText();
}

char* Config::getHost() const
{
    return host;
}

void Config::setHost(char* value)
{
    host = value;
}

char* Config::getUsername() const
{
    return username;
}

void Config::setUsername(char* value)
{
    username = value;
}

char* Config::getPassword() const
{
    return password;
}

void Config::setPassword(char* value)
{
    password = value;
}

char* Config::getType() const
{
    return type;
}

void Config::setType(char* value)
{
    type = value;
}

char* Config::getDbName() const
{
    return dbName;
}

void Config::setDbName(char* value)
{
    dbName = value;
}

XMLDocument* Config::toFileContent() {
    XMLDocument* xmlDoc = new XMLDocument();

    XMLNode* rootNode = xmlDoc->NewElement("Config");
    xmlDoc->InsertFirstChild(rootNode);

    XMLElement* hostElement = xmlDoc->NewElement("Host");
    hostElement->SetText(this->host);
    rootNode->InsertEndChild(hostElement);

    XMLElement* userNameElement = xmlDoc->NewElement("Username");
    userNameElement->SetText(this->username);
    rootNode->InsertEndChild(userNameElement);

    XMLElement* passwordElement = xmlDoc->NewElement("Password");
    passwordElement->SetText(this->password);
    rootNode->InsertEndChild(passwordElement);

    XMLElement* typeElement = xmlDoc->NewElement("Type");
    typeElement->SetText(this->type);
    rootNode->InsertEndChild(typeElement);

    XMLElement* nameElement = xmlDoc->NewElement("Name");
    nameElement->SetText(this->dbName);
    rootNode->InsertEndChild(nameElement);

    return xmlDoc;
}
