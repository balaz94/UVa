import java.util.Scanner;
import java.util.LinkedList;

public class Main {
    static String [] morse = new String[] { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    static List [] list;
    static long [] dp;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n-- > 0) {
            String s = sc.next();
            list = new List[s.length()];
            dp = new long[s.length() + 1];
            int l = sc.nextInt();
            for (int i = 0; i < l; i++) {
                String m = toMorse(sc.next());
                int startIndex = 0;
                
                while(true) {
                    int index = s.indexOf(m, startIndex);
                    if (index > -1) {
                        startIndex = index + 1;
                        if (list[index] == null)
                            list[index] = new List();
                        list[index].list.add(m.length());
                    } else {
                        break;
                    }
                }
            }
            dp[0] = 1;
            for (int i = 0; i < s.length(); i++) {
                if (dp[i] > 0 && list[i] != null) {
                    for (int j : list[i].list) {
                        if (i + j < dp.length) {
                            dp[i+j] += dp[i];
                        }
                    }
                }
            }
            
            System.out.println(dp[s.length()]);
            if (n > 0)
                System.out.println();
        }
    }
    
    static String toMorse(String word) {
        String s = "";
        for (int i = 0; i < word.length(); i++) {
            s += morse[word.charAt(i) - 'A'];
        }
        return s;
    }
    
    static class List {
        LinkedList<Integer> list;
        public List() {
            list = new LinkedList<Integer>();
        }
    }
}