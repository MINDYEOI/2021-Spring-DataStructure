#pragma once
#pragma once
/*
*	@brief	설명
*	@pre	함수가 실행되기 전 조건 (precondition)
*	@post	함수가 실행되고 난 후의 조건 (postcondition)
*	@return
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class ItemType
{
private:
	string m_Code; // primary key
	string m_Name;
	string m_Price;
	string m_WarehousingNum;
	string m_SalesNum;
public:

	// Constructor
	ItemType()
	{
		m_Code = "";
		m_Name = "";
		m_Price = "";
		m_WarehousingNum = "";
		m_SalesNum = "";
	}

	// Destructor
	~ItemType() {}

	/*
	*	@brief	Get the product name.
	*	@pre	The products name should be set.
	*	@post	none.
	*	@return	A product name.
	 */
	string GetName();

	/*
	*	@brief	Set a product code.
	*	@pre	none.
	*	@post	product code is set.
	*/
	void SetCode(string inId);

	/*
	*	@brief	Set a product name
	*	@pre	none
	*	@post	product name is set
	*/
	void SetName(string inName);


	/*
*	@brief	Set a product price
*	@pre	none
*	@post	product price is set
*/
	void SetPrice(string inPrice);

	/*
*	@brief	Set the number of a product warehousing
*	@pre	none
*	@post	The number of a product warehousing is set
*/
	void SetWarehousing(string inWarehousing);

	/*
*	@brief	Set a product Sales Number
*	@pre	none
*	@post	Product sales number is set
*/
	void SetSalesNum(string inSales);


	/*
	*	@brief	Set a product information(id, name, price, the number of a product warehousing, sales number).
	*	@pre	none.
	*	@post	product id, name, address is set.
	*/
	void SetRecord(string inId, string inName, string inPrice, string inWarehousing, string inSales);

	/*
	*	@brief	Display a product ID.
	*	@pre	A product ID is set.
	*	@post	none.
	*/
	void DisplayCodeOnScreen();

	/*
	*	@brief	Display a product name.
	*	@pre	A product name is set.
	*	@post	none.
	*/
	void DisplayNameOnScreen();

	/*
*	@brief	Display a product price.
*	@pre	A product price is set.
*	@post	none.
*/
	void DisplayPriceOnScreen();

	/*
*	@brief	Display the number of a product warehousing.
*	@pre	the number of a product warehousing is set.
*	@post	none.
*/
	void DisplayWarehousingOnScreen();

	/*
*	@brief	Display the number of a sold product.
*	@pre	The number of a sold product is set.
*	@post	none.
*/
	void DisplaySalesOnScreen();

	/*
	*	@brief	Display a record.
	*	@pre	A product record(id, name, address) is set.
	*	@post	none.
	*/
	void DisplayRecordOnScreen();

	/*
	*	@brief	Set the product id using keyboard.
	*	@pre	none.
	*	@post	A stududent id is set.
	*/
	void SetCodeNumFromKB();

	/*
	*	@brief	Set the product name using keyboard.
	*	@pre	none.
	*	@post	A stududent name is set.
	*/
	void SetNameFromKB();

	/*
	*	@brief	Set the product price using keyboard.
	*	@pre	none.
	*	@post	A stududent name is set.
	*/
	void SetPriceFromKB();

	/*
	*	@brief	Set the number of a product warehousing.
	*	@pre	none.
	*	@post	A stududent name is set.
	*/
	void SetWarehousingFromKB();

	/*
	*	@brief	Set the number of a sold product.
	*	@pre	none.
	*	@post	A stududent name is set.
	*/
	void SetSalesFromKB();

	/*
	*	@brief	Set the product record(id, name, address) using keyboard.
	*	@pre	none.
	*	@post	A stududent record is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Set the product record except primary key using keyboard.
	*	@pre	none.
	*	@post	A stududent record except primary key is set.
	*/
	void SetRecordExceptPrimaryKeyFromKB();

	/**
   *	@brief	Read data from file.
   *	@pre	the target file is opened.
   *	@post	data is set.
   *	@param	fin	file descriptor.
   *	@return If any element is empty, return false.
   */
	bool ReadDataFromFile(ifstream& fin);


	/**
	*	@brief	Write data into file. Only valid data will be written.
	*	@pre	Target file is opened. List must be initialized.
	*	@post	Target file is written by data.
	*	@param	fin	file descriptor.
	*	@return If any element is empty, return false.
	*/
	bool WriteDataToFile(ofstream& fout);

	/**
	 *  @brief  Compare item with name of content.
	 *  @pre    self, target must valid.
	 *  @post   none.
	 *  @param  target item to compare.
	 *  @return If self and target has same name, return true.
	 */
	bool operator==(const ItemType& target)
	{
		return m_Code == target.m_Code;
	}


	/**
	 *  @brief  Copy item elements into another item.
	 *  @pre    self, target must valid.
	 *  @post   target item elements is replaced with self item elements.
	 *  @param  target target of replacement.
	 */
	void operator=(const ItemType& target)
	{
		m_Code = target.m_Code;
		m_Name = target.m_Name;
		m_Price = target.m_Price;
		m_SalesNum = target.m_SalesNum;
		m_WarehousingNum = target.m_WarehousingNum;
	}
};