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
bool isEven(int position) {
    return position % 2 == 0;
}

void sortStringEvenOdd(std::string &input) {
    std::string evenChars, oddChars;

    for (int i = 0; i < input.length(); ++i) {
        if (isEven(i)) {
            evenChars += input[i];
        } else {
            oddChars += input[i];
        }
    }

    std::sort(evenChars.begin(), evenChars.end());
    std::sort(oddChars.begin(), oddChars.end());

    for (int i = 0, evenIdx = 0, oddIdx = 0; i < input.length(); ++i) {
        if (isEven(i)) {
            input[i] = evenChars[evenIdx];
            evenIdx++;
        } else {
            input[i] = oddChars[oddIdx];
            oddIdx++;
        }
    }
    cout<<input<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        if(k%2==0){
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
        else{
            sortStringEvenOdd(s);
            // cout<<s<<endl;
        }
    }
}