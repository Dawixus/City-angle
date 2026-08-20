#ifndef CITYANGLE_FILEREADER_H
#define CITYANGLE_FILEREADER_H

#include "City.h"
#include <string>
#include <vector>

class FileReader {
public:
    static std::vector<City> read(const std::string& filename);
};


#endif //CITYANGLE_FILEREADER_H
