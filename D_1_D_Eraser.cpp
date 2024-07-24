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
        int k;
        cin>>k;
        int f=0,l=0,count=0;
        vector<char> v;
        REP(i,0,n-1){
            char g;
            cin>>g;
            v.push_back(g);
        }
        while(l<n){
            
            // cout<<l<<endl;
            if(v[l]=='B'){
                f=l;
                l=l+k-1;
                count++;
                // cout<<" "<<count<<endl;
                // break;
                // l=l+k-1;
                // count++;
            }
            l++;



        }
        // l++;
        // while(l<n){
        //     char c;
        //     cin>>c;
        //     if(c=='B'){
        //         count=l;
        //     }
        //     l++;
        // }
        // // cout<<f<<" "<<count<<endl;
        // if(f==0 && count==0){
        //     cout<<0<<endl;
        // }
        // else if(count==0){
        //     cout<<1<<endl;
        // }
        // else{
        //     if((count-f+1)%k==0){
        // cout<<(count-f+1)/k<<endl;}
        // else{
        //     cout<<(count-f+1)/k+1<<endl;
        // }
        // }
        cout<<count<<endl;
    }
}