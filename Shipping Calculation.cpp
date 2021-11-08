//---------------------------------------------------------------------------------
//
// Title:          Shipping Calculation
// Lab Course:     ITCS 2530 V0801 2021FA
// Author:         Ivan Baydov
// Date:           11/7/2021
//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Output stream formats
const int COLFMT1 = 50; 
const int COLFMT2 = 40;

// Declare shipping price tiers
const double FREE_SHIPPING = 150.0;
const double SHIP_TIER_1 = 100.0;
const double SHIP_TIER_2 = 50.0;
const double REG_SHIP = 0;

// Extra cost for fragile shipping
const double FRAGILE_SHIP = 2;

// Declare shipping amounts
const double FREE = 0;
const double USA_1 = 12.00;
const double USA_2 = 9.00;
const double USA_REG = 6.00;

const double CAD_1 = 15.00;
const double CAD_2 = 12.00;
const double CAD_REG = 8.00;

const double AUS_1 = 17.00;
const double AUS_2 = 14.00;
const double AUS_REG = 10.00;

//adding const for Pluto
const double PLUTO_1 = 500.00;
const double PLUTO_2 = 250.00;
const double PLUTO_REG = 150.00;



int main()
{
    // Declare user input variables
    string ItemName;
    string Fragile;
    double OrderTotal;
    double Shipping;
    string Destination;

    // Formats numbers to 2 decimal points
    cout << fixed << setprecision(2);

    // Prints header
    cout << setw(COLFMT1) << setfill('.') << "." << endl
        << "ITCS 2530 - Programming Assignment for week #3" << endl
        << setw(COLFMT1) << "." << endl;

    // Input for item name
    cout << left << setw(COLFMT1) << "Please enter the item name (no spaces)" << ":";
    cin >> ItemName;
    // Format to upper case
    transform(ItemName.begin(), ItemName.end(), ItemName.begin(), ::toupper);

    // Input for fragile
    cout << setw(COLFMT1) << "Is the item fragile? (y=yes/n=no)" << ":";
    cin >> Fragile;
    // Format to upper case
    transform(Fragile.begin(), Fragile.end(), Fragile.begin(), ::toupper);
    // Make sure fragile is Y or N
    if (Fragile != "Y" && Fragile != "N")
    {
        cout << "Invalid entry, exiting";
        return 0;
    }

    // Input for order total
    cout << setw(COLFMT1) << "Please enter your order total" << ":";
    cin >> OrderTotal;

    // Input for destination
    cout << setw(COLFMT1) << "Please enter destination. (usa/can/aus/pluto)" << ":";
    cin >> Destination;
    // Format to upper case
    transform(Destination.begin(), Destination.end(), Destination.begin(), ::toupper);

    // Ensure destination is USA, CAN, or AUS
    if (Destination != "USA" && Destination != "CAN" && Destination != "AUS" && Destination != "PLUTO")
    {
        cout << "Invalid entry, exiting";
        return 0;
    }
    cout << endl;

    // For free shipping
    if (OrderTotal > FREE_SHIPPING)
    {
        Shipping = FREE;
    }
    // For tier 1 shipping
    else if (OrderTotal > SHIP_TIER_1)
    {
        if (Destination == "USA")
            Shipping = USA_1;
        else if (Destination == "CAN")
            Shipping = CAD_1;
        else if (Destination == "AUS")
            Shipping = AUS_1;
        else if (Destination == "PLUTO")
            Shipping = PLUTO_1;

    }
    // For tier 2 shipping
    else if (OrderTotal > SHIP_TIER_2)
    {
        if (Destination == "USA")
            Shipping = USA_2;
        else if (Destination == "CAN")
            Shipping = CAD_2;
        else if (Destination == "AUS")
            Shipping = AUS_2;
        else if (Destination == "PLUTO")
            Shipping = PLUTO_2;

    }
    // For regular shipping
    else if (OrderTotal > REG_SHIP)
    {
        if (Destination == "USA")
            Shipping = USA_REG;
        else if (Destination == "CAN")
            Shipping = CAD_REG;
        else if (Destination == "AUS")
            Shipping = AUS_REG;
        else if (Destination == "PLUTO")
            Shipping = PLUTO_REG;

    }

    // Adds extra fragile shipping cost if item is fragile
    if (Fragile == "Y")
    {
        Shipping = Shipping + FRAGILE_SHIP;
    }

    // Calculate the full total
    OrderTotal = Shipping + OrderTotal;

    // Print output to console
    cout << setw(COLFMT2) << "Your item is" << ItemName << endl
        << setw(COLFMT2) << "Your shipping cost is" << "$" << Shipping << endl
        << setw(COLFMT2) << "You are shipping to" << Destination << endl
        << setw(COLFMT2) << "Your total shipping costs are" << "$" << OrderTotal << endl
        << endl
        << setw(COLFMT2) << setfill('-') << "-" << "Thank You!";

    // Create output file stream
    ofstream OutputStream;
    // Open output file stream
    OutputStream.open("Order.txt");

    // Print to output file
    OutputStream << left << fixed << setprecision(2)
        << setfill('.') << setw(COLFMT2) << "Your item is" << ItemName << endl
        << setw(COLFMT2) << "Your shipping cost is" << "$" << Shipping << endl
        << setw(COLFMT2) << "You are shipping to" << Destination << endl
        << setw(COLFMT2) << "Your total shipping costs are" << "$" << OrderTotal << endl
        << endl
        << setw(COLFMT2) << setfill('-') << "-" << "Thank You!";

    // Close output file stream
    OutputStream.close();
}
