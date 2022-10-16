#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    bool Nfirst=false;
    while(N--){
        string str;
        cin.ignore();
        input:
        getline(cin,str);
        if(str==""){
            goto input;
        }
        if(Nfirst){
            cout<<endl;
        }Nfirst=true;
        stringstream ss(str);
        int inp;
        vector<int> indeces;
        while(ss>>inp){
            indeces.push_back(inp);
        }
        string datas[indeces.size()+5];
        string num;
        for(int i=0;i<indeces.size();i++){
            cin>>num;
            //cout<<" N : "<<num<<endl;
            datas[indeces[i]]=num;
        }
        for(int i=1;i<indeces.size()+1;i++){
            cout<<datas[i]<<endl;
        }
    }return 0;
}
