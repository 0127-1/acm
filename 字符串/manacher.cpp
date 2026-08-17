https://www.luogu.com.cn/problem/P3805
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const int maxn=2e5+7;
const int mod=1e9+7;

void solve() {
    string s;cin>>s;
    string f="#";
    for(int i=0;i<s.size();i++){
        f+=s[i];
        f+='#';
    }
    vector<int>p(f.size());
    int ans=0;
    for(int i=0,r=0,c=0,len=1;i<f.size();i++){
        if(r>i)len=min(p[2*c-i],r-i);
        while(i+len<f.size()&&i-len>=0&&f[i-len]==f[i+len]){
            len++;
        }
        if(i+len>r){
            r=i+len;
            c=i;
        }
        ans=max(ans,len);
        p[i]=len;
    }
    cout<<ans-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
