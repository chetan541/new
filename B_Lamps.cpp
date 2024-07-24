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
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        REP(i,0,n-1){
            pair<int,int> pi;
            cin>>pi.first;
            cin>>pi.second;
            v.push_back(pi);
        }
        sort(v.begin(),v.end(),sortbyCond);
        ll sum=0;
        int i=0;
        // int r=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(r==v[i].first)
        //     {
        //         if(v[i-1].first==v[i].first)
        //         continue;
        //         r=0;
        //     }
        //     if(v[i].first!=v[i-1].first)
        //     r=0;
        //     if(r<v[i].first)
        //     {
        //         sum+=v[i].second;
        //         r++;
        //     }
        // }
        
        while(i<n-1){
            int count=1;
            int x=v[i].first;
            if(v[i].first==v[i+1].first){
                sum+=v[i].second;
                while( v[i].first==v[i+1].first ){
                    i++;
                    count++;
                    if(count<=x){
                        sum+=v[i].second;
                    }
                }
                i++;
                
            }
            else{
                sum+=v[i].second;
                i++;
            }
            
        }
        if(v[n-1].first!=v[n-2].first){
            sum+=v[n-1].second;
        }
        cout<<sum<<endl;
    }
}