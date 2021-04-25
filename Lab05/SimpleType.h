//
// Created by mindyeoi on 2021/03/29.
//

#ifndef LAB03_AGAIN_AGAIN_SIMPLETYPE_H
#define LAB03_AGAIN_AGAIN_SIMPLETYPE_H


#pragma once
#include <iostream>
#include <string>
#include "QueueList.h"
#include "ItemType.h"

using namespace std;

class SimpleType
{
private:
    string m_code;
    string m_name;
    int m_salesPrice;
    int m_quantity;

public:
    SimpleType()
    {
        m_code = "";
        m_name = "";
        m_salesPrice = 0;
        m_quantity = 0;
    }
    ~SimpleType() {}

    /**
    * @brief	Get the goods code in basket.
    * @pre		The products code should be set.
    * @post		none.
    * @return	A product code.
    */
    string GetGoodsCodeInBasket();

    /**
    * @brief	Get the goods name in basket.
    * @pre		The products name should be set.
    * @post		none.
    * @return	A product name.
    */
    string GetGoodsNameInBasket();

    /**
    * @brief	Get the goods price in basket.
    * @pre		The products price should be set.
    * @post		none.
    * @return	A product price.
    */
    int GetGoodsPriceInBasket();

    /**
    * @brief	Get the goods quantity in basket.
    * @pre		The products quantity should be set.
    * @post		none.
    * @return	A product quantity.
    */
    int GetGoodsQuantityInBasket();


    /**
    * @brief   Set the product code by KB.
    * @pre     none.
    * @post    Product code is set.
    */
    void SetCodeInBasketByKB();

    /**
   * @brief   Set the product name by KB.
   * @pre     none.
   * @post    Product name is set.
   */
    void SetNameInBasketByKB();

    /**
   * @brief   Set the product quantity by KB.
   * @pre     none.
   * @post    Product quantity is set.
   */
    void SetProductQuantityInBasketByKB();
    /**
   *	@brief	Set the goods code.
   *	@pre	none.
   *	@post	product code is set.
   *    @param  the product code
   */
    void SetCodeInBasket(string inId);

    /**
    *	@brief	Set a product name
    *	@pre	none
    *	@post	product name is set
    *   @param  the product name
    */
    void SetNameInBasket(string inName);

    /**
    *	@brief	Set a product price
    *	@pre	none
    *	@post	product price is set
    *   @param  the product sales price
    */
    void SetSalesPriceInBasket(ItemType& item);


    /**
    *	@brief	Set a product price
    *	@pre	none
    *	@post	product price is set
    *   @param  the product sales price
    */
    void SetProductQuantityInBasket(int inQuantity);

    /**
    *	@brief	Set a product price
    *	@pre	none
    *	@post	product price is set
    *   @param  the product sales price
    */
    void SetBasket(string inId, string inName, ItemType& item, int inQuantity);


    /**
    *	@brief	Display a product ID in basket.
    *	@pre	A product ID is set in basket.
    *	@post	none.
    */
    void DisplayCodeInBasket();

    /*
    *	@brief	Display a product name in basket.
    *	@pre	A product name is set in basket.
    *	@post	none.
    */
    void DisplayNameInBasket();

    /*
    *	@brief	Display a product sales price in basket.
    *	@pre	A product sales price is set in basket.
    *	@post	none.
    */
    void DisplaySalesPriceInBasket();

    /*
   *	@brief	Display a product quantity in basket.
   *	@pre	A product quantity is set in basket.
   *	@post	none.
   */
    void DisplayQuantityInBasket();

    /*
  *	@brief	Display the product info in the basket.
  *	@pre	The product information in basket.
  *	@post	none.
  */
    void DisplayTheBasket();


    /*************************************************************************************************************/





    /*************************************************************************************************************/



    /**
    *  @brief  Compare item with name of content.
    *  @pre    self, target must valid.
    *  @post   none.
    *  @param  target item to compare.
    *  @return If self and target has same name, return true.
    */
    bool operator==(const SimpleType& target)
    {
        return m_code == target.m_code;
    }


    /**
     *  @brief  Copy item elements into another item.
     *  @pre    self, target must valid.
     *  @post   target item elements is replaced with self item elements.
     *  @param  target target of replacement.
     */
    void operator=(const SimpleType& target)
    {
        m_code = target.m_code;
        m_name = target.m_name;
        m_salesPrice = target.m_salesPrice;
        m_quantity = target.m_quantity;

    }

    /**
     *  @brief  Compare the items code.
     *  @pre    self, target must valid.
     *  @post   none.
     *  @param  target to compare
     */
    bool operator>(const SimpleType& target) const    // ���� const �ٿ��µ� �³�..?
    {
        return m_code > target.m_code;

    }

    /**
     *  @brief  Compare the items code.
     *  @pre    self, target must valid.
     *  @post   none.
     *  @param  target to be compared
     */
    bool operator<(const SimpleType& target) // const �ٿ��µ� �³�?
    {
        return m_code < target.m_code;

    }

    /**
     *  @brief  Overload << operators to show the target code and name.
     *  @pre    target must valid.
     *  @post   target code and name is shown.
     *  @param  target to be shown.
     */
     //  friend ostream& operator<<(ostream& ostrm, const SimpleType& item) // friend �ٿ��µ� �³�?�Ф�
     //  {
     //      ostrm << "[ Code : " << item.m_code
     //          << ", Item Name : " << item.m_name << "]";
     //      return ostrm;
     //  }
};


#endif 