#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, ll> msi;
  
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
        // int n;cin>>n;
        msi m1,m2; 
        m1['a']++;
        m2['a']++;
        int q;cin>>q;
        ll c1=1,c2=1;
        REP(i,0,q-1){
            int a,k;cin>>a>>k;
            string s;cin>>s;
            if(a==1){
                c1+=s.size()*k;
                REP(j,0,s.size()-1){
                    m1[s[j]]+=1LL*k;
                }
            }
            if(a==2){
                c2+=s.size()*k;
                REP(j,0,s.size()-1){
                    m2[s[j]]+=1LL*k;
                }
            }
            auto it1=m1.begin();
            auto it2=m2.rbegin();
             ll t1=m1[(*it1).first],t2=m2[(*it2).first];
            //  cout<<t1<<" "<<t2<<" "<<c1<<" "<<c2<<endl;
            if((*it1).first <(*it2).first)cout<<"YES"<<endl;
            else if((*it1).first ==(*it2).first){
                if(t1==t2)cout<<"NO"<<endl;
                else if(t1>t2){
                    if(t2==c2)cout<<"NO"<<endl;
                    else cout<<"YES"<<endl;
                }
                else{
                    if(t1==c1)cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }

            }
            else cout<<"NO"<<endl;

        }
    }
}