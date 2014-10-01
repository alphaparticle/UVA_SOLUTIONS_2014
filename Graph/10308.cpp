#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define P first
#define Q second
typedef pair < int , int > ii ;
vector < ii > adj [11111] ;
vector < int > duplicate [11111] ;

char arr[30] ;
bool vis [111111] ;

int dfs ( int  u ){
	vis[u] = true ;
	int z = 0 ;
	for (int i = 0 ;  i < adj[u].size() ; i++)
	if( !vis [ adj[u][i].P ] )
	z = max ( z , adj[u][i].Q + dfs(adj[u][i].P ) ) ;
	return z ;  
}

int main(){
int u , v , w , i, j,k;
  while ( gets(arr) ){
  	  
  	  if( strlen(arr) <2  ){
  	  	  getchar(); getchar() ;puts("0") ;continue ;
  	  }
  	  int mini , maxi ; mini = 1e9 ; maxi = -1e9 ;
      sscanf( arr , "%d %d %d", &u , &v , &w) ;
      adj[u].pb(ii(v,w)), adj[v].pb(ii(u,w)) , duplicate[u].pb(v),duplicate[v].pb(u) , mini  = min(mini, min(u,v)) , maxi = max(maxi ,max(u,v)) ;
      while ( gets(arr) ){
      	   if( strlen(arr) < 2)
      	   break ;
      	 sscanf( arr , "%d %d %d", &u , &v , &w) ; //puts("->") ; puts(arr) ;
         adj[u].pb(ii(v,w)), adj[v].pb(ii(u,w)) , duplicate[u].pb(v),duplicate[v].pb(u) ;
         mini  = min(mini, min(u,v)) , maxi = max(maxi ,max(u,v));
      }

     for ( i = mini ; i <= maxi ; i++)
     sort ( duplicate[i].begin() , duplicate[i].end()) ;
     
     int center = -1 ;
     //cout <<"Center ofthe tree\n" ;
   
     while(1){
        vector <int> leaf ;
        int alive = 0 ;
        for ( i = mini  ; i <= maxi ; i++)
        if( (int)duplicate[i].size() > 0  ){ 
            if( duplicate[i].size() > 1)
            alive++ ;
        	if( duplicate[i].size() == 1){
        	leaf.pb(i) ; duplicate[i].clear() ;}
        }

        if( alive == 1){
        	 for( i = mini ; i <= maxi ; i++)
             if( duplicate[i].size() > 0 )
             {
             	 center = i ; break ;
             }
            if( center != -1)
            break ;
        }


        if( leaf.size() > 2 ){
        	vector < int > :: iterator it ;
        	for( i = mini ; i <= maxi ; i++)
        	if( duplicate[i].size() > 0){
        	  //cout <<"---> "<< i << " "<< duplicate[i].size() << endl;
        		for ( j = 0 ; j < leaf.size() ; j++){
        		it = lower_bound( duplicate[i].begin() , duplicate[i].end() , leaf[j] ) ;
        	  if( it != duplicate[i].end())
        	  if( leaf[j] == *it)
        	    duplicate[i].erase(it) ;
        	  }
           }
        }
        else{
        	 center = leaf[0] ; break ; }
     }
    // cout << center << " center "<< endl;
     vector < int > ans ; memset ( vis , false ,sizeof vis) ;
     for ( i = 0 ; i < adj[center].size() ; i++)
     {
         vis [ center ] = true ;
         v = adj[center][i].Q + dfs ( adj[center][i].P ) ;
         ans.pb(v) ;
     }
    sort ( ans.begin() ,ans.end()) ;
    int sz = ans.size() ; //cout << sz << endl; 
    if( sz == 1)
    printf("%d\n",ans[0]);
  else
    printf("%d\n", ans[sz-1] + ans[sz-2]) ;  

      for ( i = mini ; i <= maxi ; i++){
      adj[i].clear() ; duplicate[i].clear() ; }
  }
 return 0 ;
}
