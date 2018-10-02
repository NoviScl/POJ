#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

//x: row , y :column

const int INF = 99999999;
int nums[9][9], sums[9][9];

int dpTable[15][9][9][9][9];

//quick way to get sums matrix
void input(){
    for(int i=1; i<=8; i++){
        for(int j=1, rowSum=0; j<=8; j++){
            cin>>nums[i][j];
            rowSum+=nums[i][j];
            sums[i][j]=sums[i-1][j]+rowSum;
        }
    }
}

//quick way to calculate sum of matrix
int calSum(int x1, int y1, int x2, int y2){
    return sums[x2][y2] - sums[x2][y1-1] - sums[x1-1][y2] + sums[x1-1][y1-1];
}


int dp(int n, int x1, int y1, int x2, int y2){
    if(dpTable[n][x1][y1][x2][y2]!=-1)
        return dpTable[n][x1][y1][x2][y2];
    if(n==1){
        int s = calSum(x1, y1, x2, y2);
        int res = s*s;
        dpTable[1][x1][y1][x2][y2]=res;
        return res;
    }
    
    int MIN = INF;
    //iterate row
    for(int i=x1; i<=x2-1; i++){
        MIN = min(MIN, dp(n-1, x1, y1, i, y2)+dp(1, i+1, y1, x2, y2));
        MIN = min(MIN, dp(1, x1, y1, i, y2)+dp(n-1, i+1, y1, x2, y2));
    }
    //iterate column
    for(int i=y1; i<=y2-1; i++){
        MIN = min(MIN, dp(n-1, x1, y1, x2, i)+dp(1, x1, i+1, x2, y2));
        MIN = min(MIN, dp(1, x1, y1, x2, i)+dp(n-1, x1, i+1, x2, y2));
    }
    dpTable[n][x1][y1][x2][y2]=MIN;
    return MIN;
}

int main(){
    int n, res;
    cin>>n;
    memset(sums, 0, sizeof(sums));
    memset(dpTable, -1, sizeof(dpTable));
    
    input();
    res=dp(n, 1, 1, 8, 8);
    cout<<fixed<<setprecision(3)<<sqrt((n*res-sums[8][8]*sums[8][8])/double(n*n))<<endl;
}









