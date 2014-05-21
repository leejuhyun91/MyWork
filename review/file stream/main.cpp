#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

//enum rankType {NORMAL, RARE, UNIQUE, LEGENDARY, MAXRANK};
//const char flowerStr[MAXRANK][15] = { "NORMAL",
//								      "RARE",
//								      "UNIQUE",
//								      "LEGENDARY"};

struct ITEM
{
	char name[20];
	//rankType rank;
	int price;
};

int main()
{
	const int num = 3;
	//ITEM* pItem = NULL;
	ITEM item[num];
	fstream file;

	file.open("item.save", ios::in | ios::binary);

	if (!(file.is_open()))//파일이 존재하지 않음.
	{
		
		//cout << "Type the number of item you want to make : ";
		//cin >> num;

		file.open("item.save", ios::out | ios::binary); //파일 쓰기
		{			
			//pItem = new ITEM[num];
			for (int i = 0; i < num; i++)
			{
				cout << "No." << i + 1 << " item's name : ";
				cin >> item[i].name;

				//cout << "Input the item's rank : ";
				//cin >> pItem[i].rank;

				cout << "Input the item's price (integer) : ";
				cin >> item[i].price;
			}

			file.write((char*)item, sizeof(item));
		}
	}

	else//파일이 존재
	{
		cout << "There is an file. Loading file..." << endl;

		file.read((char*)item, sizeof(item));

		for (int i = 0; i < num; i++)
		{
			cout << item[i].name << " : "<< item[i].price << endl;
		}
		
	}
	
	file.close();

	//delete[] pItem;
	//pItem = NULL;
}