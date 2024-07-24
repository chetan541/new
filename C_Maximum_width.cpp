#include <bits/stdc++.h>
using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define multi_ordered_set tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

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
bool check(string &s, string &t, int ans, map<int, int> &m1, map<int, int> &m2)
{
    int tmp=INT_MIN;
    int cnt=1;int prev=m1[0];int z=t.size();
    REP(i,1,z-1){
        if(m2[i]-prev>=ans)return true;
        else prev=m1[i];
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    
        int n,m;
        cin >> n>>m;
        string s,t;cin>>s>>t;
        map<int, int> m1,m2;
        int cnt = t.size()-1;
        int szn = s.size();
        for (int i = szn - 1; i >= 0; i--)
        {
            if(s[i]==t[cnt]){
                m2[cnt]=i;cnt--;
            }
            if(cnt==-1)break;
        }
        cnt=0;
        REP(i,0,szn-1){
            if(s[i]==t[cnt]){
                m1[cnt]=i;cnt++;
            }
            if(cnt==int(t.size()))break;
        }
        // for(auto it:m2)cout<<it.F<<" "<<it.S<<endl;
        int l=1,r=n;
        while(r-l>1){
            int mid=(l+r)/2;
            if(check(s,t,mid,m1,m2)==true)l=mid;
            else r=mid-1;
        }
        if(check(s,t,r,m1,m2)==true)cout<<r<<endl;
        else cout<<l<<endl;
    }
