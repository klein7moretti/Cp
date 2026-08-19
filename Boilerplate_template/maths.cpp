//lcm of a and b
ll lcm(ll a,ll b){
    return a/(__gcd(a,b))*b;
}
//fast a^b binary exponentiation
ll binpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
//modular exponentiation
ll binpow(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

//modular arithmetic
const ll mod=1e9+7;

ll add(ll a,ll b){
    return (a+b)%mod;
}

ll sub(ll a,ll b){
    return (a-b+mod)%mod;
}

ll mul(ll a,ll b){
    return a*b%mod;
}

//modular inverse for prime M
ll inv(ll a){
    return binpow(a,mod-2,mod);
}
// then 
a/b mod p = a*inv(b)%p

//modular inverse for every no.
inv[1]=1;

for(int i=2;i<mod;i++)
    inv[i]=mod-(mod/i)*inv[mod%i]%mod;

//factorial and ncr
const ll mod=1e9+7;
const int N=2e5+5;

ll fact[N],invfact[N];

ll binpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void init(){
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%mod;

    invfact[N-1]=binpow(fact[N-1],mod-2);

    for(int i=N-1;i>=1;i--)
        invfact[i-1]=invfact[i]*i%mod;
}

ll C(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}

//permutation 
ll P(int n,int r){
    if(r<0||r>n) return 0;

    return fact[n]*invfact[n-r]%mod;
}


//sieve of eratosthenes
vector<bool> prime(N,true);

void sieve(){
    prime[0]=prime[1]=false;

    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i)
                prime[j]=false;
        }
    }
}

//smallest prime factor spf  
int spf[N];

void sieve(){
    for(int i=0;i<N;i++)
        spf[i]=i;

    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
// factorization
while(n>1){
    cout<<spf[n]<<" ";
    n/=spf[n];
}

//prime factorization in O(sqrt(n))
void factorize(ll n){
    for(ll p=2;p*p<=n;p++){
        if(n%p==0){
            int cnt=0;
            while(n%p==0){
                n/=p;
                cnt++;
            }
            cout<<p<<" "<<cnt<<"\n";
        }
    }

    if(n>1)
        cout<<n<<" "<<1<<"\n";
}

//divisors of a number
vector<ll> divs;

for(ll i=1;i*i<=n;i++){
    if(n%i==0){
        divs.push_back(i);

        if(i!=n/i)
            divs.push_back(n/i);
    }
}

// when we only need no. of divisors
ll cnt=0;

for(ll i=1;i*i<=n;i++){
    if(n%i==0){
        cnt+=2;
        if(i==n/i) cnt--;
    }
}

//sum of divisors
ll sumDiv(ll n){
    ll ans=1;

    for(auto [p,e]:factorize(n)){
        ll cur=1;
        ll pw=1;

        for(int i=0;i<e;i++){
            pw*=p;
            cur+=pw;
        }

        ans*=cur;
    }

    return ans;
}


// euler totient (no. of integers 1<=x<=n coprime with n
ll phi(ll n){
    ll res=n;

    for(ll p=2;p*p<=n;p++){
        if(n%p==0){
            while(n%p==0)
                n/=p;

            res-=res/p;
        }
    }

    if(n>1)
        res-=res/n;

    return res;
}

// extended euclid algorithm
ll egcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    ll x1,y1;
    ll g=egcd(b,a%b,x1,y1);

    x=y1;
    y=x1-y1*(a/b);

    return g;
}

//check prime 
bool isPrime(ll n){
    if(n<2) return false;

    for(ll i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }

    return true;
}
// bit tricks
int cnt=__builtin_popcountll(n);
__builtin_parityll(n)
__builtin_clzll(n)
__builtin_ctzll(n)

// floor or ceiling divison
ll floor_div(ll a,ll b){
    return a/b;
}

ll ceil_div(ll a,ll b){
    return (a+b-1)/b;
}

//floor sum (ai+b)/m i from 1 to n-1
ll floor_sum(ll n,ll m,ll a,ll b){
    ll ans=0;

    while(true){
        if(a>=m){
            ans+=(n-1)*n*(a/m)/2;
            a%=m;
        }

        if(b>=m){
            ans+=n*(b/m);
            b%=m;
        }

        ll y=a*n+b;

        if(y<m)
            break;

        n=y/m;
        b=y%m;
        swap(m,a);
    }

    return ans;
}

//xor 1 to n
ll xor1n(ll n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}
//xorltor
ll xorRange(ll l,ll r){
    return xor1n(r)^xor1n(l-1);
}

//fibonacci 
pair<ll,ll> fib(ll n){
    if(n==0)
        return {0,1};

    auto [a,b]=fib(n/2);

    ll c=a*(2*b-a);
    ll d=a*a+b*b;

    if(n&1)
        return {d,c+d};

    return {c,d};
}

//legendre formula (exponent of prime p in n afctorial )
ll vp(ll n,ll p){
    ll ans=0;

    while(n){
        n/=p;
        ans+=n;
    }

    return ans;
}
// digit sum
ll digitSum(ll n){
    ll ans=0;

    while(n){
        ans+=n%10;
        n/=10;
    }

    return ans;
}
// palindrome number
bool palindrome(ll n){
    ll x=n,rev=0;

    while(x){
        rev=rev*10+x%10;
        x/=10;
    }

    return rev==n;
}

// derangement 
ll derangement(int n){
    if(n==0) return 1;
    if(n==1) return 0;

    ll a=1,b=0;

    for(int i=2;i<=n;i++){
        ll c=(i-1)*(a+b)%mod;
        a=b;
        b=c;
    }

    return b;
}

vector<ll> derangement(ll n){
    vector<ll> dp(n+1);
    dp[0]=1;
    if(n>=1) dp[1]=0;

    for(int i=2;i<=n;i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);

    return dp;
}

