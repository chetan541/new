#include <bits/stdc++.h>
using namespace std;

int count(int n)
{  
    int c=0;
    if( n==0)
    {
        return 1;
    }

   c=c+ count(n-1);
   

    if(n>=3)
    {
        c=c+count(n-3);
       // c++;
    }
    return c;
}

void solve() {
    // Your code for solving a single test case goes here
    int n;
    cin>>n;
    cout<<count(n);
}

// Main function
int main() {
    int t;
    // cin >> t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}


// Recurrence Relation for this 
//            {
//                       1         if(n==0)
// count(n)=
//             count(n-1)+count(n-3) otherwise
//             }