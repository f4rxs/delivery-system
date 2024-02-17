/******************************************************************************
 * Implementation of linked list with dummy node class
 *
 * lListWithDummyNode: defualt constructor.
 * lListWithDummyNode: copy constructor.
 * ~lListWithDummyNode: destructor.
 * isEmpty: check if the linked list is empty.
 * getSize: getter of the linked list's size.
 * addAtBeg: adds a new  element at the begining of the linked list.
 * addAtEnd: adds a new element at the end of the linked list.
 * addAtPosition: adds a new element at a given position.
 * deleteElementAtBeg: deletes an element at the begining of the linked list.
 * deleteElementAtEnd: deletes an element at the end of the linked list.
 * deleteElementAtPos: deletes an element at a given position.
 * deleteElement: deletes a given element from the linked list.
 * getDataAtPosition: getter for the linked list data at a given position.
 * search: searches for a given element.
 * displayList: displays the list.
 * operator<<: display the doubly linked list object.
 * operator>>: uses cin to get input related to the doubly linked list.
 * ****************************************************************************
 **/

#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H
#include <iostream>
using namespace std;

template <typename ElementType>
class LListWithDummyNode
{
private:
    class Node
    {
    public:
        ElementType data; // Data stored in the node.
        Node *next;       // Pointer to the next node in the list.

        Node(const ElementType &newElement);
        /*--------------------------------------------------------------------
         Node Constructor

         Precondition:  The 'newElement' is a valid element.
         Postcondition: A new Node object is created with the specified
          data and a null pointer as the next node.
       ---------------------------------------------------------------------*/
    };

    typedef Node *nodePtr; // Type definition for a pointer to Node.
    nodePtr myFirst;       // Pointer to the dummy node.
    int mySize;            // Number of elements in the list.

public:
    /***** Default Constructor *****/
    LListWithDummyNode();
    /*------------------------------------------------------------------------
  Construct an empty Linked List with a dummy node.

  Precondition:  None.
  Postcondition: An empty Linked List with a dummy node is created.
----------------------------------------------------------------------------*/

    /***** Copy Constructor *****/
    LListWithDummyNode(const LListWithDummyNode &original);
    /*-------------------------------------------------------------------------
  Construct a new Linked List with a dummy node by copying an existing one.


  Precondition:  The 'original' parameter is a valid Linked
                                     List with a dummy node.
  Postcondition: A new Linked List with a dummy node is created as a copy
  of the 'original' list, preserving the order of elements.
----------------------------------------------------------------------------*/

    /***** Destructor *****/
    ~LListWithDummyNode();
    /*-------------------------------------------------------------------------
  Destroy the Linked List with a dummy node and deallocate its memory.

  Precondition:  None.
  Postcondition: The Linked List with a dummy node is destroyed,
                                                 and its memory is deallocated.
-----------------------------------------------------------------------------*/

    /***** Check if the List is Empty *****/
    inline bool isEmpty() const;
    /*-------------------------------------------------------------------------
  Check if the Linked List with a dummy node is empty.

  Precondition:  None.
  Postcondition: Returns true if the list is empty, false otherwise.
----------------------------------------------------------------------------*/

    /***** Get the Size of the List *****/
    int getSize() const;
    /*-------------------------------------------------------------------------
  Get the size (number of elements) in the Linked List with a dummy node.

  Precondition:  None.
  Postcondition: Returns the number of elements in the list as an integer.
----------------------------------------------------------------------------*/

    /***** Add Element at the Beginning *****/
    void addAtBeg(const ElementType &newElement);
    /*-----------------------------------------------------------------------
      Add an element at the beginning of the Linked List with a dummy node.

      Precondition:  The 'newElement' is a valid element.
      Postcondition: The 'newElement' is added at the beginning of the list.
    ------------------------------------------------------------------------*/

    /***** Add Element at the End *****/
    void addAtEnd(const ElementType &newElement);
    /*-------------------------------------------------------------------------
  Add an element at the end of the Linked List with a dummy node.

  Precondition:  The 'newElement' is a valid element.
  Postcondition: The 'newElement' is added at the end of the list.
----------------------------------------------------------------------------*/

