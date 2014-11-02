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
bool p[5000001];
int dcount [5000001] ;
void seive(){
	LL i , j ;
	memset ( p ,true , sizeof p);
	//memset ( dcount , 0, sizeof  dcount);
	p[0] =p[1]= false;
	dcount[2] = 1 ;
	for ( i  = 2*2 ; i <= 5*1e6 ; i+= 2)
	dcount[i] += 2 , p[i] = false;	
    for ( i = 3 ; i <= 5*1e6 ; i += 2)
    if( p[i]){
    	 dcount[i] = i ;
         for( j = 2*i ; j <= 5*1e6 ; j += i)
         p[j] = false ,dcount[j] += i ;
    }
  
   for ( i = 3 ; i <= 5*1e6 ; i++)
   {
   	    if( p[dcount[i]] )
   	    dcount[i] =dcount[i-1] + 1 ;
   	    else
   	    dcount[i] = dcount[i-1] ;
   }
}

int main(){
   seive() ;
   int a , b ;
    while( 1 ){
    	 scanint(a) ;if( a == 0) break ;
    	 scanint(b) ;
    	 printf("%d\n",dcount[b]-dcount[a-1]) ;
    }
	return 0 ;
}
