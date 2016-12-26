import java.util.Scanner;
import java.util.HashSet;

public class Main {
    static double min;
    static int[] x, y;
    static double[][] m;
    static double[] dp;
    static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 1;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            if (n == 0)
                return;
            n *= 2;
            x = new int[n];
            y = new int[n];
            dp = new double[65536];
            
            for (int i = 0; i < n; i++) {
                sc.next();
                x[i] = sc.nextInt();
                y[i] = sc.nextInt();
            }

            min = Double.MAX_VALUE;
                  
            m = new double[n][n];
            for (int i = 0; i < m.length; i++) {
                for (int j = i + 1; j < m.length; j++) {
                    double a = Math.max(x[i], x[j]) - Math.min(x[i], x[j]);
                    double b = Math.max(y[i], y[j]) - Math.min(y[i], y[j]);
                    m[i][j] =  Math.sqrt(a * a + b * b);
                }
            }
            
            System.out.print("Case " + c + ": " + String.format("%.2f\n", search(new HashSet<Integer>(), 0)).replace(',', '.'));
            c++;
        }
    }
    
    static double search(HashSet<Integer> h, int mask) {
        if (h.size() == n)
            return 0;
        else if (dp[mask] > 0) 
            return dp[mask];
        else {
            double myMin = Double.MAX_VALUE;
            for (int i = 0; i < m.length; i++) {
                if (!h.contains(i)) {
                    h.add(i);
                    for (int j = i + 1; j < m.length; j++) {
                        if (!h.contains(j)) {
                            h.add(j);
                            double d = search(h, mask | (1 << i) | (1 << j)) + m[i][j];
                            myMin = Math.min(d, myMin);
                            h.remove(j);
                        }
                    }
                    h.remove(i);
                }
            } 
            dp[mask] =  myMin;
            return myMin;
        }
    }
}