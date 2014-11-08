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

// double st = clock() ;
//cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;

//GCD
 LL gcd(LL a, LL b) { return (b == 0 ? a : gcd(b, a % b)); }


 LL lcm(LL a, LL b) { return (a * (b / gcd(a, b))); }



int main(){
    
 LL i , j , k, l, n ,m;
 while( scanf("%lld %lld",&n ,&m)!= EOF){
     vector  < LL > p ;
     for ( i = 0 ; i < m ; i++){
         scanf("%lld",&j) ; p.push_back(j);
     }
     LL ans = 0;
     for( i = 1 ;i < (1<<m) ; i++){
         LL b = 0;
         vector < LL > temp;
         for( j = 0 ; j < m ; j++)
         if ( i&(1<<j) ){ temp.push_back(p[j]);}

         LL g = temp[0] ;
         for ( j = 1; j < temp.size() ; j++)
         g =  lcm(g,temp[j]);
         if( temp.size()%2 == 1){
            ans += n/g ;
         }
         else{
            ans -= n/g ;
         }
        //cout << i <<" "<<temp.size() <<" "<<g << endl;
     }
     //cout << ans << endl;
     printf("%lld\n",n-ans);
 } 
    return 0;
}
