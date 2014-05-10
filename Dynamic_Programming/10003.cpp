/*
Date : 9/5/2014
Time : 11.30pm IST
author - @alphaprticle
Problem id : 10003
Problem name : Cutting Sticks
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=944
*/

#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610 
#define LIM 1000000
#define readi(n) scanf("%d", &n) 
#define readc(c) scanf("%c", &c) 
#define read2i(n,m) scanf("%d %d", &n , &m) 
#define read3i(a,b,c) scanf("%d %d %d",&a ,&b ,&c)
#define pb push_back
#define rep(i,n) for( i = 0 ; i < n ; i++)
#define reps(i,a,b) for( i = a ; i <= b ; i++) 
#define first P
#define second Q

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

int len ; int n ;

int arr[55] ;
int dp [55][55];

int bk ( int l , int r){
    
    if ( dp[l][r] != -1)
      return dp[l][r] ;
    
    if ( l+1 == r)
      return dp[l][r] = 0 ;

    int i ,maxi = 1000000 ;

    for ( i = l+1 ; i < r ; i++)
    maxi = min ( maxi  , bk(l,i)+bk(i,r)+ arr[r]-arr[l] );
    
    dp[l][r] = maxi ;
    return dp[l][r] ;
}

int main(){
    int i , j,  k , l;
    while ( readi(len)){
    	 if (len == 0)
    	 break ;
    	readi(n);
      arr[0] = 0 ; arr[n+1] = len ;
    	for ( i = 1 ; i <= n ; i++)
    	readi(arr[i]) ;

      memset ( dp , -1 , sizeof dp) ;
     
      
      cout <<"The minimum cutting is "<<bk(0,n+1)<<".\n" ;
      
    }
     

	return 0 ; 
}
