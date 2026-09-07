https://codeforces.com/problemset/problem/600/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+7;
const int mod=100000000;

#define int long long

int sz[maxn];
int col[maxn];
int dfn[maxn];
int out[maxn];
int son[maxn];
int id[maxn];
int ans[maxn];
int p[maxn];
int timer=0;
int len=0,mx=0;
vector<vector<int>>d(maxn+1);

void add(int i){
    ++p[col[i]];
    if(p[col[i]]>mx){
        mx=p[col[i]];
        len=col[i];
    }
    else if(p[col[i]]==mx){
        len+=col[i];
    }
}

void del(int i){
    --p[col[i]];
}

void dfs0(int i,int fa){
    sz[i]=1;
    dfn[i]=++timer;
    id[dfn[i]]=i;
    for(auto x:d[i]){
        if(x==fa)continue;
        dfs0(x,i);
        sz[i]+=sz[x];
        if(!son[i]||sz[x]>sz[son[i]]){
            son[i]=x;
        }
    }
    out[i]=timer;
}


void dfs(int i,int fa,bool k){
    for(auto x:d[i]){
        if(x==fa||x==son[i])continue;
        dfs(x,i,0);
    }
    if(son[i]){
        dfs(son[i],i,1);
    }
    for(auto x:d[i]){
        if(x==fa||x==son[i])continue;
        for(int t=dfn[x];t<=out[x];t++){
            add(id[t]);
        }
    }
    add(i);
    ans[i]=len;
    if(!k){
        mx=0;
        len=0;
        for(auto x:d[i]){
            if(x==fa)continue;
            for(int t=dfn[x];t<=out[x];t++){
                del(id[t]);
            }
        }
        del(i);
    }
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>col[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    dfs0(1,0);
    // for(int i=1;i<=n;i++){
    //     cout<<sz[i]<<'\n';
    // }
    dfs(1,0,1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)
    solve();
}
