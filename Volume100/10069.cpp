#include <bits/stdc++.h>
using namespace std ;

string  dp[10011][105] ;
string A ,B ;
int test , n , m;

vector < int > adj [30] ;

string ADD ( string &x , string &y){
	while(x.length() < y.length())
	x += '0' ;
    while (y.length() < x.length())
    y += '0' ;
  int carry ; string ans ;
  carry = 0 ;
  for (int i = 0 ; i < x.length() ; i++)
  {
  	 ans += ((x[i] - '0') + ( y[i] -'0' ) + carry )%10 + '0'  ;
  	 carry = ((x[i] - '0') + ( y[i] -'0' ) + carry )/10 ;
  }

  while ( carry != 0){
  	ans += (carry%10) + '0' ; carry /= 10; 
  }

return ans ;
}


int main(){
    cin.sync_with_stdio(0) ; cin.tie(0) ;
    int i , j, k, l , u, v ;
    cin >> test ;
    while ( test-- ){
    	 cin >> A >> B ;
         n =  A.length() ; m = B.length() ;
       
         for ( i = 0 ; i <= n ; i++)
         for ( j = 0 ; j <= m ; j++){
           dp[i][j].clear();
           if( j == m)
           dp[i][j] = "1" ; 
         }
       
       for ( i = n-1 ; i >= 0; i--)
       for ( j = m-1 ; j >= 0 ; j--){
          dp[i][j] = ADD ( dp[i][j] , dp[i+1][j] );
          if( A[i] == B[j] )
          dp[i][j]  = ADD ( dp[i][j], dp[i+1][j+1]) ;
       }
      

      string ans = dp[0][0] ;

      reverse ( ans.begin() , ans.end());
      string :: iterator fit ;
      fit = ans.begin() ;
    

     while ( *fit == '0'){
      	 ans.erase(fit) ; fit = ans.begin() ;
      }
     
      cout << ans <<"\n" ;
   }
	return 0 ;
}
