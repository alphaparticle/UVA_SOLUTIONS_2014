/*
Date : 16 june 14
Time : 5:30 pm IST
author - @alphaparticle
Problem id : 11951
Problem name : AREA
Problem Link : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=3102&category=24
*/

#include <bits/stdc++.h>
using namespace std ;

#define INF 18446744073709551610
#define LIM 1000000
#define gi(n)                      scanf("%d", &n)
#define gc(c)                      scanf("%c", &c)
#define g2i(n,m)                   scanf("%d %d", &n , &m)
#define g3i(a,b,c)                 scanf("%d %d %d",&a ,&b ,&c)
#define gl(n)                      scanf("%ld",&n)
#define g2l(a,b)                   scanf("%ld %ld",&a ,&b)
#define g3l(a,b,c)                 scanf("%ld %ld %ld",&a,&b,&c)
#define pb                         push_back
#define rep(i,n)                   for( i = 0 ; i < n ; i++)
#define repu(i,a,b)                for( i = a ; i <= b ; i++)
#define repd(i,b,a)                for( i = b ; i >= a ; i--)
#define P                          first
#define Q                          second
#define pi(n)                      printf("%d\n",n)
#define ps(s)                      printf("%s\n",s.c_str())
#define p2i(a,b)                   printf("%d %d\n",a,b)
#define FILL (x,a)                 memset ( x , a ,sizeof x)

typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
typedef vector <int> vi ;
/*
GCD
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
*/

ll arr [110] [110 ] ;


int main(){
//freopen ( "i.txt" , "r" , stdin) ;
//freopen( "o.txt" , "w" , stdout) ;
ll money ;
int i , j , k,  l , n , m , t, test ;
gi(test) ;
repu ( t , 1 , test){
    g2i(n,m) ;
    cin >> money ;
   rep ( i , n+1)
    memset ( arr[i] , 0 , sizeof arr[i]);

    repu ( i , 1 , n)
    repu ( j , 1 , m)
    scanf("%lld", &arr[i][j] );

    repu( i , 1 , n )
    repu( j , 1 , m )
    arr[i][j] = arr[i][j-1] + arr[i][j] ;
//cout <<"\n" ;
    repu ( i , 1 , n){
    repu ( j , 1 , m ){
    arr[i][j]  = arr[i-1][j] + arr[i][j] ;
   // cout << arr [ i] [j] <<" "; }
   // cout << endl;
   }
}
   //  cout<<"\n" ;

    ll marea , mspent ;
    marea = 0 ;
    mspent = money;

    int rh ,rl ,ch,cl ;
    repu ( rh , 1 , n)
    repu( rl , 1, rh )
    repu ( ch  , 1 , m )
    repu ( cl , 1 , ch )
    {   ll tarea = (rh-rl+1) * (ch-cl+1)  ;
        ll tmoney = arr [rh][ch] + arr [rl-1][cl-1] - arr [rl-1][ch] - arr[rh][cl-1] ; //<< endl;
        //cout << tarea <<" "<< tmoney << endl;
        if( tarea >= marea && tmoney <= money){
           //  cout << rl <<" "<<cl <<" "<<rh <<" "<<ch <<" "<< tarea << " "<<tmoney << endl;
             //cout << arr [rh][ch] << " + "<< arr [rl-1][cl-1] <<" - "<< arr [rl-1][ch]  <<" - " << arr[rh][cl-1] << endl ;

             if( tarea == marea)
             mspent = min ( mspent , tmoney);
             else if( tarea > marea)
             mspent = min ( tmoney , money);
             marea = tarea ;
        }
    }
   printf("Case #%d: %lld %lld\n",t , marea ,mspent) ;
 }


	return 0;
}
