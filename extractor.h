#ifndef extractor_h
#define extractor_h

#include <iostream>
#include <fstream>
#include <cmath>
#include "classes.h"

using namespace std;

void match::get_info(ifstream& in, const int argc){
    string txt;
    maps_number() = argc; // Load number of maps
    maps = new map[maps_number()];
        cerr << "Number of maps... " << maps_number() << endl;;

        // Count the number of players
    int player_numA = 0; bool teamA_count = true;
    int player_numB = 0;
    while(!in.eof()){
        in >> txt;
        if(txt == "\"PlayersOnTeam2\"") teamA_count = false;

        if(txt == "\"name\"" && teamA_count) player_numA++;
        else if (txt == "\"name\"" && !teamA_count) player_numB++;
    }
        cerr << "Number of players in team A... " << player_numA;
        cerr << ", in team B... " << player_numB << endl;

    players_number() = player_numA + player_numB;
    teamA = new player[player_numA];
    teamB = new player[player_numB];
        cerr << "Number of players... " << players_number() << endl;
}

void player::extract(ifstream& in){
    string txt;

    skip(in, txt, "\"name\"");
    nickname() = rm_quotes(txt);

    skip(in, txt, "\"enemy2Ks\"");
    doublekills() = stoi(rm_quotes(txt));
    skip(in, txt, "\"enemy3Ks\"");
    triplekills() = stoi(rm_quotes(txt));
    skip(in, txt, "\"enemy4Ks\"");
    quadrakills() = stoi(rm_quotes(txt));
    skip(in, txt, "\"enemy5Ks\"");
    aces() = stoi(rm_quotes(txt));

    skip(in, txt, "\"Totals\"");

    skip(in, txt, "\"Kills\"");
    kills() = stoi(rm_quotes(txt));
    skip(in, txt, "\"Damage\"");
    damage() = stoi(rm_quotes(txt));
    skip(in, txt, "\"Deaths\"");
    deaths() = stoi(rm_quotes(txt));
    skip(in, txt, "\"Assists\"");
    assists() = stoi(rm_quotes(txt));
    skip(in, txt, "\"HeadshotKills\"");
    headshots() = stoi(rm_quotes(txt));

    skip(in, txt, "\"UtilityDamage\"");
    utility_damage() = stoi(rm_quotes(txt));
    skip(in, txt, "\"UtilityCount\"");
    utility_count() = stoi(rm_quotes(txt));
    skip(in, txt, "\"UtilitySuccesses\"");
    utility_success() = stoi(rm_quotes(txt));

    skip(in, txt, "\"FlashCount\"");
    flash_count() = stoi(rm_quotes(txt));
    skip(in, txt, "\"FlashSuccesses\"");
    flash_success() = stoi(rm_quotes(txt));
    skip(in, txt, "\"EnemiesFlashed\"");
    flashed_enemies() = stoi(rm_quotes(txt));

    skip(in, txt, "\"1v1Count\"");
    v1_count() = stoi(rm_quotes(txt));
    skip(in, txt, "\"1v1Wins\"");
    v1_wins() = stoi(rm_quotes(txt));
    skip(in, txt, "\"1v2Count\"");
    v2_count() = stoi(rm_quotes(txt));
    skip(in, txt, "\"1v2Wins\"");
    v2_wins() = stoi(rm_quotes(txt));

    skip(in, txt, "\"EntryCount\"");
    entry_count() = stoi(rm_quotes(txt));
    skip(in, txt, "\"EntryWins\"");
    entry_wins() = stoi(rm_quotes(txt));
}

void match::extractor(ifstream& in, const int i){
    string txt;
    
    skip(in, txt, "\"map\"");
    maps[i].name() = rm_quotes(txt);
    cerr << "Loading map..." << maps[i].name();
    skip(in, txt, "\"round\"");
    maps[i].rounds_total() = stoi(rm_quotes(txt));
    total_rounds() += maps[i].rounds_total();
    // HALFSCORE SEGMENT
    skip(in, txt, "\"team1\"");
    maps[i].halfscore_team(1) = stoi(rm_quotes(txt));
    skip(in, txt, "\"team2\"");
    maps[i].halfscore_team(2) = stoi(rm_quotes(txt));
    // TOTALSCORE SEGMENT
    skip(in, txt, "\"team1\"");
    maps[i].totalscore_team(1) = stoi(rm_quotes(txt)) + maps[i].halfscore_team(1);
    skip(in, txt, "\"team2\"");
    maps[i].totalscore_team(2) = stoi(rm_quotes(txt)) + maps[i].halfscore_team(2);
    // OVERTIME SEGMENT
    skip(in, txt, 2);
    if (txt == "\"OvertimeScore\"") {
        skip(in, txt, "\"team1\"");
        maps[i].overtime_team(1) = stoi(rm_quotes(txt));
        skip(in, txt, "\"team2\"");
        maps[i].overtime_team(2) = stoi(rm_quotes(txt));
        
        maps[i].totalscore_team(1) += maps[i].overtime_team(1);
        maps[i].totalscore_team(2) += maps[i].overtime_team(2);
        maps[i].overtime() = true;
    }
    cerr << ": " << maps[i].totalscore_team(1) << " - " << maps[i].totalscore_team(2) << endl;
    
    maps[i].players_number() = players_number();
    // TEAM A SEGMENT
    skip(in, txt, "\"PlayersOnTeam1\"");
    maps[i].teamA_ = new player[players_number() / 2];
    cerr << "Loading team A...[ ";
    for (int j = 0; j < players_number() / 2; j++) {
        maps[i].teamA_[j].extract(in);
        maps[i].teamA_[j].rounds() = maps[i].rounds_total();
        maps[i].teamA_[j].match_type() = players_number() / 2;
        cerr << maps[i].teamA_[j].nickname() << " ";
    }
    cerr << "]\n";
    // TEAM B SEGMENT
    skip(in, txt, "\"PlayersOnTeam2\"");
    maps[i].teamB_ = new player[players_number() / 2];
    cerr << "Loading team B...[ ";
    for (int j = 0; j < players_number() / 2; j++) {
        maps[i].teamB_[j].extract(in);
        maps[i].teamB_[j].rounds() = maps[i].rounds_total();
        maps[i].teamB_[j].match_type() = players_number() / 2;
        cerr << maps[i].teamB_[j].nickname() << " ";
    }
    cerr << "]\n";
    in.close();
}

#endif