    /***** Add Element at Given Position *****/
    bool addAtPosition(const ElementType &newElement, unsigned position);
    /*-------------------------------------------------------------------------
  Add an element at the specified position within the Linked List with a dummy
                                                                        node.

  Precondition:  The 'newElement' is a valid element.
                    The 'position' is a non-negative
                 integer representing a valid position within the list.
  Postcondition: If successful,
                the 'newElement' is added at the specified 'position'
                 in the list. Returns true if the addition is successful,
                                     false otherwise.
----------------------------------------------------------------------------*/

    /***** Delete Element at the Beginning *****/
    bool deleteElementAtBeg();
    /*-------------------------------------------------------------------------
  Delete the element at the beginning of the Linked List with a dummy node.

  Precondition:  None.
  Postcondition: If the list is not empty,
                                     the element at the beginning is deleted,
                 and the list is modified.
                                 Returns true if the deletion is successful,
                 false otherwise.
----------------------------------------------------------------------------*/

    /***** Delete Element at the End *****/
    bool deleteElementAtEnd();
    /*-------------------------------------------------------------------------
  Delete the element at the end of the Linked List with a dummy node.

  Precondition:  None.
  Postcondition: If the list is not empty, the element at the end is deleted,
                 and the list is modified. Returns true if the deletion
                  is successful,false otherwise.
----------------------------------------------------------------------------*/

    /***** Delete Element at Given Position *****/
    bool deleteElementAtPos(unsigned position);
    /*-------------------------------------------------------------------------
  Delete the element at the specified position within the Linked List
                                                             with a dummy node.

  Precondition:  The 'position' is a non-negative integer representing
                                 a valid position within the list.
  Postcondition: If the 'position' is valid and within the list's bounds,
   the element at that position is deleted,and the list is modified.
    Returns true if the deletion is successful, false otherwise.
----------------------------------------------------------------------------*/

    /***** Delete Specific Element *****/
    bool deleteElement(const ElementType &element);
    /*-------------------------------------------------------------------------
  Delete the first occurrence of a specific element from the Linked List
                                                             with a dummy node.

  Precondition:  The 'element' is a valid element.
  Postcondition: If the 'element' is found in the list,
                                                the first occurrence of it is
                 removed, and the list is modified. Returns true if the
                  deletion is successful, false otherwise.
----------------------------------------------------------------------------*/

    /***** Get Data at a Specific Position *****/
    ElementType *getDataAtPos(int pos);
    /*-------------------------------------------------------------------------
  Retrieve the data at a specified position in the Linked List
                                                            with a dummy node.

  Precondition:  The 'pos' is a non-negative integer representing
  a valid position within the list.
  Postcondition: If the 'pos' is valid and within the list's bounds,
   a pointer to the data at that position is returned.
    If 'pos' is invalid, nullptr is returned.
----------------------------------------------------------------------------*/

    /***** Search for an Element *****/
    int search(const ElementType &element);
    /*-------------------------------------------------------------------------
  Search for a specific element in the Linked List with a dummy node
                                                     and return its position.

  Precondition:  The 'element' is a valid element.
  Postcondition: If the 'element' is found in the list,
   its position is returned as an integer. If the element is not found
                                                            , -1 is returned.
----------------------------------------------------------------------------*/

    /***** Display the List *****/
    void displayList(ostream &os) const;
    /*-------------------------------------------------------------------------
  Display the elements of the Linked List with a dummy node.

  Precondition:  The 'os' parameter is a valid output stream.
  Postcondition: The elements of the list are displayed on the output stream.
----------------------------------------------------------------------------*/
};

// END OF HEADER FILE

// Node constructor implmentation
template <typename ElementType>
LListWithDummyNode<ElementType>::Node::Node(const ElementType &newElement)
    : data(newElement), next(nullptr)
{
}
//  linked list with dummy node constructor implementation
template <typename ElementType>
LListWithDummyNode<ElementType>::LListWithDummyNode()
    : mySize(0)
{
    ElementType garbage;
    nodePtr dummy = new Node(garbage);
    myFirst = dummy;
}

