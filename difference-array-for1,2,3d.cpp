/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define um(A,B) unordered_map <A, B>
#define us(A) unordered_set <A>
#define ms(A) multiset <A>
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<endl;
#define name(X) cout<<endl<< (#X) << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
#define FOR(i,A,B) for( auto (i) = (A); (i) < (B); (i)++ )
#define FORN(i,A,B) for( auto (i) = (B); (i) >= (A); (i)-- )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define pv(X) name(X); FOR(i,0,sz(X)) { cout<<"  "<< (#X) <<"["<<i<<"] = "<<X[i]<<endl; }
#define pvv(X) name(X); FOR(j,0,sz(X)) { cout<<endl; cout<<"  "<< (#X) <<"["<<j<<"]"<<endl; FOR(i,0,sz(X[j])) { cout<<"    "<< (#X) <<"["<<j<<"]["<<i<<"] = "<<X[j][i]<<endl; } }
#define pus(X) name(X); for( auto t : X )  cout<<"  "<<t; cout<<endl;
#define pum(X) name(X); for( auto t : X ) cout<<"  "<< (#X) <<"["<<t.first<<"] = "<<t.second<<endl;

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

typedef double db;
typedef complex<db> cd;
typedef vector<cd> vcd;
typedef long long int li;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef tuple<int,int> i2;
typedef tuple<int,int,int> i3;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<i2> vi2;
typedef vector<i3> vi3;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef unordered_map<int,int> umii;
typedef unordered_map<string,int> umsi;
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
typedef unordered_map<li,li> umll;
typedef unordered_map<string,li> umsl;
typedef unordered_set<string> uss;
typedef unordered_set<li> usl;
typedef unordered_set<li, usl> usll;
typedef multiset<li> msl;
typedef multiset<string> mss;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

void creatediff1d( vi & A, vi & D ) {
    int N = sz(A); 
    D.assign(N,0);
    D[0] = A[0];
    FOR(i,1,N) 
        D[i] = A[i]-A[i-1];
}

void creatediff2d( vvi & A, vvi & D ) {
    int N = sz(A), M = sz(A[0]);
    D.assign(N,vi(M,0));  
    FOR(i,0,N) D[i][0] = A[i][0];
    FOR(j,1,M) 
        FOR(i,0,N) 
            D[i][j] = A[i][j]-A[i][j-1];
    FOR(j,0,M) D[0][j] = A[0][j];
    FOR(i,1,N) 
        FOR(j,0,M)
            D[i][j] = A[i][j]-A[i-1][j]; 
}

void creatediff3d( vvvi & A, vvvi & D ) {
    int N = sz(A), M = sz(A[0]), K = sz(A[0][0]);
    D.assign(N,vvi(M,vi(K,0)));
    FOR(i,0,N) 
        FOR(j,0,M)
            D[i][j][0] = A[i][j][0];
    FOR(k,1,K)
        FOR(i,0,N) 
            FOR(j,0,M)
                D[i][j][k] = A[i][j][k]-A[i][j][k-1];
    FOR(k,0,K) 
        FOR(j,0,M)
            D[0][j][k] = A[0][j][k];
    FOR(i,1,N)
        FOR(k,0,K) 
            FOR(j,0,M)
                D[i][j][k] = A[i][j][k]-A[i-1][j][k];
    FOR(i,0,N) 
        FOR(k,0,K)
            D[i][0][k] = A[i][0][k];
    FOR(j,1,M)
        FOR(i,0,N) 
            FOR(k,0,K)
                D[i][j][k] = A[i][j][k]-A[i][j-1][k];
}

void getprefix1d( vi & A, vi & P ) {
    int N = sz(A);
    P.assign(N,0);
    P[0] = A[0];
    FOR(i,1,N) P[i] = A[i]+P[i-1];
}

void getprefix2d( vvi & A, vvi & P ) {
    int N = sz(A), M = sz(A[0]);
    P.assign(N,vi(M,0));
    FOR(i,0,N) 
        P[i][0] = A[i][0];
    FOR(j,1,M)
        FOR(i,0,N)
            P[i][j] = P[i][j-1]+A[i][j];
    FOR(j,0,N) 
        P[0][j] = A[0][j];
    FOR(i,1,M)
        FOR(j,0,N)
            P[i][j] = P[i-1][j]+A[i][j];
}

void getprefix3d( vvvi & A, vvvi & P ) {
    int N = sz(A), M = sz(A[0]), K = sz(A[0][0]);
    P.assign(N,vvi(M,vi(K,0)));
    FOR(i,0,N)
        FOR(j,0,M)
            P[i][j][0] = A[i][j][0];
    FOR(k,1,K)
        FOR(i,0,N)
            FOR(j,0,M)
                P[i][j][k] = A[i][j][k]+P[i][j][k-1];
    FOR(k,0,K)
        FOR(j,0,M)
            P[0][j][k] = A[0][j][k];
    FOR(i,1,N)
        FOR(k,0,K)
            FOR(j,0,M)
                P[i][j][k] = A[i][j][k]+P[i-1][j][k];
    FOR(i,0,N)
        FOR(k,0,K)
            P[i][0][K] = A[i][0][K];
    FOR(j,1,M)
        FOR(i,0,N)
            FOR(k,0,K)
                P[i][j][k] = A[i][j][k]+P[i][j-1][k];
}

void updaterange1d( vi & D, int l, int r, int val ) { // update [l,r]
    D[l] += val; 
    if( r+1 < sz(D) ) D[r+1] -= val;
}

void updaterange2d( vvi & D, ii p1, ii p2, int val ) { // update rectange with top right point p2 and bottom left point p1
    D[p1.xx][p1.yy] += val;
    int x = p2.xx, y = p2.yy;
    if( x+1 < sz(D) ) D[x+1][p1.yy] -= val;
    if( y+1 < sz(D[0]) ) D[p1.xx][y+1] -= val;
    if( x+1 < sz(D) && y+1 < sz(D[0]) ) D[x+1][y+1] += val;
}

void updaterange3d( vvvi & D, i3 p1, i3 p2, int val ) {
    int x,y,z,a,b,c,N = sz(D), M = sz(D[0]), K = sz(D[0][0]);
    tie(x,y,z) = p1; tie(a,b,c) = p2;
    D[x][y][z] += val; 
    if( a+1 < N ) D[a+1][y][z] -= val;
    if( b+1 < N ) D[x][b+1][z] -= val;
    if( c+1 < N ) D[x][y][c+1] --= val;
    if( a+1 < N && b+1 < N ) D[a+1][b+1][z] += val;
    if( a+1 < N && c+1 < N ) D[a+1][y][c+1] += val;
    if( c+1 < N && b+1 < N ) D[x][b+1][c+1] += val;
    if( c+1 < N && b+1 < N && a+1 < N ) D[a+1][b+1][c+1] -= val;
} 

int main() {
    ios_base::sync_with_stdio(0);
    
    return 0;
}
