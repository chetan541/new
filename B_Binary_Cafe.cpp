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
string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    std::string binary = "";
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary = std::to_string(remainder) + binary;
        decimal /= 2;
    }

    return binary;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<setprecision(15);
        string s=decimalToBinary(n);
        // cout<<s<<endl;
        if(s.size()>k){
            cout<<pow(2,k)<<endl;
        }
        else{
            int count=0,ans=0;
            // if(s[s.size()-1]=='1'){
            //     ans=1;
            // }
            REP(i,0,s.size()-1){
                if(s[i]=='1'){
                    count++;
                }
              }
              int c=0;
              for(int i=0;i<s.size()-1;i++){
                c++;
                if(s[i]=='1'){
                    
                    ans=ans+pow(2,s.size()-1-i);
                    
                    // cout<<pow(2,i)<<" "<<c<<endl;
                }
              }
              if(s[s.size()-1]=='1') ans +=2;
              else ans +=1;
              cout<<ans<<endl;
        }
        

    }
}