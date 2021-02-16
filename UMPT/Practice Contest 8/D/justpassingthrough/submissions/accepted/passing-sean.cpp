#include <iostream>
#include <vector>

using namespace std;

const int ILLEGAL_VALUE = 100000000;

bool Is_Pass(const vector<vector<int> >& elevations, int r, int c){
  // can't be a pass on an edge
  if(r == 0 || c == 0 || r == elevations.size()-1 || c == elevations[r].size()-1)
    return false;
  // can't be a pass if not drivable
  if(elevations[r][c] == -1 || elevations[r-1][c] == -1 ||
     elevations[r+1][c] == -1 || elevations[r][c-1] == -1 ||
     elevations[r][c+1] == -1)
    return false;
  if(elevations[r-1][c] > elevations[r][c] &&
     elevations[r+1][c] > elevations[r][c] &&
     elevations[r][c-1] < elevations[r][c] &&
     elevations[r][c+1] < elevations[r][c])
    return true;
  else
    return false;
  
		       
}
int Solve(vector<vector<int> >& elevations, vector<vector<vector<int> > > & memo, int r, int c, int p){
  if(p < 0)
    return ILLEGAL_VALUE;
  
  if(c == elevations[0].size()-1){
    if(p == 0)
      return 0;
    else
      return ILLEGAL_VALUE;
  }
  if(memo[r][c][p] != -2)
    return memo[r][c][p];
  // NE
  int best_score = ILLEGAL_VALUE;
  int cur;
  if(r > 0 && elevations[r-1][c+1] != -1){
    if(Is_Pass(elevations, r-1, c+1))
      cur = Solve(elevations, memo, r-1, c+1, p-1) + elevations[r-1][c+1];
    else
      cur = Solve(elevations, memo, r-1, c+1, p) + elevations[r-1][c+1];
    if(cur < best_score)
      best_score = cur;
  }
  // E
  if(elevations[r][c+1] != -1){
    if(Is_Pass(elevations, r,c+1))
      cur = Solve(elevations, memo, r, c+1, p-1) + elevations[r][c+1];
    else
      cur = Solve(elevations, memo, r, c+1, p) + elevations[r][c+1];
    if(cur < best_score)
      best_score = cur;
  }
  // SE
  if(r < elevations.size()-1 && elevations[r+1][c+1] != -1){
    if(Is_Pass(elevations, r+1, c+1))
      cur = Solve(elevations, memo, r+1, c+1, p-1) + elevations[r+1][c+1];
    else
      cur = Solve(elevations, memo, r+1, c+1, p) + elevations[r+1][c+1];
    if(cur < best_score)
      best_score = cur;
  }
  if(best_score > ILLEGAL_VALUE)
    best_score = ILLEGAL_VALUE;
  memo[r][c][p] = best_score;
  return best_score;
}
     
int main(){
  int r,c,n;
  cin >> r >> c >> n;
  vector<vector<int > > elevations(r);
  for(int i = 0; i < r; i++){
    elevations[i].resize(c);
    for(int j = 0; j < c; j++)
      cin >> elevations[i][j];
  }

  int best_path = ILLEGAL_VALUE;
  vector<vector<vector<int> > > memo(r);
  for(int i = 0; i < r; i++){
    memo[i].resize(c);
    for(int j = 0; j < c; j++){
      memo[i][j].resize(n+1);
      for(int k = 0; k < n+1; k++)
	memo[i][j][k] = -2; // because we have a -1 already and I'm scared
    }
  }
  for(int start_row = 0; start_row < r; start_row++){
    if(elevations[start_row][0] != -1){
      int cur = elevations[start_row][0] + Solve(elevations, memo, start_row, 0, n);
      // cout << cur << endl;
      if(cur < best_path)
	best_path = cur;
    }
  }
  if(best_path < ILLEGAL_VALUE)
    cout << best_path << endl;
  else
    cout << "impossible" << endl;
  return 0;
}
  
  
