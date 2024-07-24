#include <bits/stdc++.h>
using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<long long> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

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

bool check(ll num, vi &v, ll k)
{
    ll sum = 0;
    REP(i, 0, v.size() - 1)
    {
        ll y = v[i];
        ll tmp = 0, tmp1 = 0, ind = -1;

        for (int j = 63; j >= 0; j--)
        {
            if (!(y & (1LL << j)) && (num & (1LL << j)))
            {
                sum += (1LL << j) - y % ((1LL << j));
                y += (1LL << j) - y % ((1LL << j));
                ;
            }
        }
        //  cout<<i<<" "<<ind<<" "<<tmp<<" "<<tmp1<<endl;
    }
    // cout<<sum<<" "<<num<<endl;

    if (sum <= k)
    {
        // cout << "true" << endl;
        return true;
    }
    else
    {
        // cout << "false" << endl;
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    ll n, q;
    cin >> n >> q;
    vi v;
    ll x = INT_MIN;
    REP(i, 0, n - 1)
    {
        ll a;
        cin >> a;
        x = max(x, a);
        v.push_back(a);
    }
    // check(375324,v,1172209);
    REP(i, 0, q - 1)
    {
        ll k;
        cin >> k;
        ll sum = 0,ans=0;
        vi vec,org;
        vec=v;org=v;
        
            ll y = v[i];
          

            for (int j = 62; j >= 0; j--)
            {
                sum=0;
                REP(i,0,n-1){
                if (!(vec[i] & (1LL << j)) )
                {
                    sum += (1LL << j) - vec[i] % ((1LL << j));
                    
                }
                if(sum>k)break;
                if(!(vec[i] & (1LL << j)))vec[i]+=(1LL << j) - vec[i] % ((1LL << j));

                }
                // cout<<sum<<" "<<k<<endl;
                if(sum<=k){
                k-=sum;
                ans+=(1LL<<j);
                v=vec;
                }
                else{
                    vec=v;
                }
            }
            // for(auto it: v){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            v=org;
            cout<<ans<<endl;
        
    }
}
