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
        int n,k;cin>>n>>k;
        vi v;
        ll sum1=0,sum2=0,ans=0;

        REP(i,0,n-1){
            int a;cin>>a;
            ans+=a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        ll temp1=0,temp2=0,temp3=ans;
        while(k--){
            
        }
        while(k--){
            sum1=v[i]+v[i+1];
            sum2=v[j];
            temp1+=sum1;temp2+=sum2;
            // cout<<ans<<" "<<sum1<<" "<<sum2<<endl;
            if(sum1>sum2){j--;ans=ans-sum2;}
            else {i+=2;ans=ans-sum1;}
        }
        ll ans1=max(temp3-temp1,temp3-temp2);
        ans=max(ans,ans1);
        cout<<ans<<endl;
        
    }
}