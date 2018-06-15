#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef std::vector< std::vector<int> > IntMatrix;

class ParseGraphFile
{
private:
	std::ifstream FILE;
	std::vector<std::string> lines;
public:
    ParseGraphFile(std::string FileName);
    ~ParseGraphFile();
    std::vector<std::string> GetStrLines();
    IntMatrix ConvertStrLinesToInt();
};
