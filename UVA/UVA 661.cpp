#include<iostream>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);

    int n,m,c;
    int serial=1;
    while(cin>>n>>m>>c&&n!=0){
        int con[n+1];
        for(int i=1;i<=n;i++){
            cin>>con[i];
        }
        int max_con=0;
        int cur_con=0;
        bool active[n+1]={false};
        int id;
        while(m--){
            cin>>id;
            if(active[id]){
                cur_con-=con[id];
            }else{
                cur_con+=con[id];
                if(cur_con>max_con){
                    max_con=cur_con;
                }
            }
            active[id]=1-active[id];
        }
        cout<<"Sequence "<<serial++<<endl;
        if(c<max_con){
            cout<<"Fuse was blown."<<endl;
        }else{
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<max_con<<" amperes."<<endl;
        }cout<<endl;
    }return 0;
}
