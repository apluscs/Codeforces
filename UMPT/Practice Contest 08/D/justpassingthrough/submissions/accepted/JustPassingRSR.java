// Solution to Just Passing Through (dynamic programming)

import java.util.*;
import java.io.*;

class Entry { // one entry in the grid
  public int e; // elevation
  public boolean pass; // is this a pass?
  public int best[]; // best altitude sum so far going through [i] passes
  public int from[]; // row # of previous step yielding best[i]
  
  public Entry(int e, int n) {
    this.e = e;
    best = new int[n+1];
    from = new int[n+1];
  }
}

public class JustPassingRSR {
  public static int r,c,n;
  public static Entry grid[][];
  public static final int MAX_ELEV=1000;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(
                          new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    grid = new Entry[r][c];

    for (int i = 0; i < r; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < c; j++) {
        int e = Integer.parseInt(st.nextToken());
        grid[i][j] = new Entry(e,n);
      }
    }

    // locate the "passes":
    for (int i = 1; i < r-1; i++) {
      for (int j = 1; j < c-1; j++) {
        grid[i][j].pass = pass(i,j);
      }
    }
    //display(); // for debugging only

    // fill in first column:
    for (int i = 0; i < r; i++) {
      Entry g = grid[i][0];
      if (g.e == -1) {
        g.best[0] = MAX_ELEV*c+1;
      } else {
        g.best[0] = g.e; // elevation of this location; no passes yet
      }
      g.from[0] = -1;
      for (int k = 1; k <= n; k++) {
        g.best[k] = MAX_ELEV*c+1; // greater than any possible correct answer
        g.from[k] = -1;
      }
    }

    // fill in remaining columns:
    for (int j = 1; j < c; j++) {
      for (int i = 0; i < r; i++) {
        Entry g = grid[i][j];
        Arrays.fill(g.best,MAX_ELEV*c+1);
        if (g.e < 0) continue;
        for (int k = 0; k <= n; k++) {
          fillin(i,j,k);
        }
      }
    }
    int ans = MAX_ELEV*c+1;
    for (int i = 0; i < r; i++) {
      Entry g = grid[i][c-1];
      if (g.best[n] < ans) ans = g.best[n];
    }
    if (ans < MAX_ELEV*c+1)
      System.out.println(ans);
    else
      System.out.println("impossible");
  }

  // See if there's pass at row i, col j:
  public static boolean pass(int i, int j) {
    if (grid[i-1][j].e == -1 || grid[i+1][j].e == -1 
         || grid[i][j-1].e == -1 || grid[i][j+1].e == -1) return false;
    if (grid[i-1][j].e > grid[i][j].e && grid[i+1][j].e > grid[i][j].e &&
         grid[i][j-1].e < grid[i][j].e && grid[i][j+1].e < grid[i][j].e)
      return true;
    return false;
  }

  // Just for debugging; may also adapt at some point
  // for generating visualizations.
  public static void display() {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        System.out.printf("%3d",grid[i][j].e);
        if (grid[i][j].pass) System.out.print("p  ");
        else System.out.print("   ");
      }
      System.out.println();
    }
  }

  // fill in best[k] and from[k] in grid[i][j], j > 0:
  public static void fillin(int i, int j, int k) {
    Entry g = grid[i][j];
    int inc = g.pass?1:0;
      int k1 = k+inc;
      if (k1 > n) return; // no entry for n+1 passes
      for (int m=-1; m <= 1; m++) {
        if (i+m < 0 || i+m >= r) continue;
        Entry g2 = grid[i+m][j-1];
       // checking for paths of min length that go through exactly g2.best[r]
       // passes before entering g from g2:
        if (g2.e < 0) continue;
        int b =g2.best[k] + g.e;
        if (b < g.best[k1]) {
          g.best[k1] = b;
          g.from[k1] = i+m;
        }
      }
  }
}
