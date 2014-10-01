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

bool vis [5555] ;
vector < int > adj [5555] , extra[5555] ;
int n ,depth;
vector < int > worst ; 

int dfs ( int  u  , int d ){
	 vis[u]  = true ;
	// cout << u <<" d "<<d <<"\n" ;
	 if( d > depth ){
	 	 worst.clear() ; depth = d ; worst.push_back(u) ;
	 }
	 else if( d == depth ){ worst.push_back(u) ;}

	 for ( int i = 0 ; i < adj[u].size() ; i++){
	 	 int v = adj[u][i] ;
	 	 if( !vis[v])
	 	 dfs ( v , d+1) ;
	 }
}

int main(){
  int i , j, k, l, u , v ,mini , maxi ;
  clock_t  st = clock() ;
  freopen("in.txt" , "r" , stdin) ;
  while ( scanf("%d", &n) != EOF ){
      for ( i = 1 ; i <= n ; i++)
      adj[i].clear() , extra[i].clear() ;
      for ( i = 1 ; i <= n ; i++){
            scanint(j);
            for ( k =  1 ; k <= j ; k++)
            {
            	 scanint(v) ; adj[i].push_back(v) ; extra[i].push_back(v) ;
            }
      }
     vector < int > center ;
     for( i = 1 ; i <= n  ; i++)
     sort ( extra[i].begin() , extra[i].end()) ;

     while(1){
     	 vector < int > leaf ;
     	 //cout <<"====\n";
     	 int alive = 0 ;
     	 for ( i = 1 ; i <= n ; i++)
     	 	 if( extra[i].size() == 1){
     	 	 	// cout <<": "<<i << endl;
     	 	 	 leaf.push_back(i) ; extra[i].clear() ;
     	 	 }
     	 	 else if( extra[i].size() > 1){ alive++ ; }

     	 	if( alive == 1){
     	 		for ( i = 1 ; i <= n ; i++)
     	 		if( extra[i].size() > 1 ){ center.push_back(i) ; break ;}
     	 	    if( center.size() > 0)
     	 	    break ;
     	 	}
     	  
     	 if( leaf.size() >= 2 && alive >= 2 ){
     	 	vector < int > :: iterator it ;
     	 	 for ( i = 0 ; i < leaf.size() ; i++){
     	 	 	 u = leaf[i] ;
     	 	 	 for ( j = 0 ; j < adj[u].size() ; j++)
     	 	 	 {  v = adj[u][j] ;
     	 	 	 	 it = lower_bound( extra[v].begin() , extra[v].end() , u );
     	 	 	 	 if( it != extra[v].end())
     	 	 	 	 if( *it == u )
     	 	 	 	 extra[v].erase(it) ;
     	 	 	 }
     	 	 }
     	 }
     	 else {
            for ( i = 0 ; i < leaf.size() ; i++)
            center.push_back( leaf[i] ) ;     	    
     	    break ;
     	 }
     }
     sort ( center.begin() , center.end()) ;
     printf("Best Roots  :");
     for ( i = 0 ; i < center.size() ; i++)
     printf(" %d",center[i]);
     printf("\n");
     if( center.size() > 2){ cout << center[123456789] ;}
     depth = 0 ; worst.clear() ;
     for ( i = 0 ; i < center.size() ; i++){
      for(  j = 0 ;  j <= n ; j++)
      vis[j] = false ;
      dfs ( center[i] , 0 ) ;
    }
     printf("Worst Roots :");
     sort ( worst.begin() , worst.end()) ; 
    // cout << worst.size() << endl;
     for ( i = 0 ; i  < worst.size() ; i++)
     printf(" %d",worst[i]) ;
     printf("\n") ;

  }
  clock_t en = clock() ;
// printf("%.5lf\n", (en-st)/(CLOCKS_PER_SEC * 1.0)) ;
	return 0 ;
}
