#include<iostream>
#include<vector>

using namespace std;
const int sz = 2005;
char color[sz];
int expCount[sz];
int numberOfExp;
int tr;
int N;

void print(vector<vector<int>> d){
    for(int i=0;i<d.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<d[i].size();j++){
            cout<<d[i][j]<<' ';
        }cout<<endl;
    }cout<<endl;
}
void dp(int indx,vector<vector<int>> d){
    if(color[indx]=='b'){
        return ;
    }
    color[indx] = 'g';
    int total_exp = 0;
    //cout<<"calling indx : "<<indx<<endl;
    for(int i=0;i<d[indx].size();i++){
        if(color[d[indx][i]]=='h'){
            dp(d[indx][i],d);
        }else if(color[d[indx][i]]=='g'){
            continue;
        }
        total_exp += expCount[d[indx][i]];
    }
    color[indx] = 'b';
    expCount[indx] = total_exp+1;
}

void bombing(int indx,vector<vector<int>> d){
    //cout<<"bombing : "<<indx;
    if(color[indx]=='r'){
        //cout<<" Already boom "<<endl;
        return ;
    }
    color[indx] = 'o';
    for(int i=0;i<d[indx].size();i++){
        //cout<<" c of "<<d[indx][i]<<" is : "<<color[d[indx][i]]<<' ';
        if(color[d[indx][i]]=='b'){
            bombing(d[indx][i],d);
        }else if(color[d[indx][i]]=='o'){
            continue;
        }
    }color[indx] = 'r';
    //cout<<endl;
    tr++;
}


int main(){
    freopen("001input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        vector<pair<int,int>> points(N);
        int d[N];
        for(int i=0;i<N;i++){
            cin>>points[i].first>>points[i].second>>d[i];
        }
        vector<vector<int>> commons(N,vector<int>());
        int mt=0;
        for(int i=0;i<N;i++){
            double x1=points[i].first-(d[i]/2.0);
            double y1=points[i].second-(d[i]/2.0);
            double x2=points[i].first+(d[i]/2.0);
            double y2=points[i].second+(d[i]/2.0);
            //cout<<"common to : "<<i<<" is : ";
            for(int j=0;j<N;j++){
                if(points[j].first>=x1&&points[j].first<=x2&&points[j].second>=y1&&points[j].second<=y2){
                    if(i!=j){
                        commons[i].push_back(j);
                    }
                    //cout<<j<<' ';
                }int sz=commons[i].size();
                mt=max(mt,sz);
            }//cout<<endl;
        }//print(commons);
        for(int i=0;i<N;i++){
            color[i] = 'h';
            expCount[i]= 0;
        }
        for(int i=0;i<N;i++){
            dp(i,commons);
        }tr=0;

        /*cout<<"Explor counts are : "<<endl;
        for(int i=0;i<N;i++){
            cout<<"Color : "<<color[i]<<endl;
            cout<<i<<" -> "<<expCount[i]<<endl;
        }*/
        int res = 0;
        while(true){
            int mxi=0;
            for(int i=1;i<N;i++){
                if(expCount[mxi]<expCount[i]){
                    mxi=i;
                }
            }
            //cout<<"Max found : "<<expCount[mxi]<<" Indx is : "<<mxi<<" color is : "<<color[mxi]<<endl;
            if(expCount[mxi]==-1){
                break;
            }
            if(color[mxi]=='b'){
                res++;
                bombing(mxi,commons);
            }
            //cout<<"Total red is : "<<tr<<" cr is : "<<res<<endl;

            expCount[mxi]=-1;
        }cout<<res<<endl;
        //sort(commons.begin(),commons.end(),cmp);
    }return 0;
}

/*

1
151
500 630 128
611 640 160
481 920 145
109 371 53
576 291 159
901 316 111
65 534 69
65 640 142
234 850 13
288 896 67
435 932 133
724 221 53
170 147 121
777 909 18
11 456 76
166 553 157
97 484 10
959 841 44
830 270 152
699 48 81
324 268 129
181 537 178
66 595 79
880 889 91
431 897 15
384 680 163
778 667 104
187 315 120
705 983 188
181 19 160
891 347 195
212 908 184
692 553 29
977 255 81
570 63 163
705 661 108
355 805 103
254 457 191
219 414 34
45 883 16
170 778 47
353 940 146
29 630 17
62 992 182
476 953 31
657 973 20
341 103 188
961 576 125
584 213 150
668 631 83
851 13 173
472 547 50
321 872 56
866 615 108
710 858 158
596 394 64
929 15 156
188 38 102
932 756 172
504 137 132
36 527 193
163 778 191
947 308 154
703 781 85
344 248 12
96 691 123
388 163 19
186 233 49
807 857 55
258 279 142
232 645 161
86 977 109
24 137 180
360 488 11
152 944 53
885 407 132
163 898 195
236 822 118
187 540 18
248 357 8
437 470 146
400 131 173
469 327 4
124 946 174
531 954 155
36 782 116
358 577 133
336 52 23
667 547 5
739 791 178
812 158 16
350 656 27
435 393 27
428 792 13
22 101 116
657 330 148
680 371 142
492 648 71
641 295 59
37 537 190
114 993 57
939 962 121
129 429 129
754 658 96
24 850 86
326 943 153
301 318 182
511 920 124
193 150 94
908 832 194
426 529 180
880 86 105
136 943 196
895 894 98
587 149 159
797 288 48
789 864 134
199 335 145
755 972 112
315 181 123
59 172 192
648 423 81
698 210 174
309 465 31
48 35 40
636 955 150
284 765 78
290 64 47
595 662 80
740 83 115
622 301 4
76 331 3
900 173 171
212 134 120
70 33 181
479 343 124
190 999 112
733 324 183
897 254 23
221 549 29
718 847 165
693 347 69
69 531 133
580 763 133
99 235 58
514 596 33
176 186 177
218 740 119
431 206 79
549 30 64
858 496 38

*/
