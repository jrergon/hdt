#ifndef CONFIG_H
#define CONFIG_H

#include "fileable.h"

class Config : public Fileable
{
public:
    Config(char* host, char* username, char* password, char* type, char* dbName);
    Config(XMLDocument* xmlDoc);

    char* getHost() const;
    void setHost(char* value);

    char* getUsername() const;
    void setUsername(char* value);

    char* getPassword() const;
    void setPassword(char* value);

    char* getType() const;
    void setType(char* value);

    char *getDbName() const;
    void setDbName(char *value);

    XMLDocument* toFileContent();
private:
    char* host;
    char* username;
    char* password;
    char* type;
    char* dbName;
};

#endif
