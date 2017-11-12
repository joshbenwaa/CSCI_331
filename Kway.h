#pragma once
#include <vector>

#ifndef KWAY_H
#define KWAY_H


using namespace std;
class Kway
{
public:
	struct Data
	{
		int Value;
		int RunNumber;
		//int ArrayPosition;
	};

	struct greater1 {
		bool operator()(const Data& a, const Data& b) const {
			return a.Value > b.Value;
		}
	};

	vector <int> heap;
	int * input; //Dynamic Array for inputs
	int * offsets;
	bool Get_Inputs(ifstream& Input);
	bool sort_and_create(ofstream& Output);
	bool Compare(Data d1, Data d2);
	vector<vector<Data>> ValuesArray;
	vector<int> ByteOffsets;
	Data Value;
};

#endif

