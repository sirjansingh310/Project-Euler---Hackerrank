import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        BigInteger sum = new BigInteger("0");
        BigInteger temp;

        for(int i = 0; i < n; i++){
            temp = new BigInteger(sc.nextLine());
            sum = sum.add(temp);
        }

       System.out.println(sum.toString().substring(0 , 10));
    }
}

