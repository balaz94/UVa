import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int[][] points;
    static ArrayList<Integer> r, c;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String s = sc.next();
            String f = sc.next();
            int fC = f.charAt(0) - 'a';
            int fR = f.charAt(1) - '1';
            points = new int[8][8];
            if (!s.equals(f)) {
                int sC = s.charAt(0) - 'a';
                int sR = s.charAt(1) - '1';
                r = new ArrayList<>();
                c = new ArrayList<>();
                points[sR][sC] = -1;
                points[fR][fC] = -2;
                r.add(sR);
                c.add(sC);
                searchMin();
            }
            System.out.println("To get from " + s + " to " + f + " takes " + points[fR][fC] + " knight moves.");
        }
    }
    static void searchMin() {
        int step = 1;
        int startIndex = 0;
        int stopIndex = 1;
        while(true) {
            for (int index = startIndex; index < stopIndex; index++) {
                if (search(r.get(index), c.get(index), step))
                    return;
            }
            step++;
            startIndex = stopIndex;
            stopIndex = r.size();
        }
    }
    static boolean search(int i, int j, int step) {
        if (i - 2 >= 0) {
            if (j - 1 >= 0 && change(i-2, j-1, step))
                return true;
            if (j+1 < 8 && change(i-2, j+1, step))
                return true;
        }
        if (i - 1 >= 0) {
            if (j - 2 >= 0 && change(i-1, j-2, step))
                return true;
            if (j+2 < 8 && change(i-1, j+2, step))
                return true;
        }
        if (i + 1 < 8) {
            if (j - 2 >= 0 && change(i+1, j-2, step))
                return true;
            if (j+2 < 8 && change(i+1, j+2, step))
                return true;
        }
        if (i + 2 < 8) {
            if (j - 1 >= 0 && change(i+2, j-1, step))
                return true;
            if (j+1 < 8 && change(i+2, j+1, step))
                return true;
        }
        return false;
    }
    static boolean change(int i, int j, int step) {
        if (points[i][j] == -2) {
            points[i][j] = step;
            return true;
        } else if (points[i][j] == 0) {
            points[i][j] = step;
            r.add(i);
            c.add(j);
        }
        return false;
    }
}