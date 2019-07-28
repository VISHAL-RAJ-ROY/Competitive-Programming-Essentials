#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void countSort(int k, vector<int> &sa, vector<int> &ra, int len)
{
	vector<int> c(max(300, len + 1), 0);
	for (int i = 0; i < len; i++)
		c[i + k < len ? ra[i + k] : 0]++;
	int sum = 0;
	for (int i = 0; i < max(300, len); i++)
	{
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	vector<int> tsa(len, 0);
	for (int i = 0; i < len; i++)
		tsa[c[sa[i] + k < len ? ra[sa[i] + k] : 0]++] = sa[i];
	for (int i = 0; i < len; i++)
		sa[i] = tsa[i];
}

vector<int> buildSA(string &s)
{
	s = s + "$";
	int len = s.length();
	vector<int> ra(len, 0);
	vector<int> sa(len, 0);
	for (int i = 0; i < len; i++)
	{
		ra[i] = s[i];
		sa[i] = i;
	}
	for (int k = 1; k < len; k <<= 1)
	{
		countSort(k, sa, ra, len);
		countSort(0, sa, ra, len);
		int r = 0;
		vector<int> tra(len, 0);
		tra[sa[0]] = r = 0;
		for (int j = 1; j < len; j++)
		{
			if (ra[sa[j]] == ra[sa[j - 1]] && ra[sa[j] + k] == ra[sa[j - 1] + k])
				tra[sa[j]] = r;
			else
				tra[sa[j]] = ++r;
		}
		for (int j = 0; j < len; j++)
			ra[j] = tra[j];
		if (ra[sa[len - 1]] == len - 1)
			break;
	}
	return sa;
}

int main()
{
	string s = "GATAGACA";
	vector<int> sa = buildSA(s);
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		cout << sa[i] << " " << s.substr(sa[i]) << "\n";
	}
	return 0;
}
