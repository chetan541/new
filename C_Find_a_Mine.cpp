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

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
       int a,b,c,d;
       
        cout<<"?"<<" "<<1<<" "<<1<<endl;
        cout.flush();
        cin>>a;

        cout<<"?"<<" "<<1<<" "<<m<<endl;
        cout.flush();
        cin>>b;

        // cout<<"?"<<" "<<n<<" "<<m<<endl;
        // cout.flush();
        // cin>>c;

        cout<<"?"<<" "<<n<<" "<<1<<endl;
        cout.flush();
        cin>>d;

        int x1=((a+b)-m+1)/2+1;
        int y1=(a-x1+1)+1;

        int y2=((a+d)-n+1)/2+1;
        int x2=(a-y2+1)+1;
        int x=-1;
        if( x1>0 && y1>0 && x1<=n && y1<=m){cout<<"?"<<" "<<x1<<" "<<y1<<endl;
        cout.flush();
        cin>>x;}
        if(x==0){cout<<"!"<<" "<<x1<<" "<<y1<<endl;
        cout.flush();}
        else{
            cout<<"!"<<" "<<x2<<" "<<y2<<endl;
            cout.flush();
        }
       
       
        
    }
}