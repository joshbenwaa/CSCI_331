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
	string tempValue;
	string Values;
	vector<Data> tempData;
	Data tempSingleData;
	int tempArrayPosition = 0;
	uint8_t OldSpace = 0;
	//Start with Data file
	int RunNum = 0;
	cout << "Please enter the name of the file you wish to Merge:";
	getline(cin, input_file_name);
	Josh_Input.open(input_file_name.c_str());
	if (Josh_Input.fail())
	{
		return 0;
	}

	while (!Josh_Input.eof())
	{
		getline (Josh_Input, Values);
		for (int i = 0; i < Values.length(); i++)
		{
			if (Values[i] == ' ')
			{
				tempValue = Values.substr(OldSpace, i - OldSpace);
				tempSingleData.Value = std::stoi(tempValue, nullptr, 10);
				tempSingleData.RunNumber = RunNum;
				//tempSingleData.ArrayPosition = tempArrayPosition;
				//tempArrayPosition++;
				tempData.push_back(tempSingleData);
				OldSpace = i + 1;
			}
		}
		Values = "";
		//tempSingleData.ArrayPosition = 0;
		tempSingleData.RunNumber = 0;
		tempSingleData.Value = 0;
		//tempArrayPosition = 0;
		OldSpace = 0;
		RunNum++;
		ValuesArray.push_back(tempData);
		tempData.clear();

		//Now for the offsets

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

	cout << "Please enter the name of the file you wish to place the Merge into:";
	getline(cin, data_output_file_name);
	Josh_output.open(data_output_file_name.c_str());
	if (Josh_output.fail())
	{
		return 0;
	}

	//Fill the array initially
	for (int i = 0; i < ValuesArray.size(); i++)
	{
		heap.push_back(ValuesArray[i].front());
	}
	while (!heap.empty())
	{
		//Heapify;
		std::make_heap(heap.begin(),heap.end(), Kway::greater1());
		Min = heap.front();
		//Result.push_back(Min);
		Josh_output << Min.Value << " ";
		std::pop_heap(heap.begin(), heap.end(), Kway::greater1());
		heap.pop_back();
		if ((ValuesArray[Min.RunNumber].size() > 1))
		{
			//TempArrayPosition = Min.ArrayPosition;
			ValuesArray[Min.RunNumber].erase(ValuesArray[Min.RunNumber].begin());
			PushBack_Data = ValuesArray[Min.RunNumber].at(0);
			heap.push_back(PushBack_Data);
		}
	}

	return false;
}

bool Kway::Compare(Data d1, Data d2)
{
	return d1.Value > d2.Value;
}

long stoi(const char *s)
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