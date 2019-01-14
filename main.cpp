#include <iostream>
#include <exception>
#include "Stack.h"

using namespace std;

int main()
{
	try {
		Stack<int> st;
		st.push(1);
		st.push(2);
		st.push(5);

		cout << st.head() << endl;

		int a = 4;

		st.push(a);

		cout << st.head() << endl;

		st.pop();

		cout << st.head() << endl;

	}
	catch (const exception &e) {
		cerr << " EXCEPTION: " << e.what() << endl;
	}
}
