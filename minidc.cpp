#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class minidc
{
	private:
		stack<double> in, out;
		double a,b;
		int i;
	
	public:
		minidc()
		{
			i = 0;
		}
		
		//~minidc(){ delete <int> in; delete <int> out;}
		
		void join(double val)
		{
			in.push(val);
		}
		
		// Prints the value on the top of the stack, without altering the stack.
		void p()
		{
			if ( ! in.size()){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			cout << in.top() << endl;
			
		}
		
		// Prints the value on the top of the stack, popping it off.
		void n()
		{
			if ( ! in.size()){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			cout << in.top() << endl;
			in.pop();
		}
		
		// Prints the entire contents of the stack without altering anything.
		void f()
		{
			if ( ! in.size()){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			out = in;
			i = out.size();
			
			while(i > 0)
			{
				cout << out.top() << endl;
				out.pop();
				
				i--;
			}
			
		}
		
		
		// Pops two values off the stack, adds them, and pushes the result.
		void add()
		{
			if ( in.size() < 2){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			a = in.top(); in.pop();
			b = in.top(); in.pop();
			
			// overflow???
			in.push(a + b);
		}
		
		// Pops two values off the stack, subtracts the first one popped from the second one popped, and pushes the result.
		void sub()
		{
			if ( in.size() < 2){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			a = in.top(); in.pop();
			b = in.top(); in.pop();
			
			// underflow???
			in.push(b - a);
		}
		
		// Pops two values, multiplies them, and pushes the result.
		void mul()
		{
			if ( in.size() < 2){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			a = in.top(); in.pop();
			b = in.top(); in.pop();
			
			// overflow???
			in.push(b * a);
		}
		
		// Pops two values, divides the second one popped from the first one popped, and pushes the result.
		void div()
		{
			if ( in.size() < 2){
				cout << "minidc: stack empty" << endl;
				return;
			}
			
			a = in.top(); in.pop();
			
			if ( ! a){
				cout << "minidc: divide by zero" << endl;
				return;
			}
			
			b = in.top(); in.pop();
			
			// underflow???
			in.push(b / a);
		}
		
		string parse(string s)
		{
			unsigned found = s.find("+");
			
			while (found != string::npos)
			{
				s.replace(found, 1," + ");
				found = s.find("+", found + 2, 1);
			}
			
			found = s.find("-");
			
			while (found != string::npos)
			{
				s.replace(found, 1," - ");
				found = s.find("-", found + 2, 1);
			}
			
			found = s.find("*");
			
			while (found != string::npos)
			{
				s.replace(found, 1," * ");
				found = s.find("*", found + 2, 1);
			}
			
			found = s.find("/");
			
			while (found != string::npos)
			{
				s.replace(found, 1," / ");
				found = s.find("/", found + 2, 1);
			}
			
			return s;
		}
		
		void solve(){
			
		}
				
			
	
};

int main()
{
	minidc dc;
	int flag = 1;
	
	string s;
	char * pch;
	char valid[] = "0123456789._+-*/pnfq";
	
	while (flag){
		getline(cin, s);
		s = dc.parse(s);
		
		// tokenization
		char * cstr = new char [s.length()+1];
		strcpy(cstr, s.c_str());
		
		pch = strtok(cstr, " \t");
		
		while(pch != NULL)
		{
			if (strspn(pch, valid))
			{
				if (strstr(pch, "q"))
				{
					flag = 0;
				}
				else if (strstr(pch, "p"))
				{
					dc.p();
				}
				else if (strstr(pch, "n"))
				{
					dc.n();
				}
				else if (strstr(pch, "f"))
				{
					dc.f();
				}
				else if (strstr(pch, "*"))
				{
					dc.mul();
				}
				else if (strstr(pch, "/"))
				{
					dc.div();
				}
				else if (strstr(pch, "+"))
				{
					dc.add();
				}
				else if (strstr(pch, "-"))
				{
					dc.sub();
				}	
				else
				{
					if (strstr(pch, "_"))
					{
						s = pch;
						unsigned pos = s.find("_");
						s = s.replace(pos, 1, "");
						
						dc.join(-1 * strtod(s.c_str(), NULL));
					}
					else
					{
						dc.join(strtod(pch, NULL));
					}
				}
						
			}
			else
			{
				cout << "Invalid character" << endl;
			}

			pch = strtok (NULL, " \t");
		}
	}
	
	return 0;
}
