#include<bits/stdc++.h>
using namespace std ;

#define INF 1000000000
int val [77][77];
int dp [77][77][7][2][2] ;
bool possible ;
int N , K ;

int rec ( int row ,int col , int k , bool right , bool  left ){
     if ( k < 0 || row > N || col > N || col < 1)
     return -INF ;
  // cout << row << " "<<col <<" "<< k <<" "<< right <<" "<<left << endl;  

    if( dp[row][col][k][right][left] != -1 )
    return dp[row][col][k][right][left] ;
     
     if ( row == N && col == N && k >= 0 && val[N][N] >= 0){
     	possible = true ;
     	dp[row][col][k][right][left] = val[row][col] ;
     	return dp[row][col][k][right][left] ;
     }
     else if ( row == N && col == N && k >= 1 && val[N][N] < 0 ){
     	 possible = true ;
     	 dp[row][col][k][right][left] = val[row][col] ;
     	 return dp[row][col][k][right][left] ;
     }
     else if( row == N && col == N ){
     	return -INF ;
     }
  
  dp[row][col][k][right][left] = 0;
     
     if( val[row][col] >= 0){
        if( right  && !left )
        dp[row][col][k][right][left] = val[row][col] + max ( rec (row+1,col,k , 1 ,1 ) , rec(row ,col+1 , k , 1, 0) ) ;
        else if( !right && left )
        dp[row][col][k][right][left] = val[row][col] + max( rec(row+1 ,col ,k ,1,1) , rec( row,col-1 , k, 0,1) ) ;
        else if( left && right )
        dp[row][col][k][right][left] = val[row][col] + max( rec(row+1 , col , k, 1,1) , max(  rec ( row,col-1,k,0,1) , rec ( row ,col+1 , k ,1,0) ) ) ;
     }
     else {

        if( right  && !left )
        dp[row][col][k][right][left] = val[row][col] + max ( rec (row+1,col,k-1 , 1 ,1 ) , rec(row ,col+1 , k-1 , 1, 0) ) ;
        else if( !right && left )
        dp[row][col][k][right][left] = val[row][col] + max( rec(row+1 ,col ,k-1 ,1,1) , rec( row,col-1 , k-1, 0,1) ) ;
        else if( left && right )
        dp[row][col][k][right][left] = val[row][col] + max( rec(row+1 , col , k-1, 1,1) , max(  rec ( row,col-1,k-1,0,1) , rec ( row ,col+1 , k-1 ,1,0) ) ) ;
     
   }
    return dp[row][col][k][right][left] ;
}


int main(){
  int i ,j ,k ,l ,m; 
  int test = 1 ;
  while ( cin >> N >> K ){
  	 if ( N ==0  && K == 0)
  	 break ;
      for ( i = 1 ;  i <= N ; i++)
      for ( j = 1 ; j  <= N ; j++)
      cin >> val[i][j] ;

      for ( i = 0 ; i <= N ; i++)
      for ( j = 0 ; j <= N ; j++){
      
      for ( l = 0 ; l <= K ; l++)
      for ( k = 0 ; k < 2 ; k++)
      for ( m = 0 ; m < 2 ;m++)
      dp[i][j][l][k][m] = -1 ;
     }
     
      cout <<"Case "<<test++<<": "; 
      int ans = INF ;
      possible = false ;
      ans =  min ( ans , rec ( 1 ,1,K,1,1)) ;
      //out () ;

      if( possible )
      	cout << ans ;
      else
      	cout <<"impossible";
     cout <<"\n" ;
  }


	return 0 ;
}
