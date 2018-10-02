#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int dp[31], n;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	dp[2]=3;
	while(true){
		cin>>n;
		if(n==-1) break;
		if(n%2==1)
			cout<<0<<endl;
		else if(dp[n]!=0)
			cout<<dp[n]<<endl;
		else{
			for(int i=4; i<=n; i++){
				dp[i] = 4*dp[i-2] - dp[i-4];
			}
			cout<<dp[n]<<endl;
		}
	}
}
