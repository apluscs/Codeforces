#include <bits/stdc++.h>

using namespace std;

template <class T, class U>
inline bool ckmax(T &a, U b) { return b > a ? a = b, true : false; }

template <class T, class U>
inline bool ckmin(T &a, U b) { return b < a ? a = b, true : false; }

#define FAST_IO            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);             \
  cout.precision(20)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int MAXN = 105;

int V = MAXN, t;
vector<int> adj[MAXN];
vector<vector<int>> components;
void SCCUtil(int curr, int disc[], int low[], stack<int> *st, bool inStack[]) {
  disc[curr] = low[curr] = ++t;
  st->push(curr);
  inStack[curr] = true;
  for (auto node : adj[curr]) {
    if (!disc[node]) {
      SCCUtil(node, disc, low, st, inStack);
      ckmin(low[curr], low[node]);
    } else if (inStack[node])
      ckmin(low[curr], disc[node]);
  }
  int tmp;
  if (low[curr] == disc[curr]) {  //head
    vector<int> vec;
    while (st->top() != curr) {
      tmp = st->top(), st->pop();
      vec.push_back(tmp);
      inStack[tmp] = false;
    }
    tmp = st->top(), st->pop();
    vec.push_back(tmp);
    inStack[tmp] = false;
    components.push_back(vec);
  }
}
void SCC() {
  t = 0;
  int disc[V], low[V];
  bool inStack[V];
  stack<int> *st = new stack<int>();
  memset(disc, 0, sizeof disc);
  memset(low, 0, sizeof low);
  memset(inStack, false, sizeof inStack);
  for (int i = 0; i < V; i++)
    if (!disc[i]) {
      SCCUtil(i, disc, low, st, inStack);
    }
}

int main() {
  FAST_IO;
  string tmp;
  int n;
  cin >> n;
  getline(cin, tmp);
  map<string, vector<int>> mapp;  // home language to nodes
  vector<vector<string>> outedges;

  for (int i = 0; i < n; i++) {
    string name, home;
    cin >> name >> home;
    mapp[home].push_back(i);
    getline(cin, tmp);
    istringstream inp(tmp);
    vector<string> vec = vector<string>(istream_iterator<string>(inp), istream_iterator<string>());
    vec.push_back(home);
    outedges.push_back(vec);
  }
  // directed connections
  for (int i = 0; i < n; i++) {
    for (auto &stri : outedges[i]) {  // outedges[i] = languages i understands
      for (auto &j : mapp[stri]) {
        if (i == j) continue;
        adj[j].push_back(i);
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cout << "---" << i << "---" << endl;
  //   for (int j : adj[i]) cout << j << " ";
  //   cout << endl;
  // }

  SCC();
  int ans = n;
  for (auto &vec : components) {
    ckmin(ans, n - vec.size());
  }
  cout << ans << '\n';
}
