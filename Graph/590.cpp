#include <bits/stdc++.h>
using namespace std ;

int n , DAYS , ANS ;
int cost [11][11][1111] ;
int dp [1111] [11];

void out () {
  
   int i , j, k ; 
   for ( i = 1 ; i <= n ; i++){
   	  for ( j = 1 ; j <= n ; j++)
   	  if( j != i )
   	  {
   	  	  cout << i <<" -> "<< j << ":" ;
   	  	  for ( k = 1 ; k <= DAYS ; k++)
   	  	  cout <<" "<< k <<"("<<cost[i][j][k]<<")" ;
   	  	cout << endl;
   	  }
   	 cout << endl;
   }

}

int rec ( int day , int city  ){
  
  if( day == DAYS && city == n)
  return 0 ;
  else if( day == DAYS )
  return 1e9 ; 
 
  if( dp[day][city] != 1e9 ){
  	 return dp[day][city] ;
  }

  for ( int i = 1 ; i <= n ; i++ )
  if( city != i && cost[city][i][day+1] != 0 )
  dp[day][city] = min ( dp[day][city] , cost[city][i][day+1] + rec( day+1 , i ) ) ;
  
  return dp[day][city] ;
}

void solve () {
   int i , j, k, l , days ;
   for ( i =  1 ; i <= 10 ; i++)
   for ( j = 1 ; j <= 10 ; j++)
   for ( k = 1 ; k <= 1000 ; k++)
   cost [i][j][k] = -1 ; 
 
   for ( i = 1 ; i <= n ; i++){
   	    
   	    for ( j = 1 ; j <= n ; j++)
   	    {
   	    	  if( j == i)
   	    	  {
   	    	  	  continue ;
   	    	  }
             cin >> days ;
             for ( k = 1 ; k <= days ; k++)
             cin >> cost [i][j][k] ;

             for ( k = days+1 ; k <= DAYS ; k++){
             	 int p = (k%days) ;
             	 if( p == 0)
             	 p = days ;
             	cost[i][j][k] = cost [i][j][p] ;
             }
   	    }
   }
  
 // out () ;
  for ( i = 0 ; i <= DAYS ; i++)
  for ( j = 0 ; j <= n ; j++)
  dp[i][j] = 1e9 ;
  ANS = rec ( 0 , 1) ;
}


int main(){
 cin.sync_with_stdio(0);
 cin.tie(0) ;	
	//cout << pow(3,10)<< endl;
	int test = 1 ;
    while ( cin >> n >> DAYS ){
    	if( n == 0 && DAYS == 0)
    	break ;
    	
    	solve() ;
      cout << "Scenario #"<<test++<<"\n";
      if( ANS < 1e9 ){
      	cout<<"The best flight costs "<<ANS<<".\n";
      }
      else{
      	cout<<"No flight possible.\n" ;
      }
      cout <<"\n" ;
    }
	return 0 ; 
}
