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
typedef long long LL;
#define P first
#define Q second
#define pb push_back
#define mp make_pair
typedef pair < int , int > ii ;
typedef vector <int> vi ;

int test , N , M , P;
float cost[55] ;
map < int , int > id ;
float d [55][55];
float dp [1<<13][13];
float var [1<<13] ;
void floydwarshall(){
	for ( int k = 0 ; k <= N ; k++)for ( int i = 0 ; i <= N ; i++) for( int j = 0 ; j <= N ; j++)
    d[i][j] = min ( d[i][j] , d[i][k] + d[k][j]);
}

float tsp ( int mask , int last){
   if( last == -1){
   	  float b = var[mask] ;

   	  for ( int i = 0; i < P ; i++)
   	  if( !(mask&(1<<i)) ){
   	  	 b = min (  b , d[0][id[i]] + tsp( mask|(1<<i),i) );
   	  }
   	//  cout << mask <<" "<<last <<" tootherstore "<<b <<" amaz "<<var[mask] <<endl;
   	  return b;
   }
   if ( dp[mask][last] != -1.0)
   return dp[mask][last];
   if( mask == (1<<(P))-1 ){
   	 //cout << mask <<" "<<last <<" : "<<d[id[last]][0]<<endl;
   	 return dp[mask][last] = d[id[last]][0] ;
   }
   float  b =  var[mask] + d[id[last]][0] ;
   for ( int i = 0 ; i < P ; i++ ) 
   if( !(mask&(1<<i)) ){
   	  b = min ( b ,d[id[last]][id[i]] + tsp( mask|(1<<i) , i) );
   }
  // cout << mask <<" "<<last <<" tootherstore "<<b <<" amaz "<<var[mask] + d[id[last]][0]<<endl;
   return dp[mask][last] = b;
}

int main(){
// double st = clock() ;
int i , j, k, l ; float w;
scanint(test);
while ( test--){
	 id.clear() ;
	 scanint(N) ; scanint(M);
	 for ( i = 0 ; i <= N ;i++)for( j = 0 ;j <= N ; j++) d[i][j] =1e9 ;
	 for ( i = 0 ; i < M ; i++){
        scanint(j) ; scanint(k);
        scanf("%f",&w);
        d[j][k] = d[k][j] = min( d[j][k] , w);
        d[j][j] = d[k][k] =0.0;
	 }
	floydwarshall();
	/*cout << endl;
	for ( i = 0 ; i <= N; i++){
		 for ( j = 0 ; j <= N ; j++)
		 printf(" %.2f",d[i][j]);
		cout << endl;
	}*/
    scanint(P) ;
    for ( i = 0 ; i <= N; i++)cost[i] = 0.0;
    float aa =0.0 ;
    for ( i = 0 ; i < P ; i++){
    	 scanint(j) ; id[i] = j ; 
    	 scanf("%f",&w); cost[j] = w ;
    	 aa += w ;  
    }
    for ( i = 0; i < (1<<P) ; i++)
    {
    	  float temp =0.0 ;
    	  for( j = 0 ; j < P ; j++)
    	  { dp[i][j] = -1.0;
    	   if( !(i&(1<<j)) )
    	   temp += cost [ id[j]] ;
          }
    	var[i] = temp; //cout << i <<" "<<var[i] << endl;
    }
    
    float ans = tsp (0,-1);	
    //cout << ans << endl;
    if( ans < aa){
          printf("Daniel can save $%.2f\n",aa-ans);
    }
    else{
    	puts("Don't leave the house");
    }
}

//cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
return 0;
}
