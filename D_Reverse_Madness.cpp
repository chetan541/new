#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
void init_code()
{
#ifndef ONLINE_JUDGE
// freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
 
// void _print(ll t) {cerr << t;}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print( lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
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
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
  
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
void swapIndexes(std::string& str, int index1, int index2) {
    // Check if the indexes are within the range of the string
    if (index1 < 0 || index1 >= str.size() || index2 < 0 || index2 >= str.size()) {
        std::cerr << "Error: Index out of range." << std::endl;
        return;
    }

    // Swap the characters at index1 and index2
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
       int n,k;cin>>n>>k;
       string s;cin>>s;
       vi v1,v2;
       REP(i,0,k-1){
        int a;cin>>a;
        v1.pb(a);
       }

       REP(i,0,k-1){
        int a;cin>>a;
        v2.pb(a);
       }

       int q;cin>>q;
       vi vis(n+1,0);
       REP(i,0,q-1){
        int a;cin>>a;
        vis[a]++;
       }
       debug(vis);

       REP(i,0,k-1){
        int prev=0;
        int mid=(v1[i]+v2[i])/2,tmp=0;
        // cout<<mid<<endl;
        REP(j,v1[i],mid){
            // cout<<j<<" "<<v2[i]-j+v1[i]<<" "<<prev<<endl;
            int cnt=vis[j]+vis[v2[i]-j+v1[i]];
            if((cnt+prev)%2==0)prev=(0);
            else{
                swapIndexes(s,j-1,v2[i]-j+v1[i]-1);prev=(1);
            }
        }
       }
       cout<<s<<endl;
    }
}