#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF = 9999999;

int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}}, MIN, wid, ht;
char board[78][78];
bool visited[78][78];

bool check(int x, int y, int x2, int y2){
    bool T1 = (x>=0 && x<=wid+1 && y>=0 && y<=ht+1);
    bool T2 = (!visited[y][x]);
    bool T3 = (board[y][x]==' ');
    bool T4 = (x==x2 && y==y2);
    if(T1 && T2 && (T3||T4))
        return true;
    else return false;
}

void DFS(int x1, int y1, int x2, int y2, int steps, int dir){
    int new_x1, new_y1;
    if(steps>=MIN) return;
    if(x1==x2 && y1==y2 && board[y2][x2]=='X'){
        MIN = steps;
        return;
    }
    
    visited[y1][x1]=true;
    for(int d=0; d<4; d++){
        new_x1 = x1 + dirs[d][0];
        new_y1 = y1 + dirs[d][1];
        
        if(check(new_x1, new_y1, x2, y2)){
            if(d==dir)
                DFS(new_x1, new_y1, x2, y2, steps, d);
            else
                DFS(new_x1, new_y1, x2, y2, steps+1, d);
        }
    }
    visited[y1][x1]=false;
}

int main(){
    //x: horizontal, y: vertical
    int boardnum=0, x1, y1, x2, y2, pair;
    while(true){
        cin>>wid>>ht;
        if(wid==0) break;
        
        //new board
        boardnum++;
        cout<<"Board #"<<boardnum<<':'<<endl;
        memset(board, ' ', sizeof(board));
        memset(visited, 0, sizeof(visited));
        
        //pad around the board with ' '
        for(int i=1; i<=ht; i++){
            getchar(); //read '\n'
            for(int j=1; j<=wid; j++){
                board[i][j]=getchar();
            }
        }
        
        pair=0;
        while(true){
            cin>>x1>>y1>>x2>>y2;
            if(x1==0) break;
            
            pair++;
            MIN=INF;
            DFS(x1, y1, x2, y2, 0, -1);
            cout<<"Pair "<<pair<<": ";
            if(MIN<INF)
                cout<<MIN<<" segments."<<endl;
            else
                cout<<"impossible."<<endl;
        }
        cout<<endl;
    }
}




