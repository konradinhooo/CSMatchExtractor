#ifndef classes_h
#define classes_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "functions.h"
using namespace std;

/*  Class player - player's statistics
    Variables:
k_      - kills           a_      - assists         d_      - deaths
hs_     - headshots       dmg_    - damage          dk_     - doublekills
tk_     - triplekills     qk_     - quadrakills     pk_     - aces
udmg_   - utility dmg     ucnt_   - utility count   usccs_  - utility success
fcnt_   - flash count     fenem_  - flashed enemy   fsccs_  - flash success
ecnt_   - entry count     ewin_   - entry win       v1cnt_  - 1v1 count
v1win_  - 1v1 win         v2cnt_  - 1v2 count       v2win_  - 1v2 win
ro_     - rundy meczowe   mt_     - match type
                            >>1-1v1,2-2v2,...

    Constructors, methods, destructors:
    player()                            - default constructor
    player(string n, int k, int a, ...) - parametric constructor

    extract(ifstream& in)               - load the player data

    nickname()         - returns nickname
    kills()            - returns kills
    assists()          - returns assists
    deaths()           - returns deaths
    headshots()        - returns headshots
    damage()           - returns damage
    doublekills()      - returns double kills
    triplekills()      - returns triple kills
    quadrakills()      - returns quadra kills
    aces()             - returns aces
    utility_damage()   - returns utility damage
    utility_count()    - returns utility count
    utility_success()  - returns utility success
    flash_count()      - returns flash count
    flashed_enemies()  - returns flashed enemies
    flash_success()    - returns flash success
    entry_count()      - returns entry count
    entry_wins()       - returns entry wins
    v1_count()         - returns 1vs1 count
    v1_wins()          - returns 1vs1 wins
    v2_count()         - returns 1vs2 count
    v2_wins()          - returns 1vs2 wins
    rounds()           - returns played rounds

    adr()              - returns ADR (Average Damage per Round)
    kd()               - returns K/D (Kill/Death ratio)
    hsp()              - returns HSP (Headshot Percentage)
    kpr()              - returns KPR (Kills per Round)
*/

class player {
        string n_;
        int k_, a_, d_, hs_, dmg_;
        int dk_, tk_, qk_, pk_;
        int udmg_, ucnt_, usccs_;
        int fcnt_, fenem_, fsccs_;
        int ecnt_, ewin_;
        int v1cnt_, v1win_, v2cnt_, v2win_;
        int ro_;
        int mt_;
    public:
// CONSTRUCTORS
        player():n_("?"), k_(0), a_(0), d_(0), hs_(0), dmg_(0), dk_(0), tk_(0), qk_(0), pk_(0),
    udmg_(0), ucnt_(0), usccs_(0), fcnt_(0), fenem_(0), fsccs_(0), ecnt_(0), ewin_(0), v1cnt_(0),
    v1win_(0), v2cnt_(0), v2win_(0), ro_(0), mt_(0){}

        player(string n, int k, int a, int d, int hs, int dmg, int dk, int tk, int qk, int pk, int udmg,
    int ucnt, int usccs, int fcnt, int fenem, int fsccs, int ecnt, int ewin, int v1cnt, int v1win, int v2cnt, int v2win, int ro, int mt):
    n_(n), k_(k), a_(a), d_(d), hs_(hs), dmg_(dmg), dk_(dk), tk_(tk), qk_(qk), pk_(pk),
    udmg_(udmg), ucnt_(ucnt), usccs_(usccs), fcnt_(fcnt), fenem_(fenem), fsccs_(fsccs), ecnt_(ecnt), ewin_(ewin),
    v1cnt_(v1cnt), v1win_(v1win), v2cnt_(v2cnt), v2win_(v2win), ro_(ro), mt_(mt) {}

// EXTRACTOR
        void extract(ifstream& in);

// METHODS
    const string& nickname() const { return n_; }
    string& nickname() { return n_; }

    const int& kills() const { return k_; }
    int& kills() { return k_; }

    const int& assists() const { return a_; }
    int& assists() { return a_; }

    const int& deaths() const { return d_; }
    int& deaths() { return d_; }

    const int& headshots() const { return hs_; }
    int& headshots() { return hs_; }

    const int& damage() const { return dmg_; }
    int& damage() { return dmg_; }

    const int& doublekills() const { return dk_; }
    int& doublekills() { return dk_; }

