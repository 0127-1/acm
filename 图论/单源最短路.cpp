https://www.nowcoder.com/practice/2850d7c941f6494e82ba74bc899eb512?channelPut=tracker2

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=5e5+7;
const double eps=1e-4;
const int mod=998244353;
const int d=20;

void solve(){
    ll n,m,q;cin>>n>>m>>q;
    vector<vector<pair<ll,ll>>>d(n+1);
    for(int i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        d[a].push_back({b,c});
        d[b].push_back({a,c});
    }
    vector<ll>dis(n+1,inf);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>cnt;
    cnt.push({0,1});
    dis[1]=0;
    while(cnt.size()){
        auto [k,y]=cnt.top();
        cnt.pop();
        if(k>dis[y])continue;
        for(auto [a,b]:d[y]){
            if(dis[y]+b<dis[a]){
                dis[a]=dis[y]+b;
                cnt.push({dis[a],a});
            }
        }
    }
    ll ans=0;
    while(q--){
        ll a;cin>>a;
        ans+=dis[a]*2;
    }
    cout<<ans<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
