#include <iostream>
#include <algorithm>
using namespace std;

int row, col, n;

struct plant{
    int x, y;
};

plant plants[5005];

//reload < operator
//how you sort suggests the direction used
//here top to bottom
bool operator < (plant a, plant b){
    if(a.x == b.x)
        //doesn't matter > or <
        //but must specify because binary search needs it
        return a.y < b.y;
    return a.x < b.x;
}

int searchPath(plant secPoint, int dx, int dy){
    int steps = 2;
    int px = secPoint.x + dx, py = secPoint.y + dy;
    while(px<=row && py>=1 && py<=col){
        if(!binary_search(plants, plants+n, plant{px, py})){
            return 0;
        }
        steps++;
        px += dx;
        py += dy;
    }
    return steps;
}

int main(){
    cin>>row>>col>>n;
    //x: row no., y: col no.
    //step means #plants on the way
    int dx, dy, px, py, MAXSTEP=2, steps;
    for(int i=0; i<n; i++){
        cin>>plants[i].x>>plants[i].y;
    }
    sort(plants, plants+n);
    //need at least three points to form a path!
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            dx = plants[j].x - plants[i].x;
            dy = plants[j].y - plants[i].y;
            
            //check the first point's previous step
            px = plants[i].x - dx;
            py = plants[i].y - dy;
            
            //not outside the field, choose another second point
            if(px>=1 && px<=row && py>=1 && py<=col)
                continue;
            
            //first point's x too big
            //if no improvement possible, just cut it
            //next secPoint will have even bigger dx
            if(plants[i].x + MAXSTEP*dx > row)
                break;
            
            py = plants[i].y + MAXSTEP*dy;
            if(py<1 || py>col)
                continue;
            
            steps = searchPath(plants[j], dx, dy);
            MAXSTEP = max(steps, MAXSTEP);
            //if(steps>0) MAXSTEP = steps;
        }
    }
    if(MAXSTEP==2)
        MAXSTEP = 0;
    cout<<MAXSTEP<<endl;
}












