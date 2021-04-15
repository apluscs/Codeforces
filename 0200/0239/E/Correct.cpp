#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define inf 10000001
const int maxn = 1e5 + 10;
int head[maxn];
int dp[maxn];
int n, u, v, edgenum, arr;
struct Edge {
  int from, to, dis, next;
} edge[maxn << 1];

void add(int u, int v, int d) {
  Edge E = {u, v, d, head[u]};
  edge[edgenum] = E;
  head[u] = edgenum++;
}

void dfs(int u, int fa, int val) {  //val records the number of edges that each child node needs to change back to the root
  dp[u] = 0;
  for (int i = head[u]; ~i; i = edge[i].next)  //~ i: i! =-1
  {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u, val - edge[i].dis);
    dp[u] += dp[v] + (edge​​[i].dis != 1);  //From point u, the number of roots that need to be changed to traverse its child nodes
  }
  arr = max(arr, val);  //Find the maximum number of edges that can be changed less from each child node to the root node
                        //It is necessary to change the number of edges starting from the optimal point in this sub-tree after the edge is disconnected = dp [u] -arr;
}

int main() {
  while (scanf("% d", &n) != EOF) {
    if (n == 1) {
      puts("0");
      continue;
    }
    memset(head, -1, sizeof(head));
    edgenum = 0;  //Record the number of edges
    for (int i = 1; i < n; i++) {
      scanf("% d% d", &u, &v);
      add(u, v, 1);
      add(v, u, -1);
    }
    int ans = inf;
    for (int i = 0; i < edgenum; i += 2) {
      u = edge[i].from;
      v = edge[i].to;
      arr = -inf;
      dfs(u, v, 0);
      int tmp = dp[u] - arr;  //The optimal solution of the first subtree after disconnection

      arr = -inf;
      dfs(v, u, 0);
      tmp += dp[v] - arr;   //Add the optimal solution of the second subtree
      ans = min(ans, tmp);  //The optimal solution obtained after traversing all edges
    }
    printf("% d\n", ans);
  }
  return 0;
}