import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            String s1 = sc.next();
            String s2 = sc.next();
            if (s1.length() > s2.length()) {
                System.out.println(multiply(s1, s2));
            } else {
                System.out.println(multiply(s2, s1));
            }
        }
    }
    
    static String multiply(String s1, String s2) {
        String fS = "";
        int zero = 0;
        for (int i = s2.length() - 1; i >= 0; i--) {
            int n = s2.charAt(i) - '0';
            
            while(fS.length() < zero) {
                fS = '0' + fS;
            }
            if (n != 0) {
                int z = 0;
                String my = fS.substring(fS.length() - zero);
                for (int j = 0; j < s1.length(); j++) {
                    z += n * (s1.charAt(s1.length() - 1 - j) - '0');
                    if (fS.length() - j - zero > 0) {
                        z += fS.charAt(fS.length() - j - zero - 1) - '0';
                    }
                    my = (z % 10) + my;
                    z /= 10;
                }
                if (z > 0)
                    my = z + my;
                fS = my;
            }
            zero++;
        }
        if (fS.length() == 0)
            return "0";
        return fS;
    }
}