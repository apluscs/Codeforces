#include <iostream>
#include <vector>
using namespace std;

/*
 * read in m ballots each ranking n candidates
 * determine if for each of the n candidates there's an agenda where they
 *   win when sequential pairwise voting is used
 */

const int MAXC = 26;
const int MAXB = 2000;

int votes[MAXC+1][MAXC+1] = {0};  // votes[i][j] = number of ballots where i beats j
long long beats[MAXC+1];                 // jth bit of beats[i] = 1 -> i beats j

int update(int agenda[], int size, long long prev, long long curr, int n)
{
    long long mask = 2;
    for(int i=1; i<=n; i++) {
        long long b = curr & mask;
        if (b > 0 && b != (prev & mask)) {
            agenda[n-size-1] = i;
            size++;
        }
        mask *= 2;
    }
    return size;
}

int main()
{
    int n, m, total = 0;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int num, ballot[n];
        cin >> num;
        total += num;
        string b;
        cin >> b;
        for(int j=0; j<n; j++)
            ballot[j] = b[j] - 'A' + 1;        // + 1 legacy of previous input which used numbers not  letters
//            cin >> ballot[j];
        for(int j=0; j<n-1; j++) {
            int candidate = ballot[j];
            for(int k=j+1; k<n; k++) {
                votes[candidate][ballot[k]] += num;
            }
        }
    }

    for(int i=1; i<=n; i++){
        beats[i] = 0;
        long long mask = 2;
        for(int j=1; j<=n; j++) {
            if (votes[i][j] > total/2)
                beats[i] |= mask;
            mask *= 2;
        }
    }

/*
    for(int i=1; i<=n; i++){
        long long mask = 2;
        cout << "Candidate " << (char)('A'+i-1) <<  ' ' << beats[i] << " beats";
        for(int j=1; j<=n; j++) {
            if ((beats[i] & mask) > 0)
                cout << " " << (char)('A'+j-1);
            mask *= 2;
        }
        cout << endl;
    }
/**/

    for(int i=1; i<=n; i++) {
        int agenda[n];
        agenda[n-1] = i;
        int size = 0;
        long long prev = 0, curr = beats[i];
        curr = 1;
        curr = curr << i;
        while (prev != curr) {
            size = update(agenda, size, prev, curr, n);
            prev = curr;
            long long mask = 2;
            for(int j=1; j<=n; j++) {
                if ((prev & mask) > 0) {
                    curr |= beats[j];
                }
                mask *= 2;
            }
        }
        cout << (char)('A' + i-1) << ":";
        if (size != n)
            cout << " can't win" << endl;
        else {
            cout << " can win" << endl;
/*
            for(int k=0; k<n; k++)
                cout << ' ' << (char)('A' + agenda[k] - 1);
            cout << endl;
/**/
        }
    }
}
