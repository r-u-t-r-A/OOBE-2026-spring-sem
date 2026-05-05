#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "stdint.h"

class FileManager
{
protected:
	//string to store inputh path "data_in.txt"
	std::string inputPath;
	//string to store inputh path "data_out.txt"
	std::string outputPath;
	//variable to store reference to input file
	std::fstream inFile;
	//variable to store reference to output file
	std::fstream outFile;

public:
	FileManager();
	~FileManager();

	bool openFile(std::fstream& file, std::string path, std::ios_base::openmode mode);
	bool closeFile(std::fstream& file);
	void readFile(std::vector<std::string>& output);
	void writeFile(std::vector<float>& input);
};