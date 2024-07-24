#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c,q;
        cin>>n>>c>>q;
        string s;
        cin>>s;
        // // s.append('k');
        // cout<<s;

        for (int i = 0; i < c; i++)
        {
            /* code */
            int a,b;
            cin>>a>>b;
            // cout<<s[a-1]<<" "<<s[b-1]<<endl;
            s.append(s.begin()+a-1,s.begin()+b);
            
            // cout<<s<<endl;
        }
        // cout<<s<<endl;
        for (int i = 0; i < q; i++)
        {
            /* code */
            int v;
            cin>>v;
            cout<<s[v-1]<<endl;

        }
        
        

    }
}
