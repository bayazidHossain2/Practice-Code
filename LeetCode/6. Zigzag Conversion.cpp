class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string mys;
        for(int i=1;i<=numRows;i++){
            int p=i;
            while(p<(s.length()+1)){
                if(i!=numRows){
                    mys+=s[p-1];
                    //cout<<"m : "<<mys<<endl;
                    p+=2*(numRows-i);
                }
                if(p<(s.length()+1)&&i!=1){
                    mys+=s[p-1];
                    p+=2*(i-1);
                }//cout<<"f : "<<mys<<endl;
            }//cout<<"i is : "<<i<<" : "<<mys<<endl;
        }//cout<<"res : "<<mys<<endl;
        return mys;
    }
};