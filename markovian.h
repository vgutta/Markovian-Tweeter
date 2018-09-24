#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <map>
#include <ctime>

//Namespaces
using Prefix = std::deque<std::string>;
using Suffixes = std::vector<std::string>;
using std::string;

class Markovian {
    private:
        const int MAXGEN = 280;
        const int NPREF = 2;
        const std::string NONWORD = "\n";
        std::map<Prefix, std::vector<string> > statetab;
        
    public:
        Markovian() = default;
        ~Markovian() = default;
        void add(Prefix &prefix, const string &s);
        void build(Prefix &prefix, std::vector<string> &words);
        std::vector<string> generate(int nwords);
        std::vector<string> get_tweet(std::vector<string> &words);
        
};