#pragma once
#include "FileManager.h"
#include <string>
#include <vector>
#include <array>


class HexParser : protected FileManager
{
	//vector of arrays to store divided numbers, parsed to uint16_t
	std::vector<std::array<uint16_t, 3>> dataUint;
	//vector of strings to store undivided lines
	std::vector<std::string> dataStrUndivided;
	//vector of floats to store average for each line
	std::vector<float> dataOut;

public:
	HexParser();
	void parse();
	void output();
};