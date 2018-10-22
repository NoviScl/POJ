#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	//using scanf to read a string is very tricky
	//so use cin instead
	string a, b;
	while(cin>>a>>b){
		size_t l_a = a.length(), l_b = b.length();
		// initialized to be all 0s
		vector< vector<int> > dp(l_a+1, vector<int> (l_b+1, 0));
		for(int i=1; i<=l_a; i++){
			for(int j=1; j<=l_b; j++){
				if(a[i-1]==b[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<dp[l_a][l_b]<<endl;
	}
}


