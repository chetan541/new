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
        int ans=INT_MAX;
        int c1=0,c2=0,c3=0;
        REP(i,0,n-1){
            if(s[i]=='a')c1++;
            if(s[i]=='b')c2++;
            if(s[i]=='c')c3++;
        }
        int i=0,j=n-1;
        while(j>i){
            
            if(s[i]!='a'){
                while(i<j && s[i]!='a'){
                if(s[i]=='b')c2--;
                if(s[i]=='c')c3--;
                i++;
                }
            }
            if(s[j]!='a'){
                 while(i<j && s[j]!='a'){
                if(s[j]=='b')c2--;
                if(s[j]=='c')c3--;
                j--;
            }
            }
            if(j>i && s[i]==s[j] && c1>max(c2,c3)){
                ans=min(ans,j-i+1);
            }
            // cout<<i<<" "<<j<<" "<<c2<<" "<<c3<<endl;
            i++;
            if(s[i]=='a' && s[i-1]=='a')ans=2;
            j--;
            if(s[j]=='a' && s[j-1]=='a')ans=2;
        }
        if(ans==INT_MAX)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}