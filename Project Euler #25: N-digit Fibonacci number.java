import java.io.*;
import java.util.*;
public class Solution {

    public static int getNthFibTermLength(int n){
    //binet formula can be used to gen nth fib term. Here we are modifying it to get nth
    // fib term's length 
    double d = (n * Math.log10(1.6180339887498948)) - 
                   ((Math.log10(5)) / 2); 
      
     return (int)Math.ceil(d);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int  n = sc.nextInt();
            int termCount = 1, currentLength = 1;
            while(currentLength != n){
                currentLength = getNthFibTermLength(termCount);
                termCount++;
            }
            System.out.println(termCount - 1);
        }
    }
}

