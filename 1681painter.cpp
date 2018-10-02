#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 99999999;
int MIN=INF, N, puzzle[23][23], press[23][23];

int calc(){
    int count = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            count += press[i][j];
        }
    }
    return count;
}

int check(){
    for(int i=2; i<=N; i++){
        for(int j=1; j<=N; j++){
            press[i][j] = (puzzle[i-1][j] + press[i-1][j] + press[i-1][j-1]
                           + press[i-1][j+1] + press[i-2][j]) %2;
        }
    }
    for(int j=1; j<=N; j++){
        if((puzzle[N][j]+press[N][j-1]+press[N][j]+press[N][j+1]+press[N-1][j])%2!=0)
            return INF;
    }
    return calc();
}

void enumerate(){
    int count = 0;
    MIN = INF;
    for(int i=0; i<pow(2, N); i++){
        int d = 1;
        while(press[1][d]>1){
            press[1][d] = 0;
            d++;
            press[1][d]++;
        }
        count = check();
        MIN = min(count, MIN);
        press[1][1]++;
    }
    if(MIN==INF)
        cout<<"inf"<<endl;
    else
        cout<<MIN<<endl;
}

int main(){
    int cases;
    char t;  //'y': 0 , 'w' : 1
    cin>>cases;
    for(int ca=0; ca<cases; ca++){
        cin>>N;
        memset(puzzle, 0, sizeof(puzzle));
        memset(press, 0, sizeof(press));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin>>t;
                if(t=='w') puzzle[i][j]=1;
            }
        }
        enumerate();
    }
}