    const int& triplekills() const { return tk_; }
    int& triplekills() { return tk_; }

    const int& quadrakills() const { return qk_; }
    int& quadrakills() { return qk_; }

    const int& aces() const { return pk_; }
    int& aces() { return pk_; }

    const int& utility_damage() const { return udmg_; }
    int& utility_damage() { return udmg_; }

    const int& utility_count() const { return ucnt_; }
    int& utility_count() { return ucnt_; }

    const int& utility_success() const { return usccs_; }
    int& utility_success() { return usccs_; }

    const int& flash_count() const { return fcnt_; }
    int& flash_count() { return fcnt_; }

    const int& flashed_enemies() const { return fenem_; }
    int& flashed_enemies() { return fenem_; }

    const int& flash_success() const { return fsccs_; }
    int& flash_success() { return fsccs_; }

    const int& entry_count() const { return ecnt_; }
    int& entry_count() { return ecnt_; }

    const int& entry_wins() const { return ewin_; }
    int& entry_wins() { return ewin_; }

    const int& v1_count() const { return v1cnt_; }
    int& v1_count() { return v1cnt_; }

    const int& v1_wins() const { return v1win_; }
    int& v1_wins() { return v1win_; }

    const int& v2_count() const { return v2cnt_; }
    int& v2_count() { return v2cnt_; }

    const int& v2_wins() const { return v2win_; }
    int& v2_wins() { return v2win_; }

    const int& rounds() const { return ro_; }
    int& rounds() { return ro_; }

    const int& match_type() const { return mt_; }
    int& match_type() { return mt_; }

// FUNCTIONS
    float adr() const { return round_to(((float) dmg_ / ro_)); }
    float kd() const { return round_to((float)k_ / d_, 2); }
    float hsp() const { return round_to((float)hs_ / k_, 2) * 100; }
    float kpr() const { return round_to((float)k_ / ro_, 2); }

// OPERATORS
    friend ostream& operator<<(ostream& o, const player& p);

    player& operator+(const player& p) {
        nickname() = p.nickname();
        match_type() = p.match_type();
        kills() += p.kills();
        assists() += p.assists();
        deaths() += p.deaths();
        headshots() += p.headshots();
        damage() += p.damage();
        doublekills() += p.doublekills();
        triplekills() += p.triplekills();
        quadrakills() += p.quadrakills();
        aces() += p.aces();
        utility_damage() += p.utility_damage();
        utility_count() += p.utility_count();
        utility_success() += p.utility_success();
        flash_count() += p.flash_count();
        flashed_enemies() += p.flashed_enemies();
        flash_success() += p.flash_success();
        entry_count() += p.entry_count();
        entry_wins() += p.entry_wins();
        v1_count() += p.v1_count();
        v1_wins() += p.v1_wins();
        v2_count() += p.v2_count();
        v2_wins() += p.v2_wins();
        rounds() += p.rounds();
        return *this;
    }
};

/*  Class map - map's data
    Variables:
n_                      - map's name,
ro_t_                   - number of total rounds,
ro_hscA_, ro_hscB       - number of won rounds by team A/B after halfscore,
ro_otA_, ro_otB         - number of won rounds by team A/B in overtime,
ro_tA_, ro_tB           - number of won rounds by team A/B in a match,
pnum_                   - number of players
ot_                     - if there was an overtime
teamA_, teamB_          - player arrays of team A/B

    Constructors, methods, destructors:
    map()                           - default constructor
    map(string n, int ro_t, ...)    - parametric constructor

    name()                          - returns map's name
    rounds_total()                  - returns number of total rounds
    players_number()                - returns number of players
    overtime()                      - returns if there was an overtime
    halfscore_team(int team)        - returns halfscore of team A/B
    overtime_team(int team)         - returns overtime score of team A/B
    totalscore_team(int team)       - returns total score of team A/B
    > team = 1 - team A; team = 2 - team B
    sort_players(const string by_)  - sorting players by statistics 'by_'
    > by_: "adr", "kills", "name", ..TBD

    ~map()                          - destructor
*/

class map {
        string n_;
        int ro_t_;
        int ro_hscA_, ro_hscB_;
        int ro_otA_, ro_otB_;
        int ro_tA_, ro_tB_;
        int pnum_;
        bool ot_;
    public:
        player* teamA_, * teamB_;

// CONSTRUCTORS
        map():n_("?"), ro_t_(0), ro_hscA_(0), ro_hscB_(0), ro_otA_(0), ro_otB_(0), ro_tA_(0), ro_tB_(0), pnum_(0), ot_(false),
    teamA_(nullptr), teamB_(nullptr) {}

