#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "tinyxml2.h"

using namespace tinyxml2;

class FileSystem
{
public:
    bool createXmlFile(XMLDocument* xmlDoc, char* path);
};

#endif
