# CSMatchExtractor
CSMatchExtractor is a helpful tool that will help you export crucial informations from your Counter-Strike 2 match backup files.

## How does it work?
First you need to provide your backup round files. These are the files that are created after every round of your match (usually located in ./Counter-Strike Global Offensive/game/csgo) but the one we are the most interested is always the last file after every single round - this file gives us full statistics of our match.

Then the Extractor is doing it's thing. You get a short sum in your terminal/CMD window and additionally it is creating match_raport.txt file with all statistics.

## Usage
1) Place all backup.txt files in the same folder as the Extractor.

2) Run the Extractor:
    * by clicking **.exe**
        1. The Extractor will ask you how many files do you want to provide
        2. Then just type all of the files with extensions (ex. backup.txt)
        
        The Extractor just crashes if you link the wrong file.
    * through Terminal/Powershell
        1. You can run the Extractor directly with the files in command-line for example: ./MatchExtractor.exe backup.txt backup1.txt

## Output

In your terminal/CMD you should see:
<pre>
Welcome in Match Extractor v1.0
Number of maps... (number of maps)
Number of players in team A... (number of players), in team B... (number of players)
Number of players... (number of players)
File: example.txt
Loading map... de_example: 0 - 0
Loading team A...[ Player1 Player2 ... ]
Loading team B...[ Player1 Player2 ... ]
</pre>
This is sign that the all of the informations from backup files were exported to the Extractor. After that match details should be seen as below:
<pre>
MATCH DETAILS================================================================================
Played maps:
de_example - 0:0 (0:0)

de_example - 0:0
Player         K     A     D     K/D     ADR     HS%     KPR
=================================================================
Player1
Player2
...
-----------------------------------------------------------------
Player1
Player2
...

(if there are more maps it will be shown here)

(if there are more maps and the teams are the same in every one of them the Totals (summed statistics) will be shown below)
</pre>


The standard output is showing most basic statistics like: Kills, Assists, Deaths, K/D, ADR, Headshot%, KPR (also if this was a wingman matchup - Double Kills, 1v1 Ratio, 1v2 Ratio).

The match_raport.txt file also contains additional numbers like: Damage, Double/Triple/Quadra/Ace Kills, Utility - Count/Success/Damage, Flash - Count/Success/-ed Enemies, Entry Ratio, 1v1 Ratio, 1v2 Ratio.


## Known Issues
If you will try to combine files from the matches that differ in number of players (for example backup.txt - 2v2, backup.txt - 5v5) it will likely

1. If the first file was matchup with lower number of players - matches with higher number of players will be cut in the scoreboard according to the number of lower one.
2. If the first file was matchup with higher number of players and then the rest with lower - infinite freeze of the Extractor.
