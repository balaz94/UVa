import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
    static int[][] m;
    static int[] weight;
    static String[] names;
    static int start, end, n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int scenario = 1;
        while(true) {
            n = sc.nextInt();
            int r = sc.nextInt();
            if (n == 0 && r == 0) return;
            weight = new int[n];
            m = new int[n][n];
            names = new String[n];
            for (int i = 0; i < r; i++) {
                String s1 = sc.next();
                String s2 = sc.next();
                int a = getIndex(s1);
                int b = getIndex(s2);
                int c = sc.nextInt();
                if (m[a][b] < c) {
                    m[a][b] = c;
                    m[b][a] = c;
                }
            }
            
            start = getIndex(sc.next());
            end = getIndex(sc.next());
            
            System.out.println("Scenario #" + scenario);
            System.out.println(search() + " tons");
            System.out.println();
            scenario++;
        }
    }
    
    static int search() {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (m[start][i] > 0) {
                if (i != end)
                    q.add(i);
                weight[i] = m[start][i];
            }
        }
        
        while(!q.isEmpty()) {
            int p = q.poll();
            for (int i = 0; i < m.length; i++) {
                if (i != start && m[p][i] > 0) {
                    int min = Math.min(weight[p], m[p][i]);
                    if (min > weight[i]) {
                        weight[i] = min;
                        if (i != end)
                            q.add(i);
                    }
                }
            }
        }
        return weight[end];
    }
    
    static int getIndex(String s) {
        for (int i = 0; i < n; i++) {
            if (names[i] == null) {
                names[i] = s;
                return i;
            }
            if (names[i].equals(s)) return i;
        }
        return -1;
    }
}
