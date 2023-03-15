#include<iostream>
#include<vector>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int n;
    cin>>n;
    vector<string> people(n);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    string song[]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    int i=0;
    for(;i<n;i++){
        cout<<people[i]<<": "<<song[i%16]<<endl;
    }
    while((i%16!=0)){
        cout<<people[i%n]<<": "<<song[i%16]<<endl;
        i++;
    }
    return 0;
}
