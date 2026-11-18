#include <iostream>
#include <string>
#include <vector>

int sum(int n) { 
	if (n == 0)
		return 0;
	return n + sum(n - 1); // 5+sum(4) -> 5+4+sum(3) -> 5+4+3+sum(2) -> 5+4+3+2+sum(1) -> 5+4+3+2+1+sum(0) -> 5+4+3+2+1 (base case reached so stopped)
}
int sumDigits(int n) {
	if (n == 0)
		return 0;
	return (n % 10) + sumDigits(n / 10); 
}
bool isPalindrome(std::string s, int left, int right) {
	if (left >= right)
		return true;
	if (s[left] != s[right])
		return false;
	return isPalindrome(s, left + 1, right - 1);
}
int findMaximum(std::vector<int> v, int size) {
	if (size == 1)
		return v[0];
	int max = findMaximum(v, size - 1);
	if (v[size - 1] > max)
		return v[size - 1];
	return max;
}
int main() {
	int n, val;
	std::string s;
	//std::cout << "Enter n for the sum of natural numbers:";
	//std::cin >> n;
	//std::cout << sum(n);
	//std::cout << "Enter a number whose digits are to be sumed:";
	//std::cin >> n;
	//std::cout << sumDigits(n);
	//std::cout << "Enter a string:";
	//std::getline(std::cin, s);
	//if (isPalindrome(s, 0, s.length())) {
	//std::cout << "string is palindrome!";
	//}
	//else
	//	std::cout << "string is not palindrome!";
	std::vector<int> v = { 3,78,0,3,6,8 };
	std::cout << "Mximum value in vector v is:" << findMaximum(v, v.size());
}