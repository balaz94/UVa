import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            int n = sc.nextInt();
            int p = sc.nextInt();
            if (n == 0 && p == 0) return;
            
            int[] poc = new int[n+1];
            boolean[][] m = new boolean[n+1][n+1];
            
            for (int i = 0; i < p; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                
                m[a][b] = true;
                poc[b]++;
            }
            
            int remains = n;
            String s = "";
            int min = 0;
            while(remains > 0) {
                HashSet<Integer> h = new HashSet<>();
                boolean change = false;
                for (int i = 1; i <= n; i++) {
                    if (poc[i] <= min) {
                        poc[i] = Integer.MAX_VALUE;
                        remains--;
                        s += i;
                        if (remains > 0) s += " ";
                        change = true;
                    }
                }
                if (change) min = 0;
                else min++;
                
                for (int i : h) {
                    for (int j = 1; j <= n; j++) {
                        if (m[i][j]) poc[j]--;
                    }
                }
            }
            System.out.println(s);
        }
    }
}