import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        
        for (int i = 0; i < n; i++) {
            int numLines = in.nextInt();
            int l = in.nextInt();
            
            HashMap<String, Integer> map = new HashMap<>();
            ArrayList<String> winners = new ArrayList<>();
            
            for (int j = 0; j < numLines; j++) {
                String name = in.next();
                map.put(name, map.getOrDefault(name, 0) + 1);
                if (map.get(name) == l) {
                    winners.add(name);
                }
            }
            
            if (winners.size() < 2) {
                System.out.println("Armageddon");
            } else {
                System.out.println(String.format("%s\n%s", winners.get(0), winners.get(1)));
            }
        }
    }
}
