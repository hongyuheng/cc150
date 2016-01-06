#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;

template<typename T>

void printMatrix(const vector<vector<T>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}


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

class problem1_5 {
public:
	string compressBetter(string str) {
		int size = countCompression(str);
		if (size >= str.length())
			return str;
		
		stringstream buffer;
		char last = str[0];
		int count = 1;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] == last)
				count++;
			else {
				buffer << last;
				buffer << count;
				last = str[i];
				count = 1;
			}	
		}

		buffer << last;
		buffer << count;

		string res = buffer.str();
		return res;

	}

	int countCompression(string str) {
		if (str.size() == 0)
			return 0;

		char last = str[0];
		int size = 0;
		int count = 1;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == last)
				count++;
			else {
				last = str[i];
				size += 1 + to_string(count).size();
				count = 1;
			}
		}

		size += 1 + to_string(count).size();
		return size;
	
	}

	void test() {
		string ss = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbccccccccccccccccccccccccccccccccccccccccccccccc";
		cout << compressBetter(ss);
	}
};

class problem1_6 {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		if (matrix[0].size() == 0)
			return;
		int n = matrix.size();
		for (int layer = 0; layer < n / 2; layer++) {
			int first = layer;
			int last = n - 1 - layer;
			for (int i = layer; i < n - layer - 1; i++) {
				int offset = i - first;
				int tmp = matrix[first][i];
				matrix[first][i] = matrix[last - offset][first];
				matrix[last - offset][first] = matrix[last][last - offset];
				matrix[last][last - offset] = matrix[i][last];
				matrix[i][last] = tmp;
			}
		}
	}

	void test() {
		vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
		rotate(matrix);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

class problem1_7 {
public:
	void setZeros(vector<vector<int> >& matrix) {
		bool firstRow = false, firstCol = false;
		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i][0] == 0)
				firstCol = true;
		}

		for (int i = 0; i < matrix[0].size(); i++) {
			if (matrix[0][i] == 0)
				firstRow = true;
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < matrix.size(); i++) {
			if (matrix[i][0] == 0)
				setZero(matrix, i, 1);
		}

		for (int i = 1; i < matrix[0].size(); i++) {
			if (matrix[0][i] == 0)
				setZero(matrix, i, 2);
		}
	
		if (firstRow)
			setZero(matrix, 0, 1);
		if (firstCol)
			setZero(matrix, 0, 2);
	}

	void setZero(vector<vector<int> >& matrix, int i, int flag) {
		//set row
		if(flag == 1) {
			for (int col = 0; col < matrix[i].size(); col++) {
				matrix[i][col] = 0;
			}
		}
		//set col
		if (flag == 2) {
			for (int row = 0; row < matrix.size(); row++) {
				matrix[row][i] = 0;
			}
		}
	}

	void test() {
		vector<vector<int>> matrix = { {1,2,3,0}, {4,0,0,6}, {7,8,9,4} };
		printMatrix(matrix);
		setZeros(matrix);
		printMatrix(matrix);
	}
};


int main() {
	problem1_7 test;
	test.test();
	return 0;
}