#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int grid[254][254],dist[254][254],m,n;

int main(void) {
  int
    r,c;
  queue<int>
    q;
  stack<int>
    s;

  cin >> m >> n;

  for (r=0;r<254;r++)
    for (c=0;c<254;c++) {
      grid[r][c] = -2;
      dist[r][c] = -1;
    }

  for (r=0;r<m;r++)
    for (c=0;c<n;c++) {
      cin >> grid[r+2][c+2];
      if (grid[r+2][c+2] == -1) {
        q.push(r+2);
        q.push(c+2);
        dist[r+2][c+2] = 0;
      }
    }

  while (!q.empty()) {
    r = q.front();
    q.pop();
    c = q.front();
    q.pop();
//cout << "processing " << (r-2) << ' ' << (c-2) << endl;
    if (grid[r+2][c] >= 0 && grid[r+2][c] == grid[r+1][c] && dist[r+2][c] == -1) {
      q.push(r+2);
      q.push(c);
      dist[r+2][c] = dist[r][c] + 1;
    }

    if (grid[r-2][c] >= 0 && grid[r-2][c] == grid[r-1][c] && dist[r-2][c] == -1) {
      q.push(r-2);
      q.push(c);
      dist[r-2][c] = dist[r][c] + 1;
    }

    if (grid[r][c+2] >= 0 && grid[r][c+2] == grid[r][c+1] && dist[r][c+2] == -1) {
      q.push(r);
      q.push(c+2);
      dist[r][c+2] = dist[r][c] + 1;
    }

    if (grid[r][c-2] >= 0 && grid[r][c-2] == grid[r][c-1] && dist[r][c-2] == -1) {
      q.push(r);
      q.push(c-2);
      dist[r][c-2] = dist[r][c] + 1;
    }
  }

  cin >> r >> c;

  r++;
  c++;

  if (dist[r][c] == -1) {
    cout << "impossible" << endl;
    return 0;
  }

  while (dist[r][c] > 0) {
    s.push(grid[r][c]);
    if (dist[r+2][c] == dist[r][c] - 1 && grid[r][c] == grid[r+1][c])
      r += 2;
    else if (dist[r-2][c] == dist[r][c] - 1 && grid[r][c] == grid[r-1][c])
      r -= 2;
    else if (dist[r][c+2] == dist[r][c] - 1 && grid[r][c] == grid[r][c+1])
      c += 2;
    else
      c -= 2;
  }
//  s.push(grid[r][c]);
  cout << s.top();
  s.pop();
  while (!s.empty()) {
    cout << ' ' << s.top();
    s.pop();
  }
  cout << endl;

  return 0;
}