        map(string n, int ro_t, int ro_hscA, int ro_hscB, int ro_otA, int ro_otB, int ro_tA, int ro_tB, int pnum, bool ot,
    player* teamA, player* teamB): n_(n), ro_t_(ro_t), ro_hscA_(ro_hscA), ro_hscB_(ro_hscB), ro_otA_(ro_otA),
    ro_otB_(ro_otB), ro_tA_(ro_tA), ro_tB_(ro_tB), pnum_(pnum), ot_(ot), teamA_(teamA), teamB_(teamB) {}

// METHODS
        const string& name() const { return n_; }
        string& name() { return n_; }

        const int& rounds_total() const { return ro_t_; }
        int& rounds_total() { return ro_t_; }

        const int& players_number() const { return pnum_; }
        int& players_number() { return pnum_; }

        const bool& overtime() const { return ot_; }
        bool& overtime() { return ot_; }

        int& halfscore_team(int team) {
            if (team == 1) return ro_hscA_;
            else if (team == 2) return ro_hscB_;
            else throw -1;
        }
        const int& halfscore_team(int team) const {
            if (team == 1) return ro_hscA_;
            else if (team == 2) return ro_hscB_;
            else throw -1;
        }

        int& overtime_team(int team) {
            if (team == 1) return ro_otA_;
            else if (team == 2) return ro_otB_;
            else throw -1;
        }
        const int& overtime_team(int team) const {
            if (team == 1) return ro_otA_;
            else if (team == 2) return ro_otB_;
            else throw -1;
        }

        int& totalscore_team(int team) {
            if (team == 1) return ro_tA_;
            else if (team == 2) return ro_tB_;
            else throw -1;
        }
        const int& totalscore_team(int team) const {
            if (team == 1) return ro_tA_;
            else if (team == 2) return ro_tB_;
            else throw -1;
        }

// FUNCTIONS
        void sort_players(const string by_) {
            int size = pnum_ / 2;
            sort(teamA_, teamA_ + size, [by_](const player& a, const player& b) {
                if (by_ == "kills") return a.kills() > b.kills();
                else if (by_ == "adr") return a.adr() > b.adr();
                else if (by_ == "name") return a.nickname() > b.nickname();
                else throw -1;
            });
            sort(teamB_, teamB_ + size, [by_](const player& a, const player& b) {
                if (by_ == "kills") return a.kills() > b.kills();
                else if (by_ == "adr") return a.adr() > b.adr();
                else if (by_ == "name") return a.nickname() > b.nickname();
                else throw -1;
            });
        }

// OPERATORS
        friend ostream& operator<<(ostream& o, const map& m);

// DESTRUCTORS
        ~map() {
            delete[] teamA_;
            delete[] teamB_;
        }
};

/*  Class match - match data
    Variables:
mnum_           - number of maps,
rot_            - number of total rounds in the match,
pnum_           - number of players,
maps            - map array,
teamA/teamB     - player arrays of team A/B (for totals)

    Constructors, methods, destructors:
    match()                         - default constructor
    match(int mnum, int rot, ...)   - parametric constructor
    match(const match& m)           - copy constructor

    maps_number()       - returns number of maps
    total_rounds()      - returns number of total rounds
    players_number()    - returns number of players

    get_info(ifstream& in, int argc)    - extracting data about the match from given file
    extractor(ifstream& in, int argc)   - extracting data

    bool make_totals();                 - does totals, returns true if it is possible
    void show_totals(ostream& o);       - shows totals of the match

    ~match()            - destructor
*/

class match {
        int mnum_;
        int rot_;
        int pnum_;
    public:
        map* maps;
        player* teamA, * teamB;

// CONSTRUCTORS
        match(): mnum_(0), rot_(0), pnum_(0), maps(nullptr), teamA(nullptr), teamB(nullptr) {}

        match(int mnum, int rot, int pnum, map* maps, player* teamA, player* teamB): mnum_(mnum), rot_(rot), pnum_(pnum),
    maps(maps), teamA(teamA), teamB(teamB) {}

