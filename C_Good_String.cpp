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


void solve(){
    int n;
        cin>>n;
        string s;
        cin>>s;
        int count=0;
        
        // ll i=0;
        // while(i<s.size()-1){
        //     // cout<<s[i]<<" ";
        //     cout<<"  "<<i;
        //     if(s[i]==s[i+1]){
        //         i++;
        //         count++;
                
        //     }
        //     else{
        //         i=i+2;
        //     }
        // }
        // cout<<count<<endl;
        //  i=0;

        
        // while(i<s.size()-1){
        //     cout<<s[i];
        //     if(s[i]==s[i+1]){
        //         i=i+2;
        //         // count++;
                
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // if((s.size()-count)%2==0){
        //     cout<<s[n-1]<<endl;

            
        // }
        // else{
        //     cout<<endl;
        // }
        ll j=1;
        string si;
        while(j<=s.size()){
            si.push_back(s[j-1]);
            if((j-count)%2!=0){
                
                if(s[j-1]==s[j]){
                    count++;
                    // cout<<count<<endl;
                    j++;
                    while(s[j-1]==s[j] && j<=s.size()-1){
                        count++;
                        // cout<<count<<endl;
                        j++;
                    }
                }

            }
            j++;
            
        }
        
        if((si.size())%2==0){
            
            cout<<count<<endl;
            cout<<si<<endl;

            
        }
        else{
            // cout<<si<<endl;
            count++;
            cout<<count<<endl;
            si.pop_back();
            cout<<si<<endl;
        }

}

int main(){
     solve();
   
    
}