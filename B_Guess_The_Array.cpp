#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
        ll count=1;
        ll sum=0;
        for(int i=0;i<n;i++){
            // count+1;
            v.push_back(count);
            cout<<v[i]<<" ";
            sum=sum+count*40;
            // count=count+1;
            count=sum+1;

        }
        cout<<endl;
        fflush(stdout);
        ll sum2;
        cin>>sum2;
        vi vec;
        for(int i=n-1;i>=0;i--){
            ll temp;
            temp=sum2/v[i];
            vec.push_back(temp);
            sum2=sum2-temp*v[i];
        }
        for(int i=n-1;i>=0;i--){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
        fflush(stdout);




    }
}