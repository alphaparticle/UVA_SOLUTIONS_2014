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

int m [1111111];
int ans [1111111];
void pre (){
	LL i, j;
    int q =  0	;
    for ( i = 1; i <= 1e6 ; i++)
    m[i] = 1 ;
    for ( i = 2 ; i <= 1e6 ; i++)
    for ( j = i ; j <= 1e6 ; j += i)
    m[j] += 1 ;//,q++;

	int mm , ind ; mm = ind = -1 ;
	for ( i = 1 ; i <= 1e6 ; i++ )
	if ( m[i] >= mm){
		mm = m[i] ; ind = i ;
		ans[i] = ind ;
	}
	else{
		ans[i] = ind ;
	}
	
}


int main(){
 double st = clock() ;
pre();
/*
for ( int i = 1 ; i <= 50 ; i++){
	cout << i <<" "<<m[i] << endl;
}
*/
int n, j ;
scanint(n);
while(n--){
  scanint(j);
  printf("%d\n",ans[j]);
}

//cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
return 0;
}
