#include <bits/stdc++.h>
using namespace std ;



typedef long long LL ;

LL dp[22][22] ;
char arr[22][22] ;
int n ;

void out (){
  cout << endl; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++)
	    cout <<" "<< arr[i][j];
	  cout << endl;
	}  
}


void out2(){
    cout << endl;
	 for ( int i = 1 ; i <= n ; i++){
	 for ( int j = 1 ; j <= n ; j++)
	 cout <<" "<<dp[i][j]<<"("<<arr[i][j]<<")" ;
	cout << endl;}

}

LL rec ( int row , int col ){
	if( dp[row][col] != -1)
	return dp[row][col] ;
   // cout << col <<" "<<row << endl;
    if( col == n){
    	 dp[row][col] = 1;
    	 return dp[row][col] ;
    }

    dp[row][col] = 0 ;

    for ( int x = row-2 ; x >= 1 ; x-- )
    dp[row][col] += rec ( x ,col+1) ;
    
    for ( int x = row+2 ; x <= n ; x++)
    dp[row][col] += rec ( x ,col+1) ;
     
   //  if( arr[row][col] == 'Q' ){
   //  	 cout <<"yahan" <<" "<<dp[row][col] << endl;
   //  }
     return dp[row][col] ;
}


LL solve( string input ){
	 int i ,j , k , l;
	 memset ( dp , -1 ,sizeof dp) ;
	 for(i = 0 ; i <= 19 ; i++)
	 for( j = 0 ; j <= 19 ; j++)
	 arr[i][j] = '.' ;
      n = input.length() ;
        for ( i = 0 ; i < n  ;i++)
        if( isalpha(input[i]))
        {
        	 arr[ input[i]-'A' + 10][i+1] = 'Q' ;
        }
        else if( isdigit(input[i])){
        	arr[ input[i]- '0'][i+1] = 'Q' ;
        }
   //   cout <<"-->"<< n << endl;
  //    out() ;
    for ( i = 1 ; i <= n ; i++){
    	 bool q = false ;
    	 for ( j = 1 ; j <= n ; j++)
    	 if( arr[j][i] == 'Q' ){ q = true ; }
       if ( q ){
       	 for ( j = 1 ; j <= n ; j++)
       	 if ( arr[j][i] != 'Q' )
       	 dp[j][i] = 0 ;
       }
    }
//  out2() ;
  LL ans = 0;
  for ( int row =1 ; row <= n ; row++)
  if ( dp[row][1] == -1 )
  ans += rec ( row ,1 ) ;

//  out2() ;
  return ans ;

}


int main(){
    string s ;
    while ( cin >> s){
    	cout << solve(s) <<"\n" ;
    }
	return 0 ;
}
