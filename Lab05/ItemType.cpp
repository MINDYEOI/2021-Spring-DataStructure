//
// Created by mindyeoi on 2021/03/29.
//

#include "ItemType.h"

using namespace std;


string ItemType::GetName()
{
    return m_Name;
}

string ItemType::GetCode()
{
    return m_Code;
}


int ItemType::GetPrice()
{
    return m_Price;
}


string ItemType::GetWarehousingNum()
{
    return m_WarehousingNum;
}

string ItemType::GetSalesNum()
{
    return m_SalesNum;
}


void ItemType::SetCode(string inId)
{
    m_Code = inId;
}

void ItemType::SetName(string inName)
{
    m_Name = inName;
}


void ItemType::SetPrice(int inPrice)
{
    m_Price = inPrice;
}

void ItemType::SetWarehousing(string inWarehousing)
{
    m_WarehousingNum = inWarehousing;
}

void ItemType::SetSalesNum(string inSales)
{
    m_SalesNum = inSales;
}







void ItemType::SetRecord(string inId, string inName, int inPrice, string inWarehousing, string inSales)
{
    SetCode(inId);
    SetName(inName);
    SetPrice(inPrice);
    SetWarehousing(inWarehousing);
    SetSalesNum(inSales);
}

void ItemType::DisplayCodeOnScreen()
{
    cout << "\t Code Number : " << m_Code;
}

void ItemType::DisplayNameOnScreen()
{
    cout << "\t Name : " << m_Name;
}

void ItemType::DisplayPriceOnScreen()
{
    cout << "\t Price : " << m_Price;
}

void ItemType::DisplayWarehousingOnScreen()
{
    cout << "\t Warehoused : " << m_WarehousingNum;
}

void ItemType::DisplaySalesOnScreen()
{
    cout << "\t Sold : " << m_SalesNum;
}








void ItemType::DisplayRecordOnScreen()
{
    DisplayCodeOnScreen();
    DisplayNameOnScreen();
    DisplayPriceOnScreen();
    DisplayWarehousingOnScreen();
    DisplaySalesOnScreen();
}

void ItemType::SetCodeNumFromKB()
{
    cout << "\t Enter the Code Number : ";
    cin >> m_Code;
}

void ItemType::SetNameFromKB()
{
    cout << "\t Enter the name : ";
    cin >> m_Name;
}

void ItemType::SetPriceFromKB()
{
    cout << "\t Enter the price : ";
    cin >> m_Price;
}


void ItemType::SetWarehousingFromKB()
{
    cout << "\t Enter the number of warehoused product : ";
    cin >> m_WarehousingNum;
}

void ItemType::SetSalesFromKB()
{
    cout << "\t Enter the number of sales : ";
    cin >> m_SalesNum;
}

void ItemType::SetRecordFromKB()
{
    SetCodeNumFromKB();
    SetNameFromKB();
    SetPriceFromKB();
    SetWarehousingFromKB();
    SetSalesFromKB();
}





void ItemType::SetRecordExceptPrimaryKeyFromKB()
{
    SetNameFromKB();
    SetPriceFromKB();
    SetWarehousingFromKB();
    SetSalesFromKB();
}

bool ItemType::ReadDataFromFile(ifstream& fin)
{
    if (!fin)
    {
        cout << "\t The fle is not existed." << endl;
        return 0;
    }

    fin >> m_Code;
    fin >> m_Name;
    fin >> m_Price;
    fin >> m_WarehousingNum;
    fin >> m_SalesNum;

    return !(m_Code.empty() || m_Name.empty() || m_Price == 0 || m_WarehousingNum.empty() || m_SalesNum.empty());
}

bool ItemType::WriteDataToFile(ofstream& fout)
{
    if (m_Code.empty() || m_Name.empty() || m_Price == 0 || m_WarehousingNum.empty() || m_SalesNum.empty())
    {
        return false;
    }

    fout << setw(15) << m_Code;
    fout << setw(15) << m_Name;
    fout << setw(15) << m_Price;
    fout << setw(15) << m_WarehousingNum;
    fout << setw(15) << m_SalesNum;
    return true;
}

/*
*	@brief	Calculate the goods price
*	@pre	the price and quantity have invalid value.
*	@post	show the price.
*	@return	if this function worked well return 1 otherwise 0
*/
//int ItemType::calcEachGoods()
//{
//	//return atoi(m_Price.c_str()) * atoi(m_buyNum.c_str());
//	return m_buyPrice * m_buyNum;
//}