#include <iostream>

struct Punn
{
	union
	{
		int i;
		float f;
	};
	
	void print() const
	{
		std::cout << "Int: " << i << ", Float: " << f << '\n';
	}
};

int main()
{
	Punn p;
	p.i = 0;
	p.print();
	p.i = 21454;
	p.print();
	p.f = 571.12f;
	p.print();
}
