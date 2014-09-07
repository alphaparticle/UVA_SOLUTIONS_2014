#include <bits/stdc++.h>
using namespace std ;

int C , E , S ,T ;
bool canfinish [111] ;
int profit [111][111] ;

int dp [1011][101] ;

int rec ( int day , int city ){
    if( day > T || city > C)
    return -1*1e9 ;
    
    if( dp[day][city] != -1 )
    return dp[day][city] ;
    
    if( day == T &&  canfinish[city] ){
    	 dp[day][city] = 0 ;
    	 return dp[day][city] ;
    }
    else if( day == T){
    	 return -1*1e9 ;
    }
    
    dp[day][city] = 0 ;
    for ( int i = 1 ; i <= C ;i++)
    if( i != city )
    dp[day][city] = max ( dp[day][city] , profit[city][i] + rec ( day+1 ,i) ) ;
    return dp[day][city] ;
}

void solve(){
   int i , j , k ;
   for ( i = 1 ; i <= C ;i++)
   for ( j = 1 ; j <= C ; j++)
   cin >> profit [i][j] ;
   
   for (i = 0 ; i <= C ;i++)
   canfinish[i] = false ;
   for ( i = 0 ;i < E ; i++){
   	  cin >> j ; canfinish[j] = true ;
   }

   for ( i = 0 ; i <= T ; i++ )
   for ( j = 0; j <= C ; j++)
   dp[i][j] = -1 ;
  
  int ans = rec (0,S) ;
  cout << ans <<"\n" ;
}

int main(){
   while ( cin >> C >> S >> E >> T){
   	  if( C == 0 && S == 0 )
   	  break ;
       solve() ;
   }
	return 0;
}
