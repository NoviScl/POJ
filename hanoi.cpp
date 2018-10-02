#include <iostream>
#include <stack>
using namespace std;

// void hanoi(int n, char src, char mid, char dest){
// 	if(n==1)
// 		cout<<src<<"->"<<dest<<endl;
// 	else{
// 		hanoi(n-1, src, dest, mid);
// 		cout<<src<<"->"<<dest<<endl;
// 		hanoi(n-1, mid, src, dest);
// 	}
// }

// int main(){
// 	int n;
// 	cin>>n;
// 	hanoi(n, 'A', 'B', 'C');
// }

struct problem{
    int n;
    char src, mid, dest;
    problem(int _n, char s, char m, char d): n(_n), src(s), mid(m), dest(d) {}
};

stack<problem> stk;

int main(){
    int n;
    cin>>n;
    stk.push(problem(n, 'A', 'B', 'C'));
    while(!stk.empty()){
        problem cur = stk.top();
        stk.pop();
        if(cur.n == 1){
            cout<<cur.src<<"->"<<cur.dest<<endl;
        }
        else{
            stk.push(problem(cur.n-1, cur.mid, cur.src, cur.dest));
            stk.push(problem(1, cur.src, cur.mid, cur.dest));
            stk.push(problem(cur.n-1, cur.src, cur.dest, cur.mid));
        }
    }
}




