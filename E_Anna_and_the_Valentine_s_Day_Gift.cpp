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
        int n,m;cin>>n>>m;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        vi ans;ll sum=0;ll x=0;
        REP(i,0,n-1){
            int cnt1=0,cnt2=0;
            int tmp=v[i];

            while(tmp%10==0){cnt1++;tmp=tmp/10;}
            tmp=v[i];
            while(tmp>0){
                cnt2++;tmp=tmp/10;
                
            }
            // cout<<cnt2<<" "<<v[i]<<endl;
            if(cnt1!=0)ans.push_back(cnt1);
            else x+=1;
            sum+=cnt2;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        // cout<<sum<<endl;
        REP(i,0,ans.size()-1){
            // cout<<ans[i]<<endl;
            if(i%2==0)sum-=ans[i];
        }
        // cout<<sum<<" "<<ans.size()<<endl;
        if(sum>m)cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
    }
}