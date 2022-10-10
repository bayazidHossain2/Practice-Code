#include<iostream>
#include<stack>
using namespace std;
int main(){
    int N;
    while(cin>>N&&N){
        int req[N];
        while(cin>>req[0]&&req[0]){
            for(int i=1;i<N;i++){
                cin>>req[i];
            }
            stack<int> stk;
            int rind=0;
            int A=1;
            while(true){
                if(rind==N){
                    break;
                }
                if(A==req[rind]){
                    A++;
                    rind++;
                }else if(A<req[rind]){
                    while(A!=req[rind]){
                        stk.push(A);
                        A++;
                    }rind++;
                    A++;
                }else if(!stk.empty()&&stk.top()==req[rind]){
                    stk.pop();
                    rind++;
                }else{
                    break;
                }
                //cout<<rind<<" "<<stk.size()<<endl;
            }

            if(rind==N){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }cout<<endl;
    }return 0;
}
