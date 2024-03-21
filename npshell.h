#ifndef npshell_H
#define npshell_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class CMD {
    vector< pair<string, string> > commandPairs;
    int timestamp;

    public:
        CMD();
        CMD(string);
        ~CMD();
        void setTimeStamp(int ts);
        vector< pair<string, string> > getcommandPairs(void) {
            return commandPairs;
        }
        
};

CMD::CMD() {
    timestamp = 0;
}

CMD::~CMD() { commandPairs.clear();}

CMD::CMD(string c) {
    vector<string> v;
    stringstream ss;
    string s1, s2;
    ss.clear();
    ss << c;

    while (true) {
        ss >> s1;
        if (ss.fail()) break;
        ss >> s2;
        if (ss.fail()) {
            commandPairs.push_back(make_pair(s1,""));
            break;
        }
        commandPairs.push_back(make_pair(s1, s2));
    }
}

void CMD::setTimeStamp(int ts) {
    timestamp = ts;
}

#endif