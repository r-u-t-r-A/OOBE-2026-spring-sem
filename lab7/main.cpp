#include "HexParser.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>

int main(void) {
  FileManager fm;
  HexParser hp;  
    //std::fstream inFile;
    std::fstream outFile;
    if (!fm.openFile(outFile, "data_in.txt", std::ios::in)) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    if (!fm.openFile(outFile, "data_out.txt", std::ios::out)) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }
    hp.parse();
    hp.output();
    //fm.closeFile(inFile);
    fm.closeFile(outFile);

}