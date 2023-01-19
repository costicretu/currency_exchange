#include "ExchangeCalculator.h"
#include "FileReader.h"

double ExchangeCalculator::Convert(double amount, string from_, string to_)
{
	
	return amount* FileReader::getCurrency(from_, to_);
}