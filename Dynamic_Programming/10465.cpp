/*
Date : 11-MAy-2014
Time : 12:40pm IST
author - @alphaprticle
Problem id : 10465
Problem name : Homer Simpson
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1406
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

int dp[11000][2] ;
int n , m , t ;

ii bk ( int timeLeft , int score){
   
    if ( dp[timeLeft][0] != -1 && dp[timeLeft][1] != -1){
    	return ii(dp[timeLeft][0], dp[timeLeft][1]) ;
    }

   if( timeLeft == 0){
   	 dp[timeLeft][0] = score;
   	 dp[timeLeft][1] = 0 ;
   	 return ii (dp[timeLeft][0],dp[timeLeft][1]) ;
   }

   ii x , y ;
   if ( timeLeft -n >= 0)
    x = bk (timeLeft-n, score+1) ;
   else {
       x.P = score ;
       x.Q = timeLeft ;
   }

   if ( timeLeft -m >= 0)
   	y = bk (timeLeft-m,score+1) ;
   else{
   	  y.P = score ;
   	  y.Q = timeLeft ;
   }

   if ( x.Q < y.Q){
   	 dp[timeLeft][0] = x.P ;
   	 dp[timeLeft][1] = x.Q ;
   }
   else if ( y.Q < x.Q){
   	dp[timeLeft][0] = y.P;
   	dp[timeLeft][1] = y.Q ;
   }
   else if(x.Q == y.Q){
      dp[timeLeft][0] = max ( x.P ,y.P) ;
      dp[timeLeft][1] = x.Q ;
   } 
   return ii (dp[timeLeft][0], dp[timeLeft][1]) ;
}

int main(){
    
   
    int x , y , z ;
    while ( cin >> n >> m >> t){
          memset ( dp , -1 , sizeof dp);
          x = n ; y = m ;
          n = min (x,y) ;
          m = max(x,y) ;
          ii ans = bk(t,0) ;
       //   for ( int i = 0 ; i <= t ; i++ )
       //   cout <<i <<" "<<dp[i][0] <<" "<<dp[i][1] << "\n" ;
          if( ans.Q != 0)
          printf("%d %d\n",ans.P,ans.Q) ;
          else
          	printf("%d\n",ans.P) ;

        //  for (int i = 0 ; i <= t ; i++)
         // cout << i <<" "<<dp[i] <<"\n" ;
    }

  	return 0 ; 
}
