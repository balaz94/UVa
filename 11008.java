import java.util.Scanner;
import java.util.HashSet;

public class Main {
    static int[] x, y;
    static int[] dp;
    static Con[][] c;
    static int [][] m;
    static int M, n, min;
    static int count = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int z = 1; z <= N; z++) {
            n = sc.nextInt();
            M = sc.nextInt();
            x = new int[n];
            y = new int[n];
            c = new Con[n][n];
            m = new int[n][n];
            dp = new int[(int)Math.pow(2, n)];
            for (int i = 0; i < n; i++) {
                x[i] = sc.nextInt();
                y[i] = sc.nextInt();
            }
            if (M < 2) {
                if (M == 0)
                    min = 0;
                else
                    min = 1;
            } else {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (c[i][j] == null) {
                            int mask = (1 << i) | (1 << j);
                            HashSet<Integer> h = new HashSet<>();
                            h.add(i);
                            h.add(j);
                            for (int k = j + 1; k < n; k++) {
                                if ((y[k]-y[i])*(x[j]-x[i])==(x[k]-x[i])*(y[j]-y[i])) {
                                    mask |= (1 << k);
                                    h.add(k);
                                }
                            }
                            for (int i1 : h)
                                for (int i2 : h)
                                    if (i1 < i2) {
                                        c[i1][i2] = new Con(h);
                                        m[i1][i2] = mask;
                                    }
                        }
                    }
                }
                min = M / 2 + (M % 2 != 0 ? 1 : 0);
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        HashSet<Integer> h = new HashSet<>();
                        h.addAll(c[i][j].set);
                        min = Math.min(min, getStep(m[i][j], h) + 1);
                    }
                }
            }
            if (z > 1) System.out.print("\n");
            System.out.print("Case #" + z + ":\n" + min + "\n");
        }
    }
    static int getStep(int mask, HashSet<Integer> used) {
        if (used.size() >= M) 
            return 0;
        else if (used.size() - 1 == M)
            return 1;
        else if (dp[mask] > 0) 
            return dp[mask];
        else {
            int step = (M - used.size()) / 2 + ((M - used.size()) % 2 != 0 ? 1 : 0);
            for (int i = 0; i < n; i++) {
                if (!used.contains(i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (!used.contains(j) && c[i][j].set.size() > 2) {
                            HashSet<Integer> h = new HashSet<>();
                            h.addAll(used);
                            h.addAll(c[i][j].set);
                            step = Math.min(step, getStep(mask | m[i][j], h) + 1);
                        }
                    }
                }
            }
            dp[mask] = step;
            return step;
        }
    }
    static class Con {
        private HashSet<Integer> set;
        public Con(HashSet<Integer> set) {
            this.set = set;
        }
    }
}