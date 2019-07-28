/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define um(A, B) unordered_map<A, B>
#define us(A) unordered_set<A>
#define ms(A) multiset<A>
#define all(x) x.begin(), x.end()
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sqr(x) ((x) * (x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x, val) memset((x), (val), sizeof(x));
#define rite(X) freopen("X.txt", "w", stdout);
#define read(X) freopen("X.txt", "r", stdin);
#define FOR(A, B) for (auto i = (A); i < (B); i++)
#define FORN(A, B) for (auto i = (B); i >= (A); i--)
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN

typedef long long int li;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_set<string> uss;
typedef unordered_set<int> usi;
typedef unordered_set<int, usi> usii;
typedef multiset<int> msi;
typedef multiset<string> mss;
typedef pair<li, li> ll;
typedef pair<li, ll> lll;
typedef vector<li> vl;
typedef vector<ll> vll;
typedef vector<lll> vlll;
typedef vector<vl> vvl;
typedef unordered_map<li, li> umll;
typedef unordered_map<string, li> umsl;
typedef unordered_set<string> uss;
typedef unordered_set<li> usl;
typedef unordered_set<li, usl> usll;
typedef multiset<li> msl;
typedef multiset<string> mss;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0 / 0.0;

int fastmed( int A[], int n ) {
    sort( A, A+n ); return A[n/2];
}

void swap( int & a, int & b ) {
    int t; t = a; a = b; b = t; 
}

int partition( int A[], int l, int r, int med ) {
    int i; 
    for( i = l; i < r; i++ ) 
        if( A[i] == med ) 
            break;
    swap(A[i],A[r]);
    i = l;
    for( int j = l; j < r; j++ ) {
        if( A[j] <= med ) swap(A[i],A[j]), i++;
    } swap(A[i],A[r]);
    return i;
}

int kthSmallest(int A[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int med[(n+4)/5]; int i  = 0;
        for( i = 0; i < n/5; i++ ) med[i] = fastmed(A+l+i*5,5);
        if( i*5 < n ) {
            med[i] = fastmed(A+l+i*5, n%5); i++; 
        }
        int medofmed = (i == 1)? med[0] : kthSmallest(med,0,i-1,i/2);
        int pos = partition(A,l,r,medofmed); int len = pos-l+1;
        if( len == k ) return A[pos];
        else if( len < k ) return kthSmallest(A,pos+1,r,k-len);
        else return kthSmallest(A,l,pos-1,k);
    }
    return ima;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n - 1, k);
    return 0;
}