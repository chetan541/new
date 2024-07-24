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
  
#define INF 2000000000 // 2 biint llion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vi v;
        vi v1;
        int cnt=0;
        REP(i,0,n-1){
            int a;
            cin>>a;
            if(a<=k){
                cnt++;
            }
            v.push_back(a);
        }
        REP(i,0,n-1){
            int b;
            cin>>b;
            v1.push_back(b);
        }
        int f=0,l=1;
        int count=0;
        int count2=v[0];
        
        while(l<n){
            count2=v[l]+count2;
            
            if ( v1[l - 1]%v1[l] == 0 && count2 <= k) {
                // l++;
                // cout<<" "<<count2<<endl;
                if(l-f+1>count){
                    count=l-f+1;
                    
                    

                }
                l++;
                
            }
            else if(count2>k && v1[l - 1]%v1[l] == 0){
                count2=count2-v[f]-v[l];
                f++;
            }
            else{
                count2=v[l];
                f=l;
                l=l+1;
            }
            
            // cout<<" "<<count<<endl;
            }
            if(count==0){
                if(cnt==0){
                    cout<<0<<endl;
                }
                else{
                    cout<<1<<endl;
                }

            }
            else{
            cout<<count<<endl;

        }
       


    }
}
