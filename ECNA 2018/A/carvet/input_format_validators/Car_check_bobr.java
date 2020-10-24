// Check structure of car vet input; doesn't do rudimentary checks for things
// like input bounds or trailing spaces--use "car_syntax_bobr.ctd" for that

import java.util.*;

public class Car_check_bobr {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int m = in.nextInt();
    int n = in.nextInt();

    int onecount = 0, twocount = 0;
    int[][] grid = new int[m][n];
    int[] cars = new int[m*n];
    int ncar=0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = in.nextInt();
        if (grid[i][j] == -1) {
          onecount++;
        } else if (grid[i][j] == -2) {
          twocount++;
        } else {
          cars[ncar++] = grid[i][j];
        }
      }
    }
    int r = in.nextInt();
    int c = in.nextInt();

    // Exactly one empty location:
    if (onecount != 1) {
      System.out.println("Should be exactly one empty; this has "+onecount);
      System.exit(1);
    }

    // Goal location must be under a car:
    if (grid[r-1][c-1] < 0) {
      System.out.println("Goal should be under a car location");
      System.exit(1);
    }

    // make sure cars have unique numbers and each appears twice:
    Arrays.sort(cars,0,ncar);

    // count unique:
    int last = -1;
    int uniq = 0;
    int rep = 2;
    for (int i = 0; i < ncar; i++) {
      if (cars[i] != last) {
        if (rep < 2) {
          System.out.println("Car number " + last + " appeared only once");
          System.exit(1);
        }
        uniq++;
        rep = 1;
        last = cars[i];
      } else {
        rep++;
        if (rep > 2) {
          System.out.println("Car number "+last+" occurs more than twice");
          System.exit(1);
        }
      }
    }
    // If each car number appears twice, uniq should equal ncar/2:
    // (This is a redundant check, I guess--program will exit above
    // if this doesn't hold)
    if (uniq != ncar/2) {
      System.out.println("error in car numbering");
      System.out.println("Should be "+ncar/2+"unique cars, found = " + uniq);
      System.exit(1);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int car = grid[i][j];
        if (car < 0) continue;
        // find "other half" of this car; if we can't, error:
        if (i > 0 && grid[i-1][j] == car) continue;
        if (j > 0 && grid[i][j-1] == car) continue;
        if (i < m-1 && grid[i+1][j] == car) continue;
        if (j < n-1 && grid[i][j+1] == car) continue;
        System.out.println("Bad car: "+grid[i][j]);
        System.exit(1);
      }
    }
    System.exit(42);
  }
}
