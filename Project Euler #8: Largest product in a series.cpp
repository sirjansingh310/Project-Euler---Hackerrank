#include<bits/stdc++.h>
using namespace std;
// can be solved in O(n) time using divide by s[i - 1] digit and multiply by s[i + k -1] digit. But we need to handle cases where the current substring of size k contains a zero.
// O(n*k) solution here, since K is small ( < 7). It will as fast as O(n) sol and we need not handle edge cases.
long long largestProduct(string s, int k ){
    long long pro, maxPro;

    for(int i = 0; i < s.size() - k; i++){
        pro = (long long)1;
        for(int j = i; j < i + k; j++){
            pro *= (s[j] - 48);
        }
        maxPro = max(pro, maxPro);
    }
    return maxPro;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << largestProduct(s, k) << endl;
    }
    return 0;
}
