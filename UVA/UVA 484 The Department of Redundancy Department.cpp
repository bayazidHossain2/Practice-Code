#include<iostream>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    string str;
    vector<int> numbers;
    map<int,int> data;
    while(getline(cin,str)){
        int temp;
        if(str==""){
            return 0;
        }
        stringstream ss(str);
        while(ss>>temp){
            data[temp]++;
            numbers.push_back(temp);
        }
    }

    for(int v : numbers){
        if(data[v]>0){
            cout<<v<<' '<<data[v]<<endl;
            data[v]=0;
        }
    }return 0;
}
