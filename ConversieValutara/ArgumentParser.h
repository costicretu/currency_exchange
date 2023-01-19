#pragma once
#include <string>
#include<vector>
#include <map>
#include <functional>
using namespace std;
class ArgumentParser
{
public:
	ArgumentParser(int argc, char* argv[]);
	void ListAllValidArguments() const;
	void LoadCurrencyFromFile(string fileName) const;
	void HelpArguments(string nothing = nullptr) const;
	void ShowCurrencyExchange(string nothing = nullptr) const;
private:
	vector<string> arguments;
	static map<string, function<void(ArgumentParser&, string)>> validArguments;
	static function<void(ArgumentParser&, string)> help;
	static function<void(ArgumentParser&, string)> file;
	static function<void(ArgumentParser&, string)> currency;
	void ParseArguments();
};

