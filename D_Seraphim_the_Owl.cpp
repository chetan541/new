#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define fer(i, a, b) for (int i = a; i <= b; i++)
#define frr(i, a, b) for (int i = a; i >= b; i--)
//#define mod 998244353
# define mod  1000000007
#define precise(n) cout << fixed << setprecision(n)
#define popcnt(n) __builtin_popcountll(n)
#define int  long long
#define all(x) (x).begin(), (x).end()
void printDivisors(int n,set<int>&st); 
long long binpow(long long a, long long b, long long m);
typedef long long ll;
#define sz(v)   ((int)(v).size())
using vi = vector<int>;
using vbl = vector<bool>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;
using vpii = vector<pii>;
using vai3 = vector<ai3>;
using vvi = vector<vi>;
using vvpii = vector<vpii>;
using sti = set<int>;
using mpii = map<int, int>;
#define vecin(v, n) vi v(n); for (int &x : v) cin >> x
#define vecin1(v, n) vi v(n + 1); v[0] = 0; fer (i, 1, n) cin >> v[i]
#define vecp(v) { for (auto x : v) cout << x << ' '; cout << endl; }
#define vecpp(v) { for (auto [x, y] : v) cout << x << ' ' << y << endl; }
#define mem(dp, x) memset(dp, x, sizeof dp)



void solve(){
     int n,m;cin>>n>>m;
     int a[n];
     int b[n];
     for(int i=0;i<n;i++) cin>>a[i]; 
     for(int i=0;i<n;i++) cin>>b[i]; 

     int sum =0;
     for(int i=m;i<n;i++) sum +=min(a[i],b[i]);
     int mn=a[m-1];
     int down=0;
     for(int i=m-1;i>=0;i--){
        mn=min(mn,down+a[i]);
        down +=b[i];
     }
     cout<<sum+mn;cout << "\n";
     





}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
 return 0;
} 



void printDivisors(int n,set<int>&st) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i)   st.insert(i);
            else st.insert(i),st.insert(n/i);
        } 
    } 
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}