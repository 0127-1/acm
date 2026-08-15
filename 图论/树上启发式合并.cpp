https://www.luogu.com.cn/problem/U41492

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+7;
const double eps=1e-4;
const int mod=998244353;

int son[maxn];
int sz[maxn];
int color[maxn];
int colornum[maxn];
int ans[maxn];
int diff;


void solve(){
    ll n;cin>>n;
    vector<vector<ll>>v(n+1);
    for(int i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)cin>>color[i];
    
    auto dfs1=[&](auto&&dfs1,int i,int fa)->void{
        sz[i]++;
        for(auto x:v[i]){
            if(x==fa)continue;
            dfs1(dfs1,x,i);
            if(!son[i]||sz[x]>sz[son[i]])son[i]=x;
            sz[i]+=sz[x];
        }
    };
    auto effect=[&](auto&&effect,int i,int fa)->void{
        if(++colornum[color[i]]==1)diff++;
        for(auto x:v[i]){
            if(x==fa)continue;
            effect(effect,x,i);
        }
    };
    auto cancel=[&](auto&&cancel,int i,int fa)->void{
        if(--colornum[color[i]]==0)diff--;
        for(auto x:v[i]){
            if(x==fa)continue;
            cancel(cancel,x,i);
        }
    };
    auto dfs2=[&](auto&&dfs2,int i,int fa,int keep)->void{
        for(auto x:v[i]){
            if(x==fa||x==son[i])continue;
            dfs2(dfs2,x,i,0);
        }
        if(son[i]){
            dfs2(dfs2,son[i],i,1);
        }
        if(++colornum[color[i]]==1)diff++;
        for(auto x:v[i]){
            if(x==fa||x==son[i])continue;
            effect(effect,x,i);
        }
        ans[i]=diff;
        if(!keep){
            cancel(cancel,i,fa);
        }
    };
    dfs1(dfs1,1,0);
    dfs2(dfs2,1,0,0);
    ll m;cin>>m;
    while(m--){
        ll k;cin>>k;
        cout<<ans[k]<<'\n';
    }


}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
