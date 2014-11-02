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
bool p[10001];
vector < int > prime ;
int  pcount[10001];

void seive(){
   int i , j , k ,x;
   memset ( pcount , 0, sizeof pcount);
   memset ( p , true ,sizeof p) ;
   p[0]=p[1]= false ;
   for ( i = 2 ;i <= 1e4 ; i++ )
   if( p[i]){
      prime.push_back(i);
   	  for ( j = i*i ; j <= 1e4 ; j += i)
   	  p[j] = false ;
   }
   //cout << prime.size() << endl;
   for( i = 0 ; i <= 10000 ; i++){
      x = i*i + i + 41 ;
      if( x <= 10000 ){
       if( p[x] )
       pcount[i] = pcount[i-1] + 1 ;
       else
        pcount[i] = pcount[i-1] ;
    //   cout << i <<" "<<pcount[i] << endl;
       continue ;
     }
     bool isprime = true ;
     for( j = 0 ;  j < prime.size() && prime[j]*prime[j] <= x ; j++ )
     if( x%prime[j] == 0){ isprime = false ; break ;}
     if( isprime )
     pcount[i] = pcount[i-1]+1;
     else
     pcount[i] = pcount[i-1] ;   
  
  //cout << i <<" "<<x <<" "<<pcount[i] << endl;
 }
}

double rr(double x, int prec)
{
    double power = 1.0;
    int i;

    if (prec > 0)
    for (i = 0; i < prec; i++)
    power *= 10.0;
    else if (prec < 0)
    for (i = 0; i < prec; i++)
    power /= 10.0;

    if (x > 0)
    x = floor(x * power + 0.5) / power;
    else if (x < 0)
    x = ceil(x * power - 0.5) / power;

    if (x == -0)
    x = 0;

    return x;
}

int main(){
  seive();
  int a , b ,x,y;
  while ( scanf("%d %d",&a ,&b) != EOF ){
      y = pcount[b];
      x = 0 ;
      if( a-1 >= 0)
      x = pcount[a-1] ;
    
    //cout<< y-x <<" "<<b-a+1<<endl; 
    double ans = (((y-x)*1.00)/((b-a+1)*1.00))*100.000 ;
    ans = rr ( ans ,2);
    printf("%.2lf\n",ans);
  }


  return 0;
}
