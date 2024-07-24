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
    ll n,k,x;
    cin>>n>>k>>x;
    unsigned long long int sum=((k)*(k+1)/2);
    ll count=x-sum;
    int flag=0;
    // cout<<sum<<" "<<count;
    if(count>=k && count<=n){
        // cout<<"YES"<<endl;
        flag=1;
    }
    // else{
    //     cout<<"NO"<<endl;
    // }
    unsigned long long int sum1=n*(n+1)/2-(n-k)*(n-k+1)/2;
    ll count1=x-sum1;
    if(count1>=1 && count1<=n-k){
        flag=1;
    }
    // cout<<sum<<" "<<sum1<<endl;

    if(x>=sum && x<=sum1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    
}