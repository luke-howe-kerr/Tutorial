#include <iostream>
#include <string>
using namespace std;

bool ret;
string answer;

//Determining a yes or no answer
bool ask_if_yes(string question)
{
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
	
	//Determining if there is a discount
    if ((price >= 2500) && (count >= 5)) {
        discount = .9;
    } else {
        discount = 1;
    }
	
    price *= discount;
	
	//Warning for orders over $100
	if (price > 10000) {
		bool cont = ask_if_yes ("Your order is over $100. Do you want to continue?");
		if (!cont) {
			cout << "Your order has been terminated.";
			return 1;
		}
    }
	
	//Asks if you want to make it a gift and asks for your message
	ask_if_yes("Is this a gift?");
	if (ret) {
		cout << "What is your message?" << endl;
		cin >> message;
		cout << "Your message: " << message << endl;
	}
	
	cout << "The sale price is $" << price/100 << "." << price%100 << endl;
	
    return 0;
}