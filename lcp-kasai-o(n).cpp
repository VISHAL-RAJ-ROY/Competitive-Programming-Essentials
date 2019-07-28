vector <int> lcp_kasai( vector <int> sa, string & s )
{
	int len = sa.size();
	vector <int> rank(len,0);
	vector <int> lcp(len,0);
	for( int i = 0; i < len; i++ ) rank[sa[i]] = i;
	int k = 0;
	for( int i = 0; i < len; i++, k ? k-- : 0 )
	{
		if( rank[i] == len-1 ) 
		{
			k = 0; continue;
		}
		int j = sa[rank[i]+1];
		while( i+k < len && j+k < len && s[i+k] == s[j+k] ) k++;
		lcp[rank[i]] = k;
	}
	return lcp;
}
