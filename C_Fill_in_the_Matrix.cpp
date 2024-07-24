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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vi v1,v2;
       
        if(n<m){
            if(m==1){
                cout<<0<<endl;
            }
            else{
                cout<<n+1<<endl;
            }
             v2.push_back(0);
        REP(i,1,m-1){
            v1.push_back(i);
        } 
            // q2.push(0);
        for(int j=0;j<n;j++){
            for(auto it:v1){
                cout<<it<<" ";
            }
            for(auto it:v2){
                cout<<it<<" ";
            }
            v2.push_back(v1[0]);
            v1.erase(v1.begin());
            cout<<endl;
	
        }
        }
        else{
            if(m==1){
                cout<<0<<endl;
            }
            else{
                cout<<m<<endl;
            }
             v2.push_back(0);
        REP(i,1,m-1){
            v1.push_back(i);
        } 
        for(int j=0;j<m-1;j++){
            for(auto it:v1){
                cout<<it<<" ";
            }
            for(auto it:v2){
                cout<<it<<" ";
            }
            v2.push_back(v1[0]);
            v1.erase(v1.begin());
            cout<<endl;}
            for(int i=m-1;i<n;i++){
                REP(i,1,m-1){
                    cout<<i<<" ";
                }
                cout<<0<<endl;
            }
        
    }
}
}