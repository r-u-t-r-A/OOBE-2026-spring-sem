#include "HexParser.h"

HexParser::HexParser()
{
}

void HexParser::parse()
{
    readFile(dataStrUndivided);
    for (const auto& line : dataStrUndivided) {
        std::array<uint16_t, 3> numbers;
        for (size_t i = 0; i < 3; ++i) {
            std::string hexStr = line.substr(i * 4, 4);
            numbers[i] = static_cast<uint16_t>(std::stoul(hexStr, nullptr, 16));
        }
        dataUint.push_back(numbers);
    }
}

void HexParser::output()
{
    for (const auto& numbers : dataUint) {
        float average = (numbers[0] + numbers[1] + numbers[2]) / 3.0f;
        dataOut.push_back(average);
    }
    writeFile(dataOut);
}

