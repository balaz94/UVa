import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static boolean[][] matrix;
    static int[] prices;
    static int start, end;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 1;
        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                return;
            n++;
            matrix = new boolean[n][n];
            prices = new int[n];
            end = n;
            start = sc.nextInt();
            while(true) {
                int p = sc.nextInt();
                int q = sc.nextInt();
                if (p == 0 && q == 0)
                    break;
                matrix[p][q] = true;
            }
            
            System.out.println("Case " + c + ": The longest path from " + start + " has length " + searchMax() + ", finishing at " + end + ".\n");
            c++;
        }
    }
    
    static int searchMax() {
        int max = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i < matrix.length; i++) {
            if (matrix[start][i]) {
                q.add(i);
                prices[i] = 1;
                max = 1;
                if (i < end)
                    end = i;
            }
        }
        
        while (!q.isEmpty()) {
            int p = q.poll();
            for (int i = 1; i < matrix.length; i++) {
                if (matrix[p][i]) {
                    if (prices[p] + 1 > prices[i]) {
                        prices[i] = prices[p] + 1;
                        q.add(i);
                        if (max < prices[i]) {
                            max = prices[i];
                            end = i;
                        } else if (max == prices[i] && end > i)
                            end = i;
                    }
                }
            }
        }
        return max;
    }
}