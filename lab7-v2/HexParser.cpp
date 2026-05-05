#include "HexParser.h"

HexParser::HexParser() {
	readFile(dataStrUndivided);
}

void HexParser::parse() {
	dataUint.clear(); 
	std::stringstream lineStream;
	for (std::string line : dataStrUndivided) {
		lineStream.str(line);
		lineStream.clear();
		std::string item;
		std::array<uint16_t, 3> row;
		size_t i = 0;
		while (getline(lineStream, item, ';')) {
			if (i < row.size()) {
				row.at(i)=std::stoul(item, nullptr, 16);
			}
			i++;
		}
		dataUint.push_back(row);
	}
}

void HexParser::output() {
	dataOut.clear(); 

	for (std::array<uint16_t, 3> row : dataUint) {
		dataOut.push_back((row.at(0) + row.at(1) + row.at(2)) / 3.0f);
	}

	writeFile(dataOut);
}