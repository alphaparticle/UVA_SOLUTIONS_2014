#include <bits/stdc++.h>
using namespace std ;



int R , C , n ;
bool wolf [111][111] ;


int dp[111][111] ;

bool valid( int row,int col){
	if( row >= 0 && col <= C && row <= R && col >= 0)
	return true;
   else
   return false; 
}

int rec ( int row , int col ){

	if( dp [row][col] != -1)
		return dp[row][col] ;

	if( row == R && col == C )
	{
		 dp[row][col] = 1 ;
		 return dp[row][col] ;
	}

  dp[row][col] = 0;
	if( valid(row+1,col) )
	if( !wolf[row+1][col] )
    dp[row][col] += rec( row+1,col) ;
    
    if( valid(row,col+1) )
	if( !wolf[row][col+1] )
    dp[row][col] += rec( row,col+1) ;
   return dp[row][col] ;     
}


void solve(){
   int i , j, x, y ;
   cin >> n ; 
   while ( n-- ){
        cin >> x >> y ;
        wolf[x][y] = true ;
   }
  
   int ans = rec( 0 , 0) ;
   if( ans == 1)
   	cout <<"There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
   else if( ans > 1){
       cout <<"There are "<<ans<<" paths from Little Red Riding Hood's house to her grandmother's house.\n" ;
   }
   else
   	cout <<"There is no path.\n";
}


int main(){
    while ( cin >> R >> C ) {
    	 if ( R == 0 && C == 0)
    	 break ;
    	for( int i = 0 ; i <= R ; i++)
    	for ( int j = 0 ; j <= C; j++)
    	wolf[i][j] = false , dp[i][j] = -1 ;
    	solve() ;
    }

	return 0;
}
