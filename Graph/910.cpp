#include <bits/stdc++.h>
using namespace std ;


int N , M ;
int move [27][2] ;
bool isspecial [27] ;

int dp[33][27][2] ;

int rec ( int node , int moves_left , int last ){
    if( node > 26 || moves_left < 0 )
    return 0 ;

    if( dp[moves_left][node][last] != -1)
     return dp [moves_left][node][last] ;
    
    if( moves_left == 0 && isspecial[node] )
    {
    	  dp[moves_left][node][last] = 1 ;
    	  return dp[moves_left][node][last] ;
    }

    dp[moves_left][node][last] = 0;
    dp[moves_left][node][last] += rec( move[node][0] , moves_left-1 , 0);
    dp[moves_left][node][last] += rec( move[node][1] ,moves_left-1 ,1) ;
    return dp[moves_left][node][last] ;
}

void solve(){
   memset ( move , -1, sizeof move) ;
   memset ( isspecial , false , sizeof isspecial) ;
   char from , to0 , to1 , special ;
   for ( int i =- 0 ; i < N ;i++){
        cin >> from >> to0 >> to1 >> special ;
        move[ from - 'A'][0] = to0 - 'A' ;
        move[ from - 'A'][1] = to1 - 'A' ;
        if( special == 'x')
        isspecial [ from - 'A' ] = true ;
    }
   memset ( dp, -1, sizeof dp) ;
   cin>>M ;
   int ans = rec ( 0 , M , 0 ) ;
     cout << ans <<"\n" ;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
    while ( cin >> N){
    	solve() ;
    }
	return 0;
}
