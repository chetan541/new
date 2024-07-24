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
        ll n;
        cin>>n;
        ll u=0,l=0,up=0,lp=0;
        for (int i = 9; i>=0; i--)
        {
            /* code */
            int a=n/(pow(10,i));
            // cout<<" "<<a<<endl;
            if(a%2==0){
                u=u+(a/2)*pow(10,i);
                l=l+(a/2)*pow(10,i);
            }
            else{
                if(up<=lp){
                    u=u+(a/2 +1)*pow(10,i);
                    // cout<<u<<endl;
                    l=l+(a/2)*pow(10,i);
                    up++;
                }
                else {
                    l=l+(a/2 +1)*pow(10,i);
                    u=u+(a/2)*pow(10,i);
                    lp++;
                }
            }
            n=n-a*(pow(10,i));


        }
        cout<<u<<" "<<l<<endl;
        
    }
}