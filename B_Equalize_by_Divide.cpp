#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int ans(){
// int n;cin>>n;
//         vector<pair<int,int>> v;
        // vector<pair<int,int>> vec;
        // int z=0;
        // REP(i,0,n-1){
            
        //     int a;cin>>a;v.push_back(make_pair(a,i+1));
        //     if(a==1){z++;}
        // }
        // sort(v.begin(),v.end());
        // int x=v[0].first,y=v[0].second,count=1,check=0,pos=0;
        // if(x==1){
        //     if(z==n){cout<<0<<endl;}
        //     else{
        //     cout<<-1<<endl;}
            
        //     }
        // else{
        // REP(i,1,n-1){
        //     int temp=ceil(v[i].first/(x*1.0));
        //     // if(temp>=2){vec.push_back(make_pair(v[i].second,y));
        //     // v[i].first=temp;}
        //     // cout<<temp<<endl;
        //     if(v[i].first==x){count++;}
        //     while(temp>=2){
        //         vec.push_back(make_pair(v[i].second,y));
        //         v[i].first=temp;
        //         temp=ceil(temp/(x*1.0)); 
        //     }
        //     if(v[i].first!=x){check=v[i].first;pos=i+1;}

        // }
        // // cout<<v[n-1].first<<endl;
        // if(count==n){cout<<vec.size()<<endl;
        // for(auto it:vec){

        //         // cout<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        // else{
        //     if(check!=0){
        //         REP(i,0,n-1){
        //          int temp=ceil(v[i].first/(check*1.0));
        //     // if(temp>=2){vec.push_back(make_pair(v[i].second,pos));
        //     // v[i].first=temp;}
        //     // cout<<temp<<endl;
        //     // if(v[i].first==x){count++;}
        //     while(temp>=2){
        //         vec.push_back(make_pair(v[i].second,pos));
        //         v[i].first=temp;
        //         temp=ceil(temp/(check*1.0)); 
        //     }
        //         }
        //     }
        //     cout<<vec.size()<<endl;
        //     for(auto it:vec){

                // cout<<it.first<<" "<<it.second<<endl;
            
    //     }
    // }
    cout<<"hello"<<endl;
    return 10;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        x=ans();
        cout<<x<<endl;

    }
}