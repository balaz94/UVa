import java.util.Scanner;

public class Main {
    static boolean pal = false, rev = false;
    static char[] chars = new char[] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    static char[] rChar = new char[] { 'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J', 'M', ' ', 'O', ' ', ' ', ' ', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' ', '0' };
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()) {
            String s = sc.next();
            palindrome(s);
        }
    }
    
    static void palindrome(String s) {
        pal = true;
        rev = true;
        int l = s.length() / 2;
        for (int i = 0; i < l; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i))
                pal = false;
            if (s.charAt(i) == 'O' && !(s.charAt(s.length() - 1 - i) == 'O' || s.charAt(s.length() - 1 - i) == '0')) {
                rev = false;
            } else {
                int index = getIndex(s.charAt(i));
                if (rChar[index] == ' ' || rChar[index] != s.charAt(s.length() - 1 - i))
                    rev = false;
            }
            if (!pal && !rev)
                break;
        }
        if (s.length() % 2 != 0) {
            if (rev) {
                int index = getIndex(s.charAt(l));
                if (chars[index] != rChar[index] ) {
                    rev = false;
                }
            }
        }
        
        if (pal && rev) {
            System.out.println(s + " -- is a mirrored palindrome.");
        } else if (pal && !rev) {
            System.out.println(s + " -- is a regular palindrome.");
        } else if (!pal && rev) {
            System.out.println(s + " -- is a mirrored string.");
        } else {
            System.out.println(s + " -- is not a palindrome.");
        }
        System.out.println();
    }
    
    static int getIndex(char c) {
        for (int i = 0; i < chars.length; i++)
            if (chars[i] == c)
                return i;
        return -1;
    }
}