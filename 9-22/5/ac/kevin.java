import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        
        long count = 0;
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        
        System.out.println(count);
    }
}
