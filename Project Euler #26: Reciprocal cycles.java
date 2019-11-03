import java.io.*;
import java.util.*;
// https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
public class Solution {

    public static boolean isPrime[] = new boolean[10000];
    
    public static void generatePrimes(){
        for(int i = 0 ; i < 10000; i++)
             isPrime[i] = true;

        for(int p = 2; p * p < 10000; p++){
            if(isPrime[p]){
                for(int i = p * p; i < 10000; i += p){
                    isPrime[i] = false;
                }
            }
        }
    }
    public static int findRecurLength(int denominator){
        Map<Integer, Integer> storedRemainders = new HashMap<>();
        int remainder = 1 % denominator;
        int recurLength = 0;
        String result = "";
        // calculating the part after . in decimal format
        while(remainder != 0){
            if(storedRemainders.containsKey(remainder)){
                recurLength = result.length() - storedRemainders.get(remainder);
                break;
            }
            storedRemainders.put(remainder, result.length());
            // same as how we do division using pen and paper. 
            remainder = remainder * 10;
            result += (remainder / denominator);
            remainder = remainder % denominator;
        }
        return recurLength;
    }
    public static void main(String[] args) {
        int recurLengths[] = new int[10000];
        generatePrimes();
        for(int d = 2; d < 10000; d++){
            if(isPrime[d]) // check only for primes. Skip for rest. Primes have more number of recuring numbers. 
            recurLengths[d] = findRecurLength(d);
        }

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int result = 0, maxLength = 0;
            for(int i = 1; i < n; i++){
                if(recurLengths[i] > maxLength){
                    maxLength = recurLengths[i];
                    result = i;
                }
            }
            System.out.println(result);
        }
     }
    }

