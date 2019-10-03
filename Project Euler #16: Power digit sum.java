import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int sum = 0;
            
            BigInteger num = new BigInteger("2");
            BigInteger numPowerN = num.pow(n);
            String str = numPowerN.toString();

            for(int i = 0 ; i < str.length(); i++){
                sum += str.charAt(i) - 48;
            }

            System.out.println(sum);
        }
    }
}

