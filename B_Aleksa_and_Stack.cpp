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
        // v.push_back(4);
        // v.push_back(5);
        int curr=5;
        int prev=4;
        int count=1;
        REP(i,1,n){
            // count=(prev+curr)*3+1;
            // if(count%(3*(prev+curr))==0){
            //     count++;
            // }
            // prev=curr;
            // curr=count;
            v.push_back(count);
            count=count+2;

        }
        // REP(i,0,n-3){
        //     if((3*v[i+2])%(v[i]+v[i+1])){
        //         v[i+2]++;
        //     }
        // }
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}