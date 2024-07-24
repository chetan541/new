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
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        vector<ll> ans;
        vector<ll> ans1;
        ans1.push_back(0);
        
        ll sum=0;
        ans.push_back(0);
        
        for(int i=0;i<=n-2;i++){
            if(i==0){
                sum+=1;
                ans.push_back(sum);

            }
            else{
                if(v[i+1]-v[i]<v[i]-v[i-1]){sum+=1;ans.push_back(sum);}
                else {sum+=v[i+1]-v[i];ans.push_back(sum);}
            }
        }
        sum=0;
        for(int i=n-1;i>=1;i--){
            if(i==n-1){
                sum+=1;
                ans1.push_back(sum);

            }
            else{
                if(v[i]-v[i-1]<v[i+1]-v[i]){sum+=1;ans1.push_back(sum);}
                else {sum+=v[i]-v[i-1];ans1.push_back(sum);}
            }
        }
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int m;cin>>m;
        REP(i,0,m-1){
            int x,y;cin>>x>>y;
            if(x<y) cout<<ans[y-1]-ans[x-1]<<endl;
            else if(x>y){cout<<ans1[n-y]-ans1[n-x]<<endl;}
            else cout<<0<<endl;}

           
        }
        
    }
