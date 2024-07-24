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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n)
{
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}
bool check(msi &temp, int k, int n)
{
    for (char c = 'a'; c <= 'a' + k - 1; ++c)
    {
        if (temp[c] < n)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        msi temp;
        string ans;
        int prev = 1;
        REP(i, 0, m - 1)
        {
            temp[s[i]] = min(prev , temp[s[i]]+1);
            if (check(temp, k, prev) == true){ans.push_back(s[i]);prev++;}
        }
        int flag = 1;
        int h=INT_MAX;
        int g=INT_MIN;
        char p,o;
        for (char c = 'a'; c <= 'a' + k - 1; ++c)
        {
            // cout<<c<<" "<<temp[c]<<endl;
            if (temp[c] < n)
            {
                flag = 0;
                // break;
            }
            if(temp[c]<h){
                h=temp[c];
                p=c;
            }
            if(temp[c]>g){
                g=temp[c];
                o=c;
            }
        }


        // for (char c = 'a'; c <= 'a' + k - 1; ++c){
        //     if(temp[c]<n){
        //         REP(j,0,n-1){
        //             ans.push_back(c);
        //         }
        //     }
        // }
        if(flag==1)cout<<"YES";
        else {cout<<"NO"<<endl;
         cout<<ans;
         REP(i,ans.size()+1,n)cout<<p;
        }

        cout<<endl;
        }
    }
