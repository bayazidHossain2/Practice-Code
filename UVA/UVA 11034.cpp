#include<iostream>
#include<queue>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int l,m;
        cin>>l>>m;
        l*=100;
        bool isLeft=true;
        int time=0;
        queue<int> lq,rq;
        while(m--){
            int ll;
            string side;
            cin>>ll>>side;
            if(side=="left"){
                lq.push(ll);
            }else{
                rq.push(ll);
            }
        }
        while(!lq.empty()||!rq.empty()){
            if(isLeft){
                int sm=0;
                while(!lq.empty()&&sm+lq.front()<=l){
                    sm+=lq.front();
                    lq.pop();
                }
            }else{
                int sm=0;
                while(!rq.empty()&&sm+rq.front()<=l){
                    sm+=rq.front();
                    rq.pop();
                }
            }
            time++;
            isLeft=1-isLeft;
        }
        /*int slq=0,srq=0;
        while(m--){
            int ll;
            string side;
            cin>>ll>>side;
            if(isLeft){
                if(side=="left"){
                    if(slq+ll<=l){
                        //lq.push(ll);
                        slq+=ll;
                    }else{
                        time+=2;
                        slq=ll;
                    }
                }else{
                    slq=0;
                    time++;
                    srq+=ll;
                    isLeft=false;
                }
            }else{
                if(side=="right"){
                    if(srq+ll<=l){
                        //lq.push(ll);
                        srq+=ll;
                    }else{
                        time+=2;
                        srq=ll;
                    }
                }else{
                    srq=0;
                    time++;
                    slq+=ll;
                    isLeft=true;
                }
            }
        }
        if(isLeft){
            if(slq!=0){
                time++;
            }
            if(srq!=0){
                time+=2;
            }
        }else{
            if(srq!=0){
                time++;
            }
            if(slq!=0){
                time+=2;
            }
        }*/
        cout<<time<<endl;
    }return 0;
}
