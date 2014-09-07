#include <bits/stdc++.h>
using namespace std;



typedef vector < int > vi ;
vector < vi > adj ;

int dp [55][33] ;
int N ,M , DAYS ;
bool ispossible ;
int rec ( int city , int ginti){
    if(ginti > 30 )
    return 1e9 ;
//cout << city <<" "<<ginti <<endl;
    if( dp[city][ginti] != -1 )
    return dp[city][ginti];

    if( city == N-1 && ginti >= DAYS ){
    	dp[city][ginti] = ginti ;
    	return dp[city][ginti];
    }
   dp[city][ginti] = 1e9 ;
   for ( int i = 0 ; i < adj[city].size() ; i++){
   dp[city][ginti] = min( dp[city][ginti], rec ( adj[city][i],ginti+1) ) ;
   //dp[city][ginti] = min ( dp[city][ginti] , rec( adj[city][i],ginti) ) ; 
  }
  
  //cout << city <<" "<<ginti << " "<<dp[city][ginti]<< endl;
  return dp[city][ginti] ;
}


void solve (){
	int i , j , k;
	ispossible = false ;
	for ( i = 0 ; i < N ; i++)
	adj[i].clear() ;
    memset ( dp, -1, sizeof dp) ;
    for ( i = 0; i < M ; i++){
    	 cin >> j >> k ;
    	 if( j != k)
    	 adj[j].push_back(k) ;
    }

    int ans = rec( 0 , 1 ) ;
    //cout << ans << endl;
    if( ans >= DAYS  && ans < 1e9 ){
    	cout <<ans<<"\n";
    }
    else
    	cout <<"LOSER\n";
}


int main(){
  adj.assign(55,vi()) ;
  while ( cin >> N >> M >> DAYS){
  	 if( N == 0 && M == 0 && DAYS == 0){
  	 	break ;
  	 }
  	 solve() ;
  }
  return 0;
}
