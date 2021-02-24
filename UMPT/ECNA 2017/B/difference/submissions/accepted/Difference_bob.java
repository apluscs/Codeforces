import java.util.*;

public class Difference_bob {
  public static int r,m;
  public static int a[];
  public static boolean d[];
  public static Scanner in;

  public static void main(String[]args) {
    in = new Scanner(System.in);
    r = in.nextInt();
    m = in.nextInt();
    // Base case
    if (r == m) {
      System.out.println(1);
      System.exit(0);
    }

    int n = 200000000;
    a = new int[10001]; // no idea how big this needs to be
    d = new boolean[n+1]; // d[i] = true if i has been used

    int min = 1; // smallest unused difference
    if (r==1) min = 2; // special case when first integer in sequence is 1
    a[0] = r;
    d[r] = true;
    int step = 0;

    while (step < n) {
      step++;
      a[step] = a[step-1]+min;
      if (a[step] == m) {
        System.out.println(step+1);
        System.exit(0);
      }
      d[a[step]] = true;
      d[min] = true;
      for (int i = step-1; i >= 0 && a[step]-a[i] >= min; i--) {
        int diff = a[step] - a[i];
        if (diff == m) {
          System.out.println(step+1);
          System.exit(0);
        }
        d[diff] = true;
      }
      while (d[min])
        min++;
    }
  }
}
