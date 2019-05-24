#include "config.h"

Config::Config(char* host, char* username, char* password, char* type)
{
    this->host = host;
    this->username = username;
    this->password = password;
    this->type = type;
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

    return xmlDoc;
}
