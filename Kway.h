#pragma once
#include <vector>

#ifndef KWAY_H
#define KWAY_H


using namespace std;
class Kway
{
public:
	int Key_type;
	struct Data
	{
		int Type;
		int Value;
		int Int_Value;
		string S_Value;
		int RunNumber;
		//int ArrayPosition;
	};

	struct greater1 {
		bool operator()(const Data& a, const Data& b) const {
			switch (a.Type)
			{
			case 0: //integer
				return a.Int_Value < b.Int_Value;
			case 1: //String
				if (a.S_Value.compare(b.S_Value) < 0)
					return true;
				else
					return false;
			case 2: //Fixed Order Pairs
				if (a.Int_Value == b.Int_Value)
				{
					if (a.S_Value.compare(b.S_Value) < 0)
						return true;
					else
						return false;
				}
				else
					return a.Int_Value < b.Int_Value;
			}
		}
	};

	vector <int> heap;
	int * input; //Dynamic Array for inputs
	int * offsets;
	bool Get_Inputs(ifstream& Input);
	bool sort_and_create(ofstream& Output);
	vector<vector<Data>> ValuesArray;
	vector<int> ByteOffsets;
	Data Value;
};

#endif

