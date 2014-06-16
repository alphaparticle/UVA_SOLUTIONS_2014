/*
Date : 16 JUNE 14
Time : 15:40 IST
author - @alphaparticle
Problem id : 10827
Problem name : MAXIMUM SUM ON A TORUS
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1768
*/

#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610
#define LIM 1000000
#define gi(n)                      scanf("%d", &n)
#define gc(c)                      scanf("%c", &c)
#define g2i(n,m)                   scanf("%d %d", &n , &m)
#define g3i(a,b,c)                 scanf("%d %d %d",&a ,&b ,&c)
#define gl(n)                      scanf("%ld",&n)
#define g2l(a,b)                   scanf("%ld %ld",&a ,&b)
#define g3l(a,b,c)                 scanf("%ld %ld %ld",&a,&b,&c)
#define pb                         push_back
#define rep(i,n)                   for( i = 0 ; i < n ; i++)
#define repu(i,a,b)                for( i = a ; i <= b ; i++)
#define repd(i,b,a)                for( i = b ; i >= a ; i--)
#define P                          first
#define Q                          second
#define pi(n)                      printf("%d\n",n)
#define ps(s)                      printf("%s\n",s.c_str())
#define p2i(a,b)                   printf("%d %d\n",a,b)
#define FILL (x,a)                 memset ( x , a ,sizeof x)

typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
typedef vector <int> vi ;
/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/
int h [155][155] ;


int main(){
  int test , n , i, j, k , l;
  int rl ,rh ,cl ,ch ;
  gi(test);
  while( test-- ){
     gi(n);

     //memset ( vertical , 0 ,sizeof vertical);
     memset( h , 0, sizeof h) ;

      repu( i ,1, n )
      repu( j ,1, n){
      gi( h [i][j] ) ; ;
      }

      repu ( i , n+1 , 2*n)
      repu( j , 1, n)
      h[i][j] = h[i-n][j] ;

      repu ( i , 1, 2*n)
      repu ( j , n+1 , 2*n )
      h[i][j] = h [i][j-n] ;



      repu ( i , 1 , 2*n)
      repu( j , 1, 2*n)
      h [i][j] = h[i][j-1]  + h[i][j] ;


      repu ( i , 1,2*n)
      repu ( j , 1 ,2*n)
      h[i][j] = h[i-1][j] + h[i][j] ;

     int ans = -1000 * n * n ;



      repu ( rh , 1, 2*n)
      repu ( rl , 1 , rh)
      if( rh - rl < n)
      repu ( ch , 1 , 2*n )
      repu ( cl , 1, ch)
      if( ch - cl < n)
      {
        int temp = h [rh][ch] - h [rl-1][ch] - h [rh][cl-1] + h [rl-1][cl-1] ;
        ans = max( temp ,ans) ;
      }

      pi(ans) ;


    }


  return 0;
}
