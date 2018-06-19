#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "structs.h"

class ParseGraphFile {
private:
    std::ifstream file;
public:
    ParseGraphFile(std::string FileName);

    ~ParseGraphFile();

    Task parse_task();
};
