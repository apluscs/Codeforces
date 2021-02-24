// Solution to Car Vet assuming only one empty slot and "blocked" spots
// Probably more complicated than it needs to be (vestiges of an older
// version of the problem).

import java.util.*;

public class Car_bob {

  // Constants to denote car orientation (horizontal or vertical):
  public static final int H=0, V=1;

  // row/col coordinate:
  static class Pair {
    int r,c;
    Pair(int r, int c) {
      this.r = r; this.c = c;
    }
    public boolean equals(Pair o) {
      return (o.r == this.r && o.c == this.c);
    }
  }

  // one car:
  static class Car {
    public int id; // car's assigned number in input grid
    public Pair[] loc; // car's location (two adjacent points in the grid)
    public int dir; // car's orientation (either H or V)
    public boolean used;

    public Car(int id) { // most attributes are set directly
      this.id = id;
      this.loc = new Pair[2];
      this.used = false;
    }
  }


  public static Scanner in;
  public static int m, n, r, c;
  public static Pair goal;
  public static int grid[][]; // grid will contain indices to "car" array
  public static HashMap<Integer,Car> map; // in case we need to lookup car by id

  public static void main(String[] args) {
    in = new Scanner(System.in);
    n = in.nextInt();
    m = in.nextInt();
    Pair empty;
    int ind = 0;
    grid = new int[n][m];
    map = new HashMap<Integer,Car>();
    empty = null;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        grid[i][j] = in.nextInt();
        if (grid[i][j] == -1) {
          empty = new Pair(i,j); // only one!
        }
        else if (grid[i][j] >= 0) {
          Car x = map.get(grid[i][j]);
          if (x == null) {
            x = new Car(grid[i][j]);
            x.loc[0] = new Pair(i,j);
            map.put(x.id,x);
          }
          else {
            x.loc[1] = new Pair(i,j);
            if (x.loc[0].r == x.loc[1].r) {
              x.dir = H;
            }
            else {
              x.dir = V;
            }
          }
        }
      }
    }
    r = in.nextInt()-1;
    c = in.nextInt()-1;
    goal = new Pair(r,c);
    Stack<Car> stack = new Stack<Car>();

    int steps = 0;
    HashMap<Integer,Car> used = new HashMap<Integer,Car>();
    int re = empty.r, ce = empty.c; // just for convenience
    while (!goal.equals(empty)) {
      r = goal.r;
      c = goal.c;
      Car v = map.get(grid[r][c]); // what car is located at the goal?
      if (v.used) {
        System.out.println("impossible");
        System.exit(0);
      }
      v.used = true;
      stack.push(v);
      if (v.dir==H) {
        if (goal.equals(v.loc[0])) { //need to move car right
           if (v.loc[1].c < m-1 && grid[v.loc[1].r][v.loc[1].c+1] != -2) { // CAN we move right?
             goal.c = v.loc[1].c+1;
           } else { System.out.println("impossible"); System.exit(0);}
        } else { // need to move left
           if (v.loc[0].c > 0 && grid[v.loc[0].r][v.loc[0].c-1] != -2) { // CAN we move left?
               goal.c = v.loc[0].c-1;
           } else { System.out.println("impossible"); System.exit(0);}
        }
      } else { // dir = V
        if (goal.equals(v.loc[0])) { //need to move car down
           if (v.loc[1].r < n-1 && grid[v.loc[1].r+1][v.loc[1].c] != -2) { // CAN we move down?
             goal.r = v.loc[1].r+1;
           }  else { System.out.println("impossible"); System.exit(0);}
        } else { // goal equals v.loc[1]; need to move car up
           if (v.loc[0].r > 0 && grid[v.loc[0].r-1][v.loc[0].c] != -2) { // CAN we move down?
             goal.r = v.loc[0].r-1;
           } else { System.out.println("impossible"); System.exit(0);}
        }
      }
      steps++;
    }
    while (!stack.isEmpty()) {
      Car v = stack.pop();
      System.out.print(v.id);
      if (!stack.isEmpty()) System.out.print(" ");
    }
    System.out.println();
  }
}
