//
// Created by Ali Alkahli on 12/11/20.
//
#include <map>
#include <vector>

#ifndef FULLMARKOVGENERATOR_FULLMARKOVGENERATOR_H
#define FULLMARKOVGENERATOR_FULLMARKOVGENERATOR_H

class MarkovGenerator {
private:
    std::map<std::vector<std::string>, std::vector<std::string>> successor;
    std::string file = "";
    int keyLength = 1;
    int wordsToGenerate = 1;
    std::vector<std::string> storeFile;
    void fileToMap(std::string file);


public:
    MarkovGenerator();
    MarkovGenerator(std::string file, int keyLength);
    MarkovGenerator(std::string file, int keyLength, int wordsToGenerate);
    void printMap();
    void printVector();
    void generate();



    std::string getFile(){
        return file;
    };
    int getKeyLength(){
        return keyLength;
    };
};


#endif //FULLMARKOVGENERATOR_FULLMARKOVGENERATOR_H
