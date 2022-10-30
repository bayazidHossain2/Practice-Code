#include<iostream>
#include<stack>
using namespace std;

char starting(char ch){
    if(ch==')'){
        return '(';
    }
    if(ch==']'){
        return '[';
    }return ' ';
}
int main(){
    //freopen("001input.txt","r",stdin);
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    cin.ignore();
    while(T--){
        string str;
        getline(cin,str);
        stack<char> stk;
        bool ok=true;
        for(char ch:str){
            if(ch=='('||ch=='['){
                stk.push(ch);
            }else{
                //cout<<"ch : "<<ch<<endl;
                if(stk.empty()||stk.top()!=starting(ch)){
                    //cout<<"Not ok"<<endl;
                    ok = false;
                    break;
                }else{
                    stk.pop();
                }
            }
        }
        if(ok&&stk.empty()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }return 0;
}
