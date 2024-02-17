#ifndef PACKAGE_H
#define PACKAGE_H

#include "DeliveryItem.h"
#include <iostream>
using namespace std;

class Package : public DeliveryItem
{
public:
    Package(string senderName, string receiverName, int receiverPostalCode, double height, double width, double length, double weight);
    Package(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode, double height, double width, double length, double weight);

    double getHeight() const;
    double getWidth() const;
    double getLength() const;
    double getVolume() const;
    double getWeight() const;
    string display() const;

private:
    double height;
    double width;
    double length;
    double volume;
    double weight;

    void setCost();
    void setVolume();
};

#endif
