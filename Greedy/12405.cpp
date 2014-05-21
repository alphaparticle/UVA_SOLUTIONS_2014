/*
Date : 21 May 14
Time : 1:00 pm IST
author - @alphaparticle
Problem id : 12405
Problem name :  ScareCrow
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3836&mosmsg=Submission+received+with+ID+13661325	
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
#define rep(i,n)                   for( int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
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

/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/
char input [110] ;


int main(){
  int test , i, j , k , ans , kase ,n;
  gi(test);
  kase = 1 ;
  while(test--){
          gi(n);
          //getchar();
          //gets(input);
          scanf("%s",input) ; 
          i = ans = 0 ;
          while(i < n){
          if(input[i] == '#'){
            i++ ;
          }
          else{
          	 ans++ ;
          	 i += 3 ;
          }
      }
        printf("Case %d: %d\n",kase++,ans) ; 
  }


	return 0;
}
