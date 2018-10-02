#include <iostream>
#include <list>
#include <deque>
using namespace std;

struct pt{
    int pos, pri;
};

// int main(){
//     int cases, n, p, pr, time;
//     cin>>cases;
//     for(int c=0; c<cases; c++){
//         list<pt> L;
//         cin>>n>>p;
//         time = 1;
//         for(int i=0; i<n; i++){
//             cin>>pr;
//             L.push_back(pt{i, pr});
//         }
//         while(true){
//             list<pt>::iterator it = L.begin();
//             bool flag=true;
//             while(it!=L.end()){
//                 if(it->pri > L.front().pri){
//                     L.push_back(L.front());
//                     L.pop_front();
//                     flag = false;
//                     break;
//                 }
//                 it++;
//             }
//             if(flag){
//                 if(L.front().pos == p)
//                     break;
//                 L.pop_front();
//                 time++;
//             }
//         }
//         cout<<time<<endl;
//     }
// }



int main(){
    int cases, n, p, pr, time;
    cin>>cases;
    for(int c=0; c<cases; c++){
        deque<pt> L;
        cin>>n>>p;
        time = 1;
        for(int i=0; i<n; i++){
            cin>>pr;
            L.push_back(pt{i, pr});
        }
        while(true){
        	//can use index for deque as well
            deque<pt>::iterator it = L.begin(); 
            bool flag=true;
            while(it!=L.end()){
                if(it->pri > L.front().pri){
                    L.push_back(L.front());
                    L.pop_front();
                    flag = false;
                    break;
                }
                it++;
            }
            if(flag){
                if(L.front().pos == p)
                    break;
                L.pop_front();
                time++;
            }
        }
        cout<<time<<endl;
    }
}



