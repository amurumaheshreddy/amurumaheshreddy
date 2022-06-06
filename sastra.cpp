
#include <iostream>
#include<fstream>
using namespace std;

int main(  )
{
	fstream file; 
	char c;
	int vowels = 0;

	file.open("input.txt");
	while(!file.eof())
	{
		file.get(c);
		if (c =='a'|| c =='e'||c =='i'||c ='o'|| c =='u'||c =='A'||c =='E'||c =='I'|| =='O' ||c=='U')
			vowels++;
	}
	file.close();
    cout<<"The number of vowels in the text is:";
	cout << vowels;
	return 0;
}

