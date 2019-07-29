#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPalindrome(int pro){
  string s = to_string(pro);
  if(s.size() != 6)
    return false;
  for(int i = 0; i <= s.size()/2; i++){
      if(s[i] != s[s.size() - i - 1])
        return false;
  }
  return true;
}
int main(){
    int t;
    cin >> t;
    // generate all palindromes before all t test cases and save time!
    int allPalindromes[1000001] = {0};
    for(int i = 100; i <= 999; i++){
        for(int j = 100; j <= 999; j++){
            int pro = i * j;
            if(isPalindrome(pro))
            {
                allPalindromes[pro] = 1;
            }
        }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int palindrome = 101101;
        for(int i = n-1; i >= 101101; i--){
            if(allPalindromes[i]){
                palindrome = i;
                break;
            }
        }
        cout << palindrome << endl;
    }
    return 0;
}
