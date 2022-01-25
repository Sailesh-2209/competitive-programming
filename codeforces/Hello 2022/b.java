import java.util.*;
import java.lang.*;
import java.io.*;

public class b {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            test_case(n);
        }
    }
    public static void test_case(int n) {
        int max = Integer.MAX_VALUE;
        int minL = max, costL = max;
        int maxR = 0, costR = max;
        int maxLen = 0, costLen = max;
        PrintWriter writer = new PrintWriter(System.out);
        for (int i = 0; i < n; i++) {
            int l = scanner.nextInt(), r = scanner.nextInt(), c = scanner.nextInt();

            if (l < minL) {
                minL = l; costL = max;
            }
            if (l == minL) 
                costL = Math.min(costL, c);

            if (r > maxR) {
                maxR = r; costR = max;
            }
            if (r == maxR)
                costR = Math.min(costR, c);

            if (maxLen < r - l + 1) {
                maxLen = r - l + 1; costLen = max;
            }
            if (maxLen == r - l + 1)
                costLen = Math.min(costLen, c);

            int ans = costR + costL;
            if (maxLen == maxR - minL + 1)
                ans = Math.min(ans, costLen);
            writer.printf("%d\n", ans);
        }
        writer.close();
    }
}
