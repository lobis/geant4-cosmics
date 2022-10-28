//
// Created by lobis on 28/10/2022.
//

#include "UIMacros.h"

#include <G4UImanager.hh>

using namespace std;

vector<string> split(const string& s) {
    // splits a string with the contents of a macro file into a vector of UI commands (no comments or empty lines)
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, '\n')) {
        // strip of leading and trailing whitespaces
        const char* whitespaceTokens = " \t";
        token.erase(0, token.find_first_not_of(whitespaceTokens));
        token.erase(token.find_last_not_of(whitespaceTokens) + 1);

        if (token.empty()) {
            // skip empty lines
            continue;
        }
        if (token[0] == '#') {
            // do not include comments
            continue;
        }
        tokens.push_back(token);
    }
    return tokens;
}

void ExecuteMacro(const string& macro) {
    const auto tokens = split(macro);
    for (const auto& token: tokens) {
        G4UImanager::GetUIpointer()->ApplyCommand(token);
    }
}

void ExecuteVisualizationMacro() {
    ExecuteMacro(macros::visualization);
}