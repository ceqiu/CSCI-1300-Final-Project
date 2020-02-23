#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#ifndef CONVERTER_H
#define CONVERTER_H

/*
converter (CLASS)
FUNCTIONS:
	exchangeRate : Find the exchange rate between two currency ISO code "100 A = ? B" and "100 B = ? A"
	exportRate   : Export the exchange rate (depending on which basic currency user using) into a file named "filename.txt"
	printAll     : Print the full currency exchange rate by the basic currency ISO code
	printOne     : Find the information of a currency by the ISO code
*/
class converter{
public:
	/* Constructor & distructor */
	converter();
	~converter();
	/* Public functions */
	void exchangeRate(string currencyA, string currencyB);
	void exportRate(string currency, string filename);
	bool printAll(string basicCurrency);
	void printOne(string currency);
private:
	/*
	Data elements
		currencyInfo : (2D STRING ARRAY) Saving the ISO codes, names and countries/areas of a currency
		currencyRate : (STRING ARRAY) Saving the exchange rate (to USD) of a currency
	*/
	string currencyInfo[155][3];
	float currencyRate[155];
	/* Private functions */
	void helpPrintAll(int i);
	void helpPrintOne(int i);
	void initInfo();
	void split(string line, string words[4]);
};

#endif