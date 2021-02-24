import java.util.*;

public class Car_john
{
    public static final int HOLE = -1;
    public static final int JUNK = -2;

    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        int m, n;
        int row, col;
        int holeRow=-1, holeCol=-1;
        int [] moveOrder;
        int nmoves;
        int [][] lot;
        boolean [][] used;

        m = in.nextInt();
        n = in.nextInt();
        lot = new int[m][n];
        used = new boolean[m][n];
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) {
            lot[i][j] = in.nextInt();
            if (lot[i][j] == HOLE) {
                holeRow = i;
                holeCol = j;
            }
            used[i][j] = false;
        }
        row = in.nextInt();
        col = in.nextInt();
        row--;
        col--;
        moveOrder = new int[m*n];
        boolean ok = true;

        nmoves = 0;
        while(ok) {
            if (row < 0 || row >= m || col < 0 || col >= n)
                ok = false;
            else if (lot[row][col] == JUNK)
                ok = false;
            else if (used[row][col])
                ok = false;
            else if (row == holeRow && col == holeCol)
                break;                              // found it!
            else {
                used[row][col] = true;
                int car = lot[row][col];
                moveOrder[nmoves++] = car;
                if (row > 0 && lot[row-1][col] == car)          // car on this spot fills out above
                    row -= 2;
                else if (row < m-1 && lot[row+1][col] == car)   // car fill out below
                    row += 2;
                else if (col > 0 && lot[row][col-1] == car)     // car fills out to the left
                    col -= 2;
                else                                            // car fills out to the right
                    col += 2;
            }
        }
        if (!ok)
            System.out.println("impossible");
        else {
            System.out.print(moveOrder[nmoves-1]);
            for(int i=nmoves-2; i>=0; i--)
                System.out.print(" " + moveOrder[i]);
            System.out.println();
        }
    }
}
