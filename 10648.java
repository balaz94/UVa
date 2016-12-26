import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = 1;
        while(sc.hasNextInt()) {
            int n = sc.nextInt();
            if (n == -1)
                return;
            int m = sc.nextInt();
            if (m != 0) {
                double[][] dp = new double[n + 1][m + 1];
                dp[1][1] = 1;
                for (int i = 2; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        dp[i][j] = dp[i-1][j-1] * (j-1) / m + dp[i-1][j] * (m - j + 1) / m;
                    }
                }
            System.out.println("Case " + k++ + ": " + String.format("%.7f", 1 - dp[n][m]).replace(',', '.'));
            } else {
                System.out.println("Case " + k++ + ": -nan");
            }
        }
    }
}