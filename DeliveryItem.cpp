#include "DeliveryItem.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int DeliveryItem::serialGenerator = 1000;

DeliveryItem::DeliveryItem()
    : serialNumber(serialGenerator++),
      date(std::chrono::system_clock::now()),
      status('R'),
      senderName(""),
      receiverName(""),
      senderPostalCode(10000),
      receiverPostalCode(10000),
      cost(2),
      insurance(false)
{
}

DeliveryItem::DeliveryItem(string senderName, string receiverName, int receiverPostalCode)
    : senderName(senderName), receiverName(receiverName), senderPostalCode(10000), receiverPostalCode(receiverPostalCode),
      cost(2), insurance(false)
{
    this->serialNumber = serialGenerator++;
    this->date = chrono::system_clock::now();
    this->status = 'R';
}

DeliveryItem::DeliveryItem(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode)
    : senderName(senderName), senderPostalCode(senderPostalCode), receiverName(receiverName),
      receiverPostalCode(receiverPostalCode), cost(2), insurance(false)
{
    this->serialNumber = serialGenerator++;
    this->date = chrono::system_clock::now();
    this->status = 'R';
}

DeliveryItem ::~DeliveryItem()
{
}

// Getters
int DeliveryItem::getSerialNumber() const { return serialNumber; }
char DeliveryItem::getStatus() const { return status; }
string DeliveryItem::getSenderName() const { return senderName; }
string DeliveryItem::getReceiverName() const { return receiverName; }
int DeliveryItem::getSenderPostalCode() const { return senderPostalCode; }
int DeliveryItem::getReceiverPostalCode() const { return receiverPostalCode; }
double DeliveryItem::getCost() const { return cost; }
bool DeliveryItem::getInsurance() const { return insurance; }
chrono::system_clock::time_point DeliveryItem::getDate() const { return date; }

// Setters
void DeliveryItem::setStatus(char status)
{
    if (status == 'R' || status == 'A' || status == 'D')
    {
        this->status = status;
    }
    else
    {
        cout << "Invalid input for status (R, A, D)" << endl;
    }
}

// Methods
void DeliveryItem::addInsurance()
{
    this->insurance = true;
    this->cost += 3;
}

void DeliveryItem::cancelInsurance()
{
    this->insurance = false;
    this->cost -= 3;
}

DeliveryItem &DeliveryItem::operator=(const DeliveryItem &other)
{
    if (this != &other)
    {

        this->serialNumber = other.serialNumber;
        this->date = other.date;
        this->status = other.status;
        this->senderName = other.senderName;
        this->receiverName = other.receiverName;
        this->senderPostalCode = other.senderPostalCode;
        this->receiverPostalCode = other.receiverPostalCode;
        this->cost = other.cost;
        this->insurance = other.insurance;
    }

    return *this;
}

bool DeliveryItem::operator==(const DeliveryItem &other)
{

    return this->serialNumber == other.serialNumber;
}

string DeliveryItem::display() const
{
    string insuranceStatus = (insurance) ? "With Insurance" : "Without Insurance";
    string statusString;

    switch (status)
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
    auto timePoint = chrono::system_clock::to_time_t(date);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&timePoint));

    string display = "\n[" + to_string(serialNumber) + "] - [" + string(buffer) + "]\n";
    display += "Sender: " + senderName + " - " + to_string(senderPostalCode) + "\n";
    display += "Receiver: " + receiverName + " - " + to_string(receiverPostalCode) + "\n";
    display += "[" + insuranceStatus + "]\n";
    display += "Status: " + statusString + "\n";

    return display;
}
