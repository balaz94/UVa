import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
    static int[][] roads;
    static int[] cities;
    static int start, end;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p = 1;
        while (true) {
            int N = sc.nextInt();
            int R = sc.nextInt();
            if (R == 0 && N == 0) return;
            N++;
            roads = new int[N][N];
            cities = new int[N];
            for (int i = 0; i < R; i++) {
                int r = sc.nextInt();
                int c = sc.nextInt();
                int m = sc.nextInt();
                roads[r][c] = m;
                roads[c][r] = m;
            }
            
            start = sc.nextInt();
            end = sc.nextInt();
            int peoples = sc.nextInt();
            int max = search();
            int min = peoples / max;
            peoples += min;
            
            while (min * max < peoples) {
                min++;
                peoples++;
            }
            System.out.println("Scenario #" + p);
            System.out.println("Minimum Number of Trips = " + min);
            System.out.println();
            p++;
        }
    }   
    
    static int search() {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i < cities.length; i++) {
            if (i != start && roads[start][i] > 0) {
                cities[i] = roads[start][i];
                queue.add(i);
            }
        }
        
        while(!queue.isEmpty()) {
            int p = queue.poll();

            for (int i = 1; i < cities.length; i++) {
                if (i != p && i != start && roads[p][i] > 0) {
                    int price = Math.min(cities[p], roads[p][i]);
                    if (price > cities[i]) {
                        cities[i] = price;
                        if (i != end)
                            queue.add(i);
                    }
                }
            }
        }
        return cities[end];
    }
}