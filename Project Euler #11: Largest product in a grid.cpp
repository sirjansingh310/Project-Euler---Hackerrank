#include<bits/stdc++.h>
using namespace std;

int findProduct(int i, int j, int grid[][20]){
    int pro = 1;
    if(j + 3 < 20)
        pro = max(pro, grid[i][j] * grid[i][j + 1] * grid[i][j+2] * grid[i][j + 3]);

    if(i + 3 < 20)
        pro = max(pro, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
    
    if(i - 3 >= 0)
        pro = max(pro, grid[i][j] * grid[i -1][j] * grid[i - 2][j] * grid[i - 3][j]);

    if(j - 3 >= 20)
        pro = max(pro, grid[i][j] * grid[i][j - 1] * grid[i][j - 2] * grid[i][j - 3]);
    
    if(i + 3 < 20 && j + 3 < 20)
        pro = max(pro, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);

    if(i - 3 >= 0 && j - 3 >= 0)
        pro = max(pro, grid[i][j] * grid[i - 1][j - 1] * grid[i - 2][j - 2] * grid[i - 3][j - 3]);
    
    if(i + 3 < 20 && j - 3 >= 0)
        pro = max(pro, grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3]);

    if(i - 3 >= 0 && j + 3 < 20)
        pro = max(pro, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
    return pro;

}

int main(){
    int grid[20][20];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cin >> grid[i][j];
        }
    }
    int maxPro = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            maxPro = max(maxPro, findProduct(i, j, grid));
        }
    }

    cout << maxPro << endl;
    return 0;
}
