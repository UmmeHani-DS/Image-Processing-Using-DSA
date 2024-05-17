#include <iostream>
#include <cstdio>
#include "image.h"
using namespace std;


int main()
{
	image i;

	string str;
	cout << "ENTER YOUR FILE NAME: ";
	cin >> str;
	i.Read(str);

	//......................MENU...................................//


	bool exit = false;

	int choice;
	do {
		cout << "----------MENU----------\n" << endl;
		cout << "1. QUESTION # 1" << endl;
		cout << "2. QUESTION # 2" << endl;
		cout << "3. QUESTION # 3" << endl;
		cout << "4. QUESTION # 4" << endl;
		cout << "5. EXIT THE MENU\n" << endl;
		cout << "Enter your choice: ";
		cin >> choice;


		switch (choice)
		{
		case 1:
			cout << endl;
			cout << "A. MEAN VALUE OF PIXELS: " << i.Mean() << endl;
			cout << "B. ";
			i.numPixels();
			cout << "C. ";
			i.avgBlackpixels();
			cout << "D. IMAGE CONVERTED TO NEGATIVE." << endl;
			i.ConvertToNegative();
			cout << endl;
			break;

		case 2:
			int x, y;
			cout << "ENTER THE PIXEL LOCATION: ";
			cin >> x >> y;
			i.imageQueue(x, y);
			cout << "\nIMAGE EXTRACTED IN THE FOLDER\n" << endl;
			break;

		case 3:
			int a, b;
			cout << "ENTER THE PIXEL LOCATION: ";
			cin >> a >> b;
			i.imageStack(a, b);
			cout << "\nIMAGE EXTRACTED IN THE FOLDER\n" << endl;
			break;

			case 4:
				cout << endl;
				cout << "A. IMAGE CONVERTED AND SAVED AS RLC-ENCODING." << endl;
				cout << "B. IMAGE DECODED AND SAVED AS RLC_DECODING." << endl;;
				i.rlc_Encoding();
				cout << "C. ";
				i.rlc_Blackpixels();
				cout << "D. IMAGE CONVERTED TO NEGATIVE." << endl;
				i.rlc_Negative();
				cout << endl;
				break;

		case 5:
			exit = true;
			i.logfile();
			break;

		default:
			cout << "Error! Invalid choice entered!" << endl;
		}

	} while (!exit);



	return 0;

}
