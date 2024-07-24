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
        int n;cin>>n;
        vector<string> v;
        map<pair<ll,int>,int> m;
        REP(i,0,n-1){
            ll sum=0;
            string s;cin>>s;
            // cout<<s<<endl;
            v.push_back(s);
            REP(j,0,s.size()-1){
                sum +=int(s[j]-'0');
                // cout<<s[i]<<endl;
            }
            // cout<<sum<<endl;
            m[make_pair(sum,s.size())]++;
        } 
        // cout<<m[make_pair(1,1)]<<endl;
        ll cnt=0;
        REP(i,0,n-1){
            int temp=v[i].size();
            int start=0;
            if(temp%2==0)start=2;
            else start=1;
            ll x=0,y=0;
                for(int j=start;j<=temp;j+=2){
                    x=0,y=0;
                    REP(k,temp-(temp+j)/2,temp-1){
                        x+=int(v[i][k]-'0');
                    }
                    
                    REP(k,0,temp-(temp+j)/2-1){
                        y+=int(v[i][k]-'0');
                    }
                    if(m[make_pair(x-y,j)]!=0)cnt+=m[make_pair(x-y,j)];}
                    for(int j=start;j<temp;j+=2){
                    x=0,y=0;
                    REP(k,0,(temp+j)/2-1){
                        x+=int(v[i][k]-'0');
                    }
                    REP(k,(temp+j)/2,temp-1){
                        y+=int(v[i][k]-'0');
                    }
                    if(m[make_pair(x-y,j)]!=0)cnt+=m[make_pair(x-y,j)];

                }
                // cout<<cnt<<endl;
            
        }
        cout<<cnt<<endl;
    }
