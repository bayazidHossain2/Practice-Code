#include<iostream>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        char ch;
        double int_value[257],inp;
        for(int i=0;i<257;i++){
            int_value[i]=0;
        }

        while(N--){
            cin>>ch>>inp;
            int_value[ch]=inp;
            //cout<<"inp : "<<int_value[ch]<<endl;
        }
        cin>>N;
        cin.ignore();
        string line;
        double res=0;
        while(N--){
            getline(cin,line);
            for(int i=0;i<line.size();i++){
                res+=int_value[line[i]];
            }
        }//cout<<res<<endl;
        /*int y1=res%10;
        res/=10;
        int y=res%10;
        res/=10;
        cout<<res<<'.'<<y<<y1<<"$"<<endl;*/
        res/=100;
        printf("%0.2lf$\n",res);
    }return 0;
}
