#include <iostream>
#include <iomanip>
using namespace std;

const int MAXD = 500+2;
const int MAXELEV = 1000;
const long INF = 1000000;

long grid[MAXD][MAXD];
bool isPass[MAXD][MAXD];

long tab1[MAXD][MAXD], tab2[MAXD][MAXD];

void printTable(long a[][MAXD], int r, int c)
{
    for(int i=1; i<=r; i++) {
        cout << setw(7) << a[i][1];
        for(int j=2; j<=c; j++) {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }
}
bool checkForPass(int r, int c)
{
    int val = grid[r][c];
    if (val == INF || grid[r-1][c] == INF || grid[r+1][c] == INF)
        return false;
    if (grid[r-1][c] <= val || grid[r+1][c] <= val)
        return false;
    return (grid[r][c-1] < val && grid[r][c+1] < val);
}

void initTab1(int r, int c)
{
    for(int i=1; i<=r; i++)
        tab1[i][c] = grid[i][c];
    for(int j=c-1; j>=1; j--) {
        for(int i=1; i<=r; i++) {
            if (isPass[i][j])
                tab1[i][j] = INF;
            else {
                long tmp = min(tab1[i-1][j+1], tab1[i][j+1]);
                tab1[i][j] = grid[i][j] + min(tmp, tab1[i+1][j+1]);
            }
        }
    }
}

void nextPass(long tab[][MAXD], long tprev[][MAXD], int r, int c)
{
    for(int i=1; i<=r; i++)
        tab[i][c] = INF;
    for(int j=c-1; j>=1; j--) {
        for(int i=1; i<=r; i++) {
            if (isPass[i][j]) {
                long tmp = min(tprev[i-1][j+1], tprev[i][j+1]);
                tab[i][j] = grid[i][j] + min(tmp, tprev[i+1][j+1]);
            }
            else {
                long tmp = min(tab[i-1][j+1], tab[i][j+1]);
                tab[i][j] = grid[i][j] + min(tmp, tab[i+1][j+1]);
            }
        }
    }
}

long minFirstColumn(long t[][MAXD], int r)
{
    long ans = t[1][1];
    for(int i=2; i<=r; i++)
        ans = min(ans,t[i][1]);
    return ans;
}

int main()
{
    int r, c, npasses;

    cin >> r >> c >> npasses;
    for(int i=0; i<=r+1; i++) {
        grid[i][0] = tab1[i][0] = tab2[i][0] = INF;
        grid[i][c+1] = tab1[i][c+1] = tab2[i][c+1] = INF;
    }
    for(int j=0; j<=c+1; j++) {
        grid[0][j] = tab1[0][j] = tab2[0][j] = INF;
        grid[r+1][j] = tab1[r+1][j] = tab2[r+1][j] = INF;
    }
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == -1)
                grid[i][j] = INF;
        }
    }
    for(int i=2; i<r; i++) {
        for(int j=2; j<c; j++) {
            isPass[i][j] = checkForPass(i,j);
        }
    }

    initTab1(r, c);
//cout << "Tab 0" << endl;
//printTable(tab1, r, c);
    for(int i=1; i<=npasses; i++) {
        if (i%2 == 1) {
            nextPass(tab2, tab1, r, c);
//cout << "Tab " << i << endl;
//printTable(tab2, r, c);
        }
        else {
            nextPass(tab1, tab2, r, c);
//cout << "Tab " << i << endl;
//printTable(tab1, r, c);
        }
    }

    long ans;
    if (npasses%2 == 1) {
        ans = minFirstColumn(tab2, r);
    }
    else {
        ans = minFirstColumn(tab1, r);
    }
    if (ans >= INF)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}
