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
typedef long long LL;
int ginti [1000001];

/*
bool p [1111111];
void seive(){
    memset ( p , true , sizeof p);
    memset ( ginti , 0 ,sizeof ginti);
    p[0] = p[1]= false;
    for ( LL i  = 2 ; i <= 1e6 ; i ++ )
    if( p[i] ){
    	 for( LL j = i*i ; j <= 1e6 ; j += i)
    	 p[j] = false;
    }
    ginti[99] = 0 ;
    for(int  i = 100 ; i <= 1e6 ; i++)
    if( p[i]){
           int dd,d =0 ; int k = i ;
           while( k >0 ){ d++ ; k /= 10 ;}
           dd = d ;
           bool iscircular = true ;
           k = i ;
           //cout<<"hello "<< dd<< endl;
           while(d--){
           	  //cout << k <<" o "<<endl;
           	  int j = k%10 ; k /= 10 ;
           	  k = pow(10,dd-1)*j + k ;          	  
           	  //cout << k <<" new"<<endl;
           	  if( !p[k]){ iscircular = false ; break ;}  
           }
           if( iscircular)
           ginti[i] = ginti[i-1]+1 ,cout << i <<"\n";//<<ginti[i]<<endl ;
           else
           ginti[i] = ginti[i-1] ;
    }
    else{
    	ginti[i] = ginti[i-1] ;
    }
}
*/

int main(){
   //seive();
// double st = clock() ;
ginti[113] = 1 ;
ginti[131] = 1 ;
ginti[197] = 1 ;
ginti[199] = 1 ;
ginti[311] = 1 ;
ginti[337] = 1 ;
ginti[373] = 1 ;
ginti[719] = 1 ;
ginti[733] = 1 ;
ginti[919] = 1 ;
ginti[971] = 1 ;
ginti[991] = 1 ;
ginti[1193] = 1 ;
ginti[1931] = 1 ;
ginti[3119] = 1 ;
ginti[3779] = 1 ;
ginti[7793] = 1 ;
ginti[7937] = 1 ;
ginti[9311] = 1 ;
ginti[9377] = 1 ;
ginti[11939] = 1 ;
ginti[19391] = 1 ;
ginti[19937] = 1 ;
ginti[37199] = 1 ;
ginti[39119] = 1 ;
ginti[71993] = 1 ;
ginti[91193] = 1 ;
ginti[93719] = 1 ;
ginti[93911] = 1 ;
ginti[99371] = 1 ;
ginti[193939] = 1 ;
ginti[199933] = 1 ;
ginti[319993] = 1 ;
ginti[331999] = 1 ;
ginti[391939] = 1 ;
ginti[393919] = 1 ;
ginti[919393] = 1 ;
ginti[933199] = 1 ;
ginti[939193] = 1 ;
ginti[939391] = 1 ;
ginti[993319] = 1 ;
ginti[999331] = 1 ;
   for( int i = 100 ; i <= 1e6 ; i++)
   ginti[i] = ginti[i-1]+ginti[i] ; 
  //printf("%.6lf\n", ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0));
   int a ; int b ;
   while(1){
   	 scanint(a); if( a == -1)break ;
   	 scanint(b);
     if( ginti[b] - ginti[a-1] > 1)
   	 printf("%d",ginti[b]-ginti[a-1]),puts(" Circular Primes.");
   	 else if( ginti[b]-ginti[a-1] == 1)
   	 puts("1 Circular Prime.");
   	else
   	puts("No Circular Primes.");
   }

	return 0;
}
