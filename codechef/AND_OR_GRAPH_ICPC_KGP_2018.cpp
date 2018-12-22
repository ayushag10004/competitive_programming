

# * * * * * * * * * * * * * 		
#                         *
#  @Author  AYUSH AGRAWAL *
#                         *
# * * * * * * * * * * * * *
# LINK --> https://www.codechef.com/KGP18ROL/problems/GRAPHAND 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
//#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)

ll mul(ll x,ll y)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }

  return ans;
};

/******************************************************************************************************/
#define M 100005
ll a[M],b[M],c[M],d[M],dist[M];

vector < vector< pair<ll,ll> > > v;

void dijik(ll ss)
{
	priority_queue< pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
	pq.push(_mp(0,ss));
	dist[ss] = 0;
	pair<ll,ll> pp;

	ll size,i,y;

	while(!pq.empty())
	{
		pp = pq.top();
		pq.pop();

		if(dist[pp.ss]!=-1 && pp.ff>dist[pp.ss])
			continue;

		size = v[pp.ss].size();

		for(i=0;i<size;i++)
		{
			y = v[pp.ss][i].ff;

			if(dist[y]==-1 || (dist[y]>dist[pp.ss]+v[pp.ss][i].ss))
			{
				dist[y] = dist[pp.ss] + v[pp.ss][i].ss;
				pq.push(_mp(dist[y],y));
			}
		}

	}

	// for(i=1;i<=3;i++)
	// 	cout<<i<<" "<<v[i].size()<<" "<<dist[i]<<"\n";
	return;
}

int main()
{
	ll n,m,i,j,ss,st,k,ans=-1;
	s(n); s(m);

	for(i=1;i<=m;i++)
		s(a[i]),s(b[i]),s(c[i]),s(d[i]);

	s(ss); s(st); s(k);
	--k;

	for(i=31;i>=0;i--)
	if((k>>i)&1)
	{
		for(j=1;j<=m;j++)
			if((d[j]>>i)%2==0)
				c[j] = -1;
	}
	else
	{	
		v.clear();
		v.resize(n+1);

		for(j=1;j<=m;j++)
			if(c[j]>0 && (d[j]>>i)&1)
				v[a[j]]._pb(_mp(b[j],c[j])),v[b[j]]._pb(_mp(a[j],c[j]));

		for(j=1;j<=n;j++)
			dist[j] = -1;

		dijik(ss);

		if(dist[st]!=-1)
			ans = (ans==-1)?dist[st]:min(ans,dist[st]);
		
	}

	printf("%lld\n",ans);
	// cout<<ans<<"\n";

	return 0;
}