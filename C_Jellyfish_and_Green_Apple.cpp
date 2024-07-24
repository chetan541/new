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
        int n,m;
        cin>>n>>m;
        int x=m,count1=0,y=n,count2=0;
        while(x%2==0){
            count1++;
            x=x/2;
        }
        while(y%2==0){
            count2++;
            y=y/2;
        }
        // cout<<x<<" "<<y<<endl;

        ll ans=0,flag=0,temp=0;
            if(y%x==0){
                flag=0;
                temp=n%m;
                while(temp!=0){
                    ans=ans+temp*2;
                    temp=(2*temp)%m;
                }
            }
            else{
                flag=-1;
            }
        
        if(flag==0){
            cout<<ans/2<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
}