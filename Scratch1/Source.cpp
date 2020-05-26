//

#include <iostream>
using namespace std;


struct Employee {
	int id;
	const char * name;
	const char * role;
};

int main()
{

	int x = 7;
	int *ip = &x; //pointer to y
	int &y = x; // reference

	y = 42; //when changing y - x changes as well
	int z = 43;
	ip = &z;

	printf("the value of x is %d\n", x);
	printf("the value of y is %d\n", y);
	printf("the value of *ip is %d\n", *ip);
	printf("the value of z is %d\n", z);


	// a byte is 8 bits
	constexpr size_t byte = 8;

	printf("sizeof char is %ld bits\n", sizeof(char) * byte);
	printf("sizeof short int is %ld bits\n", sizeof(short int) * byte);
	printf("sizeof int is %ld bits\n", sizeof(int) * byte);
	printf("sizeof long int is %ld bits\n", sizeof(long int) * byte);
	printf("sizeof long long int is %ld bits\n", sizeof(long long int) * byte);

	puts("Hello World");
	int ia[] = { 1, 2, 3, 4, 5 };
	for (auto i : ia) {
		printf("i is %d\n", i);
	}
	int test;
	cin >> test;

	Employee joe = { 42, "Joe", "Boss" };
	Employee * e = &joe;
	printf(joe.name);
	printf(e->name); // access to a pointer property
	

	return 0;
}