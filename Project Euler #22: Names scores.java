import java.io.*;
import java.util.*;

public class Solution {
    public static void printScore(HashMap<String, Integer> positionMap, String str){
        int index = positionMap.get(str);

        int score = 0;
        for(int i = 0; i < str.length(); i++){
            score += str.charAt(i) - 'A' + 1;
        }

        score *= index;

        System.out.println(score);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String names[] = new String[n];

        for(int i = 0; i < n; i++)
            names[i] = scanner.next();
        
        Arrays.sort(names);
        HashMap<String, Integer> positionMap = new HashMap<>();
       
        for(int i = 1; i <= names.length; i++){
            positionMap.put(names[i - 1], i);
        }

        int q = scanner.nextInt();
        scanner.nextLine();
        while(q-- > 0){
            String queryString = scanner.next();
            printScore(positionMap,queryString);
        }

    }
}
