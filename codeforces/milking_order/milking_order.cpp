#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	int n, m, k; fin >> n >> m >> k;
	
	vector<int> heir(m, 0);
	vector<int> spec(k, 0);
	for(int i = 0; i < m; i++) {
		fin >> heir[i];
	}
	for(int i = 0; i < k; i++) {
		fin >> spec[i];
	}

}
