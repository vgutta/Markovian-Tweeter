#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "markov.h"

//Namespaces
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::stringstream;

int main() {
    std::vector<std::string> words;
    std::ifstream file("bananas.txt");
 
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    std::cout << words.size() << std::endl;
    
    std::unique_ptr<Markov> markov(new Markov);

    std::vector<std::string> markov_tweet = markov->get_tweet(words);

    for (auto &word : markov_tweet) {
        cout << word + " ";
    }
    cout << endl;
    return 0;
}