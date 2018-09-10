//杀手问题
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	//vector<int> a = { 1,2,3,4,5,6};
	vector<int> a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	int suv = n;
	int res = 0;
	while (suv != 0) {
		int temp = suv;
		int *fir = 0, *las = 0;
		for (int i = n - 1; i >=0; --i) {
			
			if (a[i] == 0)
				continue;
			else {
				if (las == 0)
					las = &a[i];
				else {
					fir = &a[i];
					if (*fir > *las) {
						*las = 0;
						suv--;
						
					}
					las = fir;
					fir = nullptr;
				}
			}
			
		}
		++res;
		if (temp == suv) {
			break;
		}

	}
	
	cout << res - 1;
	return 0;
}
