#include <iostream>
#include <string>
using namespace std;

bool ask_if_yes(string question)
{
	bool ret;
	string answer;
	cout << question << endl;
	do {
		cout<< "Enter y or n: ";
		cin >> answer;
	} while ("y" != answer && "Y" != answer && "n" != answer && "N" != answer);
	
	if ("y" == answer || "Y" == answer) {
		ret = true;
	}	else {
		ret = false;
	}

	return ret;
}

int main (int argc, char* argv[])
{
    int price, count;
    double discount;
	string message, yon, gift;
    cout << "What is the price of the order, in cents?" << endl;
    cin >> price;
    cout << "How many items are in the purchase?" << endl;
    cin >> count;
	
    if ((price >= 2500) && (count >= 5)) {
        discount = .9;
    } else {
        discount = 1;
    }
	
    price *= discount;
	
	if (price > 10000) {
		bool cont = ask_if_yes ("Your order is over $100. Do you want to continue?");
		if (!cont) {
			cout << "Your order has been terminated.";
			return 1;
		}
    }
	
	bool is_gift = ask_if_yes("Is this a gift?");
	if (is_gift) {
		cout << "What is your message?" << endl;
		cin >> message;
	}
	
	cout << "The sale price is $" << price/100 << "." << price%100 << endl;
	
	if (is_gift) {
		cout << "Your message: " << message << endl;
	}
	
    return 0;
}