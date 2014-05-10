/*
Date :  11 May 2011
Time :  8:00 pm IST
author - @alphaprticle
Problem id : 263
Problem name : Number Chains
Problem Link :http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=199&mosmsg=Submission+received+with+ID+13616209
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

int main ()
{
    int n;
 
    while ( scanf ("%d", &n) && n ) {
        char num [20];
        int chainLength = 1;
        sprintf (num, "%d", n);
 
        printf ("Original number was %d\n", n);
 
        sort (num, num + strlen (num));
 
        char num2 [20];
        strcpy (num2, num);
 
        reverse (num2, num2 + strlen (num2));
 
        int first = atoi (num2);
        int second = atoi (num);
        int subs = first - second;
        printf ("%d - %d = %d\n", first, second, subs);
        map <int, bool> m;
 
        while ( m [subs] == false ) {
            m [subs] = true;
 
            sprintf (num, "%d", subs);
            sort (num, num + strlen (num));
            strcpy (num2, num);
            reverse (num2, num2 + strlen (num2));
 
            first = atoi (num2);
            second = atoi (num);
            subs = first - second;
 
            printf ("%d - %d = %d\n", first, second, subs);
            chainLength++;
        }
 
        printf ("Chain length %d\n\n", chainLength);
    }
 
    return 0;
}
 