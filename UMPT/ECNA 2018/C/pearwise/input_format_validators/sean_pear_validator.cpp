#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

  int cur_file = 1;
//  while(cur_file < argc){
//    string filename;
//    filename = argv[cur_file];
//    ifstream fin;
//    fin.open(filename.data());
//    cout << "File " << filename << endl;
    int n, m;
    cin >> n >> m;
    if(n < 0 || n > 26) {
      cout << "BAD N!!!" << endl;
      return 1;
    }
    if(m < 0 || m > 2000) {
      cout << "BAD M!!!" << endl;
      return 1;
    }

    int total_votes = 0;
    for(int i = 0; i < m; i++){
      int p;
      string ballot;
      cin >> p;
      if(p < 0 || p > 100) {
	cout << "Line " << i << ": BAD P!!" << endl;
  return 1;
}
      total_votes = total_votes + p;
      cin >> ballot;
      if(ballot.size() != n) {
	cout << "Line " << i << ": Ballot wrong length!!" << endl;
  return 1;
}
      vector<bool> seen(n, false);
      for(int j = 0; j < n; j++){
	char vote = ballot[j];
	if(vote < 'A' || vote > ('A' + n)){
	  cout << "Line " << i << ": " << vote << " is an illegal letter!!" << endl;
    return 1;
	}
	seen[vote-'A'] = true;
      }
      for(int j = 0; j < n; j++)
	if(!seen[j]) {
	  cout << "Line " << i << " no vote for " << j+'A' << "!!!" << endl;
    return 1;
  }
    }
    if(total_votes%2 == 0) {
      cout << "Even ttoal number of votes!" << endl;
      return 1;
    }
    cur_file++;
//  }
    return 42;
}
