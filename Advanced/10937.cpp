#include <bits/stdc++.h>
using namespace std ;
#define gc getchar_unlocked
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
#define P first
#define Q second
typedef pair < int , int > ii ;
typedef pair < ii , ii > iiii ;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int dr[] = { -1 , 0 , 1 ,0};
int dc[] = { 0, 1, 0,-1} ;
bool vis[55][55] ;
char graph [55][55];
int dp[1<<11][11];
int r , c , sr ,sc , tre;
map < iiii , int > dist ;
bool check ( int rr , int cc){
	return ( rr >= 0 && rr < r && cc >=0 && cc < c) ;
}
vector < ii > treasure ;

int tsp ( int mask , int last){
  // cout <<"oo "<< mask <<" "<<last << endl; 
   
    if( dp[mask][last] != -1)
    return dp[mask][last];
    if( mask == (1<<tre)-1 )
    return dp[mask][last] =  dist[iiii(ii(sr,sc),treasure[last]) ] ;
    int ans=  1e9 ;
    if( mask == 0){
	    for ( int i = 0 ; i < tre ; i++)
	    if( !(mask&(1<<i)) )
	    ans = min ( ans , dist[iiii(ii(sr,sc),treasure[i])] + tsp( mask|(1<<i) , i )) ;	    
    }
    else{
		    for ( int i = 0 ; i < tre ; i++)
		    if( !(mask&(1<<i)) )
		    ans = min ( ans , dist[iiii(treasure[last],treasure[i])] + tsp( mask|(1<<i) , i )) ;
    }
   //cout << mask <<" "<<ans << endl;
   return dp[mask][last] = ans ;
}

int main(){
     int i , j , k, l;
     int test = 0 ;
     while(1){
     	 treasure.clear() ;
     	 dist.clear() ;
     	 scanint(r) ; scanint(c) ;
     	 if( r == 0 && c == 0 )
     	 break ;
     	 
     	 for ( i = 0 ; i < r ; i++)
     	 gets(graph[i]);
     	
     	 bool isposs = true ;
     	
     	 memset ( vis , false,sizeof vis);
     	 //memset ( dp, -1, sizeof dp);
     	 for ( i = 0 ; i < r ;i++)
     	 for( j = 0 ; j < c ; j++)
     	 {   

     	 	 if( graph[i][j] == '@')
     	 	 sr=i,sc=j;
	     	 
     	     if( graph[i][j] == '!')
     	     treasure.push_back(ii(i,j));
     	     if( graph[i][j] == '*' ){
		     	 	 for ( k = 0 ; k < 8 ; k++)
			     	 	 if ( check(i+dx[k],j+dy[k]) )
				     	 	 if( graph[i+dx[k]][j+dy[k]] == '.'  )
				     	 	  graph[i+dx[k]][j+dy[k]] = '#' ;
				     	 	else if( graph[i+dx[k]][j+dy[k]] == '@' || graph[i+dx[k]][j+dy[k]] == '!' ){ isposs = false ;}
     	     }
     	 }
        treasure.push_back(ii(sr,sc)); 
        tre = treasure.size();
        for ( i = 0 ; i < tre ; i++){
             ii u = treasure[i] ;
        	 queue < ii > q ;
        	 dist[iiii(u,u)] = 0;
        	 q.push(ii(u));
        	 while ( !q.empty()){
        	 	 ii v = q.front() ; q.pop() ;
        	 	 for ( j = 0 ;  j < 4 ; j++){
        	 	 	int tr = v.P+dr[j] ;int tc =v.Q+dc[j];
        	 	 	if( check(tr,tc) &&  ( graph[tr][tc] == '!' || graph[tr][tc] == '.' || graph[tr][tc] == '@' ) && dist.count(iiii(u,ii(tr,tc))) == 0){
        	 	 		dist[iiii(u,ii(tr,tc))] = dist[iiii(u,v)] + 1 ;
        	 	 		q.push(ii(tr,tc)) ;
        	 	 	}
        	 	 }
        	 }
        }

        for ( i = 0 ; i < tre ; i++){
          if( dist.count(iiii(ii(sr,sc),treasure[i])) == 0){ isposs = false; break ;} 
        }
        /*
        for( map < iiii , int > :: iterator it = dist.begin() ; it != dist.end() ; it++){
        	iiii u = (*it).P ;
        	int v = (*it).Q ;
        	cout << u.P.P <<" "<<u.P.Q <<" "<<u.Q.P <<" "<<u.Q.Q<<" "<<v<< endl;
        }*/
        treasure.pop_back() ;
        tre = treasure.size() ;
        if( !isposs){
        	puts("-1"); continue ;
        }
       for ( i = 0 ;  i <= (1<<tre) ; i++)
       for( j = 0 ; j <= tre ; j++)
       dp[i][j] = -1 ;
       int ans = tsp (0,0);
       printf("%d\n",ans);

  }
	return 0;
}

/*
12 9
~...!~~~~
!..#..!..
.~~.~~~~.
..!..#.!.
~.~~~.~~~
...#!...!
~.~.~~~.~
.!.......
~.~~.~.~~
....@....
~.~~~~~.~
!..#!....
12 9
~...!~~~~
!..#..!..
.~~.~~~~.
..!..#.!.
~.~~~.~~~
.*.#!...!
~.~.~~~.~
.!.......
~.~~.~.~~
....@....
~.~~~~~.~
!..#!....
12 9
~...!~~~~
!..#..!..
.~~.~~~~.
..!..#.!.
~.~~~.~~~
...#!...!
~.~.~~~.~
.!.......
~.~~.~.~~
....@..*.
~.~~~~~.~
!..#!....
12 9
~.*.!~~~~
!..#..!..
.~~.~~~~.
..!..*.!.
~.~~~.~~.
...#!...!
~.~.~~~.~
.!.......
~.~~.~.~~
....@....
~.~~~~~.~
!..#!....
0 0
//Output
88
-1
-1
82
*/
