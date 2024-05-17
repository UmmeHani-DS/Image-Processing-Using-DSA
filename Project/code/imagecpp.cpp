#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "image.h"
using namespace std;


image::image()
{
	row = 0;
	col = 0;
	arr = nullptr;
	//arr1 = nullptr;
	filename = "";
}

image :: ~image()
{

}

void image::Read(string path)
{
	filename = path;
	string line;
	string word;
	char get;
	int x;


	ifstream obj(path);

	if (obj.is_open())
	{
		for (int l = 0; l <= 4; l++)
		{
			getline(obj, line);
			info[l] = line;

			if (l == 3)
			{
				stringstream ss;
				ss << line;
				ss >> word;
				row = stoi(word);
				ss >> word;
				col = stoi(word);

			}

		}

		arr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new int[col];
		}

		obj >> get;
		info[5] = get;

		for (int j = 0; j < int(row); j++)
		{
			for (int k = 0; k < int(col); k++)
			{
				obj >> get;

				x = int(get);

				if (get == -1)
				{
					arr[j][k] = 255;
				}
				else
				{
					arr[j][k] = 0;
				}

			}
		}
	}

	obj.close();

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[0] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : Read fuction was called.";


}

void image::Save()
{
	ofstream obj;

	obj.open("save.pgm");

	for (int i = 0; i < 6; i++)
	{
		obj << info[i] << endl;

	}

	for (int j = 0; j < row; j++)
	{
		for (int k = 0; k < col; k++)
		{
			obj << char(arr[j][k]);
		}

	}

	obj.close();


}

void image::SetPixel(int r, int c, int val)
{
	if (r >= row && c >= col)
	{
		cout << "Index out of bound!" << endl;
	}
	else
	{
		if (val != 255 && val != 0)
		{
			cout << "Error! Pixel value can be either 0 or 255" << endl;
		}
		else
		{
			arr[r][c] = val;
		}

	}


}

int image::GetPixel(int r, int c)
{
	int val = 0;

	if (r >= row && c >= col)
	{
		cout << "Index out of bound!" << endl;
		return -1;
	}
	else
	{
		val = arr[r][c];
	}

	return val;

}

int image::GetSize()
{
	int size = row * col;
	return size;

}

void image::ConvertToNegative()
{

	for (int j = 0; j < row; j++)
	{
		for (int k = 0; k < col; k++)
		{
			if (arr[j][k] == 255)
			{
				arr[j][k] = 0;
			}
			else
			{
				arr[j][k] = 255;
			}
		}
	}

	ofstream obj2;

	obj2.open("negative.pgm");

	for (int i = 0; i < 6; i++)
	{
		obj2 << info[i] << endl;

	}

	for (int j = 0; j < row; j++)
	{
		for (int k = 0; k < col; k++)
		{
			obj2 << char(arr[j][k]);
		}

	}

	obj2.close();

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[1] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : Covert to negative fuction was called.";


}

int image::Mean()
{
	int sum = 0;
	int mean;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += arr[i][j];
		}
	}

	mean = sum / (row * col);


	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);


	array[2] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : Mean fuction was called.";
	return mean;

}

void image::numPixels()
{
	int blackCount = 0;
	int whiteCount = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 255)
			{
				whiteCount++;
			}
			else
			{
				blackCount++;
			}
		}
	}


	cout << "NUMBER OF BLACK PIXELS : " << blackCount << endl;
	cout << "   NUMBER OF WHITE PIXELS : " << whiteCount << endl;

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[3] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : numPixel fuction was called.";

}

void image::avgBlackpixels()
{
	int blackCount = 0;
	int avg;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				blackCount++;
			}
		}
	}

	avg = (blackCount / row);

	cout << "NUMBER OF AVERAGE BLACK PIXELS IN A ROW : " << avg << endl;

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[4] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : avgBlackpixel fuction was called.";

}

