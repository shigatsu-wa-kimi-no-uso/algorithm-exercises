#include<iostream>
#include<string>
using namespace std;


int nextj[(int)1E6 + 10];
int nextval[(int)1E6 + 10];

void init_next(const string& t) {
	int len = t.length();
	int k;
	for (int j = 2; j <= len; ++j) {
		k = j - 1;
		do {
			k = nextj[k];
		} while(t[k] != t[j - 1] && k!=0);
		if (t[k] == t[j - 1]) {
			nextj[j] = k + 1;
		} else {
			nextj[j] = k;
		}
	}
}

void init_nextval(const string& t) {
	int len = t.length();
	for (int j = 2; j <= len; ++j) {
		int k = j ;
		do {
			k = nextj[k];
		} while (t[j] == t[k] && k!=0);
		nextval[j] = k;
	}
}
void KMP_find(const string& s, const string& t) {
	int slen = s.length();
	int tlen = t.length();
	int j = 0;
	for (int i = 0; i < slen; i = (j == 0 ? i + 1 : i)) {
		for (j = nextval[j]; j < tlen && s[i] == t[j] ; ++i, ++j);
		if (j == tlen) {
			cout << i - tlen + 1 << '\n';
		}
	}
}
/*
acabaabaabcacaabc
abaabcac
*/

int main() {
	string s,t;
	cin >> s >> t;
	init_next(t);
	init_nextval(t);
	KMP_find(s,t);
	int tlen = t.length();
	for (int i = 1; i <= tlen; ++i) {
		cout << nextj[i] << ' ';
	}
}