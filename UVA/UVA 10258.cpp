#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
class contestent{
public:

    int panalty,numberOfSolved,tid;
    bool solved[10];
    int buff[10];
    bool parti;
    contestent(){
        panalty = 0;
        parti=false;
        numberOfSolved=0;
        for(int i=0;i<10;i++){
            solved[i]=false;
            buff[i]=0;
        }
    }
    int operator<(contestent c){
        if(numberOfSolved!=c.numberOfSolved){
            return numberOfSolved>c.numberOfSolved;
        }else if(panalty!=c.panalty){
            return panalty<c.panalty;
        }else{
            return tid<c.tid;
        }
    }
};
int main(){
    /*freopen("001Input.txt","r",stdin);
    freopen("001Output.txt","w",stdout);*/
    int T;
    cin>>T;
    cin.ignore();
    string line;
    getline(cin,line);
    while(T--){
        contestent team[101];
        for(int i=0;i<101;i++){
            team[i].tid=i;
        }
        while(getline(cin,line)){
            if(line==""){
                break;
            }
            stringstream ss(line);
            //cout<<"You entered : "<<line<<endl;
            int Tid,Pid,time;
            char ch;
            ss>>Tid>>Pid>>time>>ch;
            //cout<<"t id : "<<Tid<<' '<<Pid<<' '<<time<<' '<<ch<<endl;
            team[Tid].parti=true;
            switch(ch){
            case 'C':
                if(!team[Tid].solved[Pid]){
                    team[Tid].solved[Pid]=true;
                    team[Tid].panalty+=(time+team[Tid].buff[Pid]);
                    team[Tid].numberOfSolved++;
                }
                break;
            case 'I':
                if(!team[Tid].solved[Pid]){
                    team[Tid].buff[Pid]+=20;
                }
                break;
            }
        }
        sort(team,team+101);
        for(int i=0;i<101;i++){
            if(team[i].parti){
                cout<<team[i].tid<<' '<<team[i].numberOfSolved<<' '<<team[i].panalty<<endl;
            }
        }
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}
