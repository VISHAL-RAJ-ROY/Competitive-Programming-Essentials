class UF
{
private:
	int N;
	vector<int> r, p;

public:
	UF(int n)
	{
		r.assign(n, 0);
		p.assign(n, -1);
		for (int i = 0; i < n; i++)
			p[i] = i;
		N = n;
	}
	bool issame(int i, int j)
	{
		return findset(i) == findset(j);
	}
	int findset(int i)
	{
		return (p[i] == i) ? i : (p[i] = findset(p[i]));
	}
	void join(int i, int j)
	{
		int x = findset(i), y = findset(j);
		if (r[x] < r[y])
		{
			p[x] = y;
		}
		else
		{
			p[y] = x;
			if (r[x] == r[y])
				r[x]++;
		}
	}
};
