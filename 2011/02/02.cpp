#include<iostream>
using namespace std;

int strlen(const char* str) {
	if (str == NULL)
		return 0;
	if (*str != '\0')
		return 1 + strlen(++str);
	else
		return 0;
}

int main() {
	char *str = "Diaoyu islands belong to china";
	cout << "str:" << str << endl;
	cout << "length:" << strlen(str) << endl;


	return 0;
}
