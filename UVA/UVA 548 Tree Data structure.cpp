#include<iostream>
#include<sstream>
#define sz 10005
#define inf 100000000
using namespace std;

int in[sz];
int pre[sz];
int res;
int mncost;
void divideTree(int li,int ri,int lp,int rp,int cost){
    if(li==ri){
        cost += in[li];
        if(cost<mncost){
            mncost = cost;
            res = in[li];
        }else if(cost==mncost&&res>in[li]){
            res = in[li];
        }
    }else{
        cost += pre[rp];
        int i;
        for(i=li;i<=ri;i++){
            if(in[i]==pre[rp]){
                break;
            }
        }
        if(i>li){
            divideTree(li,i-1,lp,lp+(i-li)-1,cost);
        }
        if(i<ri){
            divideTree(i+1,ri,lp+(i-li),rp-1,cost);
        }
    }
}

int main(){
    string str1,str2;
    while(getline(cin,str1)){
        getline(cin,str2);
        //cout<<"input are\n"<<str1<<endl<<str2<<endl;
        stringstream ss(str1),ss2(str2);
        int numi,nump;
        int szi=0;
        while(ss>>numi){
            ss2>>nump;
            in[szi]=numi;
            pre[szi++]=nump;
        }
        res = inf;
        mncost = inf;
        divideTree(0,szi-1,0,szi-1,0);
        cout<<res<<endl;
    }
}
