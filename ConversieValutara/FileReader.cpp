#include "FileReader.h"

map<string, double> FileReader::values{};

double FileReader::getCurrency(string from_, string to_)
{
	string s = from_ + "/" + to_;

	auto found = values.find(s);
	if (found != values.end())
	{
		return found->second;
	}
	return -1;
	
}

FileReader::FileReader(string file)
{
	ifstream f(file);
	if (f.is_open())
	{
		while (!f.eof()) {
			string x;
			double y;
			f >> x;
			f >> y;
			FileReader::values.insert({ x,y });
		}
		f.close();

	}
	else
	{
		cout << "The " << file << " file can't be opened";
	}


}

void FileReader::ShowFile()
{
	if (FileReader::values.size() == 0)
	{
		cout << "No values read yet! Use -f or -file to read values from file";
	}
	else
	{
		for (auto it = FileReader::values.begin(); it != values.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}
	}


}
