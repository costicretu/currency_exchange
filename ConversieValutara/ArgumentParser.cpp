#include "ArgumentParser.h"
#include "FileReader.h"
#include <string.h>
#include <string>
#include <vector>
#include <iostream>


function<void(ArgumentParser&, string)> ArgumentParser::help = &ArgumentParser::HelpArguments;

function<void(ArgumentParser&, string)> ArgumentParser::file = &ArgumentParser::LoadCurrencyFromFile;

function<void(ArgumentParser&, string)> ArgumentParser::currency = &ArgumentParser::ShowCurrencyExchange;


map<string, function<void(ArgumentParser&, string)>> ArgumentParser::validArguments = {
	{"-l",ArgumentParser::currency},
	{"-listCurrency",ArgumentParser::currency},
	{"-h",ArgumentParser::help} ,
	{"-f",ArgumentParser::file} ,
	{"-help",ArgumentParser::help},
	{"-file",ArgumentParser::file} , };



ArgumentParser::ArgumentParser(int argc, char* argv[])
{

	if (argc <= 1) {
		ListAllValidArguments();
	}
	else
	{
		arguments.reserve(argc);

		for (int i = 1; i < argc; i++)
		{
			arguments.push_back(string(argv[i]));
		}

		ParseArguments();
	}


}

void ArgumentParser::ShowCurrencyExchange(string nothing) const
{
	FileReader::ShowFile();
}

void ArgumentParser::ListAllValidArguments() const {
	cout << "Invalid arguments, please use one of the following arguments." << endl;
	cout << " CurrencyExchange.exe -h\n CurrencyExchange.exe -help\n ";
}

void ArgumentParser::HelpArguments(string nothing) const {
	cout << " You need to introduce the file which contains the exchange values: " << endl;
	cout << " CurrencyExchange.exe -f 'filename'\n CurrencyExchange.exe -file 'filename'\n";
}

void ArgumentParser::LoadCurrencyFromFile(string fileName) const {
	FileReader f(fileName);
}

void ArgumentParser::ParseArguments() {

	for (auto it = arguments.begin(); it < arguments.end(); it++)
	{
		auto found = validArguments.find(*it);
		if (found == validArguments.end()) {
			ListAllValidArguments();
			break;
		}
		else
		{
			if (it != arguments.end() - 1 && ((*it) == "-f" || (*it) == "-file"))
			{
				it++;
			}

			found->second(*this, *it);
		}
	}
}
