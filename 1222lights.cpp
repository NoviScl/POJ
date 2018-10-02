#include <iostream>
#include <cstring>
using namespace std;

const int row = 5, col = 6;
int puzzle[row+1][col+2], press[row+1][col+2];

bool check(){
    //first infer all presses
    for(int r=2; r<=row; r++){
        for(int c=1; c<=col; c++){
            press[r][c] = (puzzle[r-1][c] + press[r-1][c-1] + press[r-1][c]
                           + press[r-1][c+1] + press[r-2][c])%2;
        }
    }
    
    //then check the last row
    for(int c=1; c<=col; c++){
        if((puzzle[row][c] + press[row][c] + press[row][c-1] + press[row][c+1]
            + press[row-1][c])%2 == 1)
            return false;
    }
    
    return true;
}

void output(){
    for(int r=1; r<=row; r++){
        for(int c=1; c<=col; c++){
            cout<<press[r][c]<<' ';
        }
        cout<<endl;
    }
}

void enumerate(){
    int c;
    while(check()==false){
        c = 1;
        press[1][c]++;
        //simulate binary adding
        while(press[1][c]>1){
            press[1][c]=0;
            c++;
            press[1][c]++;
        }
    }
    output();
}

int main(){
    int cases;
    cin>>cases;
    for(int ca=0; ca<cases; ca++){
        memset(puzzle, 0, sizeof(puzzle));
        memset(press, 0, sizeof(press));
        for(int r=1; r<=row; r++){
            for(int c=1; c<=col; c++){
                cin>>puzzle[r][c];
            }
        }
        
        cout<<"PUZZLE #"<<ca+1<<endl;
        enumerate();
    }
}





