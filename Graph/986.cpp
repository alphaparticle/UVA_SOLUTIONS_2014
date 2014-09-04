#include <bits/stdc++.h>
using namespace std ;

int h , r , n ;

int dp[44][44][22][2] ;

int rec( int row ,int col , int taken , int up ){
    
   
    if( taken > r || row > n || row < 0 || col < 0 || col > n )
    return 0 ;
 //cout <<" row " <<row <<" col "<<col << " peak "<<taken <<" up "<<up << endl ;


    if ( dp[row][col][taken][up] != -1 )
     return dp[row][col][taken][up] ;
    
    if( row == 0 && col == n && taken == r && up == 0){
    	 dp[row][col][taken][up] = 1 ;
    	 return dp[row][col][taken][up] ;
    }
    
  
   dp[row][col][taken][up] = 0 ;
   if( row == h ){
   	     if ( up == 1 ){

            dp[row][col][taken][up] += rec ( row-1 , col+1 , taken+1 ,0) ;
            dp[row][col][taken][up] += rec ( row+1 ,col+1 , taken , 1) ;
    	     }
   	     else{
             dp[row][col][taken][up] += rec( row+1 , col+1 , taken , 1);
             dp[row][col][taken][up] += rec( row-1 , col+1 , taken , 0) ;
   	     }
   	   return dp[row][col][taken][up] ;  
   }
    
    dp[row][col][taken][up] += rec( row-1 , col+1 , taken , 0) ;
    dp[row][col][taken][up] += rec( row+1 , col+1 , taken , 1 ) ;
  
   return dp[row][col][taken][up] ;
}

void solve () {
     memset ( dp , -1, sizeof dp) ;
    // cout <<"ok\n" ;
     int ans = rec(0,0,0,1);
    // cout <<"yahan\n" ;
     cout << ans <<"\n" ;
 }

int main(){
   cin.sync_with_stdio(0) ;
   cin.tie(0) ;
    while ( cin >> n >> r >> h){
    	n = 2*n ; 
    	solve() ;
    }
	return 0 ;
}
