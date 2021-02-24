import java.util.*;

public class JohnChecker
{
    public static final int MINN = 1;
	public static final int MAXN = 26;
    public static final int MINM = 1;
	public static final int MAXM = 2000;
    public static final int MINP = 1;
	public static final int MAXP = 100;

	public static String[] ballots = new String[MAXM];
	public static int nBallots = 0;

    public static void printError(int line, String msg)
	{
		System.out.println("ERROR Line " + line + ": " + msg);
		System.exit(-1);
	}

    public static void checkIntBounds(int x, int min, int max, String name, int nLines)
    {
        if (x < min || x > max)
            printError(nLines, "invalid " + name + " value: " + x);
    }

    public static boolean ok(String b, int n)
    {
        for(int i = 0; i<n; i++ )
        {
            char ch = (char)('A'+i);
            if (b.indexOf(ch) == -1)
                return false;
        }
        return true;
    }

    public static boolean unique(String b)
    {
        for(int i=0; i<nBallots; i++) {
            if (ballots[i].equals(b))
                return false;
        }
        return true;
    }

    public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int n, m;
		String line;
		int nLines=0;

        line = in.nextLine();
        nLines++;
        StringTokenizer st = new StringTokenizer(line);
        if (st.countTokens() != 2)
            printError(nLines, "number of values on line incorrect");
		n = Integer.parseInt(st.nextToken());
		checkIntBounds(n, MINN, MAXN, "n", nLines);
		m = Integer.parseInt(st.nextToken());
		checkIntBounds(m, MINM, MAXM, "m", nLines);
		int totalBallots = 0;
		for(int i=1; i<=m; i++) {
            line = in.nextLine();
            st = new StringTokenizer(line);
            nLines++;
            if (st.countTokens() != 2)
                printError(nLines, "number of values on line incorrect: ");
            int p = Integer.parseInt(st.nextToken());
            String ballot = st.nextToken();
            checkIntBounds(p, MINP, MAXP, "p", nLines);
            totalBallots += p;
            if (ballot.length() != n)
                printError(nLines, "incorrect length for ballot " + p);
            if (!ok(ballot, n))
                printError(nLines, "bad character in ballot " + p);
            if (!unique(ballot))
                printError(nLines, "ballot " + p + " not unique");
            ballots[nBallots++] = ballot;
		}
		if (totalBallots%2 != 1)
            printError(nLines, "Total number of ballots not odd");
		if (in.hasNextLine())
			printError(nLines, "incorrect number of lines");
        System.exit(42);
	}
}
