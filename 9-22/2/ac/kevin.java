import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        HashSet<String> colors = new HashSet<>();
        int count = 0;
        for (int i = 0; i < n; i++) {
            String color = in.nextLine().split(" ")[1];
            if (!colors.add(color)) {
                count++;
            }
        }
        
        System.out.println(count);
    }
}
