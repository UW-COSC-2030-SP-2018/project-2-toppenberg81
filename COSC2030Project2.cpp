//Jordan Toppenberg
//COSC 2030
//Project 2
//May 4, 2018


#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

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

//Merge Sort  https://www.geeksforgeeks.org/merge-sort/

void merge(vector<int>&vec1, int indexL, int indexR, int mid)
{

}

//Text/int to int hash ( convert string or int to integer)


//Bloom filter

int main()
{
	vector<int> tester;
	cout << "Before quicksort: " << endl;
	for (int i = 0; i < 50; i++)
	{
		int a = rand() % 100 + 1;
		tester.push_back(a);
		cout << tester.at(i) << "\t";
	}
	int qn = tester.size();
	cout << "before quicksort call" << endl;
	system("pause");
	QuickSort(tester, 0, qn-1);
	cout << "after call: " << endl;
	cout << "after quicksort: " << endl;
	for (int i = 0; i < tester.size(); i++)
	{
		cout << tester.at(i) << "\t";
	}

	int sn = tester.size();
	int search_for = 99;
	int location=binarysearch(tester, 0, sn, search_for);
	if (location == -1) { cout << "not found" << endl; }
	else {
		cout << "location of " << search_for << " found: " << location << endl;
	}
	system("pause");

}