#ifndef DELIVERYITEM_H
#define DELIVERYITEM_H

#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

class DeliveryItem
{
public:
    DeliveryItem();
    DeliveryItem(string senderName, string receiverName, int receiverPostalCode);
    DeliveryItem(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode);
   virtual ~DeliveryItem();

    int getSerialNumber() const;
    char getStatus() const;
    string getSenderName() const;
    string getReceiverName() const;
    int getSenderPostalCode() const;
    int getReceiverPostalCode() const;
    double getCost() const;
    bool getInsurance() const;
    chrono::system_clock::time_point getDate() const;

    void setStatus(char status);
    void addInsurance();
    void cancelInsurance();
    string display() const;

    DeliveryItem &operator=(const DeliveryItem &other);

    bool operator==(const DeliveryItem &other);

private:
    static int serialGenerator;
    int serialNumber;
    char status;
    string senderName;
    string receiverName;
    int senderPostalCode;
    int receiverPostalCode;
    double cost;
    bool insurance;
    chrono::system_clock::time_point date;
};

#endif
