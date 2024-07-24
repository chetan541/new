#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, int> msi;
  
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
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}
void gen(int ind,int tmp,vector<set<char>> &v,vector<char> &v1,set<char> &vec){
     if(vec.size()==tmp){v.push_back(vec);return;}
    if(ind==v1.size())return;
   
    
    vec.insert(v1[ind]);
    gen(ind+1,tmp,v,v1,vec);
    auto it = --vec.end();
    vec.erase(it);
    gen(ind+1,tmp,v,v1,vec);
}

ll matching(set<char> &s,string &s1,string &s2){
    ll cnt=0,ans=0;
    REP(i,0,s1.size()-1){
        if(s1[i]==s2[i] || s.find(s1[i])!=s.end()){
            cnt++;
        }
        else{
            ans+=(cnt*(cnt-1))/2 +cnt;cnt=0;
        }
        
        // cout<<ans<<endl;
    }
    ans+=(cnt*(cnt-1))/2 +cnt;
    return ans;
}

int main(){
//  ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s1,s2;cin>>s1>>s2;
        set<char> s;
        REP(i,0,n-1){
           s.insert(s1[i]);
        }
        vector<char> v1;
        for(auto it:s){
            v1.push_back(it);
        }
        set<char> vec;
        int tmp=min((int)s.size(),k);
        vector<set<char>> v;
        gen(0,tmp,v,v1,vec);
        ll ans=INT_MIN;
        for(auto it:v){
            ans=max(ans,matching(it,s1,s2));
            // cout<<endl;
            // for(auto i:it)cout<<i<<" ";
            // cout<<endl;
        }
        cout<<ans<<endl;
        

        
    }
}