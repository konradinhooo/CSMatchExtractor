#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Round float numbers to the spot after the decimal (default = 0) //
float round_to(float value, int places = 0) {
    float factor = pow(10.0f, places);
    return round(value * factor) / factor;
}

// Skip words in a file //
// Usage: skips to the point where it matches the given 'word'
// if giveNextWord = true, skip 'word' and assign the next value
// after it to the 't'
void skip(ifstream& in, string& t, const string word, bool giveNextWord = true) {
    while (t != word) in >> t;
    if(giveNextWord) in >> t;
}

// Skip words in a file #2 //
// Usage: skip 'n' words, the last value is assigned to the 't'
void skip(ifstream& in, string& t, const int n) {
    for (int i = 0; i < n; ++i) in >> t;
}

// Removing quotes //
// Usage: If the first and the last letter is ",
// subtract the word from the given 't'
string rm_quotes(string& t) {
    if (t[0] == '\"' && t[t.length() - 1] == '\"') {
        t = t.substr(1, t.length() - 2);
    }
    return t;
}

// Writing a line to the output stream //
// Usage: write 'n' chars 'c' to the output stream 'o'
// if endl_flag = true - it uses 'endl'
void write_line(ostream& o, const int n, const char c = '-', bool endl_flag = true) {
    for (int i = 0; i < n; ++i) o << c;
    if (endl_flag) o << endl;
}

#endif