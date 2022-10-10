#include<iostream>
#include<sstream>
using namespace std;
int parent[100002];
int find_parent(int ind){
    if(parent[ind]==ind){
        return ind;
    }
    parent[ind]=find_parent(parent[ind]);
    return parent[ind];
}
void connect(int x,int y){
    int parentx = find_parent(x);
    int parenty = find_parent(y);
    //cout<<parentx<<' '<<parenty<<endl;
    parent[parentx] = parenty;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        cin.ignore();
        for(int i=1;i<=N;i++){
            parent[i]=i;
        }
        string str;
        int success{0},fail{0};
        while(getline(cin,str)){
            if(str==""){
                //cout<<"empty "<<endl;
                break;
            }
            stringstream ss(str);
            char ch;
            int a,b;
            ss>>ch>>a>>b;
            if(ch=='c'){
                connect(a,b);
                //cout<<"connected"<<endl;
            }else{
                if(find_parent(a)==find_parent(b)){
                    success++;
                    //cout<<"success"<<endl;
                }else{
                    fail++;
                    //cout<<find_parent(a)<<' '<<find_parent(b)<<endl;
                }
            }
        }cout<<success<<','<<fail<<endl;
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}

