#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 100005;

typedef pair<int, ll> rect;
//build an increasing stack
void max_rect(int N){
    ll h, temp_area, max_area=0;
    rect t;
    stack<rect> stk;
    for(int i=0; i<N; i++){
        scanf("%lld", &h);
        t = rect(i, h);
        //met right limit of rect
        while(!stk.empty() && stk.top().second >= h){
            t = stk.top();
            stk.pop();
            
            temp_area = (i - t.first)*t.second;
            max_area = max(temp_area, max_area);
        }
        //t.first: left limit to extend
        stk.push(rect(t.first, h));
    }
    while(!stk.empty()){
        t = stk.top();
        stk.pop();
        temp_area = (N - t.first)*t.second;
        max_area = max(temp_area, max_area);
    }
    printf("%lld\n", max_area);
}

int main(){
    int N;
    while(scanf("%d", &N) && N){
        max_rect(N);
    }
}





