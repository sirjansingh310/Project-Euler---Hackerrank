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


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long long res = 0 ;
        long t1 = 0, t2 = 2, t3;
        while(1){
            res += t2;
            t3 = 4 * t2 + t1;
            t1 = t2;
            t2 = t3;
            if( t2 >= n)
                break;
        }
        cout << res << endl;
    }
    return 0;
}
