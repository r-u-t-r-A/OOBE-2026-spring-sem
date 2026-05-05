#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

bool FileManager::openFile(std::fstream& file, std::string path, std::ios_base::openmode mode)
{
    if (mode == std::ios::in) {
        FileManager::inFile.open(path, mode);
        return file.is_open();
    } else if (mode == std::ios::out) {
        FileManager::outFile.open(path, mode);
        return file.is_open();
    }
    //file.open(path, mode);
   return false;
}

bool FileManager::closeFile(std::fstream& file)
{
    file.close();
    return !file.is_open();
}

void FileManager::readFile(std::vector<std::string>& output)
{
    std::string line;
    while (std::getline(inFile, line)) {
        output.push_back(line);
    }
}

void FileManager::writeFile(std::vector<float>& input)
{
    for (const auto& value : input) {
        outFile << value << std::endl;
    }
}

