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
#define P first
#define Q second
typedef pair < int , int > ii;
int dist [65][65];
int n , test , tt , sr , sc;
int dr[] = {-2,-2,-1,-1,1,1,2,2 };
int dc[] = {-1,1,-2,2,-2,2,-1,1 };
map < ii , int > id ;
vector < ii > target ;
char chess[10][10];
int dp [1<<9][9];
bool check( int cr, int cc){
	return (cr>= 0 && cr <8 && cc >= 0&& cc < 8);
}

int tsp ( int mask , int last){
	if ( mask == (1<<tt)-1 )
	return 0;

    if( last == -1 ){
        int ans =1e9 ;
        for ( int i = 0 ; i < tt ; i++){
        int p = id[ii(sr,sc)]; int q = id[target[i]] ;
        ans = min (ans , dist[p][q] + tsp( mask|(1<<i) , i) ); }
        return ans ;
    }
    if( dp[mask][last] != -1)
    return dp[mask][last];
    int ans = 1e9 ;
    for (int i = 0 ; i < tt ; i++)
	    if( !(mask&(1<<i))){
	       int p = id[target[last]] ;
	       int q = id[target[i]] ;
	       ans = min ( ans , dist[p][q] + tsp (mask|(1<<i) , i)) ; 
	    }
	return dp[mask][last] = ans ;
}

int main(){
   int i , j, k, l , u ,v,tr ,tc;
   for ( i = 0 ; i < 8 ; i++)
   for ( j = 0 ; j < 8 ; j++)
   id[ ii(i,j)] = i*8+j ;
  
   scanint(test);
   while( test--){
   	 scanint(n);
   	 target.clear() ;
     for( i = 0  ; i < 8 ; i++)
     gets(chess[i]);
     
     for ( i = 0 ; i < 64 ; i++)for( j = 0 ; j < 64 ; j++)dist[i][j] = 1e9 ;
     for ( i = 0 ; i < 8 ; i++)for( j = 0 ; j < 8 ; j++)
     if( chess[i][j] == 'k' || chess[i][j] == 'P' ){
          if( chess[i][j] == 'P')
          target.push_back( ii(i,j));
          if( chess[i][j] == 'k') sr = i , sc= j ;
          u = id[ii(i,j)];
          dist[u][u] = 0;
          queue < ii > q ; q.push(ii(i,j));
          while(!q.empty()){
          	 ii x = q.front() ; q.pop() ;
          	 v = id[ii(x.P,x.Q)] ;
          	 for ( k = 0 ; k < 8 ; k++){
          	 	 tr = x.P + dr[k] ; tc = x.Q + dc[k];
          	 	 int z = id[ii(tr,tc)] ;
          	 	 if( check(tr,tc) && dist[u][z] == 1e9 && ( chess[tr][tc] == '.' || chess[tr][tc] == 'P' || chess[tr][tc] == 'k') ){
          	 	 	 dist[u][z] = dist[u][v] + 1;
          	 	 	 q.push(ii(tr,tc));
          	 	 }
          	 }
          }
     }
  /*
   for ( i = 0 ; i < 64 ; i++)
   {
   	  for( j = 0 ; j < 64 ; j++)
   	  if( dist[i][j] < 1e9 )
   	  cout <<" 1";
   	  else
   	  cout <<" 0";
   	 cout << endl;
   }*/
   // memset ( dp , -1, sizeof dp);
    
    tt = target.size() ;
    for( i = 0 ; i <= (1<<tt) ; i++)
    for( j = 0 ; j <= tt ; j++ )
    dp[i][j] = -1 ;
    int ans = tsp (0,-1);
    //cout <<target.size() <<" "<< ans << " ";
    if( ans <= n){
    	puts("Yes");
    }
    else{
    	puts("No");
    }  

 }
	return 0;
}
