ll power(int n,int y)
{
	ll x=y;
	ll res=1;
	while(n)
	{
		if(n&1)
		{
			res*=x;
			res%=MOD;
		}
		n/=2;
		x=(x*x)%MOD;
	}
	return res;
}