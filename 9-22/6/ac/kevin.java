import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int numBabies = in.nextInt();
            int k = in.nextInt();
            int[] values = new int[numBabies];
            
            for (int j = 0; j < numBabies; j++) {
                values[j] = in.nextInt();
            }
            
            int[] dp = new int[numBabies];
            dp[0] = values[0];
            int max = 0;
            for (int j = 1; j < k; j++) {
                dp[j] = Math.max(values[j], dp[j - 1]);
                max = Math.max(max, dp[j]);
            }
            
            for (int j = k; j < dp.length; j++) {
                dp[j] = Math.max(values[j] + dp[j - k], dp[j - 1]);
                max = Math.max(max, dp[j]);
            }
            
            System.out.println(max);
        }
    }
}
