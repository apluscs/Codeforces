import java.util.Scanner;

public class pear_bobk {
  private int
    nCandidates,
    nUniqueBallots,
    nReached,
    ballotCounts[];
  private byte
    adj[][],
    colors[];
  private String
    ballots[];

  public void visit(int v) {

    colors[v] = 1;

    nReached++;

    for (int w=0;w<nCandidates;w++)
      if (adj[v][w] == 1 && colors[w] == 0)
        visit(w);

    colors[v] = 2;
  }

  public void solve() {
    Scanner
      in = new Scanner(System.in);
    int
      nA,nB,pA,pB;

    nCandidates = in.nextInt();
    nUniqueBallots = in.nextInt();

    ballotCounts = new int[nUniqueBallots];
    ballots = new String[nUniqueBallots];

    for (int i=0;i<nUniqueBallots;i++) {
      ballotCounts[i] = in.nextInt();
      ballots[i] = in.next();
    }
/*
    System.out.println("candidates: " + nCandidates);
    System.out.println("unique ballots: " + nUniqueBallots);

    for (int i=0;i<nUniqueBallots;i++) {
      System.out.print(ballots[i] + " ... ");
      System.out.println(ballotCounts[i]);
    }
    */

    adj = new byte[nCandidates][nCandidates];
    colors = new byte[nCandidates];

    for (int a=0;a<nCandidates;a++)
      for (int b=0;b<nCandidates;b++)
        if (a != b) {
          nA = 0;
          nB = 0;
          for (int i=0;i<nUniqueBallots;i++) {
            for (pA=0;ballots[i].charAt(pA)!=(char)(65+a);pA++);
            for (pB=0;ballots[i].charAt(pB)!=(char)(65+b);pB++);
            if (pA < pB)
              nA += ballotCounts[i];
            else
              nB += ballotCounts[i];
          }
          if (nA > nB)
            adj[a][b] = 1;
          else if (nB > nA)
            adj[b][a] = 1;
//          else
//            System.out.println("Error: Tie!" + (char)(65+a) + "  " + (char)(65+b));
        }
/*
    for (int a=0;a<nCandidates;a++) {
      for (int b=0;b<nCandidates;b++)
        System.out.print(adj[a][b]);
      System.out.println();
    }
    */

    for (int a=0;a<nCandidates;a++) {
      for (int b=0;b<nCandidates;b++)
        colors[b] = 0;
      nReached = 0;
      visit(a);
      System.out.print((char)(65+a));
      if (nReached == nCandidates)
        System.out.println(": can win");
      else
        System.out.println(": can't win");
    }
  }

  public static void main(String[] args) {
    pear_bobk solver = new pear_bobk();

    solver.solve();
  }
}