//  linked list with dummy node Copy Constructor
template <typename ElementType>
LListWithDummyNode<ElementType>::
    LListWithDummyNode(const LListWithDummyNode &original)
{
    // Set the size of the new list to be the same as the original list.
    mySize = original.mySize;

    // Creating garabage value
    ElementType garbage;

    // myFirst points to a dummy Node
    myFirst = new Node(garbage);

    // Pointers to traverse the new list and the original list.
    nodePtr tempPtr = myFirst;
    nodePtr ogPtr = original.myFirst->next;

// Loop through the original list .
    while (ogPtr != nullptr)
    {
        // duplicating the elements.
        tempPtr->next = new Node(ogPtr->data);

        // Move to the next node in both the new and original lists.
        tempPtr = tempPtr->next;
        ogPtr = ogPtr->next;
    }
}

// destructor of the doubly linked list.
template <typename ElementType>
LListWithDummyNode<ElementType>::~LListWithDummyNode()
{
  
    nodePtr tempPtr = myFirst->next;
    while (tempPtr != nullptr)
    {
        nodePtr nodeToDelete = tempPtr;
        tempPtr = tempPtr->next;
        delete nodeToDelete;
        mySize--;
    }
}

// checks if the list is empty.
template <typename ElemntType>
bool LListWithDummyNode<ElemntType>::isEmpty() const
{
    return mySize == 0;
}


// gets the size of linked list.
template <typename ElementType>
int LListWithDummyNode<ElementType>::getSize() const
{
    return mySize;
}

// adds a new node at the begining of the linked list.
template <typename ElementType>
void LListWithDummyNode<ElementType>::addAtBeg(const ElementType &newElement)
{
    // Creating new Node
    nodePtr newNode = new Node(newElement);

    // checking if it is Empty
    if (isEmpty())
    {
        myFirst->next = newNode;
        mySize++;
    }
    else
    {
        newNode->next = myFirst->next;
        myFirst->next = newNode;
        mySize++; 
    }
}


