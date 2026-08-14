https://www.luogu.com.cn/problem/P3379

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

int power;
int deep[maxn];
int stjump[maxn][d];

void solve(){
    ll n,m,s;cin>>n>>m>>s;
    vector<vector<int>>v(n+1);
    for(int i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int t=-1;
    int temp=n;
    while(temp){
        t++;
        temp>>=1;
    }
    power=t;
    auto dfs=[&](auto&&dfs,int i,int fa)->void{
        deep[i]=deep[fa]+1;
        stjump[i][0]=fa;
        for(int j=1;j<=power;j++){
            stjump[i][j]=stjump[stjump[i][j-1]][j-1];
        }
        for(auto x:v[i]){
            if(x==fa)continue;
            dfs(dfs,x,i);
        }
    };
    dfs(dfs,s,0);
    auto lca=[&](int a,int b)->int{
        if(deep[a]<deep[b])swap(a,b);
        for(int i=power;i>=0;i--){
            if(deep[stjump[a][i]]>=deep[b]){
                a=stjump[a][i];
            }
        }
        if(a==b)return a;
        for(int i=power;i>=0;i--){
            if(stjump[a][i]!=stjump[b][i]){
                a=stjump[a][i];
                b=stjump[b][i];
            }
        }
        return stjump[a][0];
    };
    while(m--){
        ll x,y;cin>>x>>y;
        cout<<lca(x,y)<<'\n';
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
