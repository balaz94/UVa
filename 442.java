import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Matrix> matrix;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        matrix = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char id = sc.next().charAt(0);
            int r = sc.nextInt();
            int c = sc.nextInt();
            matrix.add(new Matrix(r, c, 0, id));
        }

        while (sc.hasNext()) {
            String s = sc.next();
            Matrix m;
            if (s.contains("("))
                m = getResult(s.substring(s.indexOf('(') + 1, s.lastIndexOf(')')));
            else 
                m = new Matrix(0, 0, 0, '0');
            if (m.m == -1) {
                System.out.println("error");
            } else {
                System.out.println(m.m);
            }
        }
    }

    static Matrix getResult(String s) {
        if (!s.contains("(")) {
            Matrix m1 = getMatrix(s.substring(0, 1));
            Matrix m2 = getMatrix(s.substring(1));
            if (m1.c == m2.r) {
                return new Matrix(m1.r, m2.c, m1.r * m2.c * m1.c, '0');
            } else {
                return new Matrix(0, 0, -1, '0');
            }
        }
        int iS = -1, iF = -1, poc = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                poc++;
            } else if (s.charAt(i) == ')') {
                if (poc == 0 && iF == -1)
                    iF = i;
                poc--;
            }
            if (poc == 0 && iS == -1)
                iS = i;
        }
        Matrix m1, m2;
        if (iS == 0) {
            m1 = getMatrix(s.substring(iS + 1, iF));
            String s2 = s.substring(iF + 1);
            if (s2.charAt(0) == '(' && s2.charAt(s2.length() - 1) == ')')
                s2 = s2.substring(1, s2.length() - 1);
            m2 = getMatrix(s2);
        } else {
            String s1 = s.substring(0, iS);
            if (s1.charAt(0) == '(' && s1.charAt(iS - 1) == ')')
                s1 = s1.substring(1, iS - 1);
            m1 = getMatrix(s1);
            m2 = getMatrix(s.substring(iS + 1, iF));
        } 
        if (m1.c != m2.r || m1.m == -1 || m2.m == -1)
            return new Matrix(0, 0, -1, '0');
        return new Matrix(m1.r, m2.c, m1.r * m2.c * m1.c + m1.m + m2.m, '0');
    }
    
    static Matrix getMatrix(String s) {
        if (s.length() == 1) 
            return matrix.get(getIndex(s.charAt(0)));
        return getResult(s);
    }
    
    static int getIndex(char id) {
        for (int i = 0; i < matrix.size(); i++)
            if (matrix.get(i).id == id)
                return i;
        return -1;
    }
    
    public static class Matrix {
        private int r, c, m;
        char id;

        public Matrix(int r, int c, int m, char id) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.id = id;
        }
    }
}