import java.util.*;
import java.lang.*;

public class a {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            test_case(n, k);
        }
    }
    public static void test_case(int n, int k) {
        if ((2 * k - 1) > n)
            System.out.println("-1");
        else {
            int prev = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == prev && j == prev && k > 0) {
                        System.out.printf("R");
                        prev += 2;
                        k--;
                    } else {
                        System.out.printf(".");
                    }
                }
                System.out.println();
            }
        }
    }
}
