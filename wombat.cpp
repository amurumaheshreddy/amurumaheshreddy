#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int dlocation[100][2];//holds data location line number at 0 + value being held at location at 1

inline int binarycon(string x)
{
	return stoi(x, NULL, 2);
}

int datalocate(int x)
{
    //locates the appropriate data location number and returns integer
    for (int i = 0; i <= 100; i++)
        if (dlocation[i][0] == x)
            return i;

	return 0;
}

int main()
{
string marray[100][2];       //holds machine code instructions split into opcode(0) + memory address(1)
string line;
string filename;

int m = 0;
int acc = 0;        //holds value in accumulator
    
	cout << "\nEnter machine language program file path\n\t:";
	cin >> filename;

ifstream myfile(filename.c_str());

     if (!myfile.is_open())
     {
		cout << "\n\t!!File not Found!!\n\n\n"; 
		system("PAUSE");
		return 1;
	 }

	/*loop reads machine instructions from file as string, splits it into (0)opcode and (1)address
	and assigns results to 2D array - marray*/
	while (myfile.good())
	{
		getline (myfile,line);

		marray[m][0] = line.substr(0, 4);
		marray[m][1] = line.substr(4, 12);

		if (marray[m][0] == "0000")
		{
			dlocation[m][0] = m;                             //assigns line number
			dlocation[m][1] = binarycon(marray[m][1]);       //assigns default value of data location
		}

		m += 2;         //counter-to simulate wombat it increments in twos
	}

	myfile.close();

int iarray[100];    //holds input values

	cout << "\n\nEnter input file path\n\t: ";
	cin >> filename;

ifstream infile(filename.c_str());

	if (!infile.is_open())
	{
		cout << "\n\t!!File not Found!!\n\n\n";
		system("PAUSE");
		return 1;
	}

	for (int n = 0; infile.good(); n++)
		infile >> iarray[n];

	infile.close();

int x = 0,
    c = 0,
    d = 0;

bool pend = false;

	while (!pend)
	{
		switch (binarycon(marray[x][0]))
		{
			case 0:
				pend = true;
				break;

			case 1:
				c = binarycon(marray[x][1]);
				acc = dlocation[datalocate(c)][1];
				x += 2;
				break;

			case 2:
				c = binarycon(marray[x][1]);
				dlocation[datalocate(c)][1] = acc;
				x += 2;
				break;

			case 3:
				acc = iarray[d++];
				x += 2;
				break;

			case 4:
				cout << "\n\tacc value is " << acc << endl;
				x += 2;
				break;

			case 5:
				c = binarycon(marray[x][1]);
				acc = acc + dlocation[datalocate(c)][1];
				x += 2;
				break;

			case 6:
				c = binarycon(marray[x][1]);
				acc = acc - dlocation[datalocate(c)][1];
				x += 2;
				break;

			case 7:
				c = binarycon(marray[x][1]);
				acc = (acc * dlocation[datalocate(c)][1]);
				x += 2;
				break;

			case 8:
				c = binarycon(marray[x][1]);
				acc = (acc / dlocation[datalocate(c)][1]);
				x += 2;
				break;

			case 9:
				x = binarycon(marray[x][1]);
				break;

			case 10:
				x = (acc == 0) ? binarycon(marray[x][1]) : x + 2;
				break;

			case 11:
				x = (acc < 0) ? binarycon(marray[x][1]) : x + 2;
				break;

			default:
				cout << "Bad op\n";

		}
	}

	//writing output file
	cout << "\n\nEnter output data file path\n\t: ";
	cin >> filename;

ofstream out_file (filename.c_str());

	out_file << acc << endl;

	system("PAUSE");
	return 0;
}