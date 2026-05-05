#include "FileManager.h"

FileManager::FileManager() {
	inputPath = "data_in.txt";
	outputPath = "data_out.txt";
	openFile(inFile, inputPath, std::ios::in);
	openFile(outFile, outputPath, std::ios::out | std::ios::trunc);
}

FileManager::~FileManager(){
	closeFile(inFile);
	closeFile(outFile);
}

bool FileManager::openFile(std::fstream& file, std::string path, std::ios_base::openmode mode) {
	if (!file.is_open()) {
		file.open(path, mode);
	}
	return !file.is_open();
}

bool FileManager::closeFile(std::fstream& file) {
	if(!file.is_open()) {
		return 1;
	}
	file.close();
	return file.is_open();
}

void FileManager::readFile(std::vector<std::string>& output) {
	if (inFile.is_open()) {
		std::string line;
		while (std::getline(inFile, line)) {
			output.push_back(line);
		}
	}
}

void FileManager::writeFile(std::vector<float>& input) {
	if (outFile.is_open()) {
		for (float line : input) {
			outFile << line << std::endl;
			//std::cout << line << std::endl;
		}
	}
}