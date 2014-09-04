#include <bits/stdc++.h>
using namespace std ;



#define P first
#define Q second
typedef long long LL ;
typedef pair < int ,int > ii ;
typedef pair < ii , int> iii ;
map < iii , LL > dp ; 
int L [22222] , R [22222] ,n ;

LL rec ( int row ,int col , int dir ){
    if( row == n+1 ){
    	return n-col ;
    } 

    iii v ;
    v.P.P = row ; v.P.Q = col ; v.Q = dir ;
    if( dp[v] != -1 ){
    	return dp[v] ;
    }
    
    if( col >= L[row] && col <= R[row] ){
    	LL a = 1 + (R[row]-col) + (R[row]-L[row]) + rec( row+1 ,L[row] , 0) ;
    	LL b = 1 + (col-L[row]) + ( R[row] - L[row]) + rec ( row+1 ,R[row],1) ;
        dp[v] = min ( a , b) ;
    }
    else if( col <= L[row] ){
    	LL a = 1 + ( R[row]-col) + ( R[row]-L[row] ) + rec ( row+1 , L[row] , 0); 
    	LL b = 1 + ( R[row] - col) + rec ( row+1 , R[row] ,1 ) ;
    	dp[v] = min ( a , b) ;            
    }
    else if( col >= R[row]){
    	LL a = 1 + (col-L[row]) + rec( row+1 , L[row],0);
    	LL b = 1 + ( col - L[row]) + ( R[row]-L[row]) + rec ( row+1 ,R[row],1) ;
    	dp[v] = min ( a , b ) ;
    }    
  // cout << row <<" "<<col<<" "<<dir <<" "<<dp[v] << endl;
   if( row == 1)
   dp[v] -= 1 ;
    return dp[v] ;
}

void solve (){
	 for ( int i = 1 ; i <= n ; i++){
	  cin >> L[i] >> R[i] ;
	  if( i == 1)
	  dp[ iii( ii(i,1) , 1 ) ] = -1 ;
	  else{
	  	dp[ iii(ii(i,L[i-1]),0) ] = dp[ iii(ii(i,L[i-1]),1) ] = -1 ;
	    dp[ iii(ii(i,R[i-1]),0) ] = dp[ iii(ii(i,R[i-1]),1) ] = -1 ;
	  }
	}
 // cout <<"aaya\n" ;
  LL ans = rec(1,1,1) ;
  cout << ans << endl;
 // cout <<"gaya\n" ;
}


int main(){
  cin.sync_with_stdio(0) ;
  cin.tie(0) ;   
   while ( cin >> n ){
   	 if ( n == 0)
   	 break ;
     dp.clear() ;
     solve() ;
   }
	return 0 ;
}
