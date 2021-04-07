//
// Created by mindyeoi on 2021/03/29.
//

#ifndef LAB03_AGAIN_AGAIN_APPLICATION_H
#define LAB03_AGAIN_AGAIN_APPLICATION_H


#pragma once

#include <iostream>
#include <fstream>
#include "SortedList.h"
#include "BasketType.h"
#include "CategoryType.h"
//using namespace std;

class Application
{
private:
    ifstream m_inFile;	// input file descriptor
    ofstream m_outFile;	// output file descriptor
    SortedList m_List;	// masterList
    BasketType m_basket;
    CategoryType m_cate;
    int m_Command;		// current command number



public:
    Application()
    {
        m_Command = 0;
    }

    ~Application() {}

    /*
*	@brief	Add new content into list. Target content is set with Keyboard input.
*	@pre	list should be initialized.
*	@post	new content is added into the list.
*	@return	return true if this function works well, otherwise false.
*/
    bool AddProductToBasket();

    /**
   *	@brief	Manage the basket.
   *	@pre	basket should be initialized.
   *	@post	basket may be changed.
   *	@return	return true if this function works well, otherwise false.
   */
    bool ManageBasket();

    /**
 *	@brief	Manage the category.
 *	@pre	The category should be initialized.
 *	@post	The category may be changed
 *	@return	return true if this function works well, otherwise false.
 */
    bool ManageCategory();


    /*
    *	@brief	Display command on screen and get a input from keyboard.
    *	@pre	none.
    *	@post	none.
    *	@return	user's command.
    */
    int GetCommand();

    /*
   *	@brief	Display All content data from list.
   *	@pre	list should be initialized.
   *	@post	none.
   *	@return	return true if this function works well, otherwise false.
   */
    bool DisplayAllRecords();

    /*
*	@brief	Open a file as a write mode, and write all data into the file,
*	@pre	The file is not opened.
*	@post	the list is stored in the output file.
*	@return	return true if this function works well, otherwise false.
*/
    bool WriteDataToFile();


    /*
    *	@brief	Open a file by file descriptor as an input file.
    *	@pre	a file for reading is exist.
    *	@post	open the file for reading.
    *	@param	fileName	a filename to open for reading.
    *	@return	return true if this function works well, otherwise false.
    */

    /*
 *  @brief  Clear List.
 *  @pre    none.
 *  @post   list is empty.
 */
    void MakeEmpty();

    /*
*	@brief	Add new content into list. Target content is set with Keyboard input.
*	@pre	list should be initialized.
*	@post	new content is added into the list.
*	@return	return true if this function works well, otherwise false.
*/
    bool AddProduct();

    /*
*	@brief	Open a file by file descriptor as an inputput file.
*	@pre	list should be initialized.
*	@post	open the file for writing.
*	@param	fileName	a filename to open for writing.
*	@return	return true if this function works well, otherwise false.
*/
    bool OpenInFile(string fileName);


    /*
    *	@brief	Open a file by file descriptor as an output file.
    *	@pre	list should be initialized.
    *	@post	open the file for writing.
    *	@param	fileName	a filename to open for writing.
    *	@return	return true if this function works well, otherwise false.
    */
    bool OpenOutFile(string fileName);


    /*
    *	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
    *	@pre	The file is not opened.
    *	@post	list holds all records from the file.
    *	@return	return true if this function works well, otherwise false.
    */
    bool ReadDataFromFile();


    /*
     *  @brief  Run application.
     *  @pre    application is started.
     *  @post   application is finished.
     */
    void Run();


    /*
    *	@brief  Search a record by product code entered by keyboard.
    *	@pre	list must have one or more item.
    *	@post	none.
    *	@return	return true if this function works well, otherwise false.
    */
    bool RetrieveProductByCode();

    /*
    *	@brief  Search a record by product code entered by keyboard using binary search.
    *	@pre	list must have one or more item.
    *	@post	none.
    *	@return	return true if this function works well, otherwise false.
    */
    bool RetrieveProductByCodeUsingBS();

    /*
    *	@brief  Search a record by name entered by keyboard.
    *	@pre	list must have one or more item.
    *	@post	none.
    *	@return	return true if this function works well, otherwise false.
    */
    bool RetrieveProductByName();

    /*
    *	@brief  Delete a record by using resident number entered by keyboard.
    *	@pre	list must have one or more item.
    *	@post	none.
    *	@return	return true if this function works well, otherwise false.
    */
    bool DeleteProduct();

    /*
    *	@brief  Replace a record by using a record entered by keyboard.
    *	@pre	list must have one or more item.
    *	@post	none.
    *	@return	return true if this function works well, otherwise false.
    */
    bool ReplaceProduct();


    //
    //		/*
    //	*	@brief	Display the products in the basket.
    //	*	@pre	the basket is not empty
    //	*	@post	none
    //	*	@return return true if this function works well, otherwise false.
    //	*/
    //		bool DisplayProductsInBasket();
    //
    //		/*
    //	*	@brief	Calculate the amound of the all product.
    //	*	@pre	the basket is not empty and the price is initialized.
    //	*	@post	none
    //	*	@return	return true if this function works well, otherwise false.
    //	*/
    //		bool ComputeTotal();
};

#endif //LAB03_AGAIN_AGAIN_APPLICATION_H
