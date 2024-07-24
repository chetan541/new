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
void findFactors(ll num, unordered_set<ll>& factors) {
    // Clear the existing set
    // factors.clear();

    // Iterate up to the square root of the number
    for (int i = 1; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            // i is a factor
            
            if(i%2==0)factors.insert(i/2+1);
            // else factors.insert(i+1);

            // num / i is also a factor (unless i and num/i are the same, in the case of a perfect square)
            if (i != num / i) {
                if((num/i)%2==0)factors.insert((num/i)/2+1);
            // else factors.insert(num/i+1);
            }
        }
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        
        unordered_set<ll> ans;
        findFactors((n+x-2),ans);
        findFactors((n-x),ans);

        int cnt=0;
        for(auto it:ans){
            if(it>=x )cnt++;
        }
        cout<<cnt<<endl;
        
    }
}