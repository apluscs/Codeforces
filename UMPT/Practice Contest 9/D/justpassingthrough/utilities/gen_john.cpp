#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAXD = 500;
const int MAXELEV = 1000;

int main()
{
    srand(time(0));

    int nrocks = 10;
    int n = MAXD, m = MAXD;
    cin >> n >> m;

    cout << n << ' ' << m << ' ' << rand()%10 << endl;
    for(int r=0; r<n; r++) {
        int val = rand()%(MAXELEV + nrocks+1) - nrocks;
        if (val < 0)
            val = -1;
        cout << val;
//        for(int c=0; c<m; c++) {
        for(int c=1; c<m; c++) {
            val = rand()%(MAXELEV + nrocks+1) - nrocks;
            if (val < 0)
                val = -1;
            cout << ' ' << val;
        }
        cout << endl;
    }
}
