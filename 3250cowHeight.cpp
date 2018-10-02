#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 80005;

//Note: scanf&printf is x10 faster than cin&cout

typedef unsigned long ll;
//first: index
//second: height
typedef pair<int, ll> cow;
int main(){
	cow stack[MAX];
	int N, top=-1;
	ll ans = 0, t;
	scanf('%d', &N);
	for(int i=1; i<=N; i++){
		scanf('%u', &t);
		while(top>=0 && t>=stack[top].second){
			ans+=(i-stack[top].first-1);
			top--;
		}
		top++;
		stack[top]=cow(i, t);
	}
	//those left in stack have no taller cows on the right
	while(top>=0){
		ans+=(N+1-stack[top].first-1);
		top--;
	}
	printf('%u\n', ans);
}