        match(const match& m){
            mnum_ = m.mnum_;
            rot_ = m.rot_;
            pnum_ = m.pnum_;
            maps = new map[mnum_];
            for (int i = 0; i < mnum_; ++i) {
                maps[i] = m.maps[i];
                maps[i].teamA_ = new player[pnum_ / 2];
                maps[i].teamB_ = new player[pnum_ / 2];
                for (int j = 0; j < pnum_ / 2; j++){
                    maps[i].teamA_[j] = m.maps[i].teamA_[j];
                    maps[i].teamB_[j] = m.maps[i].teamB_[j];
                }
            }
            
            teamA = new player[pnum_ / 2];
            teamB = new player[pnum_ / 2];
        }

// METHODS
        const int& maps_number() const { return mnum_; }
        int& maps_number() { return mnum_; }

        const int& total_rounds() const { return rot_; }
        int& total_rounds() { return rot_; }

        const int& players_number() const { return pnum_; }
        int& players_number() { return pnum_; }

// EXTRACTOR
        void get_info(ifstream& in, int argc);
        void extractor(ifstream& in, int argc);

// FUNCTIONS
        bool make_totals();
        void show_totals(ostream& o);

// OPERATORS
        friend ostream& operator<<(ostream& o, const match& m);

        map& operator[](int index){
            if (index < 0 || index >= maps_number()) throw -1;
            return maps[index];
        }

        const map& operator[] (int index) const {
            if (index < 0 || index >= maps_number()) throw -1;
            return maps[index];
        }

// DESTRUCTORS
        ~match() {
            delete[] maps;
            delete[] teamA;
            delete[] teamB;
        }
};

// Template for showing the statistics
void show_stats_template(ostream& o, int mt){
    o << left
    << setw(15) << "Player"
    << setw(6) << "K"
    << setw(6) << "A"
    << setw(6) << "D"
    << setw(8) << "K/D";

    if(&o != &cout) 
        o << setw(8) << "DMG";

    o << setw(8) << "ADR"
    << setw(8) << "HS%"
    << setw(8) << "KPR";

    if(mt == 2 || &o != &cout) // Only 2v2
        o << setw(6) << "DK";

    if(&o != &cout){
        o << setw(6) << "TK"
        << setw(6) << "QK"
        << setw(6) << "ACE"
        << setw(10) << "UTIL CNT"
        << setw(10) << "UTIL SUC"
        << setw(10) << "UTIL DMG"
        << setw(10) << "FL CNT"
        << setw(10) << "FL SUC"
        << setw(10) << "FL ENEM"
        << setw(8) << "ENTRY";
    }

    if(mt == 2 || &o != &cout){ // Only 2v2
        o << setw(8) << "1v1"
        << setw(8) << "1v2";
    }
        o << endl;
}

// Player show operator
ostream& operator<<(ostream& o, const player& p){
    o << left
    << setw(15) << p.nickname().substr(0, 13) // Always
    << setw(6) << p.kills()
    << setw(6) << p.assists()
    << setw(6) << p.deaths()
    << setw(8) << p.kd();
    if(&o != &cout) 
        o << setw(8) << p.damage();

    o << setw(8) << p.adr()
    << setw(8) << p.hsp() 
    << setw(8) << p.kpr(); 

    if(p.match_type() == 2 || &o != &cout){ // Only 2v2
        o << setw(6) << p.doublekills();
    }

    if(&o != &cout){
        o << setw(6) << p.triplekills() 
        << setw(6) << p.quadrakills() 
        << setw(6) << p.aces() 
        << setw(10) << p.utility_count() 
        << setw(10) << p.utility_success() 
        << setw(10) << p.utility_damage() 
        << setw(10) << p.flash_count() 
        << setw(10) << p.flash_success() 
        << setw(10) << p.flashed_enemies() 
        << setw(8) << to_string(p.entry_wins()) + "/" + to_string(p.entry_count());
    }

    if(p.match_type() == 2 || &o != &cout) { // Only 2v2
        o << setw(8) << to_string(p.v1_wins()) + "/" + to_string(p.v1_count()) 
        << setw(8) << to_string(p.v2_wins()) + "/" + to_string(p.v2_count());
    }

    return o;
}

