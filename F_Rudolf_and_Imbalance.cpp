#include <bits/stdc++.h>
using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<ll, int> msi;

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
template <typename KeyType, typename ValueType>
ValueType findSecondLargestValue(const std::map<KeyType, ValueType>& myMap) {
    if (myMap.size() < 2) {
        std::cerr << "Map has less than two elements. Returning a default-constructed value." << std::endl;
        return ValueType();  // Return a default-constructed value if the map has less than two elements
    }

    auto rit = myMap.rbegin();  // Iterator pointing to the first element (largest key-value pair)
    ++rit;  // Move to the second element (second largest key-value pair)

    return rit->second;  // Return the second largest value
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vi v1, v2, v3;
        REP(i, 0, n - 1)
        {
            ll a;
            cin >> a;
            v1.push_back(a);
        }
        REP(i, 0, m - 1)
        {
            ll a;
            cin >> a;
            v2.push_back(a);
        }
        REP(i, 0, k - 1)
        {
            ll a;
            cin >> a;
            v3.push_back(a);
        }
        msi val;
        ll tmp=INT_MIN;
        ll l=0,r=1; 
        REP(i, 1, n - 1)
        {
            ll x=v1[i] - v1[i - 1];
            val[x]++;
            if(x>tmp){
                l=i-1;r=i;
                tmp=x;
            }   
        }
        
        ll f=v1[l]+(tmp+1)/2; 
        // cout<<f<<" "<<v1[r]<<endl;
        sort(v3.begin(),v3.end());
        ll ans=0;
        ll y=LLONG_MAX;
        REP(i,0,m-1){
            auto it=lower_bound(v3.begin(),v3.end(),f-v2[i]);
            
            if(it!=v3.end()){
                // cout<<*it<<" "<<v2[i]<<endl;
                ll cmp=max(*it+v2[i]-v1[l],v1[r]-*it-v2[i]);
                if(cmp<y){
                    ans=*it;
                    y=cmp;
                }
            }
            if(it!=v3.begin() ){
            
                it--;
                // cout<<*it<<" "<<v2[i]<<endl;
                ll cmp=max(*it+v2[i]-v1[l],v1[r]-*it-v2[i]);;
                if(cmp<y){
                    ans=*it;y=cmp;

                }
            
            }
            // cout<<ans<<" "<<v2[i]<<endl;
        }
        if(y>v1[r]-v1[l])y=v1[r]-v1[l];
        if(n==2)cout<<y<<endl;
        else{
            auto high=val.rbegin();
            if(high->second>1)y=max(y,high->first);
            else{
                high++;
                y=max(y,high->first);
            }
            cout<<y<<endl;
        }

    }
}