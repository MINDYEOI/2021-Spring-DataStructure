//
// Created by mindyeoi on 2021/04/03.
//

#include "SimpleProductType.h"


using namespace std;


string SimpleProductType::GetName()
{
    return m_Name;
}

string SimpleProductType::GetCode()
{
    return m_Code;
}

void SimpleProductType::SetCode(string inId)
{
    m_Code = inId;
}

void SimpleProductType::SetName(string inName)
{
    m_Name = inName;
}


void SimpleProductType::SetPrice(int inPrice)
{
    m_Price = inPrice;
}

void SimpleProductType::SetWarehousing(string inWarehousing)
{
    m_WarehousingNum = inWarehousing;
}

void SimpleProductType::SetSalesNum(string inSales)
{
    m_SalesNum = inSales;
}



void SimpleProductType::SetCodeInBasketByKB()
{
    cout << "\t Enter the goods code :";
    cin >> m_Code;
}



void SimpleProductType::SetRecord(string inId, string inName, int inPrice, string inWarehousing, string inSales)
{
    SetCode(inId);
    SetName(inName);
    SetPrice(inPrice);
    SetWarehousing(inWarehousing);
    SetSalesNum(inSales);
}

void SimpleProductType::DisplayCodeOnScreen()
{
    //cout << "\t " << m_Code;
    cout << right << setw(WIDTH) << setfill(' ') << m_Code;
}

void SimpleProductType::DisplayNameOnScreen()
{
    //cout << "\t " << m_Name;

    cout << right << setw(WIDTH) << setfill(' ') << m_Name;
}

void SimpleProductType::DisplayPriceOnScreen()
{
    //cout << "\t \\" << m_Price;

    cout << right << setw(WIDTH) << setfill(' ') << m_Price;
}

void SimpleProductType::DisplayWarehousingOnScreen()
{
    //    cout << "\t " << m_WarehousingNum<<" left";

    cout << right << setw(WIDTH) << setfill(' ') << m_WarehousingNum << " left";
}

void SimpleProductType::DisplaySalesOnScreen()
{
    //    cout << "\t "<< m_SalesNum<<" sold";

    cout << right << setw(WIDTH) << setfill(' ') << m_SalesNum << " sold";
}








void SimpleProductType::DisplayRecordOnScreen()
{
    DisplayCodeOnScreen();
    DisplayNameOnScreen();
    DisplayPriceOnScreen();
    DisplayWarehousingOnScreen();
    DisplaySalesOnScreen();
    cout << endl;
}

void SimpleProductType::SetCodeNumFromKB()
{
    cout << "\t Enter the Code Number : ";
    cin >> m_Code;
}

void SimpleProductType::SetNameFromKB()
{
    cout << "\t Enter the name : ";
    cin >> m_Name;
}

void SimpleProductType::SetPriceFromKB()
{
    cout << "\t Enter the price : ";
    cin >> m_Price;
}


void SimpleProductType::SetWarehousingFromKB()
{
    cout << "\t Enter the number of warehoused product : ";
    cin >> m_WarehousingNum;
}

void SimpleProductType::SetSalesFromKB()
{
    cout << "\t Enter the number of sales : ";
    cin >> m_SalesNum;
}

void SimpleProductType::SetRecordFromKB()
{
    SetCodeNumFromKB();
    SetNameFromKB();
    SetPriceFromKB();
    SetWarehousingFromKB();
    SetSalesFromKB();
}





void SimpleProductType::SetRecordExceptPrimaryKeyFromKB()
{
    SetNameFromKB();
    SetPriceFromKB();
    SetWarehousingFromKB();
    SetSalesFromKB();
}

bool SimpleProductType::ReadDataFromFile(ifstream& fin)
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

bool SimpleProductType::WriteDataToFile(ofstream& fout)
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
//int SimpleProductType::calcEachGoods()
//{
//	//return atoi(m_Price.c_str()) * atoi(m_buyNum.c_str());
//	return m_buyPrice * m_buyNum;
//}