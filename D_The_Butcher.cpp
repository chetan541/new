#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<pair<int,int>> vi;
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
set<int> s;
void solve(vi &v1,vi &v2,int i,int j,int n){
    if(i==v1. || j==n-1){
        return;
    }
    
    int fi=0,fj=0;
    if(v1[i].first==v1[i+1].first){
        fi=1;
    }
    if(v2[j].first==v2[j].first){
        fj=1;
    }
    if(fi==1 && fj==1){}
    else{
        if(fi==1){
            i++;
            // auto it=lower_bound(v2.begin()+j-1,v2.end(),v1[i-1].second);
            v1[i].second+=v1[i-1].second;
            v1[i-1].second=-1;
            sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        }
        if(fj==1){
            i++;
            // auto it=lower_bound(v2.begin()+j-1,v2.end(),v1[i-1].second);
            v1[i].second+=v1[i-1].second;
            v1[i-1].second=-1;
            sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        }

    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v1;
        vi v2; 
        REP(i,0,n-1){
            pair<int,int> a,b;

            cin>>a.first>>a.second;
            b.first=a.second;
            b.second=a.first;
            v1.push_back(a);
            v2.push_back(b);

        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        solve(v1,v2,0,0,n);


    }
}