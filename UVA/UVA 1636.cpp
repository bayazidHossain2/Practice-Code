#include<iostream>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        int zeros{0};
        int Nlive{0};
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                zeros++;
                if(str[(i+1)%str.size()]=='0'){
                    Nlive++;
                }
            }
        }
        double pnl=Nlive/(zeros+0.0);
        double prl=zeros/(str.size()+0.0);
        if(Nlive*str.size()==zeros*zeros){
            cout<<"EQUAL"<<endl;
        }else if(pnl>prl){
            cout<<"SHOOT"<<endl;
        }else{
            cout<<"ROTATE"<<endl;
        }
    }return 0;
}
