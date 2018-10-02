#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cases=1, idx=0;
vector<string> docs;

void print_space(int d){
    for(int i=0; i<d; i++){
        cout<<"|     ";
    }
}

void print_docs(){
    for(int i=0; i<docs.size(); i++){
        cout<<docs[i]<<' ';
    }
    cout<<endl;
}

void print_map(int depth){
    vector<string> files;
    while(idx<docs.size()){
        if(docs[idx][0]=='f'){
            files.push_back(docs[idx]);
            idx++;
        }
        else if(docs[idx][0]=='d'){
            print_space(depth+1);
            cout<<docs[idx]<<endl;
            idx++;
            print_map(depth+1);
        }
        else 
        	break; //']'
    }
    //the outer most layer
    sort(files.begin(), files.end());
    for(int i=0; i<files.size(); i++){
        print_space(depth);
        cout<<files[i]<<endl;
    }
    idx++;
}

int main(){
    string cur;
    while(true){
        cin>>cur;
        if(cur=="#") break;
        else if(cur=="*"){
            cout<<"DATA SET "<<cases<<':'<<endl;
            cout<<"ROOT"<<endl;
            print_map(0);
            docs.clear();
            idx=0;
            cases++;
            cout<<endl;
        }
        else docs.push_back(cur);
    }
}