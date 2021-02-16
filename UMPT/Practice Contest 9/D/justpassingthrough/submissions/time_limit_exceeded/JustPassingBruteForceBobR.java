// Brute force solution to Just Passing Through. Does rudimentary
// checks prior to search (i.e., makes sure that there are at least n passes
// lying in distinct columns; remembers how many "pass columns" lie to the
// right of each column).

import java.util.*;
import java.io.*;

public class JustPassingBruteForceBobR {
  public static int r,c,n,best;
  public static int grid[][];
  public static boolean pass[][];
  public static boolean haspass[];
  public static int rempass[];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(
                          new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    grid = new int[r][c];
    pass = new boolean[r][c];

    for (int i = 0; i < r; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < c; j++) {
        grid[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    // locate the "passes"; keep track of which columns they're in:
    int lastc = -1;
    int ccount = 0; // number of distinct columns containing passes
    haspass = new boolean[c];
    rempass = new int[c];
    for (int i = 1; i < r-1; i++) {
      for (int j = 1; j < c-1; j++) {
        pass[i][j] = pass(i,j);
        if (pass[i][j]) haspass[j] = true;
        if (pass[i][j] && j != lastc) {
          lastc = c;
          ccount++;
        }
      }
    }

    for (int i = c-2; i >= 0; i--) {
      rempass[i] = rempass[i+1];
      if (haspass[i+1]) rempass[i]++;
    }
    //display(); // for debugging only

    // make sure there are n different columns containing passes:
    best = Integer.MAX_VALUE;
    if (ccount >= n) {
      for (int row = 0; row < r; row++) {
        if (grid[row][0] >= 0)
          bruteforce(row,0,grid[row][0],0);
      }
    }

    if (best < Integer.MAX_VALUE)
      System.out.println(best);
    else
      System.out.println("impossible");
  }

  // See if there's pass at row i, col j:
  public static boolean pass(int i, int j) {
    if (grid[i-1][j] == -1 || grid[i+1][j] == -1 
         || grid[i][j-1] == -1 || grid[i][j+1] == -1) return false;
    if (grid[i-1][j] > grid[i][j] && grid[i+1][j] > grid[i][j] &&
         grid[i][j-1] < grid[i][j] && grid[i][j+1] < grid[i][j])
      return true;
    return false;
  }

  // Just for debugging; may also adapt at some point
  // for generating visualizations.
  public static void display() {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        System.out.printf("%3d",grid[i][j]);
        if (pass[i][j]) System.out.print("p  ");
        else System.out.print("   ");
      }
      System.out.println();
    }
  }

  public static void bruteforce(int row, int col, int elsofar, int passsofar) {
    int g = grid[row][col];
    // Are we done?
    if (col==c-1) {
      // is this a solution and, if so, is it best so far?
      if (passsofar == n // visited exactly n passes
          && elsofar < best) { // smaller total elevation
            best = elsofar;
      }
      return;
    }

    for (int i = -1; i <= 1; i++) {
      if (row+i < 0 || row+i >= r) continue; // at top or bottom boundary
      if (grid[row+i][col+1] < 0) continue; // blocked location
      if (elsofar+grid[row+i][col+1] >= best) continue;
      if (rempass[col] < n-passsofar)
        continue;
      if (pass[row+i][col+1])
        if (passsofar < n) {
          bruteforce(row+i,col+1,elsofar+grid[row+i][col+1], passsofar+1);
        }
        else continue;
      else bruteforce(row+i,col+1,elsofar+grid[row+i][col+1],passsofar);
    }
  }
}
