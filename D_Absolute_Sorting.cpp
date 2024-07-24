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
        cin>>n;vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        int low=0,high=INT_MAX,flag=1;
        REP(i,0,n-2){
            int avg;
            if(v[i]>v[i+1]){
                avg=(v[i]+v[i+1]+1)/2;
                if(avg>=low && avg<=high ){
                    low=avg;
                }
                else if(avg<low && avg<=high){low=low;}
                else{flag=0;
                break;}
            }
            else if(v[i]<v[i+1]){
                avg=(v[i]+v[i+1])/2;
                if(avg<=high && avg>=low ){
                    high=avg;
                }
                else if(avg>high && avg>=low){high=high;}
                else {flag=0;
                break;}
            }
        }
        if(flag==0){cout<<-1<<endl;}
        else{cout<<low<<endl;}

    }
}