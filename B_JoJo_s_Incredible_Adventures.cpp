#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long int ll;
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
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        long long int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') ++cnt;
        }
        if(cnt==n){cout<<n*n<<endl;continue;}
        long long int mex=0;
        long long int curr=0;
        // int l=0,r=0;
        // int x=0,k=s.size()-1;
        // if(s[x]=='1' && l==0){
        //         l++;
        //     }
        // while(s[x]==s[x+1] && s[x]=='1'){
            
        //     x++;
        //     l++;
        // }
        // if(s[k]=='1' && r==0){
        //         r++;
        //     }
        // while(s[k]==s[k-1] && s[k]=='1'){
            
        //     k--;
        //     r++;
        // }
        // cout<<l<<" "<<r;
        
        // REP(i,0,s.size()-1){
        //     if(s[i]=='1'&& curr==0){
        //         curr++;
        //     }
        //     if(s[i]==s[i+1] && s[i]=='1'&& i<s.size()-1){
        //         curr++;
        //         // cout<<curr<<endl;
        //     }
        //     else{
        //         if(curr>mex){
        //             mex=curr;
        //         }
        //         curr=0;
        //     }

        // }
        // if(l+r>mex && l-1<k){
        //     mex=l+r;
        // }
        ll i=0;
        ll f=0;
        ll l=0;
        ll x=0,k=s.size()-1;
        if(s[x]=='1' && l==0){
                l++;
            }
        while(s[x]==s[x+1] && s[x]=='1'){
            
            x++;
            l++;
        }
        while(i<s.size()){
            if(s[i]=='0'){
                f=1;
            }
            if(s[i]=='1'&& curr==0){
                curr++;
            }
            if(s[i]==s[i+1] && s[i]=='1' && i<s.size()-1){
                curr++;
                // cout<<curr<<endl;
            }
           else if(s[s.size()-1]=='1' && i==s.size()-1){
                if(f==1){
                curr=curr+l;}
                else{
                    curr=curr;
                }
                if(curr>mex){
                    mex=curr;
                }

            }

            else{
                if(curr>mex){
                    mex=curr;
                }
                curr=0;
            }
            // cout<<curr<<f<<endl;
            
            
            i++;

        }

        ll max=0;
        ll cur=0;
        ll y=1;
        ll j=mex;
        ll ans=s.size();
        while(y<=j){
            curr=y*j;
                if(curr>max){
                    max=curr;
                }
                y++;
                j--;
            }
            if(mex==0) cout<<0<<endl;
            else if(f==1){
            cout<<max<<endl;}
            

        }
}

    