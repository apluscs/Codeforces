#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

string s;
int n,k;
struct Solution {
  string solve() {
    for(char c='a';c<='z'&&k;++c){
      string temp="";
      for(int i=0;i!=s.length();++i){
        char curr = s[i];
        if(curr==c && k){
          k--;
          continue;
        }
        temp+=curr; // add everything != c
      }
      s=temp;
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k>>s;
  Solution test;
  cout<<test.solve()<<endl;
}