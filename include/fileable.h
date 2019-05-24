#include "tinyxml2.h"

using namespace tinyxml2;

class Fileable
{
public:
    virtual XMLDocument* toFileContent() = 0;
};
