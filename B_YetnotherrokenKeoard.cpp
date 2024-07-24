#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
        
        // int l=-1,r=-1;
        string s;
        cin>>s;
        string str;
        msi m;
        vi l,r;

        REP(i,0,s.size()-1){
            if(s[i]!='b' && s[i]!='B'){
                // str.push_back(s[i]);
                if(s[i]>='a'){
                   l.push_back(i);
                }
                else{
                   r.push_back(i);
                }
            }
            else{
                if(s[i]=='b'){
                    if(l.size()!=0){
                        // s.erase(str.begin()+l);
                        m[l[l.size()-1]]++;
                        l.pop_back();
                    }
                }
                if(s[i]=='B'){
                    if(r.size()!=0){
                        // s.erase(str.begin()+l);
                        m[r[r.size()-1]]++;
                        r.pop_back();
                    }
                }
            }
            // cout<<l<<" "<<r<<endl;
        }
        REP(i,0,s.size()-1){
            if(m[i]==0 && s[i]!='b'&& s[i]!='B'){
                cout<<s[i];
            }
        }
        cout<<endl;


        
    }
}