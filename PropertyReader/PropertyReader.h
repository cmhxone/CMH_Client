//
// Created by MH on 2022-09-04.
//

#ifndef CMH_CLIENT_PROPERTYREADER_H
#define CMH_CLIENT_PROPERTYREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <map>

class PropertyReader {

public:
    explicit PropertyReader(const char *filename);

    std::string getProperty(const char *key);

    std::string_view getFilename();

protected:
    void init();

private:
    std::ifstream m_ifstream;
    std::string m_filename;
    std::map<std::string, std::string> m_dataset;
};


#endif //CMH_CLIENT_PROPERTYREADER_H
