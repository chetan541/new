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
        int x,y;
        REP(i,0,n-1){
            int a;
            cin>>a;
            if(a==n){
                x=i;
            }
             if(a==n-1){
                y=i;
             }
            v.push_back(a);
        }
        int r=x-1,l=x-1;
        if(x==0){
            r=y-1;
            l=y-1;
        } 
        if(n==1){
            cout<<v[0]<<" ";
        }  
        else if(r==n-2){
            l++;
            r++;
            // REP(i,x,n-1){
            //     cout<<v[i]<<" ";
            // }
            l--;
            while(v[l]>v[0] && l>=0){
                l--;
            }
            l++;
            for(int i=r;i>=l;i--){
            //     cout<<v[i]<<" ";
            // }
                cout<<v[i]<<" ";
            }
            REP(i,0,l-1){
                cout<<v[i]<<" ";
            }
        }
        else{
             l--;
            while(v[l]>v[0] && l>=0){
                l--;
            }
            l++;
            // if(l!=r){
            // l++;}
            REP(i,r+1,n-1){
                cout<<v[i]<<" ";
            }
            for(int i=r;i>=l;i--){
                cout<<v[i]<<" ";
            }
            REP(i,0,l-1){
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
    }
}