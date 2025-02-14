#include<bits/stdc++.h>
using namespace std;
int solve(){
    int l, r;
    cin>>l>>r;
    if(l==1 && r==1) return 1;
    return r-l;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int ans=solve();
        cout<<ans<<endl;
    }
    return 0;
}