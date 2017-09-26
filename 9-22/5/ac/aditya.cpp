#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>

typedef long long ll;

using namespace std;

const int SIZE = 1000005;

bitset<SIZE> sieve;
vector<int> primes;

void gen_primes() {
    sieve.flip();
    sieve[0] = false;
    sieve[1] = false;
    for(int low = 2; low < SIZE + 1; low++) {
        if(!sieve[low]) {
            continue;
        }
        for(int i = low * 2; i < SIZE + 1; i += low) {
            sieve[i] = false;
        }
    }
    for(int low = 2; low < SIZE + 1; low++) {
        if(sieve[low]) {
            primes.push_back(low);
        }
    }
}

unordered_map<ll, int> factorization;

void factor(ll num) {
    for(int prime : primes) {
        if(num == 1 || prime * prime > num) {
            break;
        }
        while(num % prime == 0) {
            factorization[prime] += 1;
            num /= prime;
        }
    }
    if(num > 1) {
        factorization[num] += 1;
    }
}

int count() {
    int prod = 1;
    for(auto it = factorization.begin(); it != factorization.end(); it++) {
        prod *= (it->second + 1);
    }
    return prod / 2 + prod % 2;
}

int main() {
    gen_primes();
    ll num;
    scanf("%lld", &num);
    factor(num);
    cout << count() << endl;
    return 0;
}


