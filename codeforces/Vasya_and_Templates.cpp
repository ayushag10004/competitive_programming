

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%d",&x)

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

ll p[1000005];
char s[1000005],a[1000005],b[1000005];

string go(string mid,ll k,ll *u)
{
	ll i,n=mid.size(),j,in;

	for(i=n-1;i>=0;i--)
	{	
		in = mid[i] - 'a';

		mid = mid.substr(0, mid.size()-1);

		for(j=in;j<k;j++)
			if(u[j]==-1)
			{
				mid+=('a'+j);
				u[in] = -1;
				u[j] = 1;

				return mid;
			}

		u[in] = -1;
	}

	return mid;
}

int main()
{
	ll t,h[26],u[26],mp[26];
	char ch;
	s(t);

	while(t--)
	{	
		ll k,i,n,in,f,j;
		s(k);

		scanf("%s",s);
		scanf("%s",a);
		scanf("%s",b);

		for(i=0;i<k+1;i++)
			h[i]=-1,u[i]=-1,mp[i]=-1;

		// cin>>s>>a>>b;
		n = strlen(s);

		for(i=0;i<n;i++)
			if(h[s[i]-'a']==-1)
				p[i] = i,h[s[i]-'a']=i;
			else
				p[i] = h[s[i]-'a'];

		string mid;

		for(i=0;i<n;i++)
		if(p[i]==i)
		{
			in = a[i] - 'a';

			if(u[in]==-1)
				mid+=a[i],u[in]=1;
			else
			{	f = 0;

				for(j=in+1;j<k;j++)
					if(u[j]==-1)
					{
						mid+=('a'+j);
						u[j] = 1;
						f = 1;
						break;
					}

				if(f==1)	
				break;

				mid = go(mid,k,u);
				break;	
			}
			
		}	
		else if(a[i]!=a[p[i]])
		{
			if(a[i]>a[p[i]])
				mid = go(mid,k,u);

			break;
		}

		if(mid.size()==0)
		{
			printf("NO\n");
			continue;
		}

		for(i=0;i<k;i++)
			if(u[i]==-1)
				mid+=('a'+i);

		// cout<<mid<<"--------------------\n";
			
		string ans;

		in = 0,f = 0;

		for(i=0;i<n;i++)
			if(p[i]==i)
			{
				mp[s[i]-'a'] = mid[in] - 'a';
				
				if(f==0 && mid[in]<b[i])
					f = 1;
				else if(f==0 && mid[in]>b[i])
					{
						f = 2;
						break;
					}

				++in;
			}
			else
			{	
				ch = mp[s[i]-'a'] + 'a';
				if(f==0 && ch<b[i])
					f = 1;
				else if(f==0 && ch>b[i])
					{
						f = 2;
						break;
					}
			}

		if(f==2)
		{
			printf("NO\n");
			continue;
		}	

		for(i=0;i<k;i++)
		if(mp[i]==-1)
			mp[i] = mid[in]-'a',++in;

			printf("YES\n");
			
			for(i=0;i<k;i++)
				printf("%c",(char)('a'+mp[i]));

			printf("\n");

	}
	return 0;
}