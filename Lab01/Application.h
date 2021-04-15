#pragma once
#pragma once

#include <iostream>
#include <fstream>
#include "UnsortedList.h"
using namespace std;

class Application
{
private:
	ifstream m_inFile;	// input file descriptor
	ofstream m_outFile;	// output file descriptor
	ArrayList m_List;	// item list
	int m_Command;		// current command number

public:
	Application()
	{
		m_Command = 0;
	}

	~Application() {}



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
	*	@brief  Search a record by resident number entered by keyboard.
	*	@pre	list must have one or more item.
	*	@post	none.
	*	@return	return true if this function works well, otherwise false.
	*/
	bool RetrieveProductByCode();

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
};