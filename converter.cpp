#include "converter.h"

/* Constructor & distructor */

converter::converter(){
	initInfo();
}

converter::~converter(){}

/* Public functions */

/*
PARAMETERS
	currencyA : (STRING) The ISO code for a currency
	currencyB : (STRING) The ISO code for a currency
NOTES
	It will print the exchange rate in "100 A = ? B" and "100 B = ? A" if the ISO code exist. Otherwise will tell user they put wrong ISO code.
*/
void converter::exchangeRate(string currencyA, string currencyB){
	// Find the index of the currency A & B in data
	int a = -1;
	int b = -1;
	for(int i = 0; i < 155; i ++){
		if(a != -1 && b != -1){
			break;
		}
		if(currencyInfo[i][0] == currencyA){
			a = i;
		}
		if(currencyInfo[i][0] == currencyB){
			b = i;
		}
	}
	// Check if both currency exist
	if(a == -1){
		cout << "Sorry, the currency " << currencyA << " does not exist." << endl;
	}
	else if(b == -1){
		cout << "Sorry, the currency " << currencyB << " does not exist." << endl;
	}
	else{
		cout << "100 " << currencyA << " = " << (currencyRate[a] / currencyRate[b]) * 100 << " " << currencyB << endl;
		cout << "100 " << currencyB << " = " << (currencyRate[b] / currencyRate[a]) * 100 << " " << currencyA << endl;
	}
}

/*
PARAMETERS
	currency : (STRING) The ISO code for a currency
	filename : (STRING) The filename for export data
NOTES
	It will export the exchange rate depending on select currency into a file named filename
*/
void converter::exportRate(string currency, string filename){
	ofstream output;
	output.open(filename);
	if(output.is_open() == true){
		int i = -1;
		for(int j = 0; j < 155; j ++){
			if(currencyInfo[j][0] == currency){
				i = j;
				break;
			}
		}
		for(int k = 0; i < 155; k ++){
			if(k != i){
				output << "100 " << currencyInfo[k][0] << " = " << (currencyRate[k] / currencyRate[i]) * 100 << " " << currencyInfo[i][0] << endl;
			}
		}
		output.close();
	}
}

/*
PARAMETERS
	basicCurrency : (STRING) The ISO code of a currency
RETURNS
	Return a bool value: true if the ISO code exist otherwise false
NOTES
	Using helpPrintAll function to print all the currency rate depending on basicCurrency if the ISO code exist. Otherwise will tell user they put wrong ISO code.
*/
bool converter::printAll(string basicCurrency){
	// Find the index of the basic currency in data
	int i = -1;
	for(int j = 0; j < 155; j ++){
		if(currencyInfo[j][0] == basicCurrency){
			i = j;
			break;
		}
	}
	// Check if currency exist
	if(i == -1){
		cout << "Sorry, the currency " << basicCurrency << " does not exist." << endl;
		return false;
	}
	else{
		helpPrintAll(i);
		return true;
	}
}

/*
PARAMETERS
	currency : (STRING) The ISO code of a currency
NOTES
	Using helpPrintOne function to print out the information of the currency if the ISO code exist. Otherwise will tell user they put wrong ISO code.
*/
void converter::printOne(string currency){
	// Find the index of the currency in data
	int i = -1;
	for(int j = 0; j < 155; j ++){
		if(currencyInfo[j][0] == currency){
			i = j;
			break;
		}
	}
	// Check if currency exist
	if(i == -1){
		cout << "Sorry, the currency " << currency << " does not exist." << endl;
	}
	else{
		helpPrintOne(i);
	}
}

/*
PARAMETERS
	i : (INT) The index of the currency
NOTES
	Print all the exchange rate depending on the select currency by the index i
*/
void converter::helpPrintAll(int i){
	for(int j = 0; j < 155; j ++){
		if(j != i){
			cout << "100 " << currencyInfo[j][0] << " = " << (currencyRate[j] / currencyRate[i]) * 100 << " " << currencyInfo[i][0] << endl;
		}
	}
}

/*
PARAMETERS
	i : (INT) The index of the currency
NOTES
	Print the information of the select currency by the index i
*/
void converter::helpPrintOne(int i){
	cout << "ISO code: " << currencyInfo[i][0] << endl;
	cout << "Currency name: " << currencyInfo[i][1] << endl;
	cout << "Locality: " << currencyInfo[i][2] << endl;
}

/*
NOTES
	Initializing the database by read the file "currency.txt"
*/
void converter::initInfo(){
	ifstream dataFile;
	dataFile.open("currency.txt");
	if(dataFile.is_open() == true){
		string line;
		int n = 0;
		while(getline(dataFile, line)){
			string words[4];
			split(line, words);
			for(int i = 0; i < 3; i ++){
				currencyInfo[n][i] = words[i];
			}
			stringstream ss;
			float f;
			ss << words[3];
			ss >> f;
			currencyRate[n] = f;
			n ++;
		}
		dataFile.close();
	}
}

/*
PARAMETERS
	line  : (INT) The index of the currency
	words : (1D STRING ARRAY) The array to save splited words
NOTES
	It will split the readed line into 4 different words
*/
void converter::split(string line, string words[4]){
	string w = "";
	int n = 0;
	for(int i = 0; i < line.length(); i ++){
		if(line[i] != '|'){
			w += line[i];
		}
		else{
			words[n] = w;
			w = "";
			n ++;
		}
	}
	words[n] = w;
}