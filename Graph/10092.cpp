#include <bits/stdc++.h>
using namespace std ;
typedef vector < int > vi ;

int noc ,nop;
vector < int > adj [1025] ;
int res [1025][1025] ;
int mf , f ,s ,t ;
vi p ;

void augment ( int node , int minedge ){
 	
	if( p[node] == -1 ){
		f = minedge ; return ;
	}
	else{
		augment( p[node] , min( minedge , res[p[node]][node]) ) ;
		res[ p[node]][node] -= f ;
		res[node][ p[node]] += f ;
		return ;
	}
}

void edmondkarp(){
	mf = f = 0 ;
	while(1){
		bitset<1025>vis ;
        vis.set(s) ;
        queue <int> q ;p.clear();q.push(s) ;
        p.assign(t+1,-1);
        f = 0;
        while ( !q.empty() ){
        	 int u = q.front(); q.pop();
        	 if( u == t)
        	 break ;
        	 
        	 for ( int i = 0 ; i < adj[u].size() ; i++)
        	 {
        	 	 int v = adj[u][i] ;
        	 	 if( res[u][v] > 0 && !vis.test(v) ){
        	 	 	vis.set(v) ;
        	 	 	q.push(v) ; p[v] = u ; 
        	 	 }
        	 }
        } 
       if( vis.test(t)) 
       augment ( t , 1e9 );
       if ( f == 0)
       break ;
       
       mf += f ;
  	}
 }
int main(){
	cin.sync_with_stdio(0) ; cin.tie(0) ;
    int i , j , k , u , v ;
    while ( cin >> noc >> nop ){
       if( noc == 0 && nop == 0)
       break ;

       s = 0 ; t = noc + nop + 1 ;
      
       for ( i = 0 ; i <= t ; i++)
       for ( j = i+1 ; j <= t ; j++)
       res[i][j] = res[j][i] = 0 ;
       
       for (i = 0 ; i <=t ; i++)
       adj[i].clear() ;

       for ( i = 1 ; i <= nop ; i++ )
       res[s][i] =   1 , adj[s].push_back(i) , adj[i].push_back(s) ;
       int expected = 0 ;
      
       for ( i = nop+1 ; i < t ; i++){
           cin >> u ; 
           expected += u ; adj[i].push_back(t) ; adj[t].push_back(i);
           res [i][t] = u  ; 
       }

       for ( i = 1 ; i <= nop ; i++){
       	   cin >> u ; 
       	   for ( j = 0 ; j < u ; j++){
       	   	 cin>> v ; 
             v += nop ;
       	   	 adj[i].push_back(v); adj[v].push_back(i) ;res[i][v] = 1 ; 
       	   }
       }

     
     edmondkarp() ;
    
     if( expected == mf ){
     	cout <<"1\n";
     
     	for ( i = nop+1 ; i < t ; i++){
     	bool first = true;
     	for ( j = 1 ; j <= nop ; j++)
     	if( res[j][i] == 0 && res[i][j] == 1  && binary_search( adj[j].begin() , adj[j].end() ,i ) ){
     		if(first)
     		cout<<j,first = false;
     	   else
     	   	cout <<" "<<j ;
     	}
     	cout <<"\n" ;
      }

     }
     else{
     	cout<<"0\n" ;
     }

  }    
	return 0;
}
