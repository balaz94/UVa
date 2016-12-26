import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static boolean [][] m;
    static int R, C, rF, cF, rS, cS;
    static ArrayList<Integer> x, y;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            R = sc.nextInt();
            C = sc.nextInt();
            if (R == 0 && C == 0) return;
            m = new boolean[R][C];
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int r = sc.nextInt();
                int p = sc.nextInt();
                for (int j = 0; j < p; j++) {
                    int c = sc.nextInt();
                    m[r][c] = true;
                }
            }
            rS = sc.nextInt();
            cS = sc.nextInt();
            
            x = new ArrayList<>();
            y = new ArrayList<>();
            x.add(rS);
            y.add(cS);
            m[rS][cS] = true;
            
            rF = sc.nextInt();
            cF = sc.nextInt();
            if (rS == rF && cS == cF)
                System.out.println(0);
            else
                System.out.println(getMin());
        }
    }
    static int getMin() {
        int start = 0;
        int end = 1;
        int step = 1;
        
        while (true) {
            for (int i = start; i < end; i++) {
                if (search(x.get(i), y.get(i)))
                    return step;
            }
            step++;
            if (start == end)
                return -1;
            start = end;
            end = x.size();
        }
    }
    static boolean search(int r, int c) {
        if (r > 0) {
            if (control(r-1, c)) return true;
        } 
        if (r+1 < R) {
            if (control(r+1, c)) return true;
        }
        if (c > 0) {
            if (control(r, c-1)) return true;
        }
        if (c+1 < C) {
            if (control(r, c+1)) return true;
        }
        return false;
    }
    static boolean control(int r, int c) {
        if (r == rF && c == cF)
            return true;
        if (!m[r][c]) {
            m[r][c] = true;
            x.add(r);
            y.add(c);
        }
        return false;
    }
}