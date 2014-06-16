/*
Date : 16 June 14
Time : 2::pm IST
author - @alphaparticle
Problem id : 10755
Problem name : Garbage heap
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696
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

ll arr [22] [22] [22] ;
ll sumrows [22] [22] [22] ;
ll sumcols [22] [22] [22] ;
ll levels [22][22][22] ;

int main(){
 int test , i ,j , k ;
 int A ,B , C;
 int hl ,hh , rl ,rh , cl , ch ;
 gi(test);
 while ( test -- ){
     g3i( A,B,C) ;
     repu ( i ,1, A)
     repu( j ,1, B)
     repu( k ,1, C)
     scanf("%lld",&arr[i][j][k]) ;

     rep(i,A+1)
     rep(j,B+1)
     rep(k,C+1)
     sumrows [i][j][k] = sumcols[i][j][k] = levels[i][j][k] = 0 ;


     for ( i = 1 ; i <= A ; i++){
         for ( j = 1 ; j <= B ; j++)
         {
             for ( k = 1; k <= C ; k++){
                sumrows [i][j][k] = sumrows[i][j][k-1] + arr [i][j][k] ;
         }
       }
   }

    for ( i = 1 ; i <= A ; i++){
          for ( j = 1 ; j <= C ; j++){
              for ( k = 1 ; k <= B ; k++)
              sumcols [i][k][j] = sumcols[i][k-1][j] + sumrows [i][k][j] ;
          }
    }

    for( i = 1 ; i <= A ; i++)
    for ( j = 1 ; j <= B ; j++)
    for ( k = 1 ; k <= C ; k++)
    levels[i][j][k] = levels[i-1][j][k] + sumcols [i][j][k] ;


    ll ans = -999999999999999999 ;

     for ( hh = 1 ; hh <= A ; hh++ ){
         for ( hl = 1 ; hl <= hh ; hl++ ){

               for ( rh = 1 ; rh <= B ; rh++ )
               for ( rl = 1 ; rl <= rh ; rl++ ){

                      for ( ch = 1 ; ch <= C ; ch++ )
                      for ( cl = 1 ; cl  <= ch ; cl++) {


                          ll temp = levels [hh][rh][ch] -  levels [hh][rh][cl-1] - levels[hh][rl-1][ch] + levels [hh][rl-1][cl-1] - ( levels [hl-1][rh][ch] -  levels [hl-1][rh][cl-1] - levels[hl-1][rl-1][ch] + levels [hl-1][rl-1][cl-1]);

                          ans = max( ans , temp) ;
                      }


               }
         }
     }

  printf("%lld\n",ans) ;

  if(test)
  printf("\n") ;


 }

}
