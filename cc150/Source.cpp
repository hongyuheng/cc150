#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

class problem1_1 {
public:
	bool isUniqueChars(string str) {
		if (str.size() == 0)
			return -1;
		unordered_map<char, int> check_hash;
		for (int i = 0; i < str.size(); i++) {
			if (check_hash.find(str[i]) != check_hash.end())
				return false;
			check_hash[str[i]]++;
		}
		return true;
	}

	void test() {
		cout << isUniqueChars("abccc");
	}
};

class problem1_2 {
public:
	void reverse(char *str) {
		char* end = str;
		char tmp;
		if (str) {
			while (*end) {
				end++;
			}
		}
		end--;

		while (str < end) {
			char tmp = *end;
			*end = *str;
			*str = tmp;
			str++;
			end--;
		}
	}

	void test() {
		char str[] =  "abc" ;
		reverse(str);
		char* base = str;
		cout << "reversed : "<< str << endl;
		//while (*base) {
		//	cout << *base;
		//	base++;
		//}
	}
};

class problem1_3 {
public:
	bool anagram1(string a, string b) {
		if (a.size() != b.size())
			return false;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		return a == b;
	}

	bool anagram2(string a, string b) {
		if (a.size() != b.size())
			return false;

		unordered_map<char, int> hash;
		
		for (int i = 0; i < a.size(); i++) {
			hash[a[i]]++;
		}

		for (int i = 0; i < b.size(); i++) {
			char c = b[i];
			if (--hash[c] < 0)
				return false;
			
		}

		return true;
	}

	void test() {
		string a = "aab";
		string b = "baa";
		cout << a << " and " << b << " is anagram is : " << anagram2(a, b) << endl;
	}
};

int main() {
	problem1_3 test;
	test.test();
	return 0;
}