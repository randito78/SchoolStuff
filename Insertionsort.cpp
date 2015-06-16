#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#pragma warning(disable: 4996)
using namespace std;

double arr[200];
int size = 0;
double num;
string filename;
string line;
int ncomparisons;
int done;
int main()
{
		cout << "Enter a file name to create excluding the extension(assumed to be txt)" << endl;
		cin >> filename;
		ifstream file (filename + ".txt");
		size = 0;
		if (file.is_open()){
			while (getline(file, line))
			{
				std::string::size_type sz;
				double num = std::stof(line, &sz);
				arr[size] = num;
				size++;
			}
			file.close();
		}

		for (int i = 1; i < size; i++){
			ncomparisons++;
			double key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j]>key){
				ncomparisons++;
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}

		/*for (int k = 0; k < size; k++){
			cout << arr[k];
			cout << " ";
		}
		cout << endl;
		*/
		ofstream myfile;
		myfile.open("InsertionSorted_" + filename + ".txt");
		for (int k = 0; k < size; k++){
			myfile << arr[k];
			myfile << "\n";
		}
		myfile.close();
		cout << "InsertionSorted_" + filename + ".txt has been created" << endl;
		cout << ncomparisons;
		cout << " comparisons were made" << endl;
		cout << "press enter to quit" << endl;
		cin >> done;
} 