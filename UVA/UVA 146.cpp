#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("001output.txt","w",stdout);
    string str;
    while(cin>>str){
        if(str=="#"){
            break;
        }
        string s=str;
        bool f=false;
        for(int i=1;i<s.size();i++){
            if(s[i-1]<s[i]){
                f=true;
            }
        }
        if(f){
            next_permutation(str.begin(),str.end());
            cout<<str<<endl;
        }else{
            cout<<"No Successor"<<endl;
        }
    }return 0;
}
