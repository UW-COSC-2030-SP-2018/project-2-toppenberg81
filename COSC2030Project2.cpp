//Jordan Toppenberg
//COSC 2030
//Project 2
//May 6, 2018


#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<random>
#include<algorithm>
using namespace std;

//partition and quicksort algorithims found on geeksforgeeks.com, used in lab 7.
//Quicksort
int partition(vector<int>& vec1, int indexL, int indexR) {

	int pivot = vec1.at(indexR);
	int i = (indexL - 1);

	for (int j = indexL; j <= indexR - 1; j++)
	{
		if (vec1.at(j) <= pivot)
		{
			i++;
			std::swap(vec1.at(i), vec1.at(j));
		}
	}
	std::swap(vec1.at(i + 1), vec1.at(indexR));

	return (i + 1);
}

void QuickSort(vector<int>& vec1, int indexL, int indexR) {

	if (indexL < indexR)
	{
		int piv = partition(vec1, indexL, indexR);
		QuickSort(vec1, indexL, piv - 1);
		QuickSort(vec1, piv + 1, indexR);
	}
	return;
}
//Binary Search given sorted vector
int binarysearch(vector<int>&vec1, int indexL, int indexR, int x) {
	if (indexR >= indexL)
	{
		int mid = indexL + (indexR - indexL) / 2;
		if (vec1.at(mid) == x)
		{
			return mid;
		}
		if (vec1.at(mid) > x)
		{
			return binarysearch(vec1, indexL, mid - 1, x);
		}
		return binarysearch(vec1, mid + 1, indexR, x);
	}
	return -1;//return -1 if not found

}
//Merge Sort found on geeksforgeeks.com
void merge(vector<int>&vec1, int indexL, int mid, int indexR)
{
	//cout << "in merge call" << endl;
	//cout << "indexL: " << indexL << " indexR: " << indexR << " mid: " << mid << endl;
	int i, j, k;
	int n1 = mid - indexL + 1;
	int n2 = indexR - mid;
	//cout << "n1: " << n1 << " n2: " << n2 << endl;
	vector<int> left, right;

	for (i = 0; i < n1; i++)
	{
		int a = vec1.at(indexL + i);
		left.push_back(a);
	}
	for (j = 0; j < n2; j++)
	{
		int b = vec1.at(mid + 1 + j);
		right.push_back(b);
	}
	i = 0;
	j = 0;
	k = indexL;
	while (i < n1 && j < n2)
	{
		if (left.at(i) <= right.at(j))
		{
			vec1.at(k) = left.at(i);
			i++;
		}
		else
		{
			vec1.at(k) = right.at(j);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		vec1.at(k) = left.at(i);
		i++;
		k++;
	}
	while (j < n2)
	{
		vec1.at(k) = right.at(j);
		j++;
		k++;
	}
}
void mergesort(vector<int>&vec1, int indexL, int indexR)
{
	//cout << "in merge sort call index L: "<<indexL<<"index R: "<<indexR << endl;
	if (indexL < indexR) {
		int mid = indexL + (indexR - indexL) / 2;
		//cout << " mid set in mergesort: " << mid << endl;

		mergesort(vec1, indexL, mid);
		mergesort(vec1, mid + 1, indexR);

		merge(vec1, indexL, mid, indexR);
	}
}

int strtoint(string result)//Ward's example for COSC2150
{
	int returnval;
	returnval = atoi(result.c_str());
	return returnval;
}
string inttostr(int tostring)//Ward's example for COSC2150
{
	ostringstream str;
	str << tostring;
	return str.str();
}
string rand_string(size_t length)
{
	auto randchar = []()->char
	{
		const char characters[] = "0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(characters) - 1);
		return characters[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

//Text/int to int hash ( convert string or int to integer)
unsigned int hasher(int value, int number_of_items)
{
	int hashed = (value % number_of_items);
	cout << "Given value: " << value << "\tHashed value: " << hashed << endl;;
	return hashed;
}

unsigned int hasher(string value, int number_of_items)//pretty much rafers weak hash function
{
	int a = 4568;
	int b = 845;
	int hashed = 0;
	for (size_t i = value.length() - 4; i < value.length() - 1; i++)
	{
		hashed = hashed*a + value[i];
		a = a*b;
	}
	cout << "Given value: " << value << "\tHashed value: " << hashed << endl;;
	return hashed;
}

//Bloom filter

int main()
{
	vector<int> tester;
	cout << "Before quicksort: " << endl;
	for (int i = 0; i < 80; i++)
	{
		int a = rand() % 100 + 1;
		tester.push_back(a);
		cout << tester.at(i) << "\t";
	}
	int qn = tester.size();
	cout << "before quicksort call" << endl;
	system("pause");
	QuickSort(tester, 0, qn - 1);
	cout << "after quicksort: " << endl;
	for (int i = 0; i < tester.size(); i++)
	{
		cout << tester.at(i) << "\t";
	}

	int sn = tester.size();
	int search_for = 93;
	int location = binarysearch(tester, 0, sn, search_for);
	if (location == -1) { cout << "not found" << endl; }
	else {
		cout << "location of " << search_for << " found: " << location << endl;
	}

	vector<int> tester2;
	cout << "Before mergesort: " << endl;
	for (int i = 0; i < 81; i++)
	{
		int b = rand() % 100 + 1;
		tester2.push_back(b);
		cout << tester2.at(i) << "\t";
	}
	int mn = tester2.size();
	mergesort(tester2, 0, mn - 1);
	cout << "After meregesort: " << endl;
	for (int i = 0; i < tester2.size(); i++)
	{
		cout << tester2.at(i) << "\t";
	}

	vector<string>tester3;
	vector<int>tester4;
	for (int i = 0; i < 21; i++)
	{
		string filler;
		string pusher = rand_string(7);
		tester3.push_back(pusher);
		cout << "tester at " << i << " is: " << tester3.at(i) << endl;
	}
	for (int i = 0; i < 11; i++)
	{
		int c = rand() % 100 + 1;
		tester4.push_back(c);
		cout << tester4.at(i) << "\t";

	}

	for (int i = 0; i < 11; i++)
	{
		hasher(tester4.at(i), 11);
		hasher(tester3.at(i), 11);
	}



	system("pause");

}
