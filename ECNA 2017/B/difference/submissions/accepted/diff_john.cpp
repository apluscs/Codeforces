#include <iostream>
#include <cstdio>
#include<vector>
using namespace std;

const int MAX = 200000000;
const int MAXSTEPS = 10000;

short used[MAX] = {false};
int d = 1;

vector<int> vals;
int nvals = 0;

int main()
{
    int start, target;
    cin >> start >> target;
    int count = 0;
    while (count < MAXSTEPS) {
        count++;
        if (start < MAX)
            used[start] = true;
        for(int i=0; i<nvals; i++) {
            if (start-vals[i] < MAX)
                used[start - vals[i]] = true;
        }
        if (used[target])
            break;
        vals.push_back(start);
        nvals++;
        while (used[d])
            d++;
        start += d;
    }
    if (count == MAXSTEPS && !used[target])
        cout << "ERROR: Too many steps for this input" << endl;
    cout << count << endl;
}
