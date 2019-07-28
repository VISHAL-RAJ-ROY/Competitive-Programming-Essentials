/*
The LIS problem can also be solved using the output-sensitive O(n log k) greedy +
D&C algorithm (where k is the length of the LIS) instead of O(n2) by maintaining an
array that is always sorted and therefore amenable to binary search. Let array L be an
array such that L(i) represents the smallest ending value of all length-i LISs found
so far. Though this definition is slightly complicated, it is easy to see that it is always
ordered—L(i-1) will always be smaller than L(i) as the second-last element of any
LIS (of length-i) is smaller than its last element. As such, we can binary search array L
to determine the longest possible subsequence we can create by appending the current
element A[i]—simply find the index of the last element in L that is less than A[i].
*/

/*
L[i] = the smallest ending value of all length-i LISs
P[i] = array index to the previous element in the LIS containing index i
L_in[i] = the index of the smallest ending value of all length-i LISs
lis_end = index at which LIS ends
*/ 

//prints LIS ending at index 'i'
void print_lis( vector <int> A, int index, vector <int> P ) {
	int x = index;
	stack<int>s; for( ; P[x] >= 0 ; x = P[x] ) s.push(A[x]); s.push(A[x]);
	while( !s.empty() ) {
		cout<<s.top()<<" "; s.pop();
	} cout<<"\n";
} 

void lis( vector <int> A ) {
	int n = A.size();
	vector<int> L(n,0),P(n,0),L_in(n,0);
	int lis = 0, lis_end = 0;
	for( int i = 0; i < n; i++ ) {
		int pos = lower_bound(L.begin(),L.begin()+lis,A[i])-L.begin();
		L[pos] = A[i]; L_in[pos] = i; 
		P[i] = pos ? L_in[pos-1] : -1;
		if( pos+1 > lis ) {
			lis = pos+1;
			lis_end = i;
		}
	}
}
