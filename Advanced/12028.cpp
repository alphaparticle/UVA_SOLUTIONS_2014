#include <bits/stdc++.h>
using namespace std ;
#define gc getchar_unlocked
inline void scanint(int &x)
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
typedef long long LL;
int n , c , K , test  ;
LL a [1000010] ,l;
LL sum [1000010] ;
int fre[1000010];

int main(){
   int i , j , k,  kase = 1;
    scanint(test);
    while( test-- ){
    	  scanint(K) ; scanint(c) ; scanint(n) ; scanf("%lld",&a[0]);
         // memset ( fre , 0 ,sizeof fre);
          l = a[0] ;
          //fre [ a[0] ]++ ; 
    	  for( i  = 1 ; i < n ; i++){
    	    a[i] = (K*a[i-1] + c)%1000007;    	    
    	    l = max(l, a[i]);
    	    //fre[a[i]]++;
    	  }
    	  
    	  for( i = 0 ; i <= l ; i++)
    	  fre[i] = 0 ;
    	  for ( i = 0 ; i < n ; i++)
    	  fre[a[i]]++;
      j = 0;
      for( i = 0 ; i <= l ; i++)
      if( fre[i] > 0){
           while( fre[i] > 0)
           {
           	  a[j] = i ;j++; fre[i]--;
           }
      }
      sum[0] = a[0] ;
      for( i = 1 ; i < n ; i++){
      	 sum[i] = sum[i-1] + a[i] ;
      }  
      LL ans =  abs ( sum[n-1]-a[0]  - (n-1)*a[0] );
      for( i = 1 ; i < n-1 ; i++){
        ans +=  abs( (sum[n-1]-sum[i]) - (n-1-i)*a[i]) ;// - min( sum[n-1]-sum[i] , (n-1-i)*a[i]) ; 
      }
      printf("Case %d: %lld\n", kase++ , ans);
   }
	return 0;
}
