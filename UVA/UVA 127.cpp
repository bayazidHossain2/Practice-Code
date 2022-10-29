#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;
class card{
public:
    char ch_rank,suit;
    card(){

    }
    card(char ch_rank,char suit){
        this->ch_rank = ch_rank;
        this->suit = suit;
    }
    card(string str){
        ch_rank=str[0];
        suit=str[1];
    }
    bool isMatch(card c){
        if(this->ch_rank==c.ch_rank){
            return true;
        }else if(this->suit==c.suit){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    //freopen("001input.txt","r",stdin);
    //freopen("001output.txt","w",stdout);
    string line;
    while(getline(cin,line)){
        if(line=="#"){
            break;
        }
        vector<stack<card>> data(52);
        //vector<int> cnt(52);
        stringstream ss(line);
        int i=0;
        string cd;
        while(ss>>cd){
            card c(cd);
            data[i].push(c);
            //cnt[i]=1;
            i++;
        }
        getline(cin,line);
        ss=stringstream(line);
        while(ss>>cd){
            card c(cd);
            data[i].push(c);
            //cnt[i]=1;
            i++;
        }
        int pointer=1;
        while(pointer<data.size()){
            if(pointer>2&&data[pointer].top().isMatch(data[pointer-3].top())){
                data[pointer-3].push(data[pointer].top());
                data[pointer].pop();
                if(data[pointer].empty()){
                    data.erase(data.begin()+pointer);
                }
                pointer-=3;

            }else if(pointer>0&&data[pointer].top().isMatch(data[pointer-1].top())){
                data[pointer-1].push(data[pointer].top());
                data[pointer].pop();
                if(data[pointer].empty()){
                    data.erase(data.begin()+pointer);
                }
                pointer-=1;
            }else{
                pointer++;
            }
        }
        if(data.size()==1){
            cout<<data.size()<<" pile remaining:";
        }else{
            cout<<data.size()<<" piles remaining:";
        }
        for(int i=0;i<data.size();i++){
            cout<<' '<<data[i].size();
        }cout<<endl;
    }return 0;
}
