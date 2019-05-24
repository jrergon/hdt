#include "fileable.h"

class Config : public Fileable
{
public:
    Config(char* host, char* username, char* password, char* type);

    char* getHost() const;
    void setHost(char* value);

    char* getUsername() const;
    void setUsername(char* value);

    char* getPassword() const;
    void setPassword(char* value);

    char* getType() const;
    void setType(char* value);

    XMLDocument* toFileContent();
private:
    char* host;
    char* username;
    char* password;
    char* type;
};
