#include <bits/stdc++.h>
using namespace std ;

#define P first
#define Q second 
typedef long long LL;
typedef pair < int , int > ii ;
typedef pair < ii , ii > iiii ;

vector < iiii > undo ;


int n,sx,sy,fx,fy ;

LL dp [33][33] ;
bool move [33][33][33][33] ;

bool valid ( int row , int col){
	 if( row >= sx && row <= fx && col >= sy && col <= fy)
	 return true ;
	else
		return false ;
}

LL rec ( int row , int col ){
	 if( dp[row][col] != -1)
	 return dp[row][col] ;

	 if( row == fx && col == fy ){
	 	 dp[row][col] = 1 ; return dp[row][col] ;
	 }

	 dp[row][col] = 0 ;

	 if( valid(row+1,col) )
	 if( move [row][col][row+1][col] )
	 dp[row][col] += rec ( row+1,col) ;

	 if( valid ( row,col+1) )
	 if( move [row][col][row][col+1] )
	 dp[row][col] += rec( row,col+1) ;
	return dp[row][col] ;
}

void out () {
	 int i , j ;
	 for( i = 0 ; i < undo.size() ; i++)
	 {
	 	 iiii v = undo[i] ;
	 	 cout << v.P.P <<","<<v.P.Q <<" -> "<<v.Q.P <<","<<v.Q.Q << endl;
	 }

	 for( i = sx ; i <= fx ; i++)
	 {
	 	 for( j = sy ; j <= fy ; j++)
	 	 cout << " "<<dp[i][j] ;
	 	cout << endl;
	 }
}


void solve () {
	 int  i, j , k , row ,col,w ; char c ;
	 cin >> n ;
	 cin >> sy >> sx ;
	 cin >> fy >> fx ;

	 cin >> w ;
	 undo.clear() ;
	 memset ( dp , -1 ,sizeof dp );

	 while( w-- ){
	 	 cin >> col >> row >> c ;
	 	 if( c == 'N' )
	 	 c = 'S' ;
	 	 else if( c == 'S' )
         c = 'N' ;

        if ( c == 'E' ){
             move[row][col][row][col+1] = false ;
             undo.push_back( iiii( ii( row,col) , ii(row,col+1) ) ) ; 
        }
        else if( c== 'W' ){
                move[row][col-1][row][col] = false ;
                undo.push_back( iiii( ii( row,col-1) , ii(row,col) ) ) ;
        }
        else if( c == 'N' ){
               move[row-1][col][row][col] = false ;
               undo.push_back( iiii( ii( row-1,col) , ii(row,col) ) ) ;
        }
        else if( c == 'S' ){
                 move[row][col][row+1][col] = false ;
             undo.push_back( iiii( ii( row,col) , ii(row+1,col) ) ) ;
        }
	 }

	 LL ans = rec( sx , sy ) ;
	// out () ;
	 cout << ans <<"\n" ;

	 for ( i = 0 ; i < undo.size() ; i++)
	 {
	 	 iiii v = undo[i];
	 	 move[v.P.P][v.P.Q][v.Q.P][v.Q.Q] = true ;
	 }
	 undo.clear() ;
}


int main(){
  
  int test ;
  for( int i = 1 ; i <= 30 ; i++)
  for( int j = 1 ; j <= 30 ; j++)
  for( int k = 1 ; k <= 30 ; k++)
  for( int l = 1 ; l <= 30 ; l++)
  move[i][j][k][l] = true ;
  
   cin >> test ;
   while( test-- ){
   	  solve() ;
   }
  
	return 0;
}
