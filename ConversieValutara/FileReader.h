#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class FileReader
{
public:
	FileReader(string file);
	static void ShowFile();
	static double getCurrency(string from_, string to_);
private:
	static map<string, double> values;
};

