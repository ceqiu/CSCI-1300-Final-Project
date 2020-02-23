#include "converter.cpp"

void menu(){
	converter CONVERTER;
	string input;
	cout << "1. Converter" << endl;
	cout << "2. Find Currency" << endl;
	cout << "3. Print All Exchange Rate" << endl;
	cout << "4. Quit" << endl;
	cout << "-------------------------------------------------------" << endl;
	cin >> input;
	while(input != "4"){
		if(input == "1"){
			// 1. Converter
			cout << "-------------------------------------------------------" << endl;
			string A, B;
			cout << "Please Enter the first currency (ISO code): " << endl;
			cin >> A;
			cout << "Please Enter the second currency (ISO code): " << endl;
			cin >> B;
			CONVERTER.exchangeRate(A, B);
		}
		else if(input == "2"){
			cout << "-------------------------------------------------------" << endl;
			// 2. Find Currency
			string currency;
			cout << "Please Enter the currency (ISO code): " << endl;
			cin >> currency;
			CONVERTER.printOne(currency);
		}
		else if(input == "3"){
			cout << "-------------------------------------------------------" << endl;
			// 3. Print All Exchange Rate
			string basic;
			cout << "Please Enter the baisc currency (ISO code): " << endl;
			cin >> basic;
			bool flag = CONVERTER.printAll(basic);
			if(flag == true){
				string ifPrint;
				cout << "Do you want to export this table? Input 'y' for yes, else no." << endl;
				cin >> ifPrint;
				if(ifPrint == "y"){
					string filename;
					cout << "Please enter the filename: " << endl;
					cin >> filename;
					filename += ".txt";
					CONVERTER.exportRate(basic, filename);
				}
			}
		}
		else{
			// Invalid input
			cout << input << " is not a valid input, Please select following choice:" << endl;
		}
		cout << "-------------------------------------------------------" << endl;
		cout << "1. Converter" << endl;
		cout << "2. Find Currency" << endl;
		cout << "3. Print All Exchange Rate" << endl;
		cout << "4. Quit" << endl;
		cin >> input;
	}
}