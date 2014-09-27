#include <bits/stdc++.h>
using namespace std ;
#define gc getchar
typedef vector < int > vi ;
vi  owner , vis ;
vi adj [210] ;
int n , m , task;

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

int mcbm ( int u ){
	 if( vis[u]) return 0;
	 vis[u] = true ;
	for ( int i = 0 ; i < adj[u].size() ; i++)
	{
		 int v = adj[u][i];
		 if( owner[v] == -1 || mcbm( owner[v])){
		 	 owner[v] = u ; 
		 	 return 1 ;
		 }
	}
  return  0; 
}

int main(){
   int i , j , k, l ;
   while( 1 ){
   	  scanint(n);
   	  if( n == 0)
   	  break ;
   	 scanint(m);scanint(task);
   	for ( i = 0;  i <= n+m ; i++)
   	adj[i].clear() ;
    for ( i = 0 ; i  < task ; i++){
    	 scanint(j);scanint(k);scanint(l);
    	 adj[k].push_back(l+n);
    	 adj[l+n].push_back(k);
    }
    int cc =0 ;
    owner.assign( n+m+1 , -1) ;
    for ( i = 1 ; i <= n ; i++){
    	 vis.assign(n+m+1 , 0) ;
    	 cc += mcbm(i) ;
    }
    printf("%d\n",cc) ;
  }   

	return 0;
}
