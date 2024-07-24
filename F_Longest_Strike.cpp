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
        vi v,temp;
        msi m;
        REP(i,0,n-1){
            int a;cin>>a;
            m[a]++;
            v.push_back(a);
        }
        for(auto it:m){
            if(it.second>=k)temp.push_back(it.first);
        }
        sort(temp.begin(),temp.end());
        if(temp.size()==0)cout<<-1<<endl;
        else{
            int l=temp[0],r=temp[0];
            int i=0,j=1;
            int cnt=0;
            
            while(i<temp.size() && j<temp.size()){
                // cout<<temp[j]<<" "<<temp[j-1]<<endl;
                if((temp[j]-temp[j-1])==1){
                    
                    
                if(j-i+1>cnt){
                    l=temp[i];r=temp[j];cnt=j-i+1;
                }
                }
                else{
                    i=j;
                    
                }
                j++;
            }
            cout<<l<<" "<<r<<endl;

        }

        
    }
}