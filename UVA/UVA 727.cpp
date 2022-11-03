#include<iostream>
#include<sstream>
using namespace std;
const int sz=10e5;
char sign[sz];
int priority(char ch){
    switch(ch){
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    }return -1;
}
int main(){
    //freopen("001output.txt","w",stdout);
    //freopen("001input.txt","r",stdin);
    int T;
    cin>>T;
    cin.ignore();
    string str;
    getline(cin,str);
    while(T--){
        int p=0;
        while(getline(cin,str)){
            //cout<<"input is : \""<<str<<"\""<<endl;
            if(str==""){
                break;
            }
            if(str=="("){
                sign[p++]='(';
            }else if(str==")"){
                while(p>=1&&sign[p-1]!='('){
                    cout<<sign[p-1];
                    p--;
                }p--;
            }else if(str=="+"){
                while(p>=1&&priority(sign[p-1])>=priority('+')){
                    cout<<sign[p-1];
                    p--;
                }
                sign[p++]='+';
            }else if(str=="-"){
                while(p>=1&&priority(sign[p-1])>=priority('-')){
                    cout<<sign[p-1];
                    p--;
                }
                sign[p++]='-';
            }else if(str=="*"){
                while(p>=1&&priority(sign[p-1])>=priority('*')){
                    cout<<sign[p-1];
                    p--;
                }
                sign[p++]='*';
            }else if(str=="/"){
                while(p>=0&&priority(sign[p-1])>=priority('/')){
                    cout<<sign[p-1];
                    p--;
                }
                sign[p++]='/';
            }else{
                cout<<str;
            }
        }p--;
        while(p>=0){
            cout<<sign[p];
            p--;
        }cout<<endl;
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}
