map<int,int>primefactors(int n)  
{
	map<int,int>mp;
	int i;
	while (n % 2 == 0)
	{
		mp[2]++;
		n = n/2;
	}
	for (i=3;i<=sqrt(n);i=i+2)
	{
		while (n % i == 0)
		{
			mp[i]++;
			n = n/i;
		}
	}
    if (n>2)
    	mp[n]++;
    return mp;
}