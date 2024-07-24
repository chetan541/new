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
string getSubSeq(string s, int n)
{
    string res = "";
    int cr = 0;
    while (cr < n) {
 
        // Get the max character from the string
        char mx = s[cr];
        for (int i = cr + 1; i < n; i++)
            mx = max(mx, s[i]);
        int lst = cr;
 
        // Use all the occurrences of the
        // current maximum character
        for (int i = cr; i < n; i++)
            if (s[i] == mx) {
                res += s[i];
                lst = i;
            }
 
        // Repeat the steps for the remaining string
        cr = lst + 1;
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        // sort(s.begin(),s.end(),greater<int>());
        // cout<<getSubSeq(s,n)<<endl;
        string temp=getSubSeq(s,n);
        int x=0,cnt=0;
        while(x<temp.size() && temp[x]==temp[0]){
            cnt++;x++;
        }
        int j=0;
        int n2=(temp.size()/2)-1;
        REP(i,0,n-1){
            if(s[i]==temp[j] ){
                s[i]=temp[temp.size()-1-j];
                // cout<<temp[temp.size()-1-j]<<endl;
                j++;
            }
        }
        int flag=0;
        REP(i,0,n-2){
            if(s[i]>s[i+1])flag=1;
        }
        if(flag==1)cout<<-1<<endl;
        else cout<<temp.size()-cnt<<endl;
        // cout<<s<<endl;
        
    }
}