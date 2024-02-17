#include "Envelope.h"
#include <iostream>
#include <string>
using namespace std;

Envelope::Envelope(string senderName, string receiverName, int receiverPostalCode, string size)
    : DeliveryItem(senderName, receiverName, receiverPostalCode), size(size)
{
}

Envelope::Envelope(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode, string size)
    : DeliveryItem(senderName, senderPostalCode, receiverName, receiverPostalCode), size(size)
{
}

void Envelope::setSize(string newSize)
{
    if (newSize == "A2" || newSize == "A6" || newSize == "A7" || newSize == "A9" || newSize == "3 square" || newSize == "4 square" || newSize == "5 square")
    {
        size = newSize;
        setCost();
    }
    else
    {
        cout << "Invalid size: " << newSize << endl;
    }
}

string Envelope::getSize() const
{

    return size;
}

void Envelope::setCost()
{
    double cost = getCost();
    if (size == "A2")
    {
        cost = 2;
    }
    else if (size == "A6")
    {
        cost = 1.6;
    }
    else if (size == "A7")
    {
        cost = 1.7;
    }
    else if (size == "A9")
    {
        cost = 1.9;
    }
    else if (size == "4 square")
    {
        cost = 1.8;
    }
    else if (size == "5 square")
    {
        cost = 1.6;
    }

    if (getInsurance())
    {
        cost += 3;
    }
}

string Envelope::display() const
{
    string insuranceStatus = (getInsurance()) ? "With Insurance" : "Without Insurance";
    string statusString;

    switch (getStatus())
    {
    case 'R':
        statusString = "Received";
        break;
    case 'A':
        statusString = "Assigned";
        break;
    case 'D':
        statusString = "Delivered";
        break;
    default:
        statusString = "Unknown";
    }

    char buffer[80];
    auto timePoint = chrono::system_clock::to_time_t(getDate());
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&timePoint));

    string display = "Envelope: [" + to_string(getSerialNumber()) + "] - [" + string(buffer) + "]\n";
    display += "Size: " + getSize() + "\n";
    display += "Sender: " + getSenderName() + " - " + to_string(getSenderPostalCode()) + "\n";
    display += "Receiver: " + getReceiverName() + " - " + to_string(getReceiverPostalCode()) + "\n";
    display += "[" + insuranceStatus + "]\n";
    display += "Status: " + statusString + "\n";
    display += "Cost: $" + to_string(getCost());

    return display;
}