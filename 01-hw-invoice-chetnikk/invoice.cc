/**
 *    @file: invoice.cc
 *  @author: Julian Stevovic // P100854577
 *    @date: 9/11/20
 *   @brief: cs2400 HW1, Hard Drive Invoice
 *  
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const double WESTERN_DIGITAL_PRICE = 90.0;
const double SEAGATE_PRICE = 95.0;

int main(int argc, char const *argv[]) {

    // Variable declaration
    int quantity;
    double discount;
    
    char typeinput;
    string typebrand;
    double typeprice;
    
    string ohio;   
    double tax;



    // Brand/quantity input
    cout << "Enter your desired hard drive type (w or s)" << endl;
    
    cin >> typeinput;

    if (typeinput == 'w')
    {
        typeinput = WESTERN_DIGITAL_PRICE;
        typebrand = "Western Digital";
        typeprice = WESTERN_DIGITAL_PRICE;

    }

    else if (typeinput == 's')
    {
        typeinput = SEAGATE_PRICE;
        typebrand = "Seagate";
        typeprice = SEAGATE_PRICE;
    }
    else
    {
        cout << "'" << typeinput << "'" << " Is not a valid hard drive type, Please try again with s or w." << endl;
        return 0;
    }
    
    cout << "Enter the amount of hard drives desired:";

    cin >> quantity;

    // Total price + discount

    double totalprice = quantity * typeinput;
 
    if (quantity >= 5)
    {
        discount = totalprice * .05;
    }
 
    // Ohio?

    cout << "Do you live in Ohio? (yes/no): ";
    cin >> ohio;

    if (ohio == "yes")
    {
        tax = (totalprice - discount) * 0.07;
        ohio = "Yes";
    }
    else if (ohio == "no")
    {
        tax = 0;
        ohio = "No";
    }
    else
    {
        cout << "'" << ohio << "'" << " is not a valid input, please try again with yes or no.";\
        return 0;
    }
    
    //Invoice

    cout << "" << endl;
    cout << "    -Hard Drive Invoice-" << endl;
    cout << "-----------------------------" << endl;
    cout << "  Drive brand: " << typebrand << endl;
    cout << "        Price: " << setprecision(2) << fixed << "$" << typeprice << endl; 
    cout << "Ohio Resident: " << ohio << endl;
    cout << "  Total price: " << setprecision(2) << fixed << "$" << totalprice << endl;
    cout << "-----------------------------" << endl;
    cout << "     Discount: " << setprecision(2) << fixed << "$" << discount << endl;
    cout << "     Subtotal: " << setprecision(2) << fixed << "$" << totalprice - discount << endl;
    cout << "        Taxes: " << setprecision(2) << fixed << "$" << tax << endl;
    cout << "=============================" << endl;
    cout << "        Total: " << setprecision(2) << fixed << "$" << (totalprice - discount) + tax << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "    Have a great day!" << endl;
    
    return 0;
}