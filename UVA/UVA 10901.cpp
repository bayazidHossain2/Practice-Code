#include<iostream>
using namespace std;
const int sz=3e5;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){

        cin>>n>>t>>m;
        int ctime=0;
        int time;
        string side;
        int Bside=1;
        queue<int> qul,qur;
        int times[m];
        int reqTime[m];
        for(int i=0;i<m;i++){
            cin>>time>>side;
            if(side=="left"){
                qul.push(i);
            }else{
                qur.push(i);
            }times[i]=time;
        }
        while(!qul.empty()||!qur.empty()){
            int nextTime=0;
            if(!qul.empty()&&!qur.empty()){
                nextTime=min(times[qul.front()],times[qur.front()]);
            }else if(!qul.empty()){
                nextTime=times[qul.front()];
            }else{
                nextTime=times[qur.front()];
            }
            ctime=max(ctime,nextTime);
            if(Bside){
                int tt=n;
                while(!qul.empty()&&times[qul.front()]<=ctime&&tt>0){
                    reqTime[qul.front()]=ctime+t;
                    qul.pop();
                    tt--;
                }
            }else{
                int tt=n;
                while(!qur.empty()&&times[qur.front()]<=ctime&&tt>0){
                    reqTime[qur.front()]=ctime+t;
                    qur.pop();
                    tt--;
                }
            }
            ctime+=t;
            Bside=1-Bside;
        }
        for(int i=0;i<m;i++){
            cout<<reqTime[i]<<endl;
        }
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}