//adds a new Element at the end of the list.
template <typename ElementType>
void LListWithDummyNode<ElementType>::addAtEnd(const ElementType &newElement)
{
    nodePtr newNode = new Node(newElement);
    if (isEmpty())
    {
        myFirst->next = newNode;
        mySize++;
    }
    else
    {
        nodePtr tempPtr = myFirst->next;
        while (tempPtr->next != nullptr)
        {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = newNode;
        mySize++; 
    }
}

//adds a new element at a given position
template <typename ElementType>
bool LListWithDummyNode<ElementType>::
    addAtPosition(const ElementType &newElement, unsigned position)
{
    if (position < 0 || position < mySize)
    {
        return false;
    }
    nodePtr newNode = new Node(newElement);

    //empty and postion is not 0
    if (isEmpty() && position != 0)
    {
        return false;
    }
    // empty and the position is 0
    else if (isEmpty() && position == 0)
    {
        myFirst->next = newNode;
        mySize++;
        return true;
    }
    //not empty and position is 0
    else if (!isEmpty() && position == 0)
    {
        newNode->next = myFirst->next;
        myFirst->next = newNode;
        mySize++;
        return true;
    }
    else
    {
        // the position is not 0
        nodePtr tempPtr = myFirst;
        for (int i = 0; i < position - 1; i++)
        {
            tempPtr = tempPtr->next;
        }
        newNode->next = tempPtr->next;
        tempPtr->next = newNode;
        mySize++;
        return true;
    }
}


//deletes an element at the begining of the linked list
template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtBeg()
{
    if (isEmpty())
    {
        return false;
    }
    nodePtr nodeTodelete = myFirst->next;
    myFirst->next = nodeTodelete->next;
    delete nodeTodelete;
    mySize--;

    return true;
}

//deletes an element at the end of the linked list
template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtEnd()
{
    if (isEmpty())
    {
        return false;
    }

    nodePtr tempPtr = myFirst->next;
    while (tempPtr->next != nullptr && tempPtr->next->next != nullptr)
    {
        tempPtr = tempPtr->next;
    }

    delete tempPtr->next;
    tempPtr->next = nullptr;
    mySize--;

    return true;
}


// deletes an elemnt at a given position
template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtPos(unsigned int position)
{

    //checking if the position is valid
    if (position < 0 || position >= mySize)
    {
        return false;
    }
    if (isEmpty())
    {
        return false;
    }
    if (position == 0)
    {
        nodePtr nodeTodelete = myFirst->next;
        myFirst->next = nodeTodelete->next;
        delete nodeTodelete;
        mySize--;

        return true;
    }
    nodePtr tempPtr = myFirst->next;

    for (int i = 1; i < position - 1; i++)
    {
        tempPtr = tempPtr->next;
    }
    nodePtr nodeTodelete = tempPtr->next;

    tempPtr->next = nodeTodelete->next;
    delete nodeTodelete;
    mySize--;
    return true;
}


// searches for the element and it returns its index
template <typename ElementType>
int LListWithDummyNode<ElementType>::search(const ElementType &element)
{
    int index = 0;
    nodePtr tempPtr = myFirst->next;
    while (tempPtr != nullptr)
    {

        if (tempPtr->data == element)
        {
            return index;
        }
        else
        {
            tempPtr = tempPtr->next;
            index++;
        }
    }
    return -1;
}


// deletes a given element from the linked list
template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElement(const ElementType &element)
{
    // storing the index of the elemnt by calling search method.

    int indexOfTheElement = search(element);
    if (indexOfTheElement == -1)
    {
        return false;
    }

    // delete from the begining
    else if (indexOfTheElement == 0)
    {
        nodePtr nodeTodelete = myFirst->next;
        myFirst->next = nodeTodelete->next;
        delete nodeTodelete;
        mySize--;
        return true;
    }

    // delete from the end 
    else if (indexOfTheElement == mySize - 1)
    {
        nodePtr tempPtr = myFirst;
        while (tempPtr->next->next != nullptr)
        {
            tempPtr = tempPtr->next;
        }
        nodePtr nodeToDelete = tempPtr->next;
        tempPtr->next = nullptr;
        delete nodeToDelete;
        mySize--;

        return true;
    }
    //delete from the middle 
    else
    {
        nodePtr tempPtr = myFirst;

        for (int i = 0; i < indexOfTheElement; i++)
        {
            tempPtr = tempPtr->next;
        }
        nodePtr nodeToDelete = tempPtr->next;
        tempPtr->next = nodeToDelete->next;
        delete nodeToDelete;

        mySize--;
        return true;
    }
}


// returns a pointer of the data at a specific position.
template <typename ElementType>
ElementType *LListWithDummyNode<ElementType>::getDataAtPos(int pos)
{

    if (pos >= 0 && pos < mySize)
    {
        nodePtr tempPtr = myFirst->next;
        for (int i = 0; i < pos; i++)
        {
            tempPtr = tempPtr->next;
        }
        return &(tempPtr->data);
    }

    return nullptr;
}


//displat the linked list
template <typename ElementType>
void LListWithDummyNode<ElementType>::displayList(ostream &os) const
{
    if (isEmpty())
    {
        cout << "The list is empty";
    }
    else
    {
        nodePtr tempPtr = myFirst->next;
        while (tempPtr != nullptr)
        {
            os << tempPtr->data << " ";
            tempPtr = tempPtr->next;
        }
    }
}

// overloaded << operator
template <typename ElementType>
ostream &operator<<(ostream &os, LListWithDummyNode<ElementType> &list)
{
    list.displayList(os);
    return os;
}

// overloaded >> operator
template <typename ElementType>
istream &operator>>(istream &is, LListWithDummyNode<ElementType> &list)
{
    ElementType element;
    while (is >> element)
    {
        list.addAtEnd(element);
    }
    return is;
}

#endif