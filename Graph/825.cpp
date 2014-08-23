#include <bits/stdc++.h>
using namespace std ;

typedef long long LL;

LL dp[111][111] ;
char maze [111][111] ;
int test, row ,col ;
char arr[1111] ;

bool valid ( int x , int y ){
	if( x >= 1 && x <= row && y >= 1 && y <= col )
		return true;
	else
		return false ;
}

LL rec ( int x , int y ){
   
   if( dp[x][y] != -1){
   	  return dp[x][y] ;
   }
   
    if( x == row && y == col ){
    	 dp[x][y] = 1 ;
    	 return dp[x][y] ;
    }
    
   dp[x][y] = 0 ;

   if( valid(x+1 ,y) )
   if( maze[x+1][y] != '*' )
   dp[x][y] += rec(x+1,y) ;
  
   if( valid(x,y+1) )
   if( maze[x][y+1] != '*' )
   dp[x][y] += rec( x,y+1) ;
   
  
  
  return dp[x][y] ;
}

LL solve (){
    cin >> row >> col ;
    getchar() ;

    int i , j , u , v ;
    
    for ( i = 0  ; i <= row ; i++)
    for ( j = 0 ; j <= col ; j++)
    maze[i][j] = '-' , dp[i][j] = -1 ;

    for ( i = 0  ; i < row ; i++){
          gets( arr ) ;
          u =  v = 0 ;
          bool f = true ;
         // cout<<"--> ";puts(arr);
          for ( j = 0 ; j < strlen(arr) ; j++ )
          if( arr[j] >= '0' && arr[j] <= '9' ){
              if(f)
              u = u*10 + (arr[j] -'0' ) ;
              else{
              	v = v*10 + ( arr[j] - '0' ) ;
              }
          }
          else {
          	  if( u > 0){ 
          	  	//cout <<"u "<< u << endl ;
          	    f = false ;
          	  }
          	  if( u > 0 && v > 0){
          	  	 //cout << v << endl;
          	  	 maze[u][v] = '*';
          	  	 v = 0 ;
          	  }
          }

         if( v > 0){ // cout << v << endl;
         maze[u][v] = '*' ;    	
      } 
    }

    /*
       for( i = 1 ; i <= row ; i++){
	       for( j = 1 ; j <= col ; j++)
	       cout << maze[i][j] ;
	      cout << endl;
       }
    */
    
   
   return rec(1,1) ;

 }

int main(){
  
  cin >> test ;
  getchar();
  while ( test-- ){
  	getchar();
  	 cout << solve () <<"\n";
  	 if(test)
  	 cout<<"\n";
  }

}



