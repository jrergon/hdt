#include "filesystem.h"

bool FileSystem::createXmlFile(XMLDocument* xmlDoc, char* path)
{
    XMLError result = xmlDoc->SaveFile(path);

    if(result == XML_SUCCESS) {
        return true;
    }

    return false;
}
