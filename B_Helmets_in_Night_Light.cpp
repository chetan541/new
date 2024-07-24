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
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        vi v1,v2;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v1.push_back(a);
        }
        vector<pair<int,int>> ans;
        REP(i,0,n-1){
            int b;
            cin>>b;
            v2.push_back(b);
            if(b<p){
                ans.push_back(make_pair(b,v1[i]));
            }
        }
        sort(ans.begin(),ans.end(),sortbyCond);
        ll count=0,temp=n,sum=0;
        // for(auto it:ans){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        sum=sum+p;
        temp--;
        REP(i,0,ans.size()-1){
            
            // temp--;
            // sum=sum+p;}
            
            if(ans[i].second<temp){
                temp=temp-ans[i].second;
                sum=sum+(ans[i].second)*(ans[i].first);
            }
            else{
                if(temp!=0){
                sum=sum+temp*ans[i].first;}
                temp=0;
            }
        
        }

        sum=sum+p*temp;
        cout<<sum<<endl;

    }
}