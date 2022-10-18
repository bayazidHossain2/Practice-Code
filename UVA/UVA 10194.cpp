#include<bits/stdc++.h>
using namespace std;
class Team{
public:
    string team_name;
    int total_earn_point;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goal_difference;
    int goals_scored;
    int goals_against;
    Team(){

    }
    Team(string team_name){
        this->team_name=team_name;
        total_earn_point=0;
        games_played=0;
        wins=0;
        ties=0;
        losses=0;
        goal_difference=0;
        goals_scored=0;
        goals_against=0;
    }
    void update(int team_goal,int o_goal){
        games_played++;
        if(team_goal>o_goal){
            wins++;
            total_earn_point+=3;
        }else if(team_goal<o_goal){
            losses++;
        }else{
            ties++;
            total_earn_point++;
        }
        goal_difference+=(team_goal-o_goal);
        goals_scored+=team_goal;
        goals_against+=o_goal;
    }
    void print(){
        cout<<team_name<<' '<<total_earn_point<<"p, "<<games_played<<"g ("<<wins<<"-";
        cout<<ties<<"-"<<losses<<"), "<<goal_difference<<"gd (";
        cout<<goals_scored<<"-"<<goals_against<<")"<<endl;
    }
};

int compare(Team t1,Team t2){
    if(t1.total_earn_point!=t2.total_earn_point){
        return t1.total_earn_point>t2.total_earn_point;
    }
    if(t1.wins!=t2.wins){
        return t1.wins>t2.wins;
    }
    if(t1.goal_difference!=t2.goal_difference){
        return t1.goal_difference>t2.goal_difference;
    }
    if(t1.goals_scored!=t2.goals_scored){
        return t1.goals_scored>t2.goals_scored;
    }
    if(t1.games_played!=t2.games_played){
        return t1.games_played<t2.games_played;
    }
    string lower_case_t1,lower_case_t2;
    for(int i=0;i<t1.team_name.size();i++){
        if(t1.team_name[i]>='A'&&t1.team_name[i]<='Z'){
            lower_case_t1+='a'+t1.team_name[i]-'A';
        }else{
            lower_case_t1+=t1.team_name[i];
        }
    }
    for(int i=0;i<t2.team_name.size();i++){
        if(t2.team_name[i]>='A'&&t2.team_name[i]<='Z'){
            lower_case_t2+='a'+t2.team_name[i]-'A';
        }else{
            lower_case_t2+=t2.team_name[i];
        }
    }
    return lower_case_t1<lower_case_t2;
}
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    cin.ignore();
    string turnament_name;
    bool f=false;
    while(T--){
        if(f){
            cout<<endl;
        }f=true;

        getline(cin,turnament_name);
        int number_of_team;
        cin>>number_of_team;
        cin.ignore();
        Team teams[number_of_team];
        unordered_map<string,Team*> team_pointer;
        for(int i=0;i<number_of_team;i++){
            string team_name;
            getline(cin,team_name);
            teams[i] = Team(team_name);
            team_pointer[team_name]=&teams[i];
        }
        int number_of_turnament;
        cin>>number_of_turnament;
        cin.ignore();
        string turnament;
        for(int i=0;i<number_of_turnament;i++){
            getline(cin,turnament);
            stringstream ss(turnament);
            string team1,team2,team_one_name,team_two_name;
            int goal1,goal2;
            getline(ss,team1,'@');
            getline(ss,team2,'@');
            ss = stringstream(team1);
            getline(ss,team_one_name,'#');
            ss>>goal1;
            ss = stringstream(team2);
            ss>>goal2;
            getline(ss,team_two_name,'#');
            getline(ss,team_two_name,'#');
            team_pointer[team_one_name]->update(goal1,goal2);
            team_pointer[team_two_name]->update(goal2,goal1);

            /*cout<<"TEAM 1 : "<<team1<<endl;
            cout<<"TEAM 1 : "<<team2<<endl;
            cout<<"t one name : "<<team_one_name<<" g : "<<goal1<<endl;
            cout<<"t two name : "<<team_two_name<<" g : "<<goal2<<endl;*/
        }
        sort(teams,teams+number_of_team,compare);
        cout<<turnament_name<<endl;
        for(int i=0;i<number_of_team;i++){
            cout<<i+1<<") ";
            teams[i].print();
        }
    }return 0;
}
