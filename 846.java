import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int length = y - x;
            int steps = 0;
            int i = 1;
            for (i = 1; length > 0; i++) {
                length -= i * 2;
                if (length < 0) {
                    length += i;
                    if (length < 0) {
                        length += i;
                    } else if (length == 0) {
                        steps++;
                    } else {
                        steps++;
                    }
                    break;
                } else {
                    steps += 2;
                }
            }
            if (length > 0)
                steps++;
            System.out.println(steps);
        }
    }
}