#include <iostream>
#include <cstdlib>
#include "Driver.h"
#include "Package.h"
#include "Envelope.h"
#include "LListWithDummyNode.h"
#include "DeliveryItem.h"

using namespace std;

int main()
{

	LListWithDummyNode<Driver> drivers;
	LListWithDummyNode<DeliveryItem> deliveyItems;

	int choice;

	while (true)
	{
		cout << "\n1. Add new Driver" << endl;
		cout << "2. Receive new item" << endl;
		cout << "3. Display all items (received - assigned - delivered)" << endl;
		cout << "4. Display all received items" << endl;
		cout << "5. Display all assigned items" << endl;
		cout << "6. Display all delivered items" << endl;
		cout << "7. Display all drivers" << endl;
		cout << "8. Assign item to a driver" << endl;
		cout << "9. Set item to Delivered" << endl;
		cout << "10. Check a driver load" << endl;
		cout << "11. Display total cost" << endl;
		cout << "12. Exit the program\n"
			 << endl;

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string driverName;
			string carRegistrationNumber;
			double maxWeight;
			double maxVolume;
			int zone1;
			int zone2;

			// Input validation
			cout << "Enter the name of the Driver: ";
			cin >> driverName;

			cout << "Enter the car registration number: ";
			cin >> carRegistrationNumber;

			cout << "Enter the max weight: ";
			while (!(cin >> maxWeight) || maxWeight <= 0)
			{
				cout << "Invalid input. Please enter a positive number for max weight: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cout << "Enter the max volume: ";
			while (!(cin >> maxVolume) || maxVolume <= 0)
			{
				cout << "Invalid input. Please enter a positive number for max volume: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cout << "Assign a zone (Enter zone 1 and zone 2): ";
			while (!(cin >> zone1 >> zone2) || zone1 >= zone2)
			{
				cout << "Invalid input. Please enter two valid postal codes (zone1 < zone2): ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			int zone[] = {zone1, zone2};

			Driver newDriver(driverName, carRegistrationNumber, maxWeight, maxVolume, zone);

			drivers.addAtBeg(newDriver);
			cout << "Driver " << driverName << " is added successfully." << endl;
		}
		break;

		case 2:
		{
			char itemType;
			cout << "Enter the type of the item (P for package, E for envelope): ";
			cin >> itemType;

			string senderName, receiverName;
			int senderPostalCode, receiverPostalCode;
			cout << "Enter the sender name: ";
			cin >> senderName;
			cout << "Enter the receiver name: ";
			cin >> receiverName;
			cout << "Enter the sender postal code: ";
			cin >> senderPostalCode;
			cout << "Enter the receiver postal code: ";
			cin >> receiverPostalCode;

			DeliveryItem *newItem = nullptr;

			switch (tolower(itemType))
			{
			case 'p':
			{
				double height, width, length, weight;
				cout << "Enter the height: ";
				cin >> height;
				cout << "Enter the width: ";
				cin >> width;
				cout << "Enter the length: ";
				cin >> length;
				cout << "Enter the weight: ";
				cin >> weight;

				char insuranceChoice;
				cout << "Do you want to add insurance? (Y for yes, N for no): ";
				cin >> insuranceChoice;

				Package packageItem(senderName, receiverName, receiverPostalCode, height, width, length, weight);
				if (tolower(insuranceChoice) == 'y')
					packageItem.addInsurance();

				newItem = &packageItem;
				break;
			}
			case 'e':
			{
				string size;
				cout << "Enter the size of the Envelope (A2, A6, A7, A9, 3 square, 4 square, 5 square): ";
				cin >> size;

				char insuranceChoice;
				cout << "Do you want to add insurance? (Y for yes, N for no): ";
				cin >> insuranceChoice;

				Envelope envelopeItem(senderName, senderPostalCode, receiverName, receiverPostalCode, size);
				if (tolower(insuranceChoice) == 'y')
					envelopeItem.addInsurance();

				newItem = &envelopeItem;
				break;
			}
			default:
				cout << "Wrong option. Please enter P or E." << endl;
				break;
			}

			if (newItem != nullptr)
			{
				deliveyItems.addAtBeg(*newItem);
				cout << "Item added successfully." << endl;
			}
		}
		break;
		case 3:
		// logical error in displaying (issue with polymorphism)
			// Display all items (received - assigned - delivered)
			// for (int i = 0; i < deliveyItems.getSize(); i++)
			// {
			// 	DeliveryItem *itemPtr = deliveyItems.getDataAtPos(i);
			// 	if (dynamic_cast<Package *>(itemPtr) != nullptr)
			// 	{
			// 		cout << "Found a Package item" << endl;
			// 		Package *packagePtr = dynamic_cast<Package *>(itemPtr);
			// 		cout << packagePtr->display() << endl;
			// 	}
			// 	else if (dynamic_cast<Envelope *>(itemPtr) != nullptr)
			// 	{
			// 		cout << "Found an Envelope item" << endl;
			// 		Envelope *envelopePtr = dynamic_cast<Envelope *>(itemPtr);
			// 		cout << envelopePtr->display() << endl;
			// 	}
			// 	else
			// 	{
			// 		cout << "Unknown item type" << endl;
			// 	}
			// }
			for (int i = 0; i < deliveyItems.getSize(); i++)
			{
				cout << deliveyItems.getDataAtPos(i)->display();
			}

			break;
		case 4:
			// Display all received items
			{
				bool found = false;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					DeliveryItem *itemPtr = deliveyItems.getDataAtPos(i);
					if (itemPtr->getStatus() == 'R')
					{
						found = true;
						cout << itemPtr->display();
					}
				}
				if (!found)
					cout << "\nNo recieved items found" << endl;
			}
			break;
		case 5:
			// Display all assigned items
			{
				bool found = false;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					DeliveryItem *itemPtr = deliveyItems.getDataAtPos(i);
					if (itemPtr->getStatus() == 'A')
					{
						found = true;
						cout << itemPtr->display();
					}
				}
				if (!found)
					cout << "\nNo assigned  items found" << endl;
			}
			break;
		case 6:
			// Display all delivered items
			{
				bool found = false;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					DeliveryItem *itemPtr = deliveyItems.getDataAtPos(i);
					if (itemPtr->getStatus() == 'D')
					{
						found = true;
						cout << itemPtr->display();
					}
				}
				if (!found)
					cout << "\nNo delivered  items found" << endl;
			}
			break;
		case 7:
			// Display all drivers
			{
				for (int i = 0; i < drivers.getSize(); i++)
					cout << drivers.getDataAtPos(i)->display();
			}
			break;
		case 8:
			//  assign an item to a driver
			{
				int serialNumber;
				cout << "Enter the item Serial number: ";
				cin >> serialNumber;

				// Find the item
				int indexOfTheItem = -1;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					if (deliveyItems.getDataAtPos(i)->getSerialNumber() == serialNumber)
					{
						indexOfTheItem = i;
						break;
					}
				}

				if (indexOfTheItem == -1)
				{
					cout << "Item with serial number " << serialNumber << " not found." << endl;
					break;
				}

				DeliveryItem *itemPtr = deliveyItems.getDataAtPos(indexOfTheItem);

				string driverName;
				cout << "Enter the name of the driver to assign the item to: ";
				cin >> driverName;

				// Find the driver
				bool driverFound = false;
				for (int i = 0; i < drivers.getSize(); i++)
				{
					Driver *driverPtr = drivers.getDataAtPos(i);
					if (driverPtr->getName() == driverName)
					{
						driverFound = true;
						cout << "Driver " << driverName << " found. Assigning the item..." << endl;
						if (driverPtr->assignDelivery(*itemPtr))
						{
							cout << "Item assigned successfully." << endl;
							itemPtr->setStatus('A');
						}
						else
						{
							cout << "Failed to assign the item to the driver." << endl;
						}
						break;
					}
				}

				if (!driverFound)
				{
					cout << "Driver " << driverName << " not found. Please enter a valid driver name." << endl;
				}
			}
			break;

		case 9:
			// Set item to be delivered
			{
				int serialNumber;
				cout << "Enter the serial number of the item : " << endl;
				cin >> serialNumber;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					DeliveryItem *itemPtr = deliveyItems.getDataAtPos(i);
					if (serialNumber == itemPtr->getSerialNumber())
					{
						itemPtr->setStatus('D');
						cout << "Item is set to Delivered succsessfully.";
						break;
					}
					else
					{
						cout << "The item with the serial number " << serialNumber << " is either already Delivered or not found\n";
					}
				}
			}

			break;
		case 10:
			// check the driver load
			{
				string driverName;
				bool foundDriver = false;
				cout << "Enter the driver name to check the load : ";
				cin >> driverName;
				for (int i = 0; i < drivers.getSize(); i++)
				{
					Driver *driverPtr = drivers.getDataAtPos(i);
					if (driverPtr->getName() == driverName)
					{
						foundDriver = true;
						cout << driverPtr->getDeliveries().getDataAtPos(i)->display();
						break;
					}
				}
				if (!foundDriver)
				{
					cout << "The driver with the name " << driverName << " is not found" << endl;
				}
			}
			break;
		case 11:
			// Display total cost
			{
				// logical error with the cost 
				double cost = 0;
				for (int i = 0; i < deliveyItems.getSize(); i++)
				{
					cost += deliveyItems.getDataAtPos(i)->getCost();
				}
				cout << "The total cost of the items is : " << cost << endl;
			}
			break;
		case 12:
			cout << "Program terminated\n";
			exit(0);
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}
