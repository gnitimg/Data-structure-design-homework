#include<bits/stdc++.h>
using namespace std;

class stacks
{
private:
	string s;
public:
	void setString(string s)
	{
		this->s = s;
	}
	bool judge()
	{
		stack<char> st;
		for (char c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else if (c == ')' || c == ']' || c == '}')
			{
				if (st.empty()) return false;
				char top = st.top();
				st.pop();//³öÕ»
				if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))  return false;
			}
		}
		return st.empty();
	}
	void print()
	{
		if (judge())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
};

int main()
{
	stacks sa;
	cout << "insert string : ";
	string s;cin >> s;
	sa.setString(s);
	sa.print();
	return 0;
}
