#include <iostream>

/*
Your program should take a filename from the user. This indicates the file you want to use to generate markov text from.

Your program should take a number from the user. This indicates how many markov words you should generate.

Your program should take another number from the user. This indicates the length of the key to be used.

* Build a map

* Pick a key at random from the map

* Pick a random value associated with that key. Print the value to cout

* Remove the first word from the key and add the value to the end of the key. Repeat until you have generated enough words.
 */
#include "fullmarkovgenerator.h"
using std::cout;
using std::endl;
const std::string INPUTFILE = "/Users/alialkahli/CLionProjects/FullMarkovGenerator/emma.txt";
#include <map>
#include <vector>
int main() {
   std::string file;
    int key;
    int wordsToGenerate;
   cout << "Please insert a file name , length of key to be used, and how many Markov words to generate."<< endl;
    std::cin >> file >> key >> wordsToGenerate;
    MarkovGenerator generator(file, key, wordsToGenerate);
    generator.generate();



   return 0;
}
