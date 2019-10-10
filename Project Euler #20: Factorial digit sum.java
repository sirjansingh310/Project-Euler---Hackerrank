import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Solution {
public static BigInteger fact[] = new BigInteger[1001];
    public static void findFacts(){
        fact[0] = new BigInteger("1");
        fact[1] = new BigInteger("1");

        for(int i = 2 ; i <= 1000; i++){
            fact[i] = new BigInteger(Integer.toString(i));
            fact[i] = fact[i].multiply(fact[i - 1]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        findFacts();
        while(t-- > 0){
            int n = scanner.nextInt();
            long sum = 0L;
            String str = fact[n].toString();
            for(int i = 0; i < str.length(); i++){
                sum += (str.charAt(i) - 48);
            }

            System.out.println(sum);
        }
    }
}


