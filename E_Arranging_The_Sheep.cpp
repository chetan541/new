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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vi v;
        int prev=0;
        // v.push_back(0);
        REP(i,0,n-1){
            if(s[i]=='*'){v.push_back(i-prev);prev=i+1;}
        }
        int m=v.size();
        if(m<=1)cout<<0<<endl;
        else{
        ll ans=0; 
        int ind=(m+1)/2 -1;
        // REP(i,0,m-1){
        //     int temp=min(i,m-i-1);
        //     if(ans<temp*v[i])ind=i;
        // }
        // for(auto it:v)cout<<it<<" ";
        // auto it=max_element(v.begin(),v.end());
        
        ll sum1=0,sum2=0;
        REP(i,0,ind){
            sum1+=v[i]*(i);
        }
        for(int i=m-1;i>ind;i--){
            sum1+=v[i]*(m-i);
        }
        for(int i=m-1;i>=ind;i--){
            sum2+=v[i]*(m-i);
        }
        REP(i,0,ind-1){
            sum2+=v[i]*(i);
        }
        // cout<<sum1<<" "<<sum2<<endl;
        cout<<min(sum1,sum2)<<endl;}

    }

}