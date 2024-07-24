#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<char> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, ll> msi;
  
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
        ll k;
        string s;
        cin>>s>>k;
        // cout<<k<<endl;
        stack<char> v;
        vi count;
        REP(i,0,s.size()-1){
            if(v.size()==0){
                v.push(s[i]);
            }
            else{
                if(s[i]>=v.top()){
                    v.push(s[i]);
                }
                else{
                    while(v.size()!=0 && v.top()>s[i]){
                        count.push_back(v.top());
                        v.pop();
                        
                    
                    }
                    v.push(s[i]);
                    
                }
            }
        }
        while(v.size()!=0){
            count.push_back(v.top());
            v.pop();
        }
        msi m;
        // for(auto it:count){
           
        // }
        
        ll pos=0,temp=s.size(),rem=k,curr=s.size();
        while(k>temp){
            pos++;
            rem-=curr;
            curr--;
            temp+=curr; 
        }
        // cout<<k<<pos<<rem<<endl;
        REP(i,0,pos-1){
            m[count[i]]++;
            // cout<<count[i]<<m[count[i]]<<endl;
        }
        rem;
        ll j=0,c=0;
        while(j<s.size() ){
            if(m[s[j]]>0){
                m[s[j]]--;
                s[j]='0';
            }
            j++;
        }
        // cout<<s<<rem<<endl;
        // remove(s.begin(),s.end(),'0');
        ll y=0,tem=0;
        while(y<s.size() && tem<rem){
            if(s[y]!='0'){
                tem++;
            }
            y++;
        }
        // cout<<s<<endl;
        cout<<s[y-1];
        
        // cout<<s[c];
    }
}