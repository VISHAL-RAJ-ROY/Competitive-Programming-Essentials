#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> kmpProcess( string & p )
{
	int len = p.length();
	vector <int> b(len+1,0);
	int i = 0, j = -1; b[0] = -1;
	while( i < len )
	{
		while( j >= 0 && p[i] != p[j] ) j = b[j];
		i++;j++;
		b[i] = j; 
	}
	return b;
}

vector <int> kmp( string & t, string & p)
{
	vector <int> b = kmpProcess(p);
	vector <int> ans;
	int i = 0, j = 0;
	int m = p.length();
	int len = t.length();
	while( i < len )
	{
		while( j >= 0 && t[i] != p[j] ) j = b[j];
		i++;j++;
		if( j == m ) 
		{
			ans.push_back(i-m);
			j = b[j];
		}
	}
	return ans;
}

int main()
{
	string t = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN"; string p = "SEVENTY SEVEN";
	vector <int> ans = kmp(t,p);
	for( int i = 0 ; i < ans.size() ; i++ ) cout<<t.substr(ans[i],p.length())<<" ";
	cout<<"\n";
	return 0;
}
