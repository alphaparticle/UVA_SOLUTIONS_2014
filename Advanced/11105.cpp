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

bool ishnumber [1000001] ;
vector < int > arr;
bool ishprime  [1000001];
vector < int> hprime;
int ginti     [1000001] ;
void f(){
	//memset ( ginti , 0 ,sizeof ginti);
	memset ( ishnumber , false,sizeof ishnumber);
	memset ( ishprime , false ,sizeof ishprime);
	for ( int i = 1 ; i <= 1e6 ; i += 4)
	{
		 ishnumber[i] = true ;
		 ishprime[i] = true ;
		 arr.push_back( i );
	}
   //cout <<"no. of hnumber "<< arr.size() << endl;
	for ( int i = 1 ; i < arr.size() ; i++){
		 int x = arr[i] ;
		 if( ishprime[x] ){
		 	 hprime.push_back(x);
		 	 for(int j = 2 ; j*x <= 1e6 ; j ++)
		 	 if( ishnumber[j*x] )
		 	 ishprime[j*x] = false ;
		 }
   }
   ishprime[1] = false;
   //cout << "no. of hprimes "<<hprime.size() << endl;
   for (int i = 4 ; i <= 1e6 ; i++)
   if(  !ishprime[i] && ishnumber[i] ){
   	   int x  = i ;
       bool issemiprime = false ;
       for( int j = 0 ; j < hprime.size() && hprime[j]*hprime[j] <= x ; j++ )
       if ( x%hprime[j] == 0 && ishprime[x/hprime[j]] ){
       	 issemiprime = true ; break ;
       }
       if( issemiprime)
       ginti[i] = ginti[i-1]+1;
      else
      	ginti[i] = ginti[i-1] ;
   }
   else{
   	 ginti[i] = ginti[i-1] ;
   }
  //cout <<"ok\n";
}

int main(){
  // double st = clock() ;
   f() ; int x ,y ;
   
   while(1){
   	  scanint(x); if( x == 0)break ;
   	  printf("%d %d\n",x ,ginti[x]);
   }
   //cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
 return  0;
}
