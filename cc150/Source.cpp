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

class problem1_4 {
public:
	void replaceSpaces(char *str, int length) {
		int numOfSpace = 0;
		for (int i = 0; i < length; i++) {
			if (*(str + i) == ' ')
				numOfSpace++;		
		}
		int end = length + numOfSpace * 2;
		int i = end;
		int j = length - 1;
		while (i >= 0) {
			if (i == end) {
				*(str + i) = '\0';
				i--;
				continue;
			}
			if (*(str + j) != ' '){
				*(str + i) = *(str + j);
				i--;
			}
			else {
				*(str + i) = '0';
				i--;
				*(str + i) = '2';
				i--;
				*(str + i) = '%';
				i--;
			}
			j--;
		}
	}

	void test() {
		char *str = (char*)malloc(5 + 1);
		*str = 'a';
		*(str + 1) = ' ';
		*(str + 2) = 'b';
		*(str + 3) = '\0';
		replaceSpaces(str, 3);
		cout << str << endl;
		free(str);
	}

};

class 

int main() {
	problem1_4 test;
	test.test();
	return 0;
}