void image::imageQueue(int x, int y)
{
	//Index check

	if (x >= row || x < 0 && y >= col || col < 0)
	{
		cout << "INVALID LOCATION ENTERED!" << endl;
	}

	else
	{

		// Creating a temporary array & setting the values to 255

		int** temp;

		temp = new int* [row];

		for (int i = 0; i < row; i++)
		{
			temp[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp[i][j] = 255;
			}
		}

		// Enqueue the location

		queue<int, Node<int>> q;

		q.enqueue(x);
		q.enqueue(y);

		while (q.isEmpty() != true)
		{
			int x1 = q.dequeue();
			int y1 = q.dequeue();

			int val = arr[x1][y1];

			if (temp[x1][y1] == 255)
			{
				temp[x1][y1] = 0;

				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1 - 1][y1 - 1] == val)
					{
						q.enqueue(x1 - 1);
						q.enqueue(y1 - 1);
					}
				}
				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1) < col && (y1) >= 0)
				{
					if (arr[x1 - 1][y1] == val)
					{
						q.enqueue(x1 - 1);
						q.enqueue(y1);
					}
				}
				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1 - 1][y1 + 1] == val)
					{
						q.enqueue(x1 - 1);
						q.enqueue(y1 + 1);
					}

				}
				if ((x1) < row && (x1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1][y1 - 1] == val)
					{
						q.enqueue(x1);
						q.enqueue(y1 - 1);
					}
				}
				if ((x1) < row && (x1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1][y1 + 1] == val)
					{
						q.enqueue(x1);
						q.enqueue(y1 + 1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1 + 1][y1 - 1] == val)
					{
						q.enqueue(x1 + 1);
						q.enqueue(y1 - 1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1) < col && (y1) >= 0)
				{
					if (arr[x1 + 1][y1] == val)
					{
						q.enqueue(x1 + 1);
						q.enqueue(y1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1 + 1][y1 + 1] == val)
					{
						q.enqueue(x1 + 1);
						q.enqueue(y1 + 1);
					}
				}

			}

		}

		// Saving the extracted image
		ofstream obj;

		obj.open("Qimg.pgm");

		for (int i = 0; i < 6; i++)
		{
			obj << info[i] << endl;

		}

		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				obj << char(temp[j][k]);
			}

		}

		obj.close();

		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);

		array[5] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : imageQueue fuction was called.";

	}
}


void image::imageStack(int x, int y)
{
	//Index check

	if (x >= row || x < 0 && y >= col || col < 0)
	{
		cout << "INVALID LOCATION ENTERED!" << endl;
	}

	else
	{

		// Creating a temporary array & setting the values to 255

		int** temp;

		temp = new int* [row];

		for (int i = 0; i < row; i++)
		{
			temp[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp[i][j] = 255;
			}
		}

		// Push the location

		stack<int, Node<int>> s;

		s.push(x);
		s.push(y);

		while (s.isEmpty() != true)
		{
			int y1 = s.pop();
			int x1 = s.pop();

			int val = arr[x1][y1];

			if (temp[x1][y1] == 255)
			{
				temp[x1][y1] = 0;

				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1 - 1][y1 - 1] == val)
					{
						s.push(x1 - 1);
						s.push(y1 - 1);
					}
				}
				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1) < col && (y1) >= 0)
				{
					if (arr[x1 - 1][y1] == val)
					{
						s.push(x1 - 1);
						s.push(y1);
					}
				}
				if ((x1 - 1) < row && (x1 - 1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1 - 1][y1 + 1] == val)
					{
						s.push(x1 - 1);
						s.push(y1 + 1);
					}

				}
				if ((x1) < row && (x1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1][y1 - 1] == val)
					{
						s.push(x1);
						s.push(y1 - 1);
					}
				}
				if ((x1) < row && (x1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1][y1 + 1] == val)
					{
						s.push(x1);
						s.push(y1 + 1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1 - 1) < col && (y1 - 1) >= 0)
				{
					if (arr[x1 + 1][y1 - 1] == val)
					{
						s.push(x1 + 1);
						s.push(y1 - 1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1) < col && (y1) >= 0)
				{
					if (arr[x1 + 1][y1] == val)
					{
						s.push(x1 + 1);
						s.push(y1);
					}
				}
				if ((x1 + 1) < row && (x1 + 1) >= 0 && (y1 + 1) < col && (y1 + 1) >= 0)
				{
					if (arr[x1 + 1][y1 + 1] == val)
					{
						s.push(x1 + 1);
						s.push(y1 + 1);
					}
				}

			}

		}

		// Saving the extracted image
		ofstream obj;

		obj.open("Simg.pgm");

		for (int i = 0; i < 6; i++)
		{
			obj << info[i] << endl;

		}

		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				obj << char(temp[j][k]);
			}

		}

		obj.close();

		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);

		array[6] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : imageStack fuction was called.";

	}
}

void image::logfile()
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	ofstream obj;

	obj.open("log_" + to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + ".txt");

	for (int i = 0; i < 11; i++)
	{
		obj << array[i] << endl;

	}


	obj.close();



}


