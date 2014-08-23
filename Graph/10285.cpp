#include <bits/stdc++.h>
using namespace std; 

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



int R , C ;
string s ;
int test ;

int matrix [111][111] ;

int dp [111][111] ;

int dx[] = { 1 , -1, 0 , 0} ;
int dy[] = { 0 , 0, -1, 1 } ;

bool valid ( int x , int y ){
	 if( x >= 0 && x < R && y >= 0 && y <C )
	 return true ;
	else
		return false;
}

int rec ( int row , int col ){

	  if( dp[row][col] != -1)
	  return dp[row][col] ;
     
      dp[row][col] = 1 ;

      for ( int i = 0 ; i < 4 ; i++ )
      {
      	  int tr = row + dx[i] ; 
      	  int tc = col + dy[i] ;
      	  if( valid ( tr,tc) )
      	  if( matrix[tr][tc] > matrix[row][col] )
      	  dp[row][col] = max( dp[row][col] , 1 + rec ( tr,tc)) ;
      }
    return dp[row][col] ;
}

void out(){

	 for( int i = 0  ; i < R ; i++){
	 for( int j = 0 ; j < C ; j++)
	 cout <<" "<< dp[i][j] ;
	 cout << endl;
	 } 
}

int solve (){
	cin >> s >>R >> C ;

	for (int i = 0 ;  i  < R ; i++)
	for ( int j = 0;  j < C ; j++)
	cin >> matrix [i][j] , dp[i][j] = -1;
    cout << s <<": " ;
    int ans = 0;
    for (int i = 0 ; i < R ; i++)
    for (int j = 0 ; j < C ; j++)
    if( dp[i][j] == -1)
    ans = max( ans,  rec(i,j) ) ;
  
    //out() ;
 
    return ans ;

}

int main(){
 // cin.sync_with_stdio(0) ;
 // cin.tie(0) ;
   cin >> test ;
   while ( test-- ){
   	 cout << solve() <<"\n" ;
   }

	return 0;
}
