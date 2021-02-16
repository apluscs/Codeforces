#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PLI;
const int MAXN = 10005;
vector<pair<int, int>> a[MAXN];
int p[MAXN];
long long dist[MAXN];

int main() {
  int N, M, E;
  scanf("%d%d%d", &N, &M, &E);
  for (int i = 1; i <= N - 1; i++) scanf("%d", &p[i]);
  p[N] = 0;
  for (int i = 0; i < M; i++) {
    int x, y, d;
    scanf("%d%d%d", &x, &y, &d);
    a[x].push_back({y, d});
    a[y].push_back({x, d});
  }
  priority_queue<PLI> Q;
  Q.push(PLI(0, N));
  dist[N] = 0;
  const long long INF = 1LL << 60;
  for (int i = 1; i < N; i++) dist[i] = INF;
  while (!Q.empty()) {
    PLI z = Q.top();
    Q.pop();
    long long d = -z.first;
    int x = z.second;
    if (dist[x] < d) continue;
    for (auto& v : a[x]) {
      int y = v.first;
      int r = v.second; // [x]---r----[y]
      long long newcost = dist[x] + r + 1 + p[y] + 1;  // +1 to climb the tree, +1 to walk from x to y
      if (newcost < dist[y]) {
        dist[y] = newcost;  // dist[y] = min time to go from y to N (climb at y) if energy == 0 when you arrive at y
        Q.push(PLI(-dist[y], y));
      }
    }
  }
  for (int i = 1; i <= N; ++i) cout << dist[i] << " ";
  cout << endl;
  // ==============================
  long long answer = INF;
  vector<long long> d2(N + 1, INF);
  d2[1] = 0;
  for (int steps = 0; steps < N; steps++) { // #nodes on path from 1 to N
    vector<long long> d2nxt(N + 1, INF);
    for (int x = 1; x <= N; x++)
      if (d2[x] != INF)
        for (auto& v : a[x]) {
          int y = v.first;
          int r = v.second;
          long long newcost = d2[x] + p[x] + r; // energy needed to get to node y from x
          if (newcost >= E) { // not enough energy to get to y
            printf("low E, steps=%d, x=%d, newcost=%lld\n", steps, x, newcost);
            answer = min(answer, 2 * steps + 2 + (newcost - E) + dist[y]);  
            // 2(steps + 1) bc need to climb at each node (including 1) and need to walk to next node
            // newcost - E = how much time need to spend waiting to get enough energy
            // dist[y] = min time to get from y to end
          } else if (d2nxt[y] > newcost) {
            // only update this here bc we need to check if it's < INF, and since dist[y] is nonchanging now, no point to update twice
            answer = min(answer, 2 * steps + 2 + dist[y]);  
            printf("steps=%d, x=%d, newcost=%lld, ans=%d\n", steps, x, newcost, answer);
            d2nxt[y] = newcost;
          }
        }
    d2.swap(d2nxt);
  }

  cout << answer << endl;
  return 0;
}
