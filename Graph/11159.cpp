#include <bits/stdc++.h>
using namespace std ;
typedef vector < int > vi ;
vector   < int > adj [211] ;
int l [111] , r[111] ;
vi owner , visited ; 

int alternating_path ( int  u ){
	
	if( visited[u] )return 0;
	visited[u] = true ;
	for (int i = 0 ; i < adj[u].size() ; i++){
		int v  = adj[u][i] ;
		if( owner[v] == -1 || alternating_path(owner[v]) ){
			owner[v] = u ; 
			return 1 ;
		}
	}
  return 0 ;
}

int main(){
 int n , m , i, j, k , u , v , test;
 scanf("%d", &test);
 for( int kase = 1 ; kase <= test ; kase++ ){
    scanf("%d", &n) ;
    for ( i = 0  ; i < n ; i++)
    scanf("%d", l + i ) ;
    scanf("%d" , &m) ;
    for ( i = 0 ; i < m ; i++)
    scanf("%d" , r + i) ;
   for ( i = 0 ; i <= n+m ; i++)
   adj[i].clear() ;
   
    for ( i = 0 ; i < n ; i++){
            u = l[i];

          for ( j = 0 ; j < m ; j++){
          	 v = r[j];
          	 if ( u != 0 ){
          	 if( v%u == 0 || v == 0)
          	 adj[i].push_back(j+n);}
          	 else if( v == 0 && u == 0)
          	 adj[i].push_back(j+n) ;
          }
    }
    int mcbm = 0 ;
    owner.assign(n+m+1,-1) ;
    
    for ( i = 0 ; i < n ; i++){
    	visited.assign(n+1,0) ;
    	mcbm += alternating_path(i) ;
    	
    }
   printf("Case %d: %d\n",kase , mcbm) ;
 }


	return 0;
}
