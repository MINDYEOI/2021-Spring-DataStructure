//
// Created by mindyeoi on 2021/03/29.
//

#include <iostream>
#include <iomanip>
#include "BasketType.h"
#define WIDTH 40
#define MAXCOMMANDS 4
using namespace std;



int BasketType::GetCommand()
{
    int select;
    while (1) {

        cout << "\t=" << setw(WIDTH + 1) << setfill('=') << "=\n";
        cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  0: Quit" << "|\n";
        cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  1: Display the basket" << "|\n";
        cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  2: Search the goods in the basket" << "|\n";
        cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  3: Empty the basket" << "|\n";


        cout << "\t=" << right << setw(WIDTH + 1) << setfill('=') << "=\n";
        cout << "\t  Select a function --> ";

        if (cin.fail() || !(cin >> select) || select < 0 || select>MAXCOMMANDS)	// input fail or input value is out of bound
        {
            cout << "\t    ### Invalid Command Number. Select again  ####" << endl;
            cin.clear();	//clear flag
            cin.ignore(INT_MAX, '\n');	//empty input buffer
        }
        else {
            cin.clear();  // clear flag
            cin.ignore(INT_MAX, '\n');  // empty input buffer
            return select;
        }
    }
}

bool BasketType::ManageBasket(SortedList& m_List)
{
    while (true)
    {
        int Command = GetCommand(); // Get command value from keyboard

        // Command execution
        switch (Command)
        {
            case 0:
                return true;
            case 1:// display all records on screen
                DisplayBasket(m_List);
                break;
            case 2:
                SearchTheGoodsInBasket(m_List);
                break;
            case 3:
                EmptyBasket();
                break;
            default:
                cout << "\t [!]ERROR Illegal selection...\n";
                break;
        }
    }
}


bool BasketType::DisplayBasket(SortedList& m_List)
{


    cout << "\t-------------- All records --------------" << "-\n";

    if (basket.isEmpty()) // If list is empty, show below error
    {
        cout << "\t [!] There's no data to show" << endl;
        return false;
    }

    basket.ResetQList();
    SimpleType data;
    int index;
    // Loop all item in the list
    while ((index = basket.GetNextItem(data) != -1))
    {
        cout << "\t " << index << ".";
        data.DisplayTheBasket();
        cout << endl;
    }

    return true;
}



bool BasketType::AddToBasket(ItemType inData)
{
    if (!basket.isFull())
    {
        SimpleType product;
        product.SetNameInBasket(inData.GetName());
        product.SetCodeInBasket(inData.GetCode());
        product.SetSalesPriceInBasket(inData);
        product.SetProductQuantityInBasketByKB();
        basket.EnQueue(product);
        cout << "\t [!] Successfully added!\n\n";
        return true;
    }

    else
    {
        cout << "[!] The basket is full\n";
        return false;
    }
}


bool BasketType::SearchTheGoodsInBasket(SortedList& m_List)
{
    if (basket.isEmpty())
    {
        cout << "\t [!] The basket is empty.\n";
        return false;
    }
    SimpleType item;
    ItemType data;
    item.SetCodeInBasketByKB();
    int index = basket.Retrieve(item);
    if (index == -1)
    {
        cout << "\t [!] The goods is not exist in the basket.\n";
        return false;
    }

    else
    {
        data.SetCode(item.GetGoodsCodeInBasket());
        if(m_List.Retrieve(data) != -1)
        {
            cout << "\t---------- The Item Information -----------" << endl;
            data.DisplayRecordOnScreen();
            cout << endl << endl;
            return true;
        }
        else
        {
            cout << "[!] There is no data in the goods list.\n\n";
            return false;
        }
    }

}

bool BasketType::EmptyBasket()
{
    if (basket.isEmpty())
    {
        cout << "[!] The basket is already empty." << endl;
        return false;
    }
    basket.makeEmpty();
    cout << "\t[!] The basket is now empty." << endl;
    return true;
}