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

// double st = clock() ;
//cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
#define pb push_back
#define P first
#define Q second
typedef pair < int , int > ii ;
int n , m , h;
set < int > hotels ;
map < int , int > idofhotels ;
int dist[105][1000001];
vector < ii > adj [100001];


int dij (){
	int i , j , k, l;
	//cout << hotels.size() << endl;
	for (int  i = 0 ; i <= hotels.size() ; i++)
 	for (int j = 0 ; j <= n ; j++)  
   	dist[i][j] =1e9 ;

   for( set < int> :: iterator it = hotels.begin() ; it != hotels.end() ; it++){
	    int u = idofhotels[*it] ;
	    dist[u][*it] = 0 ;
	    priority_queue < ii , vector < ii > , greater <ii > > pq ;
	    pq.push(ii(0, *it));
	    while( !pq.empty() ){
	    	 ii x =pq.top() ;
	    	 pq.pop() ;
	    	 if( x.P == dist[u][x.Q] )
	    	 	 for( int i = 0 ; i < adj[x.Q].size() ; i++){
	    	 	 	ii y = adj[x.Q][i] ;
	    	 	 	if( x.P + y.Q < dist[u][y.P] ){
	    	 	 		 dist[u][y.P] = x.P + y.Q ; pq.push(ii(dist[u][y.P] , y.P)) ;
	    	 	 	}
	    	 	 }
	    	 
	    }
   }

   int sz = hotels.size() ;
   /*
   for ( set < int > ::iterator fit , it = hotels.begin() ; it != hotels.end() ; it++ ){
      cout << *it <<" > "<<idofhotels[*it]<<" -: ";
      for( j = 1 ; j <= n ; j++)
      cout << j <<"("<<dist[idofhotels[*it]][j]<<") ";
      cout <<endl;  
   }
   */
   vector < int > ADJLIST [sz+10] ;
   for ( set < int > ::iterator it = hotels.begin() ; it != hotels.end() ; it++ ){
   	    int u = idofhotels[*it];
   	    for(set<int>::iterator fit = hotels.begin() ; fit != hotels.end() ; fit++)
   	    if( fit != it)
   	    if( dist[u][*fit] <= 600 ){
   	    	ADJLIST[u].pb(idofhotels[*fit]);
   	    }
   }
   /*
   for ( i = 1 ; i <= sz ; i++){
   	 cout <<i <<": ";
   	 for( j = 0 ;  j < ADJLIST[i].size() ; j++)
   	 cout <<" "<<ADJLIST[i][j] ;
   	 cout << endl;
   }
   */
   int d [sz+110] ;
   for ( i = 0 ; i <= sz ; i++)
   d[i] = 1e9 ;
   queue <int > q ; d[idofhotels[1]] = 0 ;q.push(idofhotels[1]);
   
   while(!q.empty()){
   	  int u = q.front() ; q.pop();
   //	  cout << u <<" -> "<<d[u]<< " "<<ADJLIST[u].size() << endl;
   	  for( i = 0 ; i < ADJLIST[u].size() ; i++){
   	  	int v = ADJLIST[u][i] ;
   //	  	cout <<": "<<v <<" "<<d[v] << endl;
   	  	if( d[v] == 1e9){
   	  		 d[v] = d[u] + 1 ;
   	  		 q.push(v) ;
   	  	} 
   	  }
   }
 //     for( set <int> :: iterator it = hotels.begin() ; it != hotels.end() ; it++)
 //     cout << *it <<" "<<d[idofhotels[*it]] << endl;

   return d[idofhotels[n]];
}

int main(){
  //freopen("out.txt", "w" ,stdout);
  int i , j , k, l , u , v ,w;
  while (1){
  	 scanint(n) ;
  	 if( n == 0)break ;
  	 idofhotels.clear() ; hotels.clear() ;
  	 hotels.insert(1) ;
  	 for( i = 1 ;i <= n ; i++) adj[i].clear() ;
     scanint(h) ; for( i = 0 ; i < h ; i++){ scanint(j) ; hotels.insert(j) ;}
     hotels.insert(n);
     j =1 ;
     for( set <int> :: iterator it = hotels.begin() ; it != hotels.end() ; it++)
     idofhotels[*it] = j++ ;
     scanint(m);
     while(m--){
     	 scanint(u);scanint(v);scanint(w);
     	 adj[u].pb(ii(v,w));adj[v].pb(ii(u,w));
     }
   int ans = dij() ;
  //cout << ans << endl;
   if( ans-1 <= h)
   printf("%d\n",ans-1);
else
	puts("-1");
 }
	return 0;
}

