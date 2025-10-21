/*
 * @Author: dsaDadas11
 * @Date: 2025-10-02 14:58:02
 * @LastEditTime: 2025-10-02 20:11:59
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=2e5+7;
constexpr int mod=998244353;

// 处理负数取模，确保结果为非负
inline int mod_add(int a, int b) { return (a + b) % mod; }
inline int mod_mul(int a, int b) { return (1LL * a * b) % mod; }

struct Tree
{
    int l,r;
    int olen,elen;  // 奇数、偶数位置的数量（不需要取模）
    int add;        // 延迟标记（取模处理）
    // 新增 osum4 和 esum4 存储四次方和
    int osum1,osum2,osum3,osum4;  // 奇数位置的1/2/3/4次方和（取模）
    int esum1,esum2,esum3,esum4;  // 偶数位置的1/2/3/4次方和（取模）
} t[N<<2];
int a[N];

void pushup(int rt)
{
    t[rt].olen = t[ls].olen + t[rs].olen;
    t[rt].elen = t[ls].elen + t[rs].elen;

    // 奇数位置和取模（新增 osum4 合并）
    t[rt].osum1 = mod_add(t[ls].osum1, t[rs].osum1);
    t[rt].osum2 = mod_add(t[ls].osum2, t[rs].osum2);
    t[rt].osum3 = mod_add(t[ls].osum3, t[rs].osum3);
    t[rt].osum4 = mod_add(t[ls].osum4, t[rs].osum4);  // 合并四次方和

    // 偶数位置和取模（新增 esum4 合并）
    t[rt].esum1 = mod_add(t[ls].esum1, t[rs].esum1);
    t[rt].esum2 = mod_add(t[ls].esum2, t[rs].esum2);
    t[rt].esum3 = mod_add(t[ls].esum3, t[rs].esum3);
    t[rt].esum4 = mod_add(t[ls].esum4, t[rs].esum4);  // 合并四次方和
}

void build(int rt,int l,int r)
{
    t[rt]={l,r,0,0,0, 0,0,0,0, 0,0,0,0};  // 初始化时包含四次方和字段
    if(l==r)
    {
        int val = a[l] % mod;  // 初始值先取模（注：模运算仍为潜在缺陷）
        if(l&1)  // 奇数位置
        {
            t[rt].olen = 1;
            t[rt].elen = 0;
            t[rt].osum1 = val;
            t[rt].osum2 = mod_mul(val, val);          // 平方
            t[rt].osum3 = mod_mul(t[rt].osum2, val);  // 立方
            t[rt].osum4 = mod_mul(t[rt].osum3, val);  // 四次方（新增）
        }
        else  // 偶数位置
        {
            t[rt].elen = 1;
            t[rt].olen = 0;
            t[rt].esum1 = val;
            t[rt].esum2 = mod_mul(val, val);          // 平方
            t[rt].esum3 = mod_mul(t[rt].esum2, val);  // 立方
            t[rt].esum4 = mod_mul(t[rt].esum3, val);  // 四次方（新增）
        }
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(rt);
}

void apply(int rt,int c)
{
    c %= mod;  // 对增量先取模
    t[rt].add = mod_add(t[rt].add, c);  // 延迟标记取模

    // 预计算增量的各次幂（减少重复计算）
    int c1 = c;
    int c2 = mod_mul(c1, c1);       // c²
    int c3 = mod_mul(c2, c1);       // c³
    int c4 = mod_mul(c3, c1);       // c⁴（新增）

    // -------------------------- 奇数位置更新（新增四次方处理） --------------------------
    // 1. 四次方和：(x+c)^4 = x⁴ + 4c x³ + 6c² x² + 4c³ x + c⁴
    int term1_4 = mod_mul(4, mod_mul(c1, t[rt].osum3));  // 4c x³
    int term2_4 = mod_mul(6, mod_mul(c2, t[rt].osum2));  // 6c² x²
    int term3_4 = mod_mul(4, mod_mul(c3, t[rt].osum1));  // 4c³ x
    int term4_4 = mod_mul(c4, t[rt].olen);              // c⁴ * 元素个数
    t[rt].osum4 = mod_add(t[rt].osum4, mod_add(term1_4, mod_add(term2_4, mod_add(term3_4, term4_4))));

    // 2. 三次方和（原有逻辑不变）
    int term1_3 = mod_mul(3, mod_mul(c1, t[rt].osum2));
    int term2_3 = mod_mul(3, mod_mul(c2, t[rt].osum1));
    int term3_3 = mod_mul(c3, t[rt].olen);
    t[rt].osum3 = mod_add(t[rt].osum3, mod_add(term1_3, mod_add(term2_3, term3_3)));

    // 3. 二次方和（原有逻辑不变）
    int term1_2 = mod_mul(2, mod_mul(c1, t[rt].osum1));
    int term2_2 = mod_mul(c2, t[rt].olen);
    t[rt].osum2 = mod_add(t[rt].osum2, mod_add(term1_2, term2_2));

    // 4. 一次方和（原有逻辑不变）
    t[rt].osum1 = mod_add(t[rt].osum1, mod_mul(c1, t[rt].olen));

    // -------------------------- 偶数位置更新（新增四次方处理） --------------------------
    // 1. 四次方和（同奇数位置公式）
    term1_4 = mod_mul(4, mod_mul(c1, t[rt].esum3));
    term2_4 = mod_mul(6, mod_mul(c2, t[rt].esum2));
    term3_4 = mod_mul(4, mod_mul(c3, t[rt].esum1));
    term4_4 = mod_mul(c4, t[rt].elen);
    t[rt].esum4 = mod_add(t[rt].esum4, mod_add(term1_4, mod_add(term2_4, mod_add(term3_4, term4_4))));

    // 2. 三次方和（原有逻辑不变）
    term1_3 = mod_mul(3, mod_mul(c1, t[rt].esum2));
    term2_3 = mod_mul(3, mod_mul(c2, t[rt].esum1));
    term3_3 = mod_mul(c3, t[rt].elen);
    t[rt].esum3 = mod_add(t[rt].esum3, mod_add(term1_3, mod_add(term2_3, term3_3)));

    // 3. 二次方和（原有逻辑不变）
    term1_2 = mod_mul(2, mod_mul(c1, t[rt].esum1));
    term2_2 = mod_mul(c2, t[rt].elen);
    t[rt].esum2 = mod_add(t[rt].esum2, mod_add(term1_2, term2_2));

    // 4. 一次方和（原有逻辑不变）
    t[rt].esum1 = mod_add(t[rt].esum1, mod_mul(c1, t[rt].elen));
}

void pushdown(int rt)
{
    if(t[rt].add != 0)  // 只有当有延迟标记时才下推
    {
        apply(ls, t[rt].add);
        apply(rs, t[rt].add);
        t[rt].add = 0;  // 清空标记
    }
}

void upd(int rt,int l,int r,int c)
{
    if(t[rt].r<l||t[rt].l>r) return;
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        apply(rt,c);
        return;
    }
    pushdown(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) upd(ls,l,mid,c);
    if(mid+1<=r) upd(rs,mid+1,r,c);
    pushup(rt);
}

// 奇数位置查询：返回 {1次方和, 2次方和, 3次方和, 4次方和}（新增四次方）
array<int,4> oquery(int rt,int l,int r)
{
    if(t[rt].r<l||t[rt].l>r) return {0,0,0,0};  // 初始化四次方为0
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        return {t[rt].osum1, t[rt].osum2, t[rt].osum3, t[rt].osum4};
    }
    pushdown(rt);
    array<int,4> t1,t2;
    t1=oquery(ls,l,r);
    t2=oquery(rs,l,r);
    // 结果相加后取模（包含四次方）
    return {
        mod_add(t1[0], t2[0]),
        mod_add(t1[1], t2[1]),
        mod_add(t1[2], t2[2]),
        mod_add(t1[3], t2[3])  // 四次方和合并
    };
}

// 偶数位置查询：返回 {1次方和, 2次方和, 3次方和, 4次方和}（新增四次方）
array<int,4> equery(int rt,int l,int r)
{
    if(t[rt].r<l||t[rt].l>r) return {0,0,0,0};  // 初始化四次方为0
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        return {t[rt].esum1, t[rt].esum2, t[rt].esum3, t[rt].esum4};
    }
    pushdown(rt);
    array<int,4> t1,t2;
    t1=equery(ls,l,r);
    t2=equery(rs,l,r);
    // 结果相加后取模（包含四次方）
    return {
        mod_add(t1[0], t2[0]),
        mod_add(t1[1], t2[1]),
        mod_add(t1[2], t2[2]),
        mod_add(t1[3], t2[3])  // 四次方和合并
    };
}

ll n,q;
ll op,l,r,v;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=mod;  // 初始值取模（注：模运算仍为潜在缺陷）
    }
    build(1,1,n);
    while(q--)
    {
        cin>>op>>l>>r;
        if(op==0)
        {
            cin>>v;
            v%=mod;  // 增量取模（注：模运算仍为潜在缺陷）
            upd(1,l,r,v);
        }
        else
        {
            // 比较 1-4 次方和是否全部相等（新增四次方比较）
            auto o_res = oquery(1,l,r);
            auto e_res = equery(1,l,r);
            if(o_res[0]==e_res[0] && o_res[1]==e_res[1] && o_res[2]==e_res[2] && o_res[3]==e_res[3])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
题解做法：每个数当作幂，取 2和 3当基数 base，然后 +v操作变成乘以 2^v，维护双哈希即可
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
constexpr int N=2e5+7;
constexpr int mod1=998244353;
constexpr int mod2=1e9+7;
int quickpow(int x,int y,int mod)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
struct Tree
{
    int l,r;
    int add;
    int sum1,sum2;
} t[N<<2];
int a[N];
void pushup(int rt)
{
    t[rt].sum1=(t[ls].sum1+t[rs].sum1)%mod1;
    t[rt].sum2=(t[ls].sum2+t[rs].sum2)%mod2;
}
void apply(int rt,int c)
{
    t[rt].add+=c;
    t[rt].sum1=t[rt].sum1*quickpow(2,c,mod1)%mod1;
    t[rt].sum2=t[rt].sum2*quickpow(3,c,mod2)%mod2;
}
void pushdown(int rt)
{
    int c=t[rt].add;
    apply(ls,c);
    apply(rs,c);
    t[rt].add=0;
}
void build(int rt,int l,int r)
{
    t[rt]={l,r,0,0,0};
    if(l==r)
    {
        int s=1;
        if(l&1) s=-1;
        t[rt].sum1=(s*quickpow(2,a[l],mod1)%mod1+mod1)%mod1;
        t[rt].sum2=(s*quickpow(3,a[l],mod2)%mod2+mod2)%mod2;
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(rt);
}
void upd(int rt,int l,int r,int c)
{
    if(t[rt].r<l||t[rt].l>r) return;
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        apply(rt,c);
        return;
    }
    pushdown(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) upd(ls,l,r,c);
    if(mid+1<=r) upd(rs,l,r,c);
    pushup(rt);
}
pair<int,int> query(int rt,int l,int r)
{
    if(t[rt].r<l||t[rt].l>r) return {0,0};
    if(l<=t[rt].l&&t[rt].r<=r)
    {
        return {t[rt].sum1,t[rt].sum2};
    }
    pushdown(rt);
    pair<int,int> p1,p2;
    p1=query(ls,l,r);
    p2=query(rs,l,r);
    return {(p1.first+p2.first)%mod1,(p1.second+p2.second)%mod2};
}

int n,q;
int op,l,r,v;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>op>>l>>r;
        if(op==0)
        {
            cin>>v;
            upd(1,l,r,v);
        }
        else
        {
            pair<int,int> p=query(1,l,r);
            if(p.first==0&&p.second==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/