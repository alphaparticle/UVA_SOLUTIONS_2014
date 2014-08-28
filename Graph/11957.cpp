#include <bits/stdc++.h>
using namespace std ;


static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;


typedef long long LL;
LL dp [111][111] ;
char arr [111][111] ;

int  n ;

bool valid ( int x , int y ){
	 if( x >= 0 && x  < n && y >= 0 && y < n )
	 return true ;
	else
	return false;
}

LL rec ( int row , int col ){
	if ( dp[row][col] != -1){
		 return dp[row][col] ;
	}

	if ( row == 0 ){
		 dp[row][col] = 1 ;
		 return dp[row][col] ;
	}

	dp[row][col] = 0 ;
    
    if ( valid(row-1,col-1) ){
    	if ( arr[row-1][col-1] == '.' )
    	dp[row][col] += rec ( row-1,col-1) ;
        else{
        	 if( valid(row-2,col-2))
        	 if( arr[row-2][col-2] == '.' )
        	 dp[row][col] += rec ( row-2 , col-2) ;
        }
    }

    if( valid(row-1,col+1) )
    {
    	  if( arr[row-1][col+1] == '.' )
    	  dp[row][col] += rec( row-1 ,col+1) ;
    	  else{
    	  	 if( valid( row-2,col+2) )
    	  	 if( arr[row-2][col+2] == '.' )
    	  	 dp[row][col] += rec ( row-2 ,col+2) ;
    	  }
    }
   dp[row][col] %= 1000007 ;
   return dp[row][col] ;

}



LL solve(){
	cin >> n ;

	int i , j , k ;
	for ( i = 0 ;  i < n ; i++)
	for( j = 0 ; j < n ; j++)
	dp[i][j] = -1 ;
	for ( i = 0 ; i < n ; i++)
    scanf("%s",arr[i]) ;
   
    int sx ,sy ; bool f = false ;
    for( i = 0 ; i < n && !f ; i++  )
    for ( j = 0 ; j < n && !f ; j++ )
    if ( arr[i][j] == 'W' )
    {
    	 sx = i ; sy = j ; f = true ;
    }

    LL ans = rec (sx ,sy) ;
    /*
    cout << endl;
    for ( i = 0 ; i < n ; i++){
    for ( j = 0 ; j < n ; j++)
    printf(" %lld(%c)",dp[i][j], arr[i][j]) ;
    printf("\n");
   }
*/
   return ans%1000007 ;
}


int main(){
  
  int test ;
  cin >> test ;
  for ( int i = 1 ; i <= test ; i++)
  cout <<"Case "<<i<<": "<<solve()<<"\n" ; 

  return 0 ; 
}
