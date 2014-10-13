#include <bits/stdc++.h>
using namespace std ;
int n ;
string c ;
map < string , int > dp; 

int solve( string z){

   if( dp.count(z) == 0)
   dp[z] = -1 ;

   if( dp[z] != -1 )
   return dp[z] ;
 
   int sol = 0 ;
  
   for ( int i = 0 ; i < z.length() ; i++)
   if( z[i] == 'o' )
   sol++ ;

   for (int i = 0 ; i < z.length() ; i++ ){
   	   string temp = z ;
   	   if ( temp[i] == '-' ){
   	   	  if(i-2 >= 0)
   	   	  if( temp[i-2] == 'o' && temp[i-1] == 'o' )
   	   	  {
   	   	  	 temp[i-1] = temp[i-2]= '-' ; temp[i] = 'o' ;
   	   	  	 sol = min ( sol , solve(temp)) ;
   	   	  }
   	   }
   	  temp = z ;
   	  if( temp[i] == '-' ){
   	  	 if( i+2 < temp.length())
   	  	 if( temp[i+1] == 'o' && temp[i+2] == 'o'){
   	  	 	 temp[i+1] = temp[i+2] = '-';
   	  	 	 temp[i] = 'o' ;
   	  	 	 sol = min ( sol , solve(temp)) ;
   	  	 }
   	  }
   }
  dp[z] = sol; 
  return dp[z] ;
}

int main(){
    scanf("%d",&n);
    while (n--){
    	 dp.clear() ;
    	 cin >> c ;
    	 printf("%d\n",solve(c)) ;
    }
	return 0;
}
