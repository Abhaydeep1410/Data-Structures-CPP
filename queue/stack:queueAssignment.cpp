#include<bits/stdc++.h>
using namespace std;



void reverseTheStackRecursion(stack<int> s, stack<int> s2) {
//can be also done using two extra stack
	if (s.size() == 0) {
		return ;
	}

	int x = s.top();
	s.pop();
	reverseTheStackRecursion(s, s2);

	while (!s.empty()) {
		s2.push(s.top());
		s.pop();
	}
	s.push(x);
	while (!s2.empty()) {
		s.push(s2.top());
		s2.pop();
	}


}


//check redundant paranthesis ex.((a+b)) redundant
bool redundatn(string s) {
	stack<char> a;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == ')' || s[i] == ']' || s[i] == '}') {

			while (!a.empty()) {
				if ((a.top() == '{' || a.top() == '(' || a.top() == '[')) {
					break;
				}
				a.pop();
				count++;
			}

			if (count != 0 && (a.top() == '{' || a.top() == '(' || a.top() == '[')) {
				a.pop();
				count = 0;
				continue;

			} else {
				return false;
			}


		}
		else {
			a.push(s[i]);

		}

	}

	if (a.size() == 0)return true;
	return false;
}




int main()
{
	// stack<int> s;
	// stack<int> s2;
	// s.push(10);
	// s.push(20);
	// s.push(30);

	// reverseStack(s, s2);
	// while (!s.empty()) {
	// 	cout << s.top() << endl;
	// 	s.pop();
	// }


	string s = "((a+b)+c";
	cout <<( redundatn(s)==0?"false":"true" )<< endl;




}