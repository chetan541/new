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
        int n,k;cin>>n>>k;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        unordered_set<int> s;
        int flag=0;
        int ind=n;
        while(s.find(ind)==s.end()){
            if(v[ind-1]>n){
                flag=1;break;
            }
            s.insert(ind);
            int temp=ind-1-v[ind-1];
            if(temp>=0)temp++;
            else temp=n+temp+1;
            ind=temp;
        }
        // for(auto it:s){
        //     cout<<it<<" ";
        // }
        if(flag==0){
            cout<<"Yes"<<endl;
        }
        else{
            if(k<=s.size())cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
    }
}