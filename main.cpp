#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "markovian.h"

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
    
    std::unique_ptr<Markovian> markovian(new Markovian);

    std::vector<std::string> markovian_tweet = markovian->get_tweet(words);

    int tweet_length = 0;
    
    for (auto &word : markovian_tweet) {
        if(tweet_length > 280){
            break;
        }
        tweet_length += word.length();
        tweet_length += 1;
        cout << word + " ";
    }
    cout << endl;
    return 0;
}