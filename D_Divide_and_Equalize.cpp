#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
void sieveoferatosthenes()
{
    int maxi = 1000000;
    for (int i = 0; i <= maxi; i++)
        is_prime[i] = -1;
    is_prime[0] = is_prime[1] = -1;

    for (int i = 2; i<= maxi; i++)
    {
        if (is_prime[i] == -1)
        {
            is_prime[i] = i;
            for (int j = i; j <= maxi; j += i)
                if (is_prime[j] == -1)
                    is_prime[j] = i;
        }
    }

    for (int i = 2; i <= maxi; i++)
    {
        if (is_prime[i] == i) {
            primes.push_back(i);
        }
    }
}
vi SieveOfEratosthenes(int n) 
{  vi v;
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) {  
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p = 2; p <= n; p++){ 
        if (prime[p]) 
            v.push_back(p);}
    return v;
}
int main(){
    int t;
    cin>>t;
    sieveoferatosthenes();
    while(t--){
        int n;
        cin>>n;
        msi m;
        vi v;
        
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
        }
        unordered_map<int,int>mp;
        REP(i,0,n-1){
            
            // int n;cin>>n;
            while(v[i]>1){
            int r=is_prime[v[i]];
            mp[r]++;
            v[i]=v[i]/r;
             }
        }
        int flag=1;
        for(auto it:mp){
            if(it.second!=0){
                if(it.second%n!=0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}