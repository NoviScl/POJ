#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 1000;
#define INF 9999999;

int t, n, x, y, maxHeight;
struct platform{
	int Lx, Rx, h;
	bool operator < (const platform &p2) const{
		return h > p2.h;
	}
};

platform plats[MAX_N + 10];
int leftMinTime[MAX_N + 10];
int rightMinTime[MAX_N + 10];
int L[MAX_N + 10]; // rightMinTime

// bLeft true: go from left
//false: go from right
int MinTime(int l, bool bLeft){
	int y = plats[l].h;
	int x;
	if(bLeft)
		x = plats[l].Lx;
	else
		x = plats[l].Rx;
	int i;

	// find the next board below
	for(i=l+1; i<=n; i++){
		if(plats[i].Lx <= x && plats[i].Rx >= x)
			break;
	}
	if(i<=n){
		if(y - plats[i].h > maxHeight)
			return INF;
	}
	// not board below
	else{
		if(y > maxHeight)
			return INF;
		else
			return y;
	}

	int nLeftTime = y - plats[i].h + x - plats[i].Lx;
	int nRightTime = y - plats[i].h + plats[i].Rx - x;
	if(leftMinTime==-1)
		leftMinTime[i] = MinTime(i, true);
	if(L[i]==-1)
		L[i] = MinTime(i, false);
	nLeftTime += leftMinTime[i];
	nRightTime += L[i];
	if (nLeftTime < nRightTime)
		return nLeftTime;
	return nRightTime;
}


int main(){
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		memset(leftMinTime, -1, sizeof(leftMinTime));
		memset(L, -1, sizeof(rightMinTime));
		scanf("%d%d%d%d", &n)
		plats[0].Lx = x;
		plats[0].Rx = x;
		plats[0].h = y;
		for(int j=1; j<=n; j++){
			scanf
		}
		sort(plats, plats+n+1);

	}
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 10000;
#define INF = 9999999;

int t, n, x, y, maxHeight;
struct platform{
	int Lx, Rx, h;
	bool operator < (const platform &p2) const{
		return h > p2.h;
	}
};

platform plats[MAX_N + 10];
int leftMinTime[MAX_N + 10];
int rightMinTime[MAX_N + 10];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf()
		plats[0].Lx = x;
		plats[0].Rx = x;
		plats[0].h = y;
		for(int j=1; j<=n; j++){
			scanf("%d%d%d", &plats[j].Lx, &plats[j].Rx, &plats[j].h);
		}
		sort(plats, plats+n+1);
		// from the lowest board to the highest
		for(int i=n; i>=0; --i){
			int j;
			// find the board below left
			for(j=i+1; j<=n; ++j){
				if(plats[i].Lx <= plats[j].Rx && plats[i].Lx >= plats[j].Lx)
					break;
			}
			// not board below left
			if(j>n){
				if(plats[i].h > maxHeight)
					leftMinTime[i] = INF;
				else
					leftMinTime[i] = plats[i].h;
			}
			else{
				int y = plats[i].h - plats[j].h;
				if(y > maxHeight)
					leftMinTime[i] = INF;
				else
					leftMinTime[i] = y + min(leftMinTime[j] + plats[i].Lx - plats[j].Lx,
						rightMinTime[j] + plats[j].Rx - plats[i].Lx);
			}
			// find the board below right
			for(j = i+1; j<=n; ++j){
				if(plats[i].Rx <= plats[j].Rx && plats[i].Rx>=plats[j].Lx)
					break;
			}
			if(j>n){
				if(plats[i].h > maxHeight)
					rightMinTime[i] = INF;
				else
					rightMinTime[i] = plats[i].h;
			}
			else{
				int y = plats[i].h - plats[j].h;
				if(y > maxHeight)
					rightMinTime[i] = INF;
				else
					rightMinTime[i] = y + min(leftMinTime[j] + plats[i].Rx - plats[j].Lx,
						rightMinTime[j]+plats[j].Rx - plats[i].Rx);
			}
		}
	}
}






































