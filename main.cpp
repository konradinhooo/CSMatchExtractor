#include <iostream>
#include <fstream>
#include <cmath>
#include "classes.h"
#include "extractor.h"

using namespace std;

int main(int argc, char* argv[]) {
    string* srcs = nullptr;
    int files = 0;
    string welcome_message = "Welcome in Match Extractor v1.0\n";

    // Checking number of arguments
    if (argc < 2) {
        cout << welcome_message;
        cout << "How much files do you want to provide?\n";
        int count;
        do {
            cin >> count;
            if(!cin) {
                cin.clear();
                cin.ignore();
            }
        } while (count < 1);
        
        cout << "Provide your files in .txt format (file by file):\n";
        srcs = new string[count];
        for (int i = 0; i < count; i++)
            cin >> srcs[i];
        files = count;
    } else {
        cout << welcome_message;
        srcs = new string[argc - 1];
        for (int i = 0; i < argc - 1; i++)
            srcs[i] = argv[i + 1];
        files = argc - 1;
    }

    match m1; // Creating match object
    for (int i = 0; i < files; i++){
        string input_src = srcs[i]; // Input source
        ifstream in(input_src);
        if (in.fail()) {
            cerr << "Error while opening file: " << input_src << endl;
            return -1;
        }
        
        // Loading match information (depends on the first provided)
        if(i == 0) {
            m1.get_info(in, files);
            in.clear();
            in.seekg(0, ios::beg);
        }
        
        cout << "File: " << input_src << endl;
        m1.extractor(in, i); // Extracting data from current input source
        m1.maps[i].sort_players("adr"); // Sorting players in the scoreboard by ADR
        in.close();
    }

    cout << m1 << endl;
    
    // Writing to the output file
    string outsrc = "match_raport.txt";
    ofstream fout(outsrc);
    if (fout.fail()) {
        cerr << "Could not create match raport.\n";
        fout.close();
        return -1;
    }

    fout << m1;

    if(m1.make_totals() && m1.maps_number() > 1){
        m1.show_totals(cout);
        m1.show_totals(fout);
    } 

    cout << "Full statistics saved in: " << outsrc << endl;

    fout.close();
    
    // Pause for Windows
    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}