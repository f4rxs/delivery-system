#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "DeliveryItem.h"
#include <iostream>

using namespace std;

class Envelope : public DeliveryItem
{
public:
    Envelope(string senderName, string receiverName, int receiverPostalCode, string size);
    Envelope(string senderName, int senderPostalCode, string receiverName, int receiverPostalCode, string size);
    void setSize(string size);
    string getSize() const;
    string display() const;

private:
    string size;
    void setCost();

};

#endif