// Map show operator
ostream& operator<<(ostream& o, const map& m){
    o << m.name() << " - " << m.totalscore_team(1) << ":" << m.totalscore_team(2) << endl;
    
    int width;
    if (&o == &cout && m.players_number() / 2 == 2) width = 85;
    else if(&o == &cout) width = 65;
    else width = 180;
    
    show_stats_template(o, m.players_number() / 2);
    write_line(o, width, '=');
    for(int i = 0; i < m.players_number() / 2; i++){
        o << m.teamA_[i] << endl;
    }
    write_line(o, width);
    for(int i = 0; i < m.players_number() / 2; i++){
        o << m.teamB_[i] << endl;
    }
    return o;
};

// Match show operator
ostream& operator<<(ostream& o, const match& m){
    o << (&o == &cout ? "\n" : "") << "MATCH DETAILS";
    write_line(o, 80, '=');
    o << "Played maps:\n";
    for(int i = 0; i < m.maps_number(); i++){
        o << m.maps[i].name() << " - "
<< m.maps[i].totalscore_team(1) << ":" << m.maps[i].totalscore_team(2) 
<< " (" << m.maps[i].halfscore_team(1) << ":" << m.maps[i].halfscore_team(2) 
<< (m.maps[i].overtime() ? (", " + to_string(m.maps[i].overtime_team(1)) + ":" + to_string(m.maps[i].overtime_team(2))) : "") << ")\n";
    }
    o << endl;
    for (int i = 0; i < m.maps_number(); i++){
        o << m[i] << endl;
    }
    return o;
}

// CLASS MATCH FUNCTIONS
bool match::make_totals(){
    // Creating temporary object
    match temp(*this);
    // Sorting the players by the nickname
    for (int i = 0; i < maps_number(); i++) temp[i].sort_players("name");
    
    // Variables for validation
    bool TeamsValidated = true;
    int Team1ValPlayers = 0, Team1ValPlayersB = 0;
    int Team2ValPlayers = 0, Team2ValPlayersA = 0;
    int TeamDistribution[maps_number()][2];
    int PlayersInTeam = players_number() / 2;

    // Checking if the players are the same on different maps
    for (int j = 0; j < maps_number(); j++){
        for (int i = 0; i < PlayersInTeam; i++) {
            if(temp[0].teamA_[i].nickname() == temp[j].teamA_[i].nickname()) Team1ValPlayers++;
            if(temp[0].teamA_[i].nickname() == temp[j].teamB_[i].nickname()) Team1ValPlayersB++;
            if(temp[0].teamB_[i].nickname() == temp[j].teamB_[i].nickname()) Team2ValPlayers++;
            if(temp[0].teamB_[i].nickname() == temp[j].teamA_[i].nickname()) Team2ValPlayersA++;
        }
        if (Team1ValPlayers == PlayersInTeam && Team2ValPlayers == PlayersInTeam) {
            TeamDistribution[j][0] = 0;
            TeamDistribution[j][1] = 1;
        } else if (Team1ValPlayersB == PlayersInTeam && Team2ValPlayersA == PlayersInTeam) {
            TeamDistribution[j][0] = 1;
            TeamDistribution[j][1] = 0;
        } else TeamsValidated = false;
        Team1ValPlayers = 0; Team1ValPlayersB = 0; Team2ValPlayers = 0; Team2ValPlayersA = 0;
    }

    // If so -> make totals
    if (TeamsValidated) {
        for (int i = 0, j = 0; i < maps_number(); i++) {
            if (TeamDistribution[i][j] == 0) {
                for(int k = 0; k < PlayersInTeam; k++){
                    teamA[k] = teamA[k] + temp[i].teamA_[k];
                    teamB[k] = teamB[k] + temp[i].teamB_[k];
                }
            }
            else {
                for(int k = 0; k < PlayersInTeam; k++){
                    teamA[k] = teamA[k] + temp[i].teamB_[k];
                    teamB[k] = teamB[k] + temp[i].teamA_[k];
                }
            }
        }
    } else {
        cout << "Could not create totals. Different players in each map.\n";
        return false;
    }    
    return true;
}

void match::show_totals(ostream& o){
    o << (&o == &cout ? "\n" : "") << "Totals: " << total_rounds() << " rounds" << endl;

    int width;
    if (&o == &cout && players_number() / 2 == 2) width = 85;
    else if(&o == &cout) width = 65;
    else width = 180;

    show_stats_template(o, players_number() / 2);
    write_line(o, width, '=');
    for(int i = 0; i < players_number() / 2; i++){
        o << teamA[i] << endl;
    }
    write_line(o, width);
    for(int i = 0; i < players_number() / 2; i++){
        o << teamB[i] << endl;
    }
}

#endif