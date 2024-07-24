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
        ll n,m,k;
        cin>>n>>m>>k;
        if(k>3){
            cout<<0<<endl;
        }
        else if(k==3){
            if(m>n){
                int a=(m-n+1)-(m/n);
                if(a<0){
                    a=0;
                }
                cout<<a<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else if(k==2){
            if(m>=n){
            int b=(m/n)+(n-1);
            cout<<b<<endl;}
            else{
                int c=m;
                cout<<c<<endl;
            }
            
        }
        else if(k==1){
            if(m==0){
                cout<<1<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }

    }
}