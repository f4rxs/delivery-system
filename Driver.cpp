#include "Driver.h"
#include "Package.h"
#include "Envelope.h"

#include <iostream>
#include <string>

class Package;
class Envelope;
using namespace std;

Driver::Driver() : name("undefined"),
                   carRegistrationNb(""),
                   maxWeight(500),
                   maxVolume(50),
                   currentWeight(0),
                   currentVolume(0), zone(new int[2]{10000, 50000})
{
}

Driver::Driver(string name)
{
    setName(name);
    this->zone = new int[2]{10000, 50000};
    this->carRegistrationNb = "";
    this->maxWeight = 500;
    this->maxVolume = 50;
    this->currentWeight = 0;
    this->currentVolume = 0;
}

Driver::Driver(string name, string carRegistrationNb, double maxWeight, double maxVolume, int zone[])
{
    setName(name);
    setCarRegistrationNb(carRegistrationNb);
    setMaxWeight(maxWeight);
    setMaxVolume(maxVolume);
    this->zone = new int[2];
    this->zone[0] = zone[0];
    this->zone[1] = zone[1];
    this->currentWeight = 0;
    this->currentVolume = 0;
}

// getters
string Driver::getName() const
{
    return name;
}

vector<int> Driver::getZone() const
{
    return vector<int>{zone[0], zone[1]};
}

LListWithDummyNode<DeliveryItem> Driver::getDeliveries() const
{
    return deliveries;
}

string Driver::getCarRegistrationNb() const
{
    return carRegistrationNb;
}

double Driver::getMaxWeight() const
{
    return maxWeight;
}

double Driver::getMaxVolume() const
{
    return maxVolume;
}

double Driver::getCurrentWeight() const
{
    return currentWeight;
}

double Driver::getCurrentVolume() const
{
    return currentVolume;
}

// setters
void Driver::setName(const string &name)
{
    this->name = name;
}

void Driver::setZone(int zone[])
{
    this->zone[0] = zone[0];
    this->zone[1] = zone[1];
}

void Driver::setCarRegistrationNb(string carRegistrationNb)
{
    this->carRegistrationNb = carRegistrationNb;
}

void Driver::setMaxWeight(double maxWeight)
{
    this->maxWeight = maxWeight;
}

void Driver::setMaxVolume(double maxVolume)
{
    this->maxVolume = maxVolume;
}

bool Driver::assignDelivery(DeliveryItem item)
{
    if (item.getReceiverPostalCode() < zone[0] || item.getReceiverPostalCode() > zone[1])
    {
        cout << "Error: Item cannot be assigned to the driver. Delivery zone mismatch." << std::endl;
        return false;
    }

    if (Package *item = dynamic_cast<Package *>(item))
    {
        if (currentWeight + item->getWeight() > maxWeight ||
            currentVolume + item->getVolume() > maxVolume)
        {
            cout << "Error: Item cannot be assigned to the driver. Maximum weight or volume exceeded." << std::endl;
            return false;
        }

        deliveries.addAtBeg(*item);
        currentWeight += item->getWeight();
        currentVolume += item->getVolume();
    }
    else
    {

        deliveries.addAtBeg(*item);
        currentWeight += item->getWeight();
        currentVolume += item->getVolume();
    }
    return true;
}

bool Driver::accomplishDelivery(int serialNb)
{
    bool found = false;

    for (int i = 0; i < deliveries.getSize(); i++)
    {
        if (deliveries.getDataAtPos(i)->getReceiverPostalCode() == serialNb)
        {
            found = true;
            deliveries.deleteElement(*deliveries.getDataAtPos(i));
            return true;
        }
    }
    if (!found)
    {
        cout << "The item is not found";
        return false;
    }
}

string Driver::display() const
{

    string display = '[' + name + "]";
    display += "\nActive Zone: [" + to_string(zone[0]) + "-" + to_string(zone[1]) + "]";
    display += "Car:[" + carRegistrationNb + "]\n";
    display += "Max Weight: [" + to_string(maxWeight) + "]- Max Volume : [" + to_string(maxVolume) + "]\n\n";

    return display;
}