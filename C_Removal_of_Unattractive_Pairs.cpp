#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<char> vi;
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
        
        // stack<char> ans,opt,hope1,hope2;
        // // ans.push(s[0]);
        // REP(i,0,s.size()-1){
        //     if(ans.size()>=1  && ans.top()!=s[i] &&  i<s.size()-1 && s[i]==s[i+1] ){
                
        //         // cout<<ans.size()<<endl;
        //         ans.pop();
        //         // i++;
        //     }
        //    else{
        //     ans.push(s[i]);
        //    }
        // //    cout<<ans.top()<<endl;
        // }
        // vi v;
        // while(!ans.empty()){
        //     v.push_back(ans.top());
            
        //     ans.pop();
        // }
        // for(int i=v.size()-1;i>=0;i--){
        //     if(opt.size()>=1  && opt.top()!=v[i]){
                
        //         opt.pop();
        //         // ans.pop();
        //     }
        //    else{
        //     opt.push(v[i]);
        //    }
        // }


        // int temp=min(ans.size(),opt.size());
        // cout<<opt.size()<<endl; 
        msi m;
        REP(i,0,n-1){
            m[s[i]]++;
        }
        int ans=0;
        for(auto it:m){
            if(it.second>ans)ans=it.second;
        }
        // cout<<ans<<endl;
        if(2*ans-n>=0)ans=2*ans-n;
        else ans=0;
        
        if(n%2==0)cout<<ans<<endl;
        else cout<<max(1,ans)<<endl;

        }
}