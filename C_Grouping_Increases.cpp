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
        vi v1,v2;
        v1.push_back(v[0]);
        int flag=1;
        REP(i,1,n-1){
            if(v2.size()==0){
                if(v1.back()>=v[i])v1.push_back(v[i]);
                else v2.push_back(v[i]);
            }
            else{
                int curr,m;
                if((v1.back())>=(v2.back()))curr=1,m=v1.back();
                else curr=2,m=v2.back();
                if(v[i]>m){
                    if(curr==1)v2.push_back(v[i]);
                    else v1.push_back(v[i]);
                }
                else{
                    if((v1.back())>=v[i] && curr==2)v1.push_back(v[i]);
                    else if((v2.back())>=v[i] && curr==1)v2.push_back(v[i]);
                    else{
                        if(curr==1)v1.push_back(v[i]);
                        else v2.push_back(v[i]);
                    }
                }


            }
        }
        int ans=0;
        REP(i,0,v1.size()-2){
            // cout<<v1[i]<<" ";
            if(v1[i]<v1[i+1])ans++;
            
        }
        // cout<<v1[v1.size()-1]<<endl;
        REP(i,0,v2.size()-2){
            // cout<<v2[i]<<" ";
            if(v2[i]<v2[i+1])ans++;
            
        }
        // cout<<v2[v2.size()-1]<<endl;
        cout<<ans<<endl;
    }
}