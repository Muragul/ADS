# include <bits/stdc++.h>
 
using namespace std;
 
const int N = (int)1e5 + 7;
 
int sz;
long long a[N];
 
int heapify_up(int v) {
	while (v > 1 && a[v] < a[v / 2]) {
		swap(a[v], a[v/2]);
		v /= 2;
	}
	return v;
}
 
void heapify_down(int v) {
	while (v <= sz) {
		int l = 2 * v; // left son
		int r = 2 * v + 1; // right son
		int s = v; // min among a[v],a[l],a[r]
 
		/* let's find min */
		if (l <= sz && a[l] < a[s])
			s = l;
		if (r <= sz && a[r] < a[s])
			s = r;
		// if v is min, then everything is ok
		if (s == v)
			return;
		// go down to vertex s
		swap(a[v], a[s]);
		v = s;
	}
}
 
void add(long long x) {
	// add to the end
	sz++;
	a[sz] = x;
	// propogate (heapify) upwards
	heapify_up(sz);
}
 
long long top() {
	// min element is on top
	return a[1];
}
 
void remove_top() { // a.k.a. pop()
	// swap min with last element
	swap(a[1], a[sz]);
	// delete last element (delete min)
	sz--;
	// propogate top element downwards
	heapify_down(1);
}
 
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
    	add(x);
	}
	double ans = 0;
	for(int i = 1; i < n; ++i){
    	long long mn1 = top();
    	remove_top();
    	long long mn2 = top();
    	remove_top();
    	ans += (mn1 + mn2) * 0.05;
    	add(mn1 + mn2);
	}
	cout << fixed << setprecision(11) << ans;
	return 0;
}