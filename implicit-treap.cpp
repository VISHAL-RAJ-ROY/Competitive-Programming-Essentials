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
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<"\n";
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
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

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

struct Imtreap { // Implicit Treap
    int p, cnt;
    int v; // v is any value
    int s; // s is sum
    int add; // lazy addition in an interval
    bool rev; // lazy reversal of an interval
    // int h; // height of the tree
    Imtreap * l; 
    Imtreap * r;
    Imtreap() {}
    Imtreap( int p ) :v(0), p(p), l(NULL), r(NULL), cnt(1), rev(false), add(0), s(0) {}//, h(0) {}
    Imtreap( int p, int v ) : v(v), p(p), cnt(1), l(NULL), r(NULL), rev(false), add(0), s(v) {}//, h(0) {}
}; 

typedef Imtreap * ptreap;

int cnt( ptreap t ) {
    return (!t) ? 0 : t->cnt;
}

void upd_cnt( ptreap t ) {
    if(t) t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

// int cnt_H( ptreap t ) {
//     return (!t) ? 0 : t->h;
// }

// void upd_H( ptreap t ) {
//     if(t) t->h = max(cnt_H(t->l), cnt_H(t->r)) + 1;
// }

void pushAdd( ptreap t ) {
    if( !t || !t->add ) return;
    // addition to interval
    t->v += t->add;
    // This is not needed in CALL 1(see start of merge and split) 
    //but is required in CALL 2(because we propagate the lazy addition to v and s of their child and then increment the parent accordingly)
    t->s += t->add*cnt(t); 
    if( t->l ) t->l->add += t->add;
    if( t->r ) t->r->add += t->add;
    t->add = 0; 
}

void pushRev( ptreap t ) {
    // reversing an interval   
    if( t && t->rev ) {
        t->rev = false;
        swap(t->l,t->r);
        if( t->r ) t->r->rev ^= true;
        if( t->l ) t->l->rev ^= true;
    }
}

void push( ptreap t ) {
    pushAdd(t);
    pushRev(t);
}

void operate( ptreap t ) {
    if(!t) return;
    pushAdd(t->l); pushAdd(t->r);
    t->s = t->v;
    if( t->l ) t->s += t->l->s;
    if( t->r ) t->s += t->r->s;
}

void split( ptreap t, int pos, ptreap & l, ptreap & r, int add = 0 ) {
    if( !t ) return void( l = r = NULL );
    push(t); // CALL 1
    int cpos = add+cnt(t->l);
    if( pos <= cpos ) 
        split(t->l, pos, l, t->l, add), r = t;
    else 
        split(t->r, pos, t->r, r, cpos+1), l = t;
    upd_cnt(t);// upd_H(t); 
    operate(t);// CALL 2
}

void merge( ptreap & t, ptreap l, ptreap r ) {
    push(l); push(r); // CALL 1
    if( !l || !r ) 
        t = l ? l  : r;  
    else if( r->p < l->p ) 
       merge( l->r, l->r, r ), t = l;
    else 
       merge( r->l, l, r->l ), t = r;
    upd_cnt(t);// upd_H(t); 
    operate(t);// CALL 2
}

void insert( ptreap & t, ptreap it, int pos ) {
    ptreap l, r; 
    split(t, pos, l, r);
    merge(l, l, it);
    merge(t, l, r);
}

void del( ptreap & t, int key, int add = 0 ) {
    if( !t )
        return;
    else {
        int currpos = cnt(t->l)+add;
        if( key == currpos ) 
            merge(t, t->l, t->r);
        else if( key < currpos ) 
            del(t->l, key, add);
        else 
            del(t->r, key, currpos+1);
    }
}

// build offline has some problem
// void heapify( ptreap & t ) {
//     if( !t ) return;
//     ptreap maxx = t;
//     if( t->l && t->l->p > maxx->p ) maxx = t->l;
//     if( t->r && t->r->p > maxx->p ) maxx = t->r;
//     if( maxx != t ) {
//         swap(t->p,maxx->p);
//         heapify(maxx);
//     }
// }

// void buildoffline( ptreap & t, vi & v, int l, int r ) { 
//     if( r == l ) return;
//     int mid = (l+r)/2;
//     t = new Imtreap(rand(), v[mid]);
//     buildoffline(t->l, v, l, mid);
//     buildoffline(t->r, v, mid+1, r);
//     upd_cnt(t); //upd_H(t);
//     heapify(t);
// }

void buildonline( ptreap & t, vi & v ) { 
    t = new Imtreap(rand(), v[0]);
    FOR(i,1,sz(v)) merge(t,t,new Imtreap(rand(),v[i]));
}

void printasarray( ptreap & t ) {
    if(!t) return;
    printasarray(t->l);
    cout<<t->v<<" ";
    printasarray(t->r);
}

void treetoarray( ptreap & t, vi & v ) {
    if(!t) return;
    treetoarray(t->l,v);
    v.pb(t->v);
    treetoarray(t->r,v);
}

// void call( int l, int r ) {
//     if( r == l ) return;
//     int mid = (l+r)/2;
//     trace3(l,r,mid);
//     call(l,mid);
//     call(mid+1,r);
// }

void Addtointerval( ptreap & t, int A, int B, int num ) { // Add num to interval [A,B]
    ptreap l, r, s; 
    split(t,A,l,r);
    split(r,B-A+1,s,r);
    s->add += num;
    merge(r,s,r);
    merge(t,l,r);
}

int Sumofinterval( ptreap & t, int A, int B ) {
    ptreap l, r, s;
    split(t,A,l,r);
    split(r,B-A+1,s,r);
    printasarray(s);
    int u = s->s;
    merge(r,s,r);
    merge(t,l,r);
    return u;
}

void ReverseInterval( ptreap & t, int A, int B ) { // reverse interval [A,B]
    ptreap l, r, m;
    split(t,A,l,r);
    split(r,B-A+1,m,r);
    m->rev ^= true;
    merge(r,m,r);
    merge(t,l,r);
}

void pbt( ptreap & root, int tab = 0, char desig = 'T' ) {
    if( desig == 'T' ) name(root);
    if(!root) return;
    FOR(i,0,tab)cout<<" "; cout<<desig<<" : ("; cout<<root->v<<", "<<root->p<<" "<<root->cnt<<")"; cout<<endl;
    pbt(root->l, tab+2, 'L');
    pbt(root->r, tab+2, 'R');
}

void cyclicrotate( ptreap & t, int units ) {
    ptreap l, r;
    split(t,units,l,r);
    merge(t,r,l);
}

int main(int argc, char const *argv[])
{
    //srand(time(0));
    int N = 10; //cout<<log2(N); nl;
    //int ma = -1; cout<<"start"; nl; 
    ptreap t;vi v;FOR(i,0,N) v.pb(2*i+1);//pv(v);
    buildonline(t,v);
    printasarray(t); nl;    // 0 1 2  3  4  5  6  7  8  9  
    pbt(t);                 // 1 3 5  7  9  11 13 15 17 19
    ReverseInterval(t,2,6); // 1 3 13 11 9  7  5  15 17 19
    ReverseInterval(t,4,7); // 1 3 13 11 15 5  7  9  17 19
    Addtointerval(t,4,6,1); 
    Addtointerval(t,1,4,2);
    int s = Sumofinterval(t,4,6);
    watch(s);
    buildonline(t,v);
    cyclicrotate(t,4); printasarray(t); nl;
    return 0;
}
