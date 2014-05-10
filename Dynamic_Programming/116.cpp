#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610 
#define LIM 1000000
#define readi(n) scanf("%d", &n) ;
#define readc(c) scanf("%c", &c) ;
#define read2i(n,m) scanf("%d %d", &n , &m) ;
#define read3i(a,b,c) scanf("%d %d %d",&a ,&b ,&c);
#define pb push_back
#define rep(i,n) for(  i = 0 ; i < n ; i++)
#define reps(i,a,b) for( i = a ; i <= b ; i++) 


typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii> viii ;

/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/

/*
  //Seive
  bool p[LIM] ;
  vector <ll> prime ;
  void seive(){
	 memset (p , true ,sizeof p);
	 p[0] = p[1] = false ;
	 for ( ll i = 2 ; i <= LIM ; i++){
	   if(p[i])
	   {
	     prime.pb(i);
	     for ( ll j = i*i ; j <= LIM ; j += i)
	     p[j] = false ;
	   }
	 }
  }

*/

long long rows , cols ;
long long dp[11][110][2] ;

long long value[11][110] ;

vector < pair<long , long> > v ;


int main(){
   long long i , j ,  k ;  

    while( cin >> rows >> cols ){
         
         rep(i , rows)
         rep(j , cols)
         scanf("%lld",&value[i][j]) ;

         long long ans = (ll)pow(2,50);
         //cout << ans << endl;
         
         rep ( i , rows)
         rep(j , cols)
         dp[i][j][0] = value[i][j] ;


         for ( j = cols-2 ; j >= 0 ; j--){
            
            for ( i = 0 ; i < rows ; i++){
            	  if ( i == 0){
                        v.clear() ;
                        v.push_back( ii (dp[rows-1][j+1][0] , rows-1));
                        v.push_back( ii (dp[i][j+1][0] , i));
                        if ( i+1 < rows)
                        v.push_back( ii (dp[i+1][j+1][0] , i+1));
                        sort(v.begin() , v.end()) ;
                        dp[i][j][0] += v[0].first;
                        dp[i][j][1] = v[0].second ;
            	    continue ;
            	  }
            	  if ( i == rows-1){
                        v.clear() ;
                        if ( i-1 >= 0)
                        v.push_back( ii (dp[i-1][j+1][0] , i-1));

                        v.push_back( ii (dp[i][j+1][0] , i));
                        v.push_back( ii (dp[0][j+1][0] , 0));
                    
                        sort(v.begin() , v.end()) ;
                        dp[i][j][0] += v[0].first ;
                        dp[i][j][1] = v[0].second ;
            	     continue ;
            	  }
            	        v.clear();
            	        if ( i-1 >= 0)
                        v.push_back( ii (dp[i-1][j+1][0] , i-1));
                        v.push_back( ii (dp[i][j+1][0] , i));
                        if ( i+1 < rows)
                        v.push_back( ii (dp[i+1][j+1][0] , i+1));
                        sort(v.begin() , v.end()) ;
                        dp[i][j][0] += v[0].first ;
                        dp[i][j][1] = v[0].second ;
            	     

            }


         }
         
        rep ( i , rows)
        ans = min ( ans , dp[i][0][0]) ;

        for ( i = 0 ; i < rows ; i++)
        if ( dp[i][0][0] == ans){
        	  
        	  long long x = i ;
        	  printf("%lld",x+1);

             // x = dp[x][0][1] ;

        	  rep( j ,  cols-1){
              
              printf(" %lld",dp[x][j][1]+1);
              x = dp[x][j][1] ;


          }

             
             printf("\n%lld\n",ans) ;
             break ;
        }
      // cout << ans << endl << endl;
    
    }

  
	return 0 ; 
}