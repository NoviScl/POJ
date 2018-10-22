#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

// height, index
// using STL stack is too slow 
// because I am using stack very frequently here
// and that's slower than a array/vector
typedef pair<int, int> block;
const int M = 2005, N = 2005;
int mat[M][N], blocks[M][N], m, n;

int get_max(){
	int max_area = 0;
	block t;
	// convert to 2D histogram
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &mat[i][j]);
			if(mat[i][j]==0)
				blocks[i][j]=0;
			else
				blocks[i][j]=blocks[i-1][j]+1;
		}
	}
	for(int i=1; i<=m; i++){
		block S[N];
		int top = -1;
		for(int j=1; j<=n; j++){
			t = block(blocks[i][j], j);
			while(top>=0 && S[top].first>=blocks[i][j]){
				t = S[top];
				top--;
				max_area=max(max_area, (j-t.second)*t.first);
			}
			top++;
			S[top]=(block(blocks[i][j], t.second));
		}
		while(top>=0){
			t = S[top];
			top--;
			max_area = max(max_area, (n+1-t.second)*t.first);
		}
	}
	return max_area;
}

int main(){
	while(~scanf("%d %d", &m, &n)){
		memset(mat, 0, sizeof(mat));
		memset(blocks, 0, sizeof(blocks));
		printf("%d\n", get_max());
	}
}

