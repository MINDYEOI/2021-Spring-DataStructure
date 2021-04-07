//
// Created by mindyeoi on 2021/04/03.
//

#ifndef LAB04_CATEGORYTYPE_H
#define LAB04_CATEGORYTYPE_H
#include <iostream>
#include <string>
#include "SortedLinkedList.h"
#include "SimpleProductType.h"
#include "SortedList.h"
#define WIDTH 40
#define MAXCOMMANDS 4

class CategoryType {
private:
    int m_ItemNumInCate; // the number of the goods in this category
    SortedLinkedList<SimpleProductType> m_ItemListInCate;   // the items list in this category

public:



    /*
*	@brief	Display command on screen and get a input from keyboard.
*	@pre	none.
*	@post	none.
*	@return	user's command.
*/
    int GetCommand();


    /**
* @brief   Manage the basket.
* @pre     The baset is initialized.
* @post    none.
* @return  If this function works well, return true, otherwise return false.
*/
    bool ManageCategory(SortedList& m_List);

    /**
*	@brief	Display All content data from list.
*	@pre	list should be initialized.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
    bool DisplayCategoryItem();
    /**
     * @brief   Add item to the category.
     * @pre     The List is initialized, and the item does not already exist in the category.
     * @post    The item is added to the category
     * @param   item
     * @return  if this function works well, return true, otherwise return false.
     */
    bool AddToCateList(SortedList& m_List);

    /**
    * @brief   Display the goods detail information in category. Target content is set with keyboard input.
    * @pre     List should be initialized.
    * @post    none.
    * @return  If this function works well, return true, otherwise return false.
    */
    bool DisplayCateList(SortedList& m_List);

    /**
* @brief   Search the goods in category. Target content is set with keyboard input.
* @pre     List should be initialized.
* @post    none.
* @return  If this function works well, return true, otherwise return false.
*/
    bool FindProductInCate();

};


#endif //LAB04_CATEGORYTYPE_H
