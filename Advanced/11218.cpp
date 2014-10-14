#include <bits/stdc++.h>
using namespace std ;
#define gc getchar
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int dp [1<<11] ; int order ; bool haha ;
int test ,bonus [88][4] , cost [88] ;

int rec( int mask ){
	

  if( dp[mask] != -1)
  return dp[mask] ;
   int i ,j ;
	bool r = true ;
	for ( i= 0 ; i < 9 ; i++)
	if ( !(mask&(1<<i)) ){ r = false; break;}
    
    if(r){
    haha = true ;
    return 0 ;}

   int t = 0 ;
   string u ;
   for ( i = 0 ; i < 9 ; i++)
   if( (mask&(1<<i)) ) u += '1';
   else
   u += '0' ;
 
   for ( i = 0 ;  i < order ; i++){
    bool p = true ;
    for ( j = 0 ; j < 3 ; j++)
    if( u[ bonus[i][j] ] == '1')
    { p = false ; break ;}
      
    if(p){
        string pp = u;
    	pp [bonus[i][0]] = pp [bonus[i][1]] = pp [bonus[i][2]] = '1' ;
    	int x = 0;
    	
    	for( int k = 0 ; k < 9; k++)
    	if( pp[k] == '1' )
    	x |= (1<<k) ;
        
    	t = max ( t , cost[i] + rec(x));
    }  
  }
  if( t == 0)
  t = -1e9 ;
  dp[mask] = t ;
 
  return dp[mask] ;    
}

int main(){
  
  for( int kase =1 ;  ; kase++){
  	 scanint(order) ;
  	 if( order == 0)
  	 break ;
  	 for ( int i = 0 ;  i < order ; i++){
	  	 for ( int j = 0; j < 3 ;j++){
	  	 scanint(bonus[i][j]) ; bonus[i][j] -= 1;}
	   scanint(cost[i]) ;  
     }
    
     for (int i = 0 ; i <= (1<<9) ; i++)
     dp[i]= -1 ;
     
     haha  = false ;
     int ans = rec(0);
     if( !haha || ans <= 0)
     ans = -1 ;
     printf("Case %d: %d\n", kase ,ans);
  }
   	return 0;
}
