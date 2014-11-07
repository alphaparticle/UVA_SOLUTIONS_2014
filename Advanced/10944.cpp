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
#define P first
#define Q second
typedef pair < int , int > ii ;
char graph[22][22];
int dist [411][411] ;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int r , c, sr ,sc ;
int dp[1<<16][16];
bool check ( int cr ,int cc){
	 return ( cr >= 0 && cr < r && cc >= 0 && cc < c) ;
}
int tre ;
vector < ii > nuts ;
inline int node ( ii x){
	return (x.P*c+x.Q);
}
int pp;
int tsp ( int mask , int last){
  // cout <<"oo "<< mask <<" "<<last << endl; 
  //  pp ++ ;
    if( dp[mask][last] != -1)
    return dp[mask][last];

    if( mask == (1<<tre)-1 ){
      return dp[mask][last] = dist[node(ii(sr,sc))] [node(nuts[last])] ;
    }
    int ans =  1e9 ;
    if( mask == 0){
	    for ( int i = 0 ; i < tre ; i++)
	    if( !(mask&(1<<i)) )
	    ans = min ( ans , dist[node(ii(sr,sc))][node(nuts[i])] + tsp( mask|(1<<i) , i )) ;	    
    }
    else{
		    for ( int i = 0 ; i < tre ; i++)
		    if( !(mask&(1<<i)) )
		    ans = min ( ans , dist[node(nuts[last])][node(nuts[i])] + tsp( mask|(1<<i) , i )) ;
    }
   //cout << mask <<" "<<ans << endl;
   return dp[mask][last] = ans ;
}

int main(){
   int i , j, k, l ; 
  // double st = clock() ;
 
   //freopen("in.txt" , "r" , stdin);
   while( scanf("%d %d", &r, &c) != EOF ){
        
        nuts.clear() ; 
        memset ( dist , -1, sizeof dist);
        getchar();
        for( i = 0 ; i < r ; i++)
        gets(graph[i]) ;//, puts(graph[i]);
        
        for ( i = 0 ; i < r ; i ++)
        for ( j = 0 ; j < c ; j++) if( graph[i][j] == 'L' ){ sr = i ;sc = j ;} 
        else if( graph[i][j] == '#'){ nuts.push_back(ii(i,j)) ;}
        nuts.push_back(ii(sr,sc));
        for ( i  = 0 ; i < nuts.size() ; i++){
        	ii u = nuts[i];
        	queue < ii > q ; dist[node(u)][node(u)] = 0;
        	q.push(ii(u.P,u.Q));
            while ( !q.empty() ){
               ii v = q.front() ; q.pop() ;
               for ( int j = 0 ; j < 8 ; j++){
               	  int tr = v.P+dx[j] ; int tc = v.Q+dy[j];
               	  if( check(tr,tc) && dist [node(u)] [node(ii(tr,tc))] == -1 ){
               	  	  dist[node(u)][node( ii(tr,tc))] = dist[node(u)][node(v)] + 1 ;
               	  	  q.push(ii(tr,tc));
               	  }
               }
            }             
       }
     /*  cout<<sr <<" "<<sc<<endl;
       cout << nuts.size()<<endl;
       for( i = 0 ; i < nuts.size() ; i++){
         for ( j = 0 ; j < r*c ; j++)
         cout <<i <<" "<< nuts[i].P<<" "<<nuts[i].Q<<" -> "<<j/c <<" "<<j%c<<" : "<<dist[node(nuts[i])][j]<<endl;  
       }
      */
       nuts.pop_back();
       tre = nuts.size();
       
       memset ( dp ,-1, sizeof dp);
       int ans = tsp ( 0 , 0);      
       printf("%d\n",ans);
   }
  //cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;

}
/*
input
20 20
#..................#
....................
...............#....
#...................
..........L.......#.
....................
.....#..............
..............#.....
..#.................
....................
.............#......
#...................
.........#..........
....................
................#...
....................
....#...............
....................
....................
#..................#
78
*/
/*
20 20
#..................#
....................
......L........#....
#...................
..................#.
....................
.....#..............
..............#.....
..#.................
....................
.............#......
#...................
.........#..........
....................
................#...
....................
....#...............
....................
....................
#..................#
80
*/

/*
20 20
#..................#
....................
...................#
#...................
..........L.......#.
....................
.....#..............
...................#
#...................
....................
...................#
#...................
#...................
....................
...................#
....................
#...................
....................
....................
#..................#
77
*/
