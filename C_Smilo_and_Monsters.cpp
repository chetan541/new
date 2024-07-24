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
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        ll steps=0;
        ll temp=v[n-1];
        while(r>l){
            if(temp>v[l]){
                temp-=v[l];
                steps+=v[l];l++;
                if(l==r && temp<=1)steps++;
                // cout<<steps<<" "<<v[l]<<endl;
            }
            else{
                v[l]-=temp;steps+=1+temp;
                if(v[l]==0)l++;
                r--;
                if(l!=r)temp=v[r];
                else temp=v[l];
            }
            // cout<<l<<r<<" "<<temp<<" "<<steps<<endl;
        }
        if(temp!=0){
        if(temp%2==0)steps+=temp/2+1;
        else{
            if(temp==1)steps++;
            else steps+=temp/2+2;
        }
        }
        cout<<steps<<endl;
        
    }
}