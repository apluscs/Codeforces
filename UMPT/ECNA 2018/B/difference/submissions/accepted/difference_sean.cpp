#include <iostream>
#include <vector>

using namespace std;

int main(){
  long long r, m;
  cin >> r >> m;
  vector<bool> seen(m+1, false);
  seen[0] = true;
  seen[r] = true;
  vector<long long> seq;
  long long cur = r;
  long long num = 1;
  seq.push_back(r);
  while(cur != m){
    int i = 1;
    while(seen[i])
      i++;
    cur = cur + i;
    num++;
    if(cur < seen.size())
      seen[cur] = true;
    seq.push_back(cur);
    for(int i = 0; i < seq.size(); i++){
      long long diff = cur-seq[i];
      if(diff < seen.size())
	seen[diff] = true;
      if(diff == m){
	cur = m;
	i = seq.size();
      }
    }
  }
  cout << num << endl;
  return 0;
}
    
