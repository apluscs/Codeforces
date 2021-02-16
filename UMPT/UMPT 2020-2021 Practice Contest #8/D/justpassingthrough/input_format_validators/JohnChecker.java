import java.util.*;

// abstract checker

public class JohnChecker
{
	public static final int MINRC = 3;
	public static final int MAXRC = 500;
	public static final int MINN = 0;
	public static final int MAXN = 10;
	public static final int MINSQ = -1;
	public static final int MAXSQ = 1000;

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

    public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int r, c, n;
		String line;
		int nLines=0;

        line = in.nextLine();
        nLines++;
        StringTokenizer st = new StringTokenizer(line);
        if (st.countTokens() != 3)
            printError(nLines, "number of values on line incorrect");
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        checkIntBounds(r, MINRC, MAXRC, "r", nLines);
        checkIntBounds(c, MINRC, MAXRC, "c", nLines);
        checkIntBounds(n, MINN, MAXN, "n", nLines);

        boolean leftOpen = false, rightOpen = false;
        for(int i=1; i<=r; i++) {
            line = in.nextLine();
            nLines++;
            st = new StringTokenizer(line);
            if (st.countTokens() != c)
                printError(nLines, "number of values on line incorrect");
            for(int j=1; j<=c; j++) {
                int elev = Integer.parseInt(st.nextToken());
                checkIntBounds(elev, MINSQ, MAXSQ, "elev_"+j, nLines);
                if (j==1 && elev != -1)
                    leftOpen = true;
                else if (j==c && elev != -1)
                    rightOpen = true;
            }
        }
        if (!leftOpen) {
            printError(nLines, "no open square on left side");
        }
        if (!rightOpen) {
            printError(nLines, "no open square on right side");
        }
		if (in.hasNextLine())
			printError(nLines, "incorrect number of lines");
        System.exit(42);
	}
}
