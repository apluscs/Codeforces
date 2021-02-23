#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Wins(const vector<vector<int> >& votes, int r, int c, int total_votes) {  // if r beats c
  if (votes[r][c] > total_votes / 2)
    return true;
  else
    return false;
}

void Make_Agenda(vector<int>& agenda, const vector<vector<int> >& votes, int winner, int total_votes) {
  agenda.resize(0);
  vector<bool> used(votes.size(), false);
  vector<int> frontier;
  frontier.push_back(winner);
  used[winner] = true;
  agenda.push_back(winner);
  int frontier_pos = 0;
  while (frontier_pos < frontier.size()) {  // ensures that progress is made each step
    int cur = frontier[frontier_pos];
    for (int i = 0; i < votes.size(); i++) {
      if (!used[i] && Wins(votes, cur, i, total_votes)) {  //  need to find an unused i that cur can beat
        frontier.push_back(i);
        used[i] = true;
        agenda.push_back(i);
      }
    }
    frontier_pos++;
  }
  for (auto f : frontier) cout << f << " ";
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > votes(n);
  for (int i = 0; i < n; i++)
    votes[i].resize(n, 0);

  int total_votes = 0;
  for (int i = 0; i < m; i++) {
    string ballot;
    int frequency;
    cin >> frequency >> ballot;
    total_votes += frequency;
    for (int j = 0; j < ballot.size(); j++)
      for (int k = j + 1; k < ballot.size(); k++) {
        char winner = ballot[j];
        char loser = ballot[k];
        votes[winner - 'A'][loser - 'A'] += frequency;
      }
  }

  for (int i = 0; i < n; i++) {
    vector<int> agenda;
    Make_Agenda(agenda, votes, i, total_votes);
    cout << (char)(i + 'A') << ": ";
    if (agenda.size() == n) {
      /*for(int j = agenda.size()-1; j >=0; j--)
	cout << (char) (agenda[j] + 'A') << " ";*/
      cout << "can win" << endl;
    } else {
      cout << "can't win" << endl;
    }
  }
  return 0;
}
