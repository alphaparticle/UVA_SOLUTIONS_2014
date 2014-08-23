#include <bits/stdc++.h>
using namespace std;



typedef long  long LL;
set < int > death ;

typedef vector < int > vi ;
vector < vi > adjlist ;

LL dp[11111] ;

LL rec ( int cur_event ){
	
	if( dp[cur_event] != -1)
	return dp[cur_event] ;
   //cout << cur_event <<"-->\n"; 
    if( adjlist[cur_event].size() == 0){
    	 dp[cur_event] = 1;
    	 return dp[cur_event] ;
    }

    dp[cur_event] = 0 ;
    for( int i = 0 ; i < adjlist[cur_event].size() ; i++)
    dp[cur_event] += rec ( adjlist[cur_event][i]) ;
    
    return dp[cur_event] ;
}


LL solve ( int events ){
    
    death.clear() ;
    adjlist.clear() ;
    
    adjlist.assign( events , vi()) ;
    int i , j, k, l ;

    for( i = 0 ; i < events ; i++){
    	 cin >> k ;

    	 for( j = 0 ; j < k ; j++)
    	 {
    	 	 cin >> l ;
    	 	 adjlist[i].push_back ( l ) ;
    	 }
    	dp[i] = -1 ;
    }
	LL ans = rec(0);
	//for( i = 0  ; i < events ; i++)
	//cout << i <<" "<<dp[i] << endl;
    return ans ;
}


int main(){
    cin.sync_with_stdio(0);
   // cin.tie(0);
    bool first = true ;
    int events;    
    while ( cin >> events ){
       if(!first)
       cout <<"\n";
       
       cout << solve ( events)<<"\n" ;	
       first = false ;
    }

	return  0 ;
}
