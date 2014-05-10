/*
Date : 11-May-2014
Time : 3:40 pm IST
author - @alphaprticle
Problem id : 568
Problem name : Just The Facts
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=509&mosmsg=Submission+received+with+ID+13614455
*/

#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610 
#define LIM 1000000
#define readi(n) scanf("%d", &n) ;
#define readc(c) scanf("%c", &c) ;
#define read2i(n,m) scanf("%d %d", &n , &m) ;
#define read3i(a,b,c) scanf("%d %d %d",&a ,&b ,&c);
#define pb push_back
#define rep(i,n) for( int i = 0 ; i < n ; i++)
#define reps(i,a,b) for(int i = a ; i <= b ; i++) 
#define rev(i,b,a) for(int i = b ; i >= a ; i--)
#define P first
#define Q second

typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii> viii ;

/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/

/*
  //Seive
  bool p[LIM] ;
  vector <ll> prime ;
  void seive(){
	 memset (p , true ,sizeof p);
	 p[0] = p[1] = false ;
	 for ( ll i = 2 ; i <= LIM ; i++){
	   if(p[i])
	   {
	     prime.pb(i);
	     for ( ll j = i*i ; j <= LIM ; j += i)
	     p[j] = false ;
	   }
	 }
  }

*/


int N, ld[10010];
 
void lnd(int n) {
    long long m = 1;
    for(int i = 1; i <= n; i++) {
        m = (m * i);
        while(m % 10 == 0) m /= 10;
        m = m % 100000;
        ld[i] = m % 10;
    }
}
 
int main() {
    lnd(10000);
    while(scanf("%d", &N) == 1) {
        printf("%5d -> %d\n", N, ld[N]);
    }
}