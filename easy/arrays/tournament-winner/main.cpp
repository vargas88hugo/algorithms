#include <vector>
#include <unordered_map>
using namespace std;

string tournamentWinner(
  vector<vector<string>> competitions, vector<int> results
) {
  unordered_map<string, int> teamScores;
  string winner = "";

  for (int i = 0; i < competitions.size(); i++) {
    string currentWinner = competitions[i][!results[i]];

    teamScores[currentWinner] += 3;

    winner = teamScores[currentWinner] > teamScores[winner] ? currentWinner : winner;
  }
  
  return winner;
}
