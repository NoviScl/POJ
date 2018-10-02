#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 9999999;
int init_clocks[10]; //don't use clocks[0]
int ops[9][5] = {{1,2,4,5},{1,2,3},{2,3,5,6},
    {1,4,7},{2,4,5,6,8},{3,6,9},
    {4,5,7,8},{7,8,9},{5,6,8,9}};
int states[9], best[9]={0};


void copy_array(int a[], int b[], int L){
    for(int i=0; i<L; i++){
        b[i] = a[i];
    }
}

int sum_array(){
    int count = 0;
    for(int i=0; i<9; i++){
        count += states[i];
    }
    return count;
}

int check(){
    int clocks[10];
    copy_array(init_clocks, clocks, 10);
    for(int i=0; i<9; i++){
        for(int j=0; j<5; j++){
            clocks[ops[i][j]] = (clocks[ops[i][j]] + states[i])%4;
        }
    }
  
    for(int i=1; i<=9; i++){
        if(clocks[i]!=0)
            return INF;
    }
    return sum_array();
}


//states: how many times to do each operation
int main(){
    int MIN = INF;
   
    for(int i=1; i<=9; i++){
        cin>>init_clocks[i];
    }
    memset(states, 0, sizeof(states));
    for(int i=0; i<pow(4,9); i++){
        int d = 0;
        while(states[d]>=4){
            states[d]=0;
            d++;
            states[d]++;
        }
        int res = check();
        if(res < MIN)
        {
            MIN = res;
            //cout<<MIN<<endl;
            copy_array(states, best, 9);
        }
        states[0]++;
    }
   
    for(int i=0; i<9; i++){
        for(int j=0; j<best[i]; j++)
            cout<<(i+1)<<' ';
    }
    
}




