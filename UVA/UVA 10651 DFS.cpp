#include<iostream>
#include<queue>
using namespace std;

int hash_value(string str){
    int base=1;
    int value=0;
    for(char ch : str){
        if(ch == 'o'){
            value+=base;
        }base=base<<1;
        //cout<<base<<endl;
    }return value;
}
void DFS(string str,int indxB){

}
int main(){
    //cout<<hash_value("----o-o-oo--")<<endl;
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        bool visited[5000]={false};
        int res=0;
        queue<string> qu;
        for(int i=0;i<12;i++){
            if(str[i]=='o'){
                res++;
                if(i>0&&i<11){
                    if(str[i-1]=='-'&&str[i+1]=='o'){
                        string temp=str;
                        temp[i-1]='o';
                        temp[i]='-';
                        temp[i+1]='-';
                        visited[hash_value(temp)]=true;
                        qu.push(temp);
                    }
                    if(str[i-1]=='o'&&str[i+1]=='-'){
                        string temp=str;
                        temp[i-1]='-';
                        temp[i]='-';
                        temp[i+1]='o';
                        visited[hash_value(temp)]=true;
                        qu.push(temp);
                    }
                }
            }
        }
        while(!qu.empty()){
            string st = qu.front();
            qu.pop();
            int cr=0;
            for(int i=0;i<12;i++){
                if(st[i]=='o'){
                    cr++;
                    if(i>0&&i<11){
                        if(st[i-1]=='-'&&st[i+1]=='o'){
                            string temp=st;
                            temp[i-1]='o';
                            temp[i]='-';
                            temp[i+1]='-';
                            int sh_value=hash_value(temp);
                            if(!visited[sh_value]){
                                visited[sh_value]=true;
                                qu.push(temp);
                            }
                        }
                        if(st[i-1]=='o'&&st[i+1]=='-'){
                            string temp=st;
                            temp[i-1]='-';
                            temp[i]='-';
                            temp[i+1]='o';
                            int sh_value=hash_value(temp);
                            if(!visited[sh_value]){
                                visited[sh_value]=true;
                                qu.push(temp);
                            }
                        }
                    }
                }
            }
            if(cr<res){
                res=cr;
            }
        }cout<<res<<endl;
    }return 0;
}
