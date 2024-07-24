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
        int n;
        cin>>n;
        vi v;
        vector<vector<int>> ans;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
        }
        int count=0;
        REP(i,0,n-2){
           
                int b=min(v[i],v[i+1]);
                ll c=1e9+7;
                // int c=lcm(v[i],v[i+1]);
                vi vec;
                vec.push_back(i+1);
                vec.push_back(i+2);
                vec.push_back(b);
                vec.push_back(c);
                ans.push_back(vec);
                count++;
                i++;
            
                
        }
        // if(n%2!=0){
        //     if((__gcd(v[n-2],v[n-1]))!=1){
        //         int d=min(v[n-1],v[n-2]);
        //         ll f=1e9+7;
        //         // int c=lcm(v[i],v[i+1]);
        //         vi vec;
        //         vec.push_back(n-1);
        //         vec.push_back(n);
        //         vec.push_back(d);
        //         vec.push_back(f);
        //         ans.push_back(vec);
        //         count++;
        // }
        // }
        cout<<count<<endl;
        for(auto it:ans){
            for(auto itw:it){
                cout<<itw<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;


    }
}