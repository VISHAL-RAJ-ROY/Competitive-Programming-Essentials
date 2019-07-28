#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> manachar( string & s )
{
	int n = s.length();
	char * y = new char[2*n+1];
	y[0] = '#'; 
	int j = 1;
	for( int i = 0; i < n; i++ )
		y[j++] = s[i], y[j++] = '#'; 
	int m = 2*n+1;
	for( int i =0; i< m; i++ ) cout<<y[i]<<" ";cout<<"\n"; 
	vector <int> p(m,0);
	int c = 0, r = -1, rad; 
	for( int i = 0; i < m; i++ )
	{
		if( i <= r )
			rad = min(p[2*c-i]+1,r-i);
		else 
			rad = 0;
		while( i+rad < m && i-rad >= 0 && y[i+rad] == y[i-rad] )
			rad++;
		p[i] = rad-1;
		if( i+rad-1 > r )
			c = i, r = i+rad-1;
	}
	return p;
}

int main()
{
	string s = "babcbabcbaccba";
	vector <int> p = manachar(s);
//	cout<<p.size()<<"\n";
	for( int i = 0; i < p.size() ; i++) cout<<p[i]<<" "; cout<<"\n";
	return 0;
}	
