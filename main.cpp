#include <iostream>
#include <string>
#include <stack>
#include<queue>

int main() {
    /*
	//question 1
	std::string line;  // part a
	std::cout << "Enter a line:";
	std::getline(std::cin, line);
	std::stack<char> s;
	for (char c : line) {
		s.push(c);
	}
	while (!s.empty()) {
		std::cout << s.top();
		s.pop();
	}
	std::cout << std::endl;
	//part b
	std::stack<std::string> s1;
	std::string word= "";
	for (int i = 0; i <= line.length(); ++i) {

		if (line[i] != ' ' && i < line.length()) {
			word += line[i];
		}
		else {
			if (word != "") {
				s1.push(word);
				word = "";
			}
		}
	}
	while (!s1.empty()) {
		std::cout << s1.top() << " ";
		s1.pop();
	} */
	// question 2
	std::string code;
	std::cout << "Enter an expression:";
	//std::getline(std::cin, code);
	std::cin >> code;
	std::stack<char> s2;
    std::stack<int> positions;

    for (int i = 0; i < code.length(); i++) {

        char c = code[i];
        if (c == '(' || c == '[' || c == '{') {
            s2.push(c);
            positions.push(i);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s2.empty()) {
                std::cout << "Error at " << i << ": unexpected closer '" << c << "'";
            }
            char expected;

            if (s2.top() == '(')
                expected = ')';
            else if (s2.top() == '[')
                expected = ']';
            else
                expected = '}';

            if (c != expected) {
                std::cout << "Error at " << i << ": expected '" << expected << "' but found '" << c << "'";
            }

            s2.pop();
            positions.pop();
        }
    }

    if (!s2.empty()) {
        int pos = positions.top();
        char opener;
        while (!s2.empty()) {
            opener = s2.top();
            s2.pop();
            pos = positions.top();
            positions.pop();
        }

        std::cout << "Error at " << pos << ": unclosed opener '" << opener << "'";
    }
    else {
        std::cout << "Balanced";
    }

    //question 3
   int n, k;

   std::cout << "Enter number of players: ";
   std::cin >> n;
   std::cout << "Enter number of passes: ";
   std::cin >> k;
   std::queue<int> q;

   for (int i = 1; i <= n; i++) {
      q.push(i);
    }
    std::cout << "Eliminated: ";
    while (q.size() > 1) {
      for (int i = 0; i < k; i++) {
          q.push(q.front());
          q.pop();
      }
      std::cout << q.front() << " ";
      q.pop();
    }
    std::cout << std::endl;
    std::cout << "Winner: " << q.front();

  return 0;
}