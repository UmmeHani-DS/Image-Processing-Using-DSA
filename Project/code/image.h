#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
#include "list.h"
using namespace std;

class image
{
	int row;
	int col;
	int** arr;
	int** arr1;
	string info[6];
	string filename;
	string array[11];
	//list <string> m;


public:

	image();
	~image();
	void Read(string);
	void Save();
	void SetPixel(int, int, int);
	int GetPixel(int, int);
	int GetSize();
	void ConvertToNegative();
	int Mean();
	void numPixels();
	void avgBlackpixels();
	void imageQueue(int, int);
	void imageStack(int, int);
	void logfile();
	void rlc_Encoding();
	void rlc_Blackpixels();
	void rlc_Negative();
	void data_base();

};