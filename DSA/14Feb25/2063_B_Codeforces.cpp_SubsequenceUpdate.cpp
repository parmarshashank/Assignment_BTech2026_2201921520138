#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(){
    ll n, l, r;
    cin>>n>>l>>r;
    l--, r--;
    vector<int> a(n);
    for(auto i=0; i<n; i++) cin>>a[i];
    ll required= r-l+1;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for(ll i=0; i<=r; i++)
        pq.push(a[i]);
    ll leftSum=0;
    while(required--){
        leftSum+=pq.top();
        pq.pop();
    }
    required=r-l+1;
    while(!pq.empty()) pq.pop();
    for(ll i=l; i<n; i++)
        pq.push(a[i]);
    ll rightSum=0;
    while(required--){
        rightSum+=pq.top();
        pq.pop();
    }
    return (leftSum<rightSum)?leftSum:rightSum;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll ans= solve();
        cout<<ans<<endl;
    }
    return 0;
}