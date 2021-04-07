//
// Created by mindyeoi on 2021/03/29.
//
#include "SimpleType.h"

string SimpleType::GetGoodsCodeInBasket()
{
    return m_code;
}


string SimpleType::GetGoodsNameInBasket()
{
    return m_name;
}


int SimpleType::GetGoodsPriceInBasket()
{
    return m_salesPrice;
}


int SimpleType::GetGoodsQuantityInBasket()
{
    return m_quantity;
}

void SimpleType::SetCodeInBasketByKB()
{
    cout << "\t Enter the goods code :";
    cin >> m_code;
}


void SimpleType::SetNameInBasketByKB()
{
    cout << "\t Enter the goods name :";
    cin >> m_name;
}


void SimpleType::SetProductQuantityInBasketByKB()
{
    cout << "\t Enter the goods quantity :";
    cin >> m_quantity;
}

void SimpleType::SetCodeInBasket(string inId)
{
    m_code = inId;
}


void SimpleType::SetNameInBasket(string inName)
{
    m_name = inName;
}


void SimpleType::SetSalesPriceInBasket(ItemType& item)
{
    m_salesPrice = item.m_Price + 100;
}


void SimpleType::SetProductQuantityInBasket(int inQuantity)
{
    m_quantity = inQuantity;
}

void SimpleType::SetBasket(string inId, string inName, ItemType& item, int inQuantity)
{
    SetCodeInBasket(inId);
    SetNameInBasket(inName);
    SetSalesPriceInBasket(item);
    SetProductQuantityInBasket(inQuantity);
}

/**
*	@brief	Display a product ID in basket.
*	@pre	A product ID is set in basket.
*	@post	none.
*/
void SimpleType::DisplayCodeInBasket()
{
    cout << "\t Code Number : " << m_code;
}

/*
*	@brief	Display a product name in basket.
*	@pre	A product name is set in basket.
*	@post	none.
*/
void SimpleType::DisplayNameInBasket()
{
    cout << "\t Name : " << m_name;

}

/*
*	@brief	Display a product sales price in basket.
*	@pre	A product sales price is set in basket.
*	@post	none.
*/
void SimpleType::DisplaySalesPriceInBasket()
{
    cout << "\t Sales Price : " << m_salesPrice;

}

/*
*	@brief	Display a product quantity in basket.
*	@pre	A product quantity is set in basket.
*	@post	none.
*/
void SimpleType::DisplayQuantityInBasket()
{

    cout << "\t Quantity : " << m_quantity;

}

/*
*	@brief	Display the product info in the basket.
*	@pre	The product information in basket.
*	@post	none.
*/
void SimpleType::DisplayTheBasket()
{
    DisplayCodeInBasket();
    DisplayNameInBasket();
    DisplaySalesPriceInBasket();
    DisplayQuantityInBasket();
}