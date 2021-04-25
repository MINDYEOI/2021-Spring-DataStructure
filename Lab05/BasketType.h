//
// Created by mindyeoi on 2021/03/29.
//

#ifndef LAB03_AGAIN_AGAIN_BASKETTYPE_H
#define LAB03_AGAIN_AGAIN_BASKETTYPE_H
#pragma once
#include <iostream>
#include "QueueList.h"
#include "SimpleType.h"

#include "SortedList.h"
class BasketType
{
private:
    QueueList<SimpleType> basket;

public:
    BasketType() {}	// Default Constoructor

    ~BasketType() {} // Destructor

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
    bool ManageBasket(SortedList& m_List);

    /**
    * @brief   Display the goods in the basket.
    * @pre     The basket is not empty.
    * @post    none.
    * @return  If this function works well, return true, otherwise return false.
    */
    bool DisplayBasket(SortedList& m_List);

    /**
     * @brief   Add the goods to the basket.
     * @pre     The goods is available, and the basket is initialized.
     * @post    none.
     * @return  If this function works well, return true, otherwise return false.
     */
    bool AddToBasket(ItemType inData);

    /**
     * @brief   Search the goods in basket. Target content is set with keyboard input.
     * @pre     List should be initialized.
     * @post    none.
     * @return  If this function works well, return true, otherwise return false.
     */
    bool SearchTheGoodsInBasket(SortedList& m_List);

    /**
     * @brief   Make the basket empty.
     * @pre     none.
     * @post    Basket is empty.
     * @return  If this function works well, return true, otherwise return false.
     */
    bool EmptyBasket();


};




#endif