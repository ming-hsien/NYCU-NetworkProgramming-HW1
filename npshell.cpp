#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include <sys/wait.h>
#include <unistd.h>

#include "npshell.h"

using namespace std;

#define PROCESS_LIMIT 512

vector<CMD> cmdList;

void pipeProcess() {

}

bool execute(CMD newCmd, int ts) {
    CMD currentCmd = newCmd;
    currentCmd.setTimeStamp(ts);
    
}

void runNpShell() {
    string cmd;
    int count = 1;
    while (true) {
        cout << "%";
        getline(cin, cmd);
        CMD newCmd(cmd);
        if (newCmd.getcommandPairs().size() == 0) continue;

        string BIN = (newCmd.getcommandPairs()[0]).first;
        string PATH = (newCmd.getcommandPairs()[0]).second;
        if (BIN == "printenv") {
            if (PATH == "") continue;
            cout << getenv(PATH.c_str()) << endl;
        }
        else if (BIN == "exit") {
            exit(0);
        }
        else if (BIN == "setenv") {
            if (newCmd.getcommandPairs().size() == 1) continue;
            setenv(PATH.c_str(), newCmd.getcommandPairs()[1].first.c_str(), 1);
        }
        else {
            bool exec = execute(newCmd, count);
            if (!exec) {
                cout << "Unknown command: [" << BIN << "].";
                continue;
            }
        }
        count++;
    }
}

void init() {
    setenv("PATH", "bin/:.", 1);
}

int main() {
    init();
    runNpShell();
}