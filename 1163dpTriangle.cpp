#include <iostream>
#include <algorithm>
using namespace std;

int N, triangle[101][101], dp[101][101];
int MaxSum(int r, int c){
	if(dp[r][c]!=-1)
		return dp[r][c];
	if(r==N)
		dp[r][c] = triangle[r][c];
	else
		dp[r][c] = max(MaxSum(r+1, c), MaxSum(r+1, c+1)) + triangle[r][c];
	return dp[r][c];
}

int main(){
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			cin>>triangle[i][j];
			// dp[i][j]=-1;
		}
	}
	// cout<<MaxSum(1, 1)<<endl;
	for(int i=N-1; i>=1; i--){
		for(int j=1; j<=i; j++){
			triangle[N][j]=max(triangle[N][j], triangle[N][j+1]) + triangle[i][j];
		}
	}
	cout<<triangle[N][1]<<endl;
}