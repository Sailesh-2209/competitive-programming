import java.util.*;
import java.lang.*;

public class a {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int result = test_case();
            sb.append(result).append("\n");
        }
        System.out.println(sb.toString());
    }
    public static int test_case() {
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) 
            arr[i] = scanner.nextInt();
        int[] counts = new int[101];
        for (int i = 0; i < n; i++) {
            counts[Math.abs(arr[i])]++;
        }
        int result = Math.min(1, counts[0]);
        for (int i = 1; i < 101; i++) {
            result += Math.min(2, counts[i]);
        }
        return result;
    }
}
