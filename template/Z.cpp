using i64 = long long;

template<class T>
constexpr T power(T a,i64 b){
	T res;
	for(; b; b >>= 1,a *= a){
		if(b & 1){
			res *= a;
		}
	}
	return res;
}//快速幂

