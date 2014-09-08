#include <bits/stdc++.h>
using namespace std ;
typedef  vector < int > vi ;
vector < vi > adj ;
int N  ;
int dp[10001][11] ;
int DP[10001] ;

// EXTRA DEBUGGING FUNCTIONS 

void out (){
  int i , j ;
  for ( i = 0 ; i < N ;i++){
     cout << i <<"-> ";
     for( j = 0 ; j < adj[i].size() ; j++ )
     cout <<" "<<adj[i][j];
   cout << endl;
  }
}
//


int rec( int node  ){
	if( DP[node] != -1 )
	return DP[node] ;
    
    DP[node] = 1 ;
    for ( int i = 0 ; i < adj[node].size() ; i++)
    DP[node] += rec ( adj[node][i]) ;
   return DP[node] ;
}

int optimize ( int node , int color ){
   //cout << node <<" "<<color << endl;
  	if( dp[node][color] != -1)
	  return dp[node][color] ;
    
    if( color == 0)
    {
        dp[node][color] = 1e9;
        for ( int i = 1 ; i <= 10 ; i++)
        {
            //cout << "---------------\n";
            int b = optimize ( node , i);
            //cout <<"------>"<< b << endl;
            dp[node][color] = min ( dp[node][color],b) ;
        }
        return dp[node][color] ;
    }
    dp[node][color] = color ;
    
    for ( int i = 0 ; i < adj[node].size() ; i++){
           int c  = 1e9 ;
          for ( int j = 1 ; j <= 10 ; j++)
          if( j != color)
          c = min ( c , optimize(adj[node][i],j));
       dp[node][color] += c ;
    }
    
    //cout << node <<" "<<color <<" "<< dp[node][color] << endl;
    return dp[node][color] ;
}


void solve (){
   int i , j , u , v ; string s ;
   for ( i = 0 ; i < N ; i++)
   {
   	  getline(cin,s);
   	  v = 0 ; bool f = false ;

   	  for ( j = 0 ; j < s.length() ; j++)
   	  if ( s[j] == ':'){ break ;}

      for ( j = j+1 ; j < s.length() ; j++ ){
      	 if ( s[j] >= '0' && s[j] <= '9' ){
      	 	 v = v*10 + (s[j] - '0') ;
      	 	 f = true ; 
      	 }
      	 else{
      	 	if ( v != i && f ){ adj[i].push_back(v) ; //cout << i <<" "<<v << endl; 
      	                }
      	 	v = 0 ; f = false;
      	 }
      }
     if( f && v != i  ){
       adj[i].push_back(v) ;
       //cout << i <<" "<< v <<endl;
     } 
  }

  for( i = 0 ; i <= N ; i++){
  DP[i]  = -1 ;
  for ( j = 0 ; j <= 10 ; j++)
  dp[i][j] = -1 ;}
  
  int root = -1 ;
  //out();
  for ( i = 0 ; i < N ; i++)
  {
  	  int children = rec (i) ;
  	  //cout << i <<" reaches "<<children << endl;
  	  if( children == N ){
  	  	root = i ; break ;
  	  }
  }

 // cout <<" ROOT " << root << endl;
  if( root == -1){ while(1) ; }

   
  int ans = optimize ( root , 0) ; 
  cout << ans <<"\n" ;

}

int main(){
adj.assign(10011,vi()) ;
 
 while ( cin >> N){
 	 if ( N == 0)
 	 break ;
 	getchar() ;
 	for ( int i = 0 ; i <= N ; i++)
 	adj[i].clear() ;
 	solve() ;
 } 
 return 0 ;
}
