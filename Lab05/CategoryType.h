//
// Created by mindyeoi on 2021/04/03.
//

#ifndef LAB04_CATEGORYTYPE_H
#define LAB04_CATEGORYTYPE_H
#include <iostream>
#include <string>
#include "DoublySortedLinkedList.h"
#include "SimpleProductType.h"
#include "SortedList.h"
#define WIDTH 40
#define MAXCOMMANDS 4


class CategoryType {
private:
    int m_ItemNumInCate; // the number of the goods in this category
    DoublySortedLinkedList<SimpleProductType> m_cateitem;   // the items list in this category
    //DoublyIterator<SimpleProductType> m_cateitem;

public:



    /*
*	@brief	Display command on screen and get a input from keyboard.
*	@pre	none.
*	@post	none.
*	@return	user's command.
*/
    int GetCommand()
    {
        int select;
        while (1) {

            cout << "\t=" << setw(WIDTH + 1) << setfill('=') << "=\n";
            cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  0: Quit" << "|\n";
            cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  1: Display the category" << "|\n";
            cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  2: Display goods info in the category" << "|\n";
            cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  3: Add a item to the category" << "|\n";
            cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  4: Find product in the category" << "|\n";


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


    /**
* @brief   Manage the basket.
* @pre     The baset is initialized.
* @post    none.
* @return  If this function works well, return true, otherwise return false.
*/
    bool ManageCategory(SortedList& m_List)
    {
        while (true)
        {
            int Command = GetCommand(); // Get command value from keyboard

            // Command execution
            switch (Command)
            {
            case 0:
                return true;
            case 1:
                DisplayCategoryItem();
                break;
            case 2:
                DisplayCateList(m_List);    // Display the item's detail information.
                break;
            case 3:
                AddToCateList(m_List);
                break;
            case 4:
                FindProductInCate();
                break;
            default:
                cout << "\t [!]ERROR Illegal selection...\n";
                break;
            }
        }
    }

    /**
*	@brief	Display All content data from list.
*	@pre	list should be initialized.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
    bool DisplayCategoryItem()
    {
        cout << "\t-------------- All records --------------" << "-\n";

        if (m_cateitem.IsEmpty()) // If list is empty, show below error
        {
            cout << "\t [!] There's no data to show" << endl;
            return false;
        }

        int i = 1;
        SimpleProductType data;
        while (m_cateitem.GetNextItem(data) != -1)
        {
            cout << "\t " << i << ".";
            data.DisplayRecordOnScreen();
            cout << endl;
            i++;
        }


        //m_cateitem.ResetCurPointer();
        //SimpleProductType data;
        //int index;
        //int i = 1;
        // Loop all item in the list


       // while ((index = m_cateitem.GetNextItem(data)) != -1)
       // {
       //     cout << "\t " << i << ".";
       //     data.DisplayRecordOnScreen();
       //     cout << endl;
       //     i++;
       // }

        return true;
    }
    /**
     * @brief   Add item to the category.
     * @pre     The List is initialized, and the item does not already exist in the category.
     * @post    The item is added to the category
     * @param   item
     * @return  if this function works well, return true, otherwise return false.
     */
    bool AddToCateList(SortedList& m_List)
    {
        ItemType inData;
        inData.SetCodeNumFromKB();
        int index = m_List.Retrieve(inData);
        if (index == -1)
        {
            cout << "\t [!] There's no data with that code number\n";
            return false;
        }
        else
        {
            SimpleProductType product;
            product.SetName(inData.GetName());
            product.SetCode(inData.GetCode());
            product.SetPrice(inData.GetPrice());
            product.SetWarehousing(inData.GetWarehousingNum());
            product.SetSalesNum(inData.GetSalesNum());
            int isit = m_cateitem.Add(product);
            if (isit == false)
            {
                return false;
            }
            cout << "\t [!] Successfully added!\n\n";
            return true;
        }
    }

    /**
    * @brief   Display the goods detail information in category. Target content is set with keyboard input.
    * @pre     List should be initialized.
    * @post    none.
    * @return  If this function works well, return true, otherwise return false.
    */
    bool DisplayCateList(SortedList& m_List)
    {
        if (m_cateitem.IsEmpty())
        {
            cout << "\t [!] This category is empty.\n";
            return false;
        }
        SimpleProductType item;
        ItemType data;
        item.SetCodeInBasketByKB();
        int index = m_cateitem.Get(item);
        if (index == -1)
        {
            cout << "\t [!] The goods does not exist in this category.\n";
            return false;
        }

        else
        {
            data.SetCode(item.GetCode());
            if (m_List.Retrieve(data) != -1)
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

    /**
* @brief   Search the goods in category. Target content is set with keyboard input.
* @pre     List should be initialized.
* @post    none.
* @return  If this function works well, return true, otherwise return false.
*/
    bool FindProductInCate()
    {
        if (m_cateitem.IsEmpty())
        {
            cout << "\t [!] This category is empty.\n";
            return false;
        }
        SimpleProductType item;

        item.SetCodeInBasketByKB();
        int index = m_cateitem.Get(item);
        if (index == -1)
        {
            cout << "\t [!] The goods is not exist in this category.\n";
            return false;
        }

        else
        {
            cout << "\t---------- The Item Information -----------" << endl;
            item.DisplayRecordOnScreen();
            cout << endl;
            return true;
        }
    }

};


#endif