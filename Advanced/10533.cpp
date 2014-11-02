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
bool p[1000001];
int dprime[1000001];

void seive(){
   LL i , j , k ;
   memset ( dprime , 0 ,sizeof dprime);
   memset ( p , true ,sizeof p) ;
   dprime[2] = 1 ;
   for ( i = 4 ; i <= 1e6 ; i += 2)
   p[i] = false;
   for ( i = 3 ;i <= 1e6 ; i+=2 )
   if( p[i]){
   	  for ( j = i*i ; j <= 1e6 ; j += i)
   	  p[j] = false ;
   	  k = i ;
   	  int s = 0 ;
   	  while( k > 0 ){ s += k%10 ; k /= 10 ;}
   	  if(p[s])
   	  dprime[i] = 1 ;
   }
   for ( i = 1 ; i <= 1e6 ; i++)
   dprime[i] += dprime[i-1] ;
}

int main(){
  int test , i, j , k,  l , m ,ans;
  seive(); //cout << dprime.size() << endl;
  scanint(test) ;
  vector < int > :: iterator it , fit ;
  while( test-- ){
  	 scanint(j) ; scanint(k) ;
     ans = max( 0 , dprime[k]-dprime[j-1]) ;
     printf("%d\n",ans);
  }
	return 0;
}
