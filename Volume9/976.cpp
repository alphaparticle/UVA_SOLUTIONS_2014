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


char graph[1010][1010];
int r , c ;
int northlow [1010];
int southhigh[1010];
int diff [1010] ;
int bridges , gap ;

int dp[1010][110];

int dr[] = {1,0,-1,0};
int dc[] = { 0 ,-1 ,0,1};
bool vis [1001][1001]; 
bool check( int cr , int  cc){ return ( cr >= 0 && cr < r && cc >= 0 && cc < c) ;}
void floodfill1( int cr , int cc ){
     //cout <<"u "<<cr <<" "<<cc <<endl;
     vis[cr][cc] = true ;
     northlow[cc] = max( northlow[cc] , cr);
     for ( int  i = 0; i < 4 ; i++){
     	 int tr = cr+dr[i] ; int tc = cc+dc[i];
     	 if( check(tr,tc) && !vis[tr][tc] && graph[tr][tc] == '#' )
     	 floodfill1(tr,tc);
     }
}
void floodfill2( int cr , int cc ){
     vis[cr][cc] = true ;
     southhigh[cc] = min( southhigh[cc] , cr);
     for ( int  i = 0; i < 4 ; i++){
     	 int tr = cr+dr[i] ; int tc = cc+dc[i];
     	 if( check(tr,tc) && !vis[tr][tc] && graph[tr][tc] == '#' )
     	 floodfill2(tr,tc);
     }
}


int topdown ( int index , int b){
	if( index >= c){
		if( b == bridges)return 0; 
		else return 1e9 ;
	}
	if( b > bridges)return 1e9;
	if ( b == bridges)return 0;
	if( dp[index][b] != -1)
	return dp[index][b] ;
    int ans = 1e9 ;
    ans = min ( ans , diff[index] + topdown(index+gap,b+1));
    ans = min( ans , topdown(index+1,b));

  return dp[index][b] = ans ;
}


int main(){
  int i , j, k, l;
  while (scanf("%d %d",&r,&c) != EOF){
  	  scanint(bridges);scanint(gap); gap += 1 ;
  	  for ( i = 0 ; i < r ; i++)
  	  gets(graph[i]);
      for ( i = 0 ; i < c; i++)
      northlow[i] = 0,southhigh[i] = r-1 ;
     
      for( i = 0 ; i < r ; i++)for( j = 0 ; j < c; j++)vis[i][j] = false;
      floodfill1(0,0);
      floodfill2(r-1,0);
      
      for ( i = 0 ; i < c; i++)
      diff[i] = (southhigh[i]-northlow[i]-1);// cout << i <<" "<<diff[i]<<endl;     
    memset ( dp , -1,sizeof dp);
    //for( i = 0 ; i < c; i++)for( j = 0 ; j <= bridges ; j++)dp[i][j] = -1;
    int ans = topdown(0,0);  
    printf("%d\n",ans);
 }  
	return 0;
}
