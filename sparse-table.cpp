/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define posLSB(X) __builtin_ctz((long long int)X)
#define num1bit(X) __builtin_popcount((long long int)X)
#define numlead0(X) __builtin_clz(X)
#define gcd(X,Y) __gcd(X,Y)
#define pb push_back
#define eb emplace_back
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
//#define FOR(i,A,B) for( auto (i) = (A); (i) < (B); (i)++ )
//#define FORN(i,A,B) for( auto (i) = (B); (i) >= (A); (i)-- )
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define pv(X) name(X); FOR(i,0,sz(X)) { cout<<"  "<< (#X) <<"["<<i<<"] = "<<X[i]<<endl; }
#define pvv(X) name(X); FOR(j,0,sz(X)) { cout<<endl; cout<<"  "<< (#X) <<"["<<j<<"]"<<endl; FOR(i,0,sz(X[j])) { cout<<"    "<< (#X) <<"["<<j<<"]["<<i<<"] = "<<X[j][i]<<endl; } }
#define pus(X) name(X); for( auto t : X )  cout<<"  "<<t; cout<<endl;
#define pum(X) name(X); for( auto t : X ) cout<<"  "<< (#X) <<"["<<t.first<<"] = "<<t.second<<endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

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

vi calclog( int N ) { // for fast log calculation
    vi log(N+1,0);
    FOR(i,2,N+1) log[i] = log[i/2]+1;
    return log;
}

int func( int A, int B ) {
    return A+B; // for sum 
    return A*B; // for multiplication
    return min(A,B); // for min
    return max(A,B); // for max
}

int idem( int a, int b ) {   // for idempotent functions like min and max
    return min(a,b);
    return max(a,b); 
}

int query_idem( vvi & sptable, int l, int r ) { // for querying 
    int len = r-l+1;
    int K = log2(len);
    return idem(sptable[l][K],sptable[r-(1<<K)+1][K]);
}

int query_non_idem( vvi & sptable, int l, int r ) {
    int N = sz(sptable), K = sz(sptable[0]);
    int sum = 0, L = l, len = r-l+1;
    while( len ) {
        int p = posLSB(len), po = (1<<p);
        len -= po;
        sum += sptable[l][p];
        l += po;
    }
    return sum;
}

vvi store_in_spare_table( vi & v ) {
    int N = sz(v), K = log2(N)+1; 
    vvi sptable(N,vi(K,0));
    FOR(i,0,N) sptable[i][0] = v[i];
    FOR(j,1,K)
        FOR(i,0,N-(1<<j)+1)
            sptable[i][j] = func(sptable[i][j-1],sptable[i+(1<<(j-1))][j-1]);
    return sptable;
}

int main() {
    ios_base::sync_with_stdio(0);
    vi v{1,2,3,4,5,6,7,8,9,10}; int N = sz(v);
    vvi sptable = store_in_spare_table(v);
    vi pr(N,0); pr[0] = v[0];int sum,mm;
    FOR(i,1,N) pr[i] = pr[i-1]+v[i];
    pv(pr);
    FOR(i,0,N)
        FOR(j,i+1,N)
            if( (sum = query_non_idem(sptable,i,j) )!= (mm = pr[j]-(i>0?pr[i-1]:0)) ) {
                cout<<i<<" "<<j<<" "<<sum<<" "<<mm; nl;
                cout<<"lol"; nl; break;
            }
    cout<<query_non_idem(sptable,2,4)<<"\n";
    return 0;
}
