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
#define um(A,B) unordered_map <A, B>
#define us(A) unordered_set <A>
#define ms(A) multiset <A>
#define all(x) x.begin(),x.end()
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(X) freopen("X.txt","w",stdout);
#define read(X) freopen("X.txt","r",stdin);
#define FOR(i,A,B) for( auto (i) = (A); (i) < (B); (i)++ )
#define FORN(i,A,B) for( auto (i) = (B); (i) >= (A); (i)-- )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN

typedef double db;
typedef complex<db> cd;
typedef vector<cd> vcd;
typedef long long int li;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
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

vi rep;
vcd powofunity;

void print( vi v ) {
    for( auto y : v ) cout<<y<<" "; cout<<"\n";
}

void print( vcd v ) {
    for( auto t : v ) cout<<t.real()<<" "<<t.imag()<<"\n";
}

void storebit( int n ) {
    int j = 0; rep.assign(n,-1);
    FOR(i,1,n) {
        int bit = n/2; 
        for(; j&bit ; bit >>= 1 )
            j ^= bit;
        j ^= bit;
        if( i < j ) rep[i] = j;
    } 
}

void storepower( int n ) {
    powofunity.resize(n); 
    double ang = 2*pi/(n*1.0);
    cd wn(cos(ang), sin(ang)); cd w(1);
    powofunity[0] = w;
    FOR(i,1,n) w *= wn, powofunity[i] = w;
}

void fft( vcd & a, bool convert ) {
    int n = sz(a); 
    FOR(i,0,n) if(rep[i]!=-1) swap(a[i],a[rep[i]]);
    if( n == 1 ) return;
    for( int len = 2; len <= n; len <<= 1 ) {
        for( int i =0 ; i < n; i += len ) {
            int h = len/2, g = n/len;
            FOR(j,0,h) {
                cd u = a[i+j], v = a[i+j+h], w = powofunity[g*j], mul(w.real(), w.imag()*(convert?-1:1)); 
                v *= mul; 
                a[i+j] = u+v; a[i+j+h] = u-v; 
            } 
        }
    } if( convert ) FOR(i,0,n) a[i] /= n;
}

vi multiply( vi a, vi b ) {
    int n = 1;
    int as = sz(a), bs = sz(b); 
    while( n < as+bs ) n <<= 1;
    vcd fa(all(a)), fb(all(b)); 
    fa.resize(n); fb.resize(n); 
    storebit(n); storepower(n);
    fft(fa,false); fft(fb,false);
    FOR(i,0,n) fa[i] *= fb[i];
    fft(fa, true); vi res(n,0); int k = 0;
    for( auto e : fa ) res[k++] = round(e.real());
    return res;
}
/* 
void mull( cd & t ) {
    FOR(i,0,8) t *= t;
}*/

int main() {
    ios_base::sync_with_stdio(0);
/*  storebit(8);
    for( auto t: rep ) cout<<t<<" "; cout<<"\n"; 
    storepower(8);
    for( auto t : powofunity ) mull(t), cout<<t.real()<<" "<<t.imag()<<"\n";*/
    vi a{5,0,10,6}, b{1,2,4}; 
    vi res = multiply(a,b);
    for( auto t: res ) cout<<t<<" "; cout<<"\n";
    return 0;
}