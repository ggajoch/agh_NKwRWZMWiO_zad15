
#include "ParseGraphFile.hpp"



ParseGraphFile::ParseGraphFile(std::string FileName)
{
    FILE.open(FileName);
}

ParseGraphFile::~ParseGraphFile()
{
    FILE.close();
}

std::vector<std::string>ParseGraphFile::GetStrLines()
{
  std::string line;

  while (std::getline(FILE, line))
  {
    lines.push_back(line);
  }
  return lines;
}


IntMatrix ParseGraphFile::ConvertStrLinesToInt()
{
  IntMatrix array;

  for( std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it)
  {
    std::vector<int> sub;
    int temp;
    std::istringstream iss(*it);

    for(int i = 0; i < 3; i++)
    {
      iss >> temp;
      sub.push_back(temp);
    }
    array.push_back(sub);
  }

  return array;
}
