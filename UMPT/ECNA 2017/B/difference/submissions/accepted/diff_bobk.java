import java.util.Scanner;

public class diff_bobk {
  int
    r,m,n;
  boolean[]
    seen;
  long[]
    a;

  public void solve() {
    Scanner
      in = new Scanner(System.in);
    int
      next = 1;
    long
      diff;

    r = in.nextInt();
    m = in.nextInt();

    a = new long[10000];
    seen = new boolean[m+1];

    a[0] = r;
    if (r <= m)
      seen[r] = true;

    n = 0;

    while (!seen[m]) {
      while (seen[next])
        next++;
      a[n+1] = a[n] + next;
      n++;
      if (a[n] <= m)
        seen[(int)(a[n])] = true;
      for (int i=0;i<n;i++) {
        diff = a[n] - a[i];
        if (diff <= m)
          seen[(int)diff] = true;
      }
    }

    System.out.println(n+1);
  }

  public static void main(String[] args) {
    diff_bobk solver = new diff_bobk();

    solver.solve();
  }
}
