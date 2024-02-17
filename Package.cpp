#include "Package.h"
#include <iostream>
#include <string>
using namespace std;

Package::Package(string senderName, string receiverName, int receiverPostalCode, double height, double width, double length, double weight)
    : DeliveryItem(senderName, receiverName, receiverPostalCode), height(height), width(width), length(length), weight(weight)
{
    setVolume();
    setCost();
}

Package::Package(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode, double height, double width, double length, double weight)
    : DeliveryItem(senderName, senderPostalCode, receiverName, receiverPostalCode), height(height), width(width), length(length), weight(weight)
{
    setVolume();
    setCost();
}

// getters
double Package::getHeight() const
{
    return height;
}

double Package::getWidth() const
{
    return width;
}

double Package::getLength() const
{
    return length;
}
double Package::getVolume() const
{
    return volume;
}
double Package::getWeight() const
{
    return weight;
}

void Package::setCost()
{

    double cost;
    if (volume <= 2)
    {
        cost = 2 + 3 * weight;
    }
    else if (volume > 2 && volume <= 5)
    {
        cost = 2.8 + 3 * weight;
    }
    else
    {
        cost = 2.8 + 3 * weight + 5 * (volume - 5);
    }

    if (getInsurance() == true)
    {
        cost += 20 * weight;
    }
}

void Package::setVolume()
{
    this->volume = length * width * height;
}

string Package::display() const
{

    string insuranceStatus = (getInsurance()) ? "With insurance" : "Without insurance";
    string statusOfThePackage;

    switch (getStatus())
    {
    case 'R':
        statusOfThePackage = "Received";
        break;
    case 'A':
        statusOfThePackage = "Assigned";
        break;
    case 'D':
        statusOfThePackage = "Delivered";
        break;
    default:
        statusOfThePackage = "Unknown";
    }
    char buffer[80];
    auto timePoint = chrono::system_clock::to_time_t(getDate());
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&timePoint));

    string display = "[" + to_string(getSerialNumber()) + "] - [" + string(buffer) + "]";
    display += "\nDimension:[" + to_string(getHeight()) + "]*[" + to_string(getWidth()) + "]*[" + to_string(getLength()) + "]";
    display += "\nVolume:[" + to_string(volume) + "]-Weight: [" + to_string(getWeight()) + "]";
    display += "\nSender:[" + getSenderName() + "]-[" + to_string(getSenderPostalCode()) + "]";
    display += "\nReceiver:[" + getReceiverName() + "]-[" + to_string(getReceiverPostalCode()) + "]";
    display += "\n[" + insuranceStatus + "]\nStatus:[" + statusOfThePackage + "]";
    display += "Cost:[" + to_string(getCost()) + "]";

    return display;
}