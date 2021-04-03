//
// Created by mindyeoi on 2021/04/03.
//

#ifndef LAB04_CATEGORYTYPE_H
#define LAB04_CATEGORYTYPE_H
#include <iostream>
#include <string>
#include "SortedLinkedList.h"
#include "SimpleProductType.h"

class CategoryType {
private:
    int m_ItemNumInCate; // the number of the goods in this category
    SortedLinkedList<SimpleProductType> m_ItemListInCate;   // the items list in this category

public:
    /**
     * @brief   Add item to the category.
     * @pre     The List is initialized, and the item does not already exist in the category.
     * @post    The item is added to the category
     * @param   item
     * @return  if this function works well, return true, otherwise return false.
     */
    bool AddToCateList(SimpleProductType& item);


    bool DisplayCateList();

    bool FindProductInCate(SimpleProductType& item);

};


#endif //LAB04_CATEGORYTYPE_H
