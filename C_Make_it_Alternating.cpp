#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
// int fact(int a,int b){
//     ll ans=1;

// }
ll m=998244353;
unsigned long long int factorial(unsigned long long int n)
{
   ll res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res%m)*i)%m;
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        string s;
        
        cin>>s;
        char a=s[0];
        ll i=0;
        ll sum=0;
        ll min_count=0;
        ll con=0;
        ll ans=1;
        vi v;
        
        while(i<s.size()){
             ll count=0;
            if(s[i]==s[i+1]){
                con++;
                
               
                // a=s[i+1];
                while(i<s.size() && s[i]==s[i+1]){
                    i++;
                    count++;
                }
                count++;
                // v.push_back(count);
                min_count=min_count+count-1;
                ans=(ans*count)%m;
                // sum=(sum+factorial(count))%m;
                i++;

                // cout<<count<<endl;
            }
            else{
                i++;
            }
        }
        
        // sum=(sum+factorial(con))%m;
        sum=(ans%m)*(factorial(min_count)%m)%m;
        if(min_count==0){
            cout<<0<<" "<<1<<endl;
        }
        else{
        cout<<min_count<<" "<<sum<<endl;}



    }
}