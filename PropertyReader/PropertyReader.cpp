//
// Created by MH on 2022-09-04.
//

#include "PropertyReader.h"
#include <sstream>

PropertyReader::PropertyReader(const char *filename) {
    m_filename = filename;
    this->init();
}

void PropertyReader::init() {

    m_ifstream.open(this->getFilename().data(), std::ios_base::in);
    if (!m_ifstream.is_open()) {
        std::fprintf(stderr, "Failed to initialize property, filename=%s\r\n", this->getFilename().data());
        return;
    }

    std::string line;
    while (std::getline(m_ifstream, line)) {
        std::istringstream iss(line);
        // Skip comment line
        if (iss.str().starts_with("#")) {
            continue;
        }

        int split_pos = iss.str().find('=');
        if (split_pos == -1) {
            continue;
        }

        m_dataset[iss.str().substr(0, split_pos).c_str()] = iss.str().substr(split_pos + 1,
                                                                             iss.str().length() - split_pos);
    }

    std::fprintf(stdout, "Initialized property, filename=%s\r\n", this->getFilename().data());
}

std::string_view PropertyReader::getFilename() {
    return m_filename;
}

std::string PropertyReader::getProperty(const char *key) {
    return m_dataset[key];
}
