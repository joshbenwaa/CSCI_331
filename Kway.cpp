#include "Kway.h"
#include <iostream>  // provides istream and ostream
#include <fstream> // input from file
#include <sstream>
#include <algorithm>
#include <sstream>
#include <string>
bool Kway::Get_Inputs()
{
	ifstream Josh_Input;
	string input_file_name;
	int counter = 0;
	int TempType = 0;
	int Pairs = 0;
	string tempValue;
	string Values;
	vector<Data> tempData;
	Data tempSingleData;
	int tempArrayPosition = 0;
	uint8_t OldSpace = 0;
	//Start with Data file
	int RunNum = 0;
	cout << "Please enter the name of the file you wish to Merge: ";
	cin >> input_file_name;
	cout << "Please enter what type of keys: ";
	cout << "0 = Integers\n1 = Strings\n2 = Pairs:   ";
	cin >> TempType;
	if (TempType == 2)
	{
		cout << "Which value in the Pair do you wish to sort by?";
		cout << "0 = Integers\n 1 = Strings:   ";
		cin >> Pairs;
		TempType += Pairs;
		;
	}
	Key_type = TempType;
	Josh_Input.open(input_file_name.c_str());
	if (Josh_Input.fail())
	{
		return 0;
	}

	while (!Josh_Input.eof())
	{
		getline (Josh_Input, Values);
		if (Key_type == 1)
		{
			Values.erase(Values.end() - 10, Values.end());
		}

		for (int i = 0; i < Values.length(); i++)
		{
			if (Values[i] == ' ')
			{
				tempValue = Values.substr(OldSpace, i - OldSpace);
				//What to do with the data
				switch (this->Key_type)
				{
				case 0: //Integers

					tempSingleData.Int_Value = stoi(tempValue.c_str());
					tempSingleData.S_Value = ""; break;
				case 1: //Strings
					tempSingleData.Int_Value = 0;
					tempSingleData.S_Value = tempValue; break;
				case 2: case 3: //Mixed Pairs
					tempSingleData.Int_Value = stoi(tempValue.substr(0, 3).c_str());
					tempSingleData.S_Value = tempValue.substr(3, 3);break;

				}
				tempSingleData.RunNumber = RunNum;
				tempSingleData.Type = TempType;
				//tempSingleData.ArrayPosition = tempArrayPosition;
				//tempArrayPosition++;
				tempData.push_back(tempSingleData);
				OldSpace = i + 1;
			}
			tempSingleData.RunNumber = 0;
			tempSingleData.Int_Value = 0;
			tempSingleData.S_Value = "";
		}
		Values = "";
		tempSingleData.RunNumber = 0;
		tempSingleData.Int_Value = 0;
		tempSingleData.S_Value = "";
		OldSpace = 0;
		RunNum++;
		ValuesArray.push_back(tempData);
		tempData.clear();
	}
	return true;
}
//ofstream& Output
bool Kway::sort_and_create()
{
	ofstream Josh_output;
	string data_output_file_name;
	vector<Data> heap;
	Data Min;
	Data PushBack_Data;
	vector<Data> Result;

	cout << "Please enter the name of the file you wish to place the Merge into: ";
	cin >> data_output_file_name;
	Josh_output.open(data_output_file_name.c_str());
	if (Josh_output.fail())
	{
		return 0;
	}

	//Fill the array initially
	for (int i = 0; i <= ValuesArray.size() - 1; i++)
	{
		heap.push_back(ValuesArray[i].front());
	}
	while (!heap.empty())
	{
		//Heapify;
		std::make_heap(heap.begin(),heap.end(), Kway::greater1());
		Min = heap.front();
		//Result.push_back(Min);
		switch (Min.Type)
		{
			case 0: //Integers
				Josh_output << Min.Int_Value << " "; break;
			case 1: //Strings
				Josh_output << Min.S_Value << " "; break;
			case 2: //Pairs by Integers
				Josh_output << Min.Int_Value << Min.S_Value << " "; break;
			case 3: //Pairs by String
				Josh_output << Min.S_Value << Min.Int_Value << " "; break;
		}
		std::pop_heap(heap.begin(), heap.end(), Kway::greater1());
		heap.pop_back();
		if ((ValuesArray[Min.RunNumber].size() > 1))
		{
			//TempArrayPosition = Min.ArrayPosition;
			ValuesArray[Min.RunNumber].erase(ValuesArray[Min.RunNumber].begin());
			PushBack_Data = ValuesArray[Min.RunNumber].at(0);
			heap.push_back(PushBack_Data);
			if ((ValuesArray[Min.RunNumber].size() == 1))
			{
				ValuesArray[Min.RunNumber].clear();
			}
		}
	}

	return false;
}

long Kway::stoi(const char *s)
{
	long i;
	i = 0;
	while (*s >= '0' && *s <= '9')
	{
		i = i * 10 + (*s - '0');
		s++;
	}
	return i;
}