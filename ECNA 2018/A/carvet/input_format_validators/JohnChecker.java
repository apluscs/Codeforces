import java.util.*;

// abstract checker

public class JohnChecker
{
    public static final int MIN = 1;
	public static final int MAX = 250;

	public static final int EMPTY = -1;
	public static final int JUNK = -2;
	public static final int FOUND = -3;

	public static int[][] grid = new int[MAX][MAX];

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

    public static void checkGrid(int m, int n, int nLines)
    {
        int emptyCount = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == FOUND)
                    continue;
                if (grid[i][j] == EMPTY)
                    emptyCount++;
                else if (grid[i][j] != JUNK) {
                    boolean found = false;
                    if (i < m-1 && grid[i+1][j] == grid[i][j]) {
                        grid[i+1][j] = FOUND;
                        found = true;
                    }
                    else if (j < n-1 && grid[i][j+1] == grid[i][j]) {
                        grid[i][j+1] = FOUND;
                        found = true;
                    }
                    if (found)
                        grid[i][j] = FOUND;
                }
            }
        }
        if (emptyCount == 0)
            printError(nLines, "missing empty grid square");
        else if (emptyCount > 1)
            printError(nLines, "too many empty grid squares");
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                switch (grid[i][j]) {
                case EMPTY:
                case JUNK :
                case FOUND : break;
                default : printError(nLines, "missing matching piece for car " + grid[i][j]);
                }
            }
    }

    public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int m, n, r, c;
		String line;
		int nLines=0;

        line = in.nextLine();
        nLines++;
        StringTokenizer st = new StringTokenizer(line);
        if (st.countTokens() != 2)
            printError(nLines, "number of values on line incorrect");
		m = Integer.parseInt(st.nextToken());
		checkIntBounds(m, MIN, MAX, "m", nLines);
		n = Integer.parseInt(st.nextToken());
		checkIntBounds(n, MIN, MAX, "n", nLines);
		for(int i=0; i<m; i++) {
            nLines++;                       // not quite true if multiple values on a line
       		line = in.nextLine();
       		st = new StringTokenizer(line);
            if (st.countTokens() != n)
                printError(nLines, "number of values on line incorrect");
            for(int j=0; j<n; j++) {
                int val = Integer.parseInt(st.nextToken());
                checkIntBounds(val, -2, Integer.MAX_VALUE, "val", nLines);
                grid[i][j] = val;
            }
		}
		checkGrid(m, n, nLines);
		line = in.nextLine();
		nLines++;
        st = new StringTokenizer(line);
        if (st.countTokens() != 2)
            printError(nLines, "number of values on line incorrect");
		r = Integer.parseInt(st.nextToken());
		checkIntBounds(r, MIN, MAX, "r", nLines);
		c = Integer.parseInt(st.nextToken());
		checkIntBounds(c, MIN, MAX, "c", nLines);
		if (in.hasNextLine())
			printError(nLines, "incorrect number of lines");
        System.exit(42);
	}
}
