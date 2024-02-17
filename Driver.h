#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <vector>
#include "LListWithDummyNode.h"

class DeliveryItem;

using namespace std;

class Driver
{
public:
    Driver();
    Driver(string name);
    Driver(string name, string carRegistrationNb, double maxWeight, double maxVolume, int zone[]);

    string getName() const;
    vector<int> getZone() const;
    LListWithDummyNode<DeliveryItem> getDeliveries() const;
    string getCarRegistrationNb() const;
    double getMaxWeight() const;
    double getMaxVolume() const;
    double getCurrentWeight() const;
    double getCurrentVolume() const;

    void setName(const string &name);
    void setZone(int zone[]);
    void setCarRegistrationNb(string carRegistrationNb);
    void setMaxWeight(double maxWeight);
    void setMaxVolume(double maxVolume);

    bool assignDelivery(DeliveryItem item);
    bool accomplishDelivery(int serialNb);

    string display() const;

private:
    string name;
    int *zone;
    LListWithDummyNode<DeliveryItem> deliveries;
    string carRegistrationNb;
    double maxWeight;
    double maxVolume;
    double currentWeight;
    double currentVolume;
};

#endif
