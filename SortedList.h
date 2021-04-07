//
// Created by mindyeoi on 2021/03/29.
//

#ifndef LAB03_AGAIN_AGAIN_SORTEDLIST_H
#define LAB03_AGAIN_AGAIN_SORTEDLIST_H


#pragma once

#include <iostream>

#include "ItemType.h"
#include "SimpleType.h"
#define MAXSIZE 5
using namespace std;
class SortedList
{
private:
    ItemType m_Array[MAXSIZE];
    int m_Length;
    int m_CurPointer;

public:
    // Constructor
    SortedList()
    {
        m_Length = 0;
        m_CurPointer = -1;
    }

    // Destructor
    ~SortedList() {};

    /*
    *	@brief	make the list empty.
    *	@pre	none.
    *	@post	the list is empty.
    */
    void MakeEmpty();

    /*
    *	@brief	Return the number of the records in current list.
    *	@pre	none.
    *	@post	none.
    *	@return the number of records in current list.
    */
    int GetLength();

    /*
    *	@brief	Check the array is full
    *	@pre	none.
    *	@post	none.
    *	@return if the array is full, return true, otherwise return false.
    */
    bool IsFull();

    /*
    *	@brief	Check the 'data' is exist in the array.
    *	@pre	data should be available.
    *	@post	none.
    *	@param	data what we want to know whether existed.
    *	@return	if exist, return index of array, otherwise return -1.
    */
    int IsExist(ItemType data);

    /*
    *	@brief	Check the data is added in the array.
    *	@pre	data should be available and list should be initialized.
    *	@post	data is added to the list.
    *	@param	data what we want to add.
    *	@return	return 1 if 'Add' is successful, otherwise return -1.
    */
    bool Add(ItemType data);

    /*
    *	@brief	Reset the list. (Reset the current pointer)
    *	@pre	list should be initialized.
    *	@post	the current pointer is reset.
    */
    void ResetList();

    /**
    *	@brief	move list iterator to the next item in list and get that item.
    *	@pre	list and list iterator should not be initialized.
    *	@post	iterator is moved to next item.
    *	@param	data	get current iterator's item. it does not need to be initialized.
    *	@return	index of current iterator's item if is not end of list, otherwise return -1.
    */
    int GetNextItem(ItemType& data);

    /**
 *  @brief  Check whether the list is empty.
 *  @pre    none
 *  @post   none
 */
    bool isEmpty();

    /*
    *	@brief  Check the 'data' is exist in the array.
    *	@pre    data should be available.
    *	@post	none.
    *	@param	data what we want to know whether existed.
    *	@return	if the data exists, return the data
    */
    int Retrieve(ItemType& data);
    //int Retrieve(SimpleType& data);
    /*
    *	@brief  Check the 'data' is exist in the array using binary search.
    *	@pre    data should be available.
    *	@post	none.
    *	@param	data what we want to know whether existed.
    *	@return	if the data exists, return the data
    */
    int Retrieve_Binary(ItemType& inData);

    /*
    *	@brief  Delete the 'data' in the array.
    *	@pre    data should be available and the array has the data.
    *	@post	the array does not have the data.
    *	@param	data what we want to delete.
    *	@return	if successful, return 1, otherwhise return 0.
    */
    bool Delete(ItemType data);

    /*
    *	@brief  Replace a old 'data' with a new 'data(parameter)'.
    *			(if old data's primary key is same to new data primary key.)
    *	@pre    data should be available and the array has the old data has a same primary key
    *			to new data's primary key.
    *	@post	the array has a new data
    *	@param	data what what we want to replace
    *	@return	if successful, return 1, otherwhise return 0;
    */
    bool Replace(ItemType data);

    /*
    *	@brief  Add to the data in the array
    *	@pre    data should be available
    *	@post	the array has the data
    *	@param	data what what we want to add to basket
    *	@return	if successful, return 1, otherwise return 0;
    */
    //bool AddToBasket(ItemType& data);
};
#endif //LAB03_AGAIN_AGAIN_SORTEDLIST_H
