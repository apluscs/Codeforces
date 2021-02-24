import java.util.*;

// abstract checker

public class JohnChecker
{
    public static final int MINR = 1;
	public static final int MAXR = 100;
    public static final int MINM = 1;
	public static final int MAXM = 200000000;

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
		int r, m;
		String line;
		int nLines=0;

        line = in.nextLine();
        nLines++;
        StringTokenizer st = new StringTokenizer(line);
        if (st.countTokens() != 2)
            printError(nLines, "number of values on line incorrect");
		r = Integer.parseInt(st.nextToken());
		checkIntBounds(r, MINR, MAXR, "r", nLines);
		m = Integer.parseInt(st.nextToken());
		checkIntBounds(m, MINM, MAXM, "m", nLines);
		if (in.hasNextLine())
			printError(nLines, "incorrect number of lines");
        System.exit(42);
	}
}
