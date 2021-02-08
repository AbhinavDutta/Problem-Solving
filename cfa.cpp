ll binpow(ll a, ll b,ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll fact[1005],inv[1005];
	fact[0]=1; fact[1]=1; inv[0]=1; inv[1]=1;
	for(i=2;i<=1004;i++)
	{
		fact[i]=fact[i-1]*i%inf;
		inv[i]=binpow(fact[i],inf-2,inf);
	}
ll highestPowerOf2(ll n) 
{ 
     ll p=(n & (~(n - 1))); 
     ll pow=0;
     if(p==0)
     return 0;
     while(p&1==0)
     {
		 pow++;
		 p>>=1;
	 }
	 return pow; 
}
ll st[maxn][27];

for (ll i = 0; i < n; i++)
    st[i][0] = arr[i];

for (ll j = 1; j <27; j++)
{
    for (ll i = 0; i + (1 << j) <n; i++)
    {
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	}
}
ll j = log2(r-l+1);
ll minimum = min(st[l][j], st[r- (1 << j) + 1][j]);

vector<pair<ll,ll>> factorize(ll n) 
{
    vector<pair<ll,ll>> factors;
    pair<ll,ll> prime;
    for (ll d = 2; d * d <= n; d++)
    {
		ll pow=0;
		
		if(n%d!=0)
		continue;
		
        while (n % d == 0)
        {
            pow++;
            n /= d;
        }
        prime.first=d; prime.second=pow;
        factors.pb(prime);
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}


const int n = 10000000;
int lp[n+1];  //lowest prime factor
vector<int> pr;	 //list of primes
void liear_sieve(ll n)
{
	for (ll i=2; i<=n; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back (i);
		}
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}


while (low <= high)
    {
        int mid = (low + high)/2;   
        if (x == A[mid])
            return mid;
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
//geometric

struct point
{
	ll x,y;
};
double d(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool comp(point a,point b)
{
	return a.x<b.x;
}
vector<point> set_of_points;
vector<point> active;
double min_dist;
point magnus,anish;
void sweepline()
{
	min_dist=1000000.0;
	
	for(auto i:set_of_points)
	{
		point curr=i;
		for(auto x:active)
		{
			if(d(x,curr)<min_dist)
			{
				min_dist=d(x,curr);
				magnus=curr;
				anish=x;
			}
		}
		
		for(auto it=active.begin();it!=active.end();it++)
		{
			if(d(*it,curr)>min_dist)
			active.erase(it);
		}
		active.pb(curr);
	}
}
		
		
void solve()
{
	ll n,i;
	cin>>n;
	set_of_points.resize(n);
	for(i=0;i<n;i++)
	cin>>set_of_points[i].x>>set_of_points[i].y;
	sort(set_of_points.begin(),set_of_points.end(),comp);
	sweepline();
	cout<<min_dist<<endl;
	cout<<magnus.x<<" "<<magnus.y<<" || "<<anish.x<<" "<<anish.y<<endl;
}
ll n,i,curr;	cin>>n;	ll arr[n],ple[n],nle[n];
	for(i=0;i<n;i++)	cin>>arr[i];
	stack<ll> s;
	for(i=0;i<n;i++)
	{	ple[i]=-1;	nle[i]=-1;	}
	for(i=0;i<n;i++)
	{
		if(s.empty())
		{	ple[i]=-1;	s.push(i);	}
		else
		{
			curr=s.top();
			while(arr[curr]<arr[i])
			{
				s.pop();
				if(s.empty())	break;
				curr=s.top();
			}
			if(s.empty())
			{	ple[i]=-1;	s.push(i);	}
			else
			{	ple[i]=s.top();	s.push(i);	}
		}
	}
	s=stack<ll>();
	for(i=0;i<n;i++)
	{
		if(s.empty())
		{	nle[i]=-1;	s.push(i);	}
		else
		{
			curr=s.top();
			while(arr[curr]<arr[i])
			{
				nle[curr]=i;	s.pop();
				if(s.empty())	break;
				curr=s.top();
			}
		}
		s.push(i);
	}
	//reversing strings in O(1)
	ll q=queries[i];	ll tomove;
		if(i==0)	tomove=last-queries[i];
		else  tomove=queries[i-1]-queries[i];
		if(direction==1)
		last-=tomove;
		else
		last+=tomove;
		swap(first,last); //note this
		direction^=1;
		res[q]=last;

ll ceil(ll num,ll den){return (num+den-1)/den;}
ll red(ll a){a=a-mod*(a/mod);return a;}
ll mult(ll a,ll b){a=red(a); b=red(b);ll pdt=red(a*b);return pdt;}
ll add(ll a,ll b){return red(a+b);}
ll sub(ll a,ll b){ll res=red(a)-red(b)+mod;res=red(res);return res;}

ll st[maxn*4+1];
ll lz_first[maxn*4+1]; //will store first term of ap
ll lz_diff[maxn*4+1];

struct SegmentTree{
	
	void push_down(ll node,ll ss,ll se)
	{
		ll len=se-ss+1;
		st[node]+=(2*lz_first[node]+(len-1)*lz_diff[node])*len/2;
		lz_diff[2*node+1]+=lz_diff[node];lz_diff[2*node+2]+=lz_diff[node];
		ll mid=(ss+se)/2;
		lz_first[2*node+1]+=lz_first[node];
		lz_first[2*node+2]+=lz_first[node]+(mid+1-ss)*lz_diff[node];
		lz_diff[node]=0; lz_first[node]=0;
	}
	void update(ll node,ll ss,ll se,ll l,ll r,ll a,ll d)//add (a,d) ap on [l,r]
	{
		if(ss>r||se<l)
		{
			return;
		}
		else if(l<=ss&&se<=r)
		{	
			if(ss>=l)
			a+=(ss-l)*d;
			lz_diff[node]+=d; lz_first[node]+=a;
			push_down(node,ss,se);
		}
		else
		{
			push_down(node,ss,se);
			ll mid=(ss+se)/2;
			update(2*node+1,ss,mid,l,r,a,d);
			update(2*node+2,mid+1,se,l,r,a,d);
			st[node]=st[node*2+1]+st[node*2+2];
		}
	}
	ll get(ll node,ll ss,ll se,ll l,ll r)
	{
		if(ss>r||se<l)
		{
			return 0;
		}
		else if(l<=ss&&se<=r)
		{
			push_down(node,ss,se);
			return st[node];
		}
		else
		{
			push_down(node,ss,se);
			ll mid=(ss+se)/2;
			ll res=get(2*node+1,ss,mid,l,r);
			res+=get(2*node+2,mid+1,se,l,r);
			return res;
		}
	}
} segtree;
void solve()
{
	SegmentTree s;
	ll n,i,l,r,q;	cin>>n>>q;
	for(i=0;i<4*n+1;i++)
	st[i]=lz_first[i]=lz_diff[i]=0;
	for(i=0;i<q;i++)
	{
		cin>>l>>r;
		l--; r--;
		s.update(0,0,n-1,l,r,1,1);
	}
	for(i=0;i<n;i++)
	cout<<s.get(0,0,n-1,i,i)<<" ";
	cout<<endl;
	
}

seed_seq seq
	{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int base = uniform_int_distribution<int>(0, p-1)(rng);
//HASHING RELIABLE
ll c_hash(string const& s) 
{
    int p = 31;
    int m = 1e9 + 9;
	ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
//euler tree traversal
vector<ll> euler;
vector<ll> adj[maxn]; bool vis[maxn];
ll tin[maxn],tout[maxn]; ll t=0;
void dfs(int v)
{
	vis[v]=true; tin[v]=t++;
	euler.pb(v);
	for(auto x:adj[v])
	{
		if(!vis[x])
		dfs(x);
	}
	tout[v]=t++;
	euler.pb(v);
}
void solve()
{
	ll n,m,i,u,v;	cin>>n>>m;
	for(i=0;i<n;i++) {vis[i]=false; adj[i].clear();}
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0);
	cin>>u; // i will show its subtree
	set<ll> s;//contains subtree without double counting
	for(i=tin[u];i<tout[u];i++)
	s.insert(euler[i]);
	for(auto x:s)
	cout<<x<<" ";
}

