#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define sz(x)             int ((x).size())
#define All(x)            (x).begin(), (x).end()
#define scanv(x)          for(auto &i: x) cin >> i
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>v(x);
    scanv(v);
    sort(v.begin(),v.end());
    int cnt=x-2;
    int ans=0;
    
    for(int i=0;i<x-1;i++){
      if(v[i]+2==v[i+1]){
        cnt++;
      }
    }
    if(x>=2 && (v[x-1]+2)%n==v[0]){
      cnt++;
    }
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ttt; cin >> ttt;
    while(ttt--) {
        solve();
    }
    return 0;
}