void image::rlc_Encoding()
{
	List<int> l;

	ofstream obj;

	l.insertData(row);
	l.insertData(col);
    
	obj.open("rlc_encoding.txt");

	obj << row << " " << col << endl;
	int c1 = 0;

	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				c1 = j;
				l.insertData(c1);
				obj << c1 << " ";
				while (arr[i][j] == arr[i][j + 1])
				{
					j++;
				}

				l.insertData(j);
				obj << j  << " ";
			}

		}

		l.insertData(-1);
		obj << -1 << endl;
	}

	obj.close();

	//DECODING RLC


	int r = l.removeData();
	int c = l.removeData();

	arr1 = new int* [r];

	for (int i = 0; i < r; i++)
	{
		arr1[i] = new int[c];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr1[i][j] = 255;
		}
	}

	int p = 0;
	int q = 0;
	int m, n;

	while (l.isEmpty() != true)
	{
		m = l.removeData();  //5

		if (m == -1)
		{
			p++;
		}

		else
		{
			n = l.removeData();
			q = m;
			while (q <= n)
			{
				arr1[p][q] = 0;
				q++;
			}


		}

	}

	ofstream obj1;

	obj1.open("rlc_decoding.pgm");

	for (int i = 0; i < 6; i++)
	{
		obj1 << info[i] << endl;

	}

	for (int j = 0; j < r; j++)
	{
		for (int k = 0; k < c; k++)
		{
			obj1 << char(arr1[j][k]);
		}

	}

	obj1.close();

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[7] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : rlc_encoding fuction was called.";
	array[8] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : rlc_decoding fuction was called.";

}

void image::rlc_Blackpixels()
{
	int blackCount = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr1[i][j] == 0)
			{
				blackCount++;
			}
		}
	}

	cout << "NUMBER OF BLACK PIXELS ARE: " << blackCount << endl;


	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[9] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : rlc_Blackpixels fuction was called.";


}

void image::rlc_Negative()
{

	for (int j = 0; j < row; j++)
	{
		for (int k = 0; k < col; k++)
		{
			if (arr[j][k] == 255)
			{
				arr1[j][k] = 0;
			}
			else
			{
				arr1[j][k] = 255;
			}
		}
	}

	ofstream obj1;

	obj1.open("rlc_negative.pgm");

	for (int i = 0; i < 6; i++)
	{
		obj1 << info[i] << endl;

	}

	for (int j = 0; j < row; j++)
	{
		for (int k = 0; k < col; k++)
		{
			obj1 << char(arr1[j][k]);
		}

	}

	obj1.close();


	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	array[10] = to_string(1900 + now.tm_year) + to_string(1 + now.tm_mon) + to_string(now.tm_mday) + to_string(now.tm_hour) + to_string(now.tm_min) + " : rlc_negative fuction was called.";


}

void image::data_base()
{
	int* hori;
	int* ver;

	hori = new int[row];
	ver = new int[col];

	//HORIZINTAL i.e NUMBER OF BLACK PIXELS IN A ROW
	int sum = 0;
	int k = 0;
	for (int i = 0; i < row; i++)
	{
		sum = 0;

		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				sum += 1;
			}
		}

		hori[k] = sum;
		k++;
	}

	// VERTICLE i.e NUMBER OF BLACK PIXELS IN A COLUMN
    
	k = 0;

	for (int i = 0; i < row; i++)
	{
		sum = 0;

		for (int j = 0; j < col; j++)
		{
			if (arr[j][i] == 0)
			{
				sum += 1;
			}
		}

		ver[k] = sum;
		k++;
	}

	
	// MAKING NEW ARRAY CONTAINING ALL THE ELEMENTS OF HORI & VER

	int num = row + col;
	int* array;
	array = new int[num];

	int j = 0;

	for (int i = 0; i < num; i++)
	{
		if (i >= row)
		{
			array[i] = hori[j];
			j++;
		}
		else
		{
			array[i] = ver[i];
		}

	}

	//CALCULATING 4 DIGIT SUM

	int n1, n2, n3, n4;
	int count1 = num / 4;
	int count2 = num % 4;
	int hash_sum = 0;

	for (int i = 0; i < (18 - count2); i += 4)
	{
		n1 = 1000 * array[i];
		n2 = 100 * array[i+1];
		n3 = 10 * array[i+2];
		n4 = array[i+3];

		hash_sum += (n1 + n2 + n3 + n4);

	}

	int l = (count1 * 4);

	if (count2 == 1)
	{
		hash_sum += 1000 * array[l];
	}

	else if (count2 == 2)
	{
		hash_sum += (1000 * array[l] + 100 * array[l + 1]);
	}
	else if (count2 == 3)
	{
		hash_sum += (1000 * array[l] + 100 * array[l + 1] + 10 * array[l + 2]);
	}



}



