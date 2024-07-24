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
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion

// If you need to recall how to use memset:
#define MEMSET_INF 127     // about 2B
#define MEMSET_HALF_INF 63 // about 1B
// int is_prime[1000001];
// vector<int> primes;
// vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
//   memset(prime, true, sizeof(prime));

//   for (int p = 2; p * p <= n; p++) {
//      if (prime[p] == true) {
//          for (int i = p * p; i <= n; i += p)
//              prime[i] = false;
//     }
// }
// for (int p = 2; p <= n; p++) {
//   if (prime[p])
//       v.push_back(p);
//}
// return v;
//}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        msi m;
        string s;
        cin >> s;
        REP(i, 0, n-1)
        m[s[i]]++;
        for (char c = 'a'; c <= 'z'; c++) {
    if (m.find(c) == m.end()) {
        m[c] = 0;  // If 'c' is not present in the map, add it with value 0.
    }
}

        ll ans = INT_MAX,size=n;
        vector<pair<int,char>> v;
        for(auto it:m){
            v.push_back({it.second,it.first});
        }
        
        sort(v.begin(),v.end());
        
        
        for (int i = 26; i >= 1; i--)
        {
            if (n % i == 0)
            {
                ll ex = 0, tmp = n / i,cnt=0,sum=0;
                for(int j=25;j>=26-i;j--){
                    // cout<<v[j].second<<endl;
                    ex+=-v[j].first+tmp;sum+=v[j].first;
                    if(-v[j].first+tmp>0)cnt+=-v[j].first+tmp;
                }
                // cout<<ex<<" "<<cnt<<endl;
                if(ex-n+sum==0){
                    if(ans>cnt)size=i;ans=min(ans,cnt);}
                
            }
        }
        
        queue<char> q;
        for(int i=25;i>=26-size;i--){
            // cout<<v[i].second<<endl;
            if(v[i].first<n/size){
                
                REP(j,1,n/size-v[i].first)q.push(v[i].second);
            }
        }

        for(int i=0;i<=26-size-1;i++){
            // cout<<v[i].second<<endl;
            if(m[v[i].second]!=0)m[v[i].second]+=n/size;
        }
        // while(!q.empty()){cout<<q.front()<<endl;q.pop();}
        // for(auto it:m)cout<<it.first<<" "<<it.second<<endl;
        REP(i,0,n-1){
   
            
    if(m[s[i]] > n/size && q.size() != 0){
        m[s[i]]--;
        s[i] = q.front(); q.pop();
                
    }
    // Add more print statements or debug information if needed
  
}
        cout<<ans<<endl;
        cout<<s<<endl;
    }
}