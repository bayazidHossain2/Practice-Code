#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        string str;
        bool f=false;
        while(ss>>str){
            if(f){
                cout<<' ';
            }else{
                f=true;
            }
            for(int i=str.size()-1;i>=0;i--){
                cout<<str[i];
            }
        }cout<<endl;
    }return 0;
}
