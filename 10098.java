import java.util.Scanner;
import java.util.HashSet;

public class Main {
    static HashSet<String> set;
    static char[] c;
    static boolean[] used;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            c = sort(sc.next().toCharArray());
            set = new HashSet<>();
            used = new boolean[c.length];
            
            for (int i = 0; i < c.length; i++) {
                used[i] = true;
                generate("" + c[i]);
                used[i] = false;
            }
            System.out.println();
        }
    }
    static void generate(String s) {
        if (s.length() == c.length) {
            if (!set.contains(s)) {
                System.out.println(s);
                set.add(s);
            }
        } else {
            for (int i = 0; i < c.length; i++) {
                if (!used[i]) {
                    used[i] = true;
                    generate(s + c[i]);
                    used[i] = false;
                }
            }
        }
    }
    static char[] sort(char[] c) {
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c.length; j++) {
                if (i != j && c[j] > c[i]) {
                    char h = c[j];
                    c[j] = c[i];
                    c[i] = h;
                }
            }
        }
        return c;
    }
}