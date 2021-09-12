//
// Created by Ali Alkahli on 12/11/20.
//

//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#include "fullmarkovgenerator.h"
using std::cout;
using std::endl;
using std::string;
MarkovGenerator::MarkovGenerator() {
    fileToMap(file);
}
MarkovGenerator::MarkovGenerator(std::string file, int keyLength) {
    this->file = file;
    this->keyLength = keyLength;
    fileToMap(file);

}

MarkovGenerator::MarkovGenerator(std::string file, int keyLength, int wordsToGenerate) {
    this->file = file;
    this->keyLength = keyLength;
    this->wordsToGenerate = wordsToGenerate;
    fileToMap(file);
}

void MarkovGenerator::fileToMap(std::string file) {
    std::ifstream inputFile;
    inputFile.open(file);
    string currentLine;
    string tempCurrentLine;
    int counter = 0;
    std::vector<string> temp;
    std::vector<string> otherTemp;

    if (inputFile) {

        while (!inputFile.eof()) {


            getline (inputFile, currentLine);

            for (int i = 0; i < currentLine.length(); i++) {

                if (currentLine.find(' ') ==i || currentLine.find("    ")== i) {
                    tempCurrentLine = currentLine.substr(0,i);
                    currentLine = currentLine.substr(i+1);
                    storeFile.push_back(tempCurrentLine);
                    i = 0;
                }
            }
            storeFile.push_back(currentLine);
        }
        inputFile.close();
    }
    else
        cout << "Could not open file(s)" << endl;

    for (int i = 0; i < storeFile.size(); ++i) {

        for (int j = i; j < storeFile.size()-1; j++) {

            if (keyLength > counter){

                while (keyLength > counter){
                    temp.push_back(storeFile.at(j));
                    j++;
                    counter++;
                    if (j >= storeFile.size())
                        j = 0;
                }

            }
            else{
                otherTemp.push_back(storeFile.at(j-1));
                if (successor.count(temp) > 0){

                    std::map<std::vector<std::string>, std::vector<std::string>>::iterator it;
                    it = successor.find(temp);
                    for (auto iterator = otherTemp.begin(); iterator != otherTemp.end() ; iterator++) {
                        it->second.push_back(*iterator);

                    }
                }
                else
                    successor.emplace(temp,otherTemp);

                counter = 0;
                temp = {};
                otherTemp = {};
                break;
            }

        }

    }


}

void MarkovGenerator::printMap() {
    cout << "Print map" << endl;

    std::map<std::vector<string>, std::vector<string>>::iterator it;
    for (it = successor.begin(); it != successor.end() ; it++) {

        for (const auto & it2 : it->first)
            cout <<it2 <<" ";

        cout << " => ";
        for (auto & it3 : it->second)
            cout <<it3 <<" ";

        cout << "]"<<endl;


    }


}

void MarkovGenerator::printVector() {

    for (int i = 0; i < storeFile.size(); ++i) {
        cout << storeFile.at(i) << " ";

    }
    cout << endl;


}

void MarkovGenerator::generate() {

    int counter = 0;
    int rand = random() % storeFile.size();
    std::vector<std::string> temp;
    std::vector<std::string> values;

    for (int i = 0; i < keyLength; ++i)
        temp.push_back(storeFile.at(rand+i));


    while (wordsToGenerate > counter){

        int counter2 = 0;
        auto it = successor.find(temp);
        int secondRand;
        secondRand = random() % it->second.size();

        for (auto & it3 : it->second){
            if (secondRand == counter2){
                temp.erase(temp.begin());
                temp.push_back(it3);
                values.push_back(it3);

            }
            counter2++;
        }
        counter++;


    }

    for (auto it = values.begin(); it < values.end() ; it++) {
        cout << * it << " ";
    }
    cout << endl;
}







