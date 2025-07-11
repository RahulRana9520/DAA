#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<pair<int,int>>activity;
    int n,s,e;
    cout<<"Enter number of Activity:";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(),activity.end());
    int count=0;
    int currentEnd=-1;
    for(int i=0;i<n;i++){
        if(activity[i].second>currentEnd){
            count++;
            currentEnd=activity[i].first;
        }
    }
    cout<<count<<endl;
}