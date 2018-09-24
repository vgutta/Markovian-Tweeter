#include "markovian.h"

// Namespaces
using std::string;

// Returns vector containing generated tweet
std::vector<string> Markovian::get_tweet(std::vector<string> &words) {
    Prefix prefix((unsigned long) NPREF, NONWORD);
    build(prefix, words);
    add(prefix, NONWORD);
    std::vector<string> generated_tweet = generate(MAXGEN);
    return generated_tweet;
}

// takes input words and builds state table
void Markovian::build(Prefix& prefix, std::vector<string> &words){
    for(auto &word: words){
        add(prefix, word);
    }
}

// adds word to suffix deque, updates prefix
void Markovian::add(Prefix& prefix, const string& s){
    if (prefix.size() == NPREF) {
        statetab[prefix].push_back(s);
        prefix.pop_front();
    }
    prefix.push_back(s);
}

// produces output, one word per line
std::vector<string> Markovian::generate(int nwords){
    Prefix prefix;
    int i;
    
    std::vector<string> markov;
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (i = 0; i < NPREF; i++)
        add(prefix, NONWORD);
    for (i = 0; i < nwords; i++) {
        std::vector<string>& suf = statetab[prefix];
        const string& w = suf[std::rand() % suf.size()];
        if (w == NONWORD)
            break;
        markov.push_back(w);
        prefix.pop_front(); // advance
        prefix.push_back(w);
    }
    return markov;
}

