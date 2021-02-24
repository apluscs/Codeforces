import java.util.*;

public class Car_john_slow
{
    public static Queue<QueueItem> queue = new LinkedList<QueueItem>();
    public static HashSet<CarLot> table = new HashSet<>();

    public static final int NORTH = 0;
    public static final int SOUTH = 1;
    public static final int EAST = 2;
    public static final int WEST = 3;

    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        int m, n;
        int row, col;

        m = in.nextInt();
        n = in.nextInt();
        CarLot c = new CarLot(m,n);
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) {
            c.lot[i][j] = in.nextInt();
        }
        row = in.nextInt();
        col = in.nextInt();
        row--;
        col--;

        QueueItem qi = new QueueItem(c, 0, -1, null);
        queue.add(qi);
        table.add(c);
        boolean found = false;
        while (!queue.isEmpty()) {
//System.out.println(queue.size() + " " + table.size());
            qi = queue.poll();
            if (qi.c.lot[row][col] == -1) {
                found = true;
                break;
            }
            c = qi.c;
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    if (c.lot[i][j] == -1)
                        addItems(c, qi.nMoves+1, i, j, m, n, qi);
                }
            }
//            System.out.println(c);

        }
        if (found) {
//            System.out.println(qi.nMoves);
            printSolution(c, qi, row, col, false);
            System.out.println();
        }
        else
            System.out.println("impossible");
    }

    public static void printSolution(CarLot clot, QueueItem qi, int r, int c, boolean printBlank)
    {
        if (qi.prev != null) {
            if (qi.dir == NORTH) {
                printSolution(clot, qi.prev, r-2, c, true);
                System.out.print(clot.lot[r-1][c]);
            }
            else if (qi.dir == SOUTH) {
                printSolution(clot, qi.prev, r+2, c, true);
                System.out.print(clot.lot[r+1][c]);
            }
            else if (qi.dir == EAST) {
                printSolution(clot, qi.prev, r, c-2, true);
                System.out.print(clot.lot[r][c-1]);
            }
            else {
                printSolution(clot, qi.prev, r, c+2, true);
                System.out.print(clot.lot[r][c+1]);
            }
            if (printBlank)
                System.out.print(" ");
        }
    }

    public static void addItems(CarLot c, int nMoves, int row, int col, int nRows, int nCols, QueueItem prev)
    {
        for(int j=col-1; j>0; j--) {
            if (c.lot[row][j] == -1)
                continue;
            if (c.lot[row][j] == c.lot[row][j-1]) { // found a car to move to the west
                CarLot newc = new CarLot(c);
                newc.lot[row][col] = newc.lot[row][j];
                newc.lot[row][j] = -1;
                newc.lot[row][col-1] = newc.lot[row][j-1];
                newc.lot[row][j-1] = -1;
                if (!table.contains(newc)) {
                    queue.add(new QueueItem(newc, nMoves, WEST, prev));
                    table.add(newc);
//                   System.out.println("Adding\n" + newc);
                }
            }
            break;
        }
        for(int j=col+1; j<nCols-1; j++) {
            if (c.lot[row][j] == -1)
                continue;
            if (c.lot[row][j] == c.lot[row][j+1]) { // found a car to move to the east
                CarLot newc = new CarLot(c);
                newc.lot[row][col] = newc.lot[row][j];
                newc.lot[row][j] = -1;
                newc.lot[row][col+1] = newc.lot[row][j+1];
                newc.lot[row][j+1] = -1;
                if (!table.contains(newc)) {
                    queue.add(new QueueItem(newc, nMoves, EAST, prev));
                    table.add(newc);
//                    System.out.println("Adding\n" + newc);
                }
            }
            break;
        }
        for(int i=row-1; i>0; i--) {
            if (c.lot[i][col] == -1)
                continue;
            if (c.lot[i][col] == c.lot[i-1][col]) { // found a car to move to the south
                CarLot newc = new CarLot(c);
                newc.lot[row][col] = newc.lot[i][col];
                newc.lot[i][col] = -1;
                newc.lot[row-1][col] = newc.lot[i-1][col];
                newc.lot[i-1][col] = -1;
                if (!table.contains(newc)) {
                    queue.add(new QueueItem(newc, nMoves, SOUTH, prev));
                    table.add(newc);
//                    System.out.println("Adding\n" + newc);
                }
            }
            break;
        }
        for(int i=row+1; i<nRows-1; i++) {
            if (c.lot[i][col] == -1)
                continue;
            if (c.lot[i][col] == c.lot[i+1][col]) { // found a car to move to the north
                CarLot newc = new CarLot(c);
                newc.lot[row][col] = newc.lot[i][col];
                newc.lot[i][col] = -1;
                newc.lot[row+1][col] = newc.lot[i+1][col];
                newc.lot[i+1][col] = -1;
                if (!table.contains(newc)) {
                    queue.add(new QueueItem(newc, nMoves, NORTH, prev));
                    table.add(newc);
//                    System.out.println("Adding\n" + newc);
                }
            }
            break;
        }
    }
}

class CarLot
{
    public int rows, cols;
    public int [][] lot;

    public CarLot(int r, int c)
    {
        rows = r;
        cols = c;
        lot = new int[rows][cols];
    };

    public CarLot(CarLot c)
    {
        rows = c.rows;
        cols = c.cols;
        lot = new int[rows][cols];
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++)
                lot[i][j] = c.lot[i][j];
        }
    }

    public boolean equals(Object o)
    {
        CarLot c = (CarLot)o;
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if (c.lot[i][j] != lot[i][j])
                    return false;
        return true;
    }

    public int hashCode()
    {
        return toString().hashCode();
    }

    public String toString()
    {
        String s = "";
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                s += " " + lot[i][j];
            }
            s += "\n";
        }
        return s;
    }
};

class QueueItem
{
    public CarLot c;
    public int nMoves;
    public QueueItem prev;
    public int dir;

    public QueueItem(CarLot cc, int n, int d, QueueItem p)
    {
        c = cc;
        nMoves = n;
        dir = d;
        prev = p;
    }
}
