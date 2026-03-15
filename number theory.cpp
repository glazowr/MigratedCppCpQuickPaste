void binaryprint(int n) {
	for (int i = 10; i >= 0; --i)
		cout << ((n >> i) & 1);
	cout << endl;
}

int setcount(int n) {
	int ct = 0;
	for (int i = 32; i >= 0; --i)
		if (n & (1 << i)) ct++;
	return ct;
}

//checking if ith bit is set or not
(a & (1 << 0))? cout << "set\n" : cout << "unset\n";
//bit set 
binaryprint(a | (1 << 6));
//bit unset 
binaryprint( a & (~(1 << 2)));
//bit toggle
binaryprint(a ^ (1 << 8)); 

char c = 'h', c1 = 'H';
// char(c1 | (1 << 5)); uppercase to lowercase
cout << char(c1 | ' ');
//char(c & ~(1 << 5)); lowercase to uppercase
cout << char(c & '_')
	
//unset ith bit from right 
int c1  = (a & (~((1 << (i+1))-1)));
//unset ith bit from left
int c2 = (a & ((1 << (i+1))-1));

int gcd (int a, int b) {
	if (b == 0) return a; // extra one recursive call will be added where remainder is 0 and dividend is divisor of previous divison
	if (a % b == 0) return b; // if a is divisible by b then b is gcd
	return gcd(b, a % b);
}

gcd can be used to calculate the minimum fraction
lcm can be calculated using gcd

a / gcd(a, b) 
_____________ = min fraction
b / gcd(a, b)

//recursive binary exponentation. log(n)
int binexprec(int a, int b) { 
	if (b == 0) return 1;
	long long ans = binexprec(a, b/2);
	if (b & 1) return (a * ((ans * ans) % M)) % M; // add long long or add 1ll in ans * ans as ans * ans may be > 1e9
	else return (ans * ans) % M;
}

//iterative binary exponentation                            1          0         0         1         0
int binexpitr(int a, int b) { 3 ^ 18 --> 3 ^ (10010) --> (3 ^ 16) * (3 ^ 8) * (3 ^ 4) * (3 * 2) * (3 ^ 1)
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * 1ll * a) % M;
		a = (a * 1ll * a) % M;
		b >>= 1;
	}
	return ans;
}

const long long int M = 1e18+7;

// if the value of M becomes greater than integer range like ll int
//binary multiplication when we have to take mod of number greater than integer.
//multiplication function if we have to take mod of two big numbers where mod is big

int binmul(long long int a, long long int b) { 
	int ans = 0;
	while (b != 0) {
		if ( b & 1) ans = (ans + a) % M;
		a = (a + a) % M;
		b >>= 1;
	}
	return ans;
}
int binexpitr(long long int a, long long int b) {
	int ans = 1;
	while (b != 0) {
		if (b & 1) ans = binmul(ans, a);
		a = binmul(a,a);
		b >>= 1;
	}
	return ans;
}

//evaluating all primes of a numbers in O(sqrt(N))

int n;
cin >> n;
vector<int> prime_f;
for (int i = 2; i*i <= n; i++) {
	while (n % i == 0) {
		prime_f.push_back(i); n /= i;
	}
}
if (n > 1) prime_f.push_back(n);
for (auto it : prime_f) {
	cout<< it <<" ";
}


const int N = 1e7 + 10;
vector<bool> is_prime(N, 1);
vector<int> hp(N, 0), lp(N, 0);
vector<int> divisors[N];

//sieve algorithm
void sieve(int n) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] == true) {
			lp[i] = hp[i] = i;
			for (int j = 2 * i; j <= n; j += i){
				is_prime[j] = false; hp[j] = i;
				if (lp[j] == 0) lp[j] = i;
			}
		}
	}
}
//calculation of prime factors showing through vectors and map formats using sieve algorithm.

vector<int> prime_f;
unordered_map<int,int> prime_factors;
sieve(x);
while (n > 1) {
	int prime = lp[n];
	while (n % prime == 0) {
		prime_f.push_back(prime);
		prime_factors[prime]++;  n/= prime;
	}
}

const int N = 1e5+7;

//precomputation of all the divisors and sum of divisors;

vector<int> divisors[N];
int sum[N];

void find_dv(int n) {
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			divisors[j].push_back(i); 
			sum[j] += i;
		}
	}
}

//precomputation of all the factorials 

const int M = 1e9 + 7;

int fact[n];

for (int i = 1; i <= N ; ++i)
	fact[i] = (fact[i-1]*1ll*i) % M;
