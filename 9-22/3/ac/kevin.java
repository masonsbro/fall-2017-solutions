import java.io.*;
import java.util.*;

public class Solution {
    
    static char[][] maze;
    static int energy, cowX, cowY;
    static int[] costs = new int[4];
    
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    
    static void readInput() {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        maze = new char[m][n];
        
        for (int i = 0; i < m; i++) {
            String line = in.next();
            for (int j = 0; j < line.length(); j++) {
                char c = line.charAt(j);
                maze[i][j] = c;
                
                if (c == 'C') {
                    cowX = j;
                    cowY = i;
                }
            }
        }
        
        energy = in.nextInt();
        
        for (int i = 0; i < 4; i++) {
            costs[i] = in.nextInt();
        }
    }

    public static void main(String[] args) {
        readInput();
        
        int x = cowX;
        int y = cowY;
        int lastX = -1;
        int lastY = -1;
        boolean escaped = false;
        while (!escaped) {
            for (int i = 0; i < 4; i++) {
                if (maze[y][x] == 'E') {
                    System.out.println(energy < 0 ? -1 : energy);
                    escaped = true;
                    break;
                }
                
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (newX < 0 || newX >= maze[0].length || newY < 0 || newY >= maze.length
                    || (newX == lastX && newY == lastY)) {
                    continue;
                }
                
                if (maze[newY][newX] != 'X') {
                    lastX = x;
                    lastY = y;
                    x = newX;
                    y = newY;
                                        
                    energy -= costs[i];
                }
            }
        }
    }
}
