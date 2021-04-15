#include "Application.h"
#include <iostream>
#include <iomanip>
#include <string>

#define WIDTH 40
#define MAXCOMMANDS 9
using namespace std;

int Application::GetCommand()
{
	int select;
	while (1) {

		cout << "\t=" << setw(WIDTH + 1) << setfill('=') << "=\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  0: Quit" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  1: Display All Records" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  2: Read Data From File" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  3: Write Data to File" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  4: Empty Data in List" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  5: Add a Record" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  6: Delete a Record" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  7: Replace a Record" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  8: Retrieve by Resident Number" << "|\n";
		cout << "\t|" << left << setw(WIDTH) << setfill(' ') << "  9: Retrieve by name" << "|\n";
		cout << "\t=" << right << setw(WIDTH + 1) << setfill('=') << "=\n";
		cout << "\t  Select a function --> ";

		if (cin.fail() || !(cin >> select) || select < 0 || select>MAXCOMMANDS)	// input fail or input value is out of bound
		{
			cout << "\t    ### Invalid Command Number. Select again  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return select;
		}
	}
}

void Application::Run()
{
	while (true)
	{
		m_Command = GetCommand(); // Get command value from keyboard

		// Command execution
		switch (m_Command)
		{
		case 0:
			return;
		case 1:// display all records on screen
			DisplayAllRecords();
			break;
		case 2:  // read data from file
			ReadDataFromFile();
			break;
		case 3:  // write data to file
			WriteDataToFile();
			break;
		case 4: // empty list
			MakeEmpty();
			break;
		case 5: // add a record to list
			AddProduct();

			break;
		case 6:	// delete a record
			DeleteProduct();
			break;
		case 7: // Replace a record
			ReplaceProduct();
			break;
		case 8:
			RetrieveProductByCode();
			break;
		case 9:
			RetrieveProductByName();
			break;
		default:
			cout << "\t [!]ERROR Illegal selection...\n";
			break;
		}
	}
}



/**
*	@brief	Display All content data from list.
*	@pre	list should be initialized.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::DisplayAllRecords()
{
	cout << "\t-------------- All records --------------" << "-\n";

	if (m_List.isEmpty()) // If list is empty, show below error
	{
		cout << "\t [!] There's no data to show" << endl;
		return false;
	}

	m_List.ResetList();
	ItemType data;
	int index;
	// Loop all item in the list
	while ((index = m_List.GetNextItem(data)) != -1)
	{
		cout << "\t " << index << ".";
		data.DisplayRecordOnScreen();
		cout << endl;
	}

	return true;
}


/**
*	@brief	Open a file by file descriptor as an input file.
*	@pre	a file for reading is exist.
*	@post	open the file for reading.
*	@param	fileName	a filename to open for reading.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::OpenInFile(string fileName)
{
	m_inFile.open(fileName);

	if (m_inFile) // Check opened file valid
	{
		return true;
	}

	cout << "\n\t [!]ERROR There's no such File" << endl;
	return false;
}


/**
*	@brief	Open a file by file descriptor as an output file.
*	@pre	list should be initialized.
*	@post	open the file for writing.
*	@param	fileName	a filename to open for writing.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::OpenOutFile(string fileName)
{
	m_outFile.open(fileName);

	if (m_outFile) // Check opened file valid
	{
		return true;
	}

	return false;
}



/**
*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
*	@pre	The file is not opened.
*	@post	list holds all records from the file.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::ReadDataFromFile()
{
	ItemType readData;
	string fileName;

	cout << "\n\t Enter a Filename to Read : ";
	cin >> fileName;

	if (!OpenInFile(fileName)) return false;

	bool hasMissingData = false;
	int readDataCount = 0;
	while (!m_inFile.eof())
	{
		if (readData.ReadDataFromFile(m_inFile)) // Add only valid data
		{

			m_List.Add(readData);
			readDataCount++;
		}
		else
		{
			hasMissingData = true;
		}
	}

	if (hasMissingData) // If missing data exist, show below error
	{
		cout << "\n\t [!] There's missing data due to invalid element \n";
	}

	m_inFile.close();
	cout << "\n\t " << readDataCount << " data have been successfully read from '"
		<< fileName << "'" << endl;

	return true;
}


/**
 *  @brief  Clear List.
 *  @pre    none.
 *  @post   list is empty.
 */
void Application::MakeEmpty()
{
	if (!(m_List.isEmpty()))
	{
		m_List.MakeEmpty();

		cout << "\t [!] All item have been removed" << endl;
	}
	else
	{
		cout << "\t [!] There's no item to remove" << endl;
	}
}


/**
*	@brief	Open a file as a write mode, and write all data into the file,
*	@pre	The file is not opened.
*	@post	the list is stored in the output file.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::WriteDataToFile()
{
	int length = m_List.GetLength();
	if (length <= 0)
	{
		cout << "\n\t [!]ERROR There's no data to save" << endl;
		return false;
	}

	string fileName;

	cout << "\n\t Enter a Filename to Save : ";
	cin >> fileName;

	if (!OpenOutFile(fileName)) return false;

	m_List.ResetList();
	ItemType data;

	bool hasInvalidData = false;
	int index;

	while ((index = m_List.GetNextItem(data)) != -1)
	{
		if (!data.WriteDataToFile(m_outFile)) // Write only valid data
		{
			hasInvalidData = true;
		}
	}

	if (hasInvalidData) // If invalid data exist, show below error
	{
		cout << "\n\t [!] There's data that has not been written due to invalid element value" << endl;
	}

	m_outFile.close();
	cout << "\n\t " << length << " data have been successfully saved as '" << fileName << "'" << endl;

	return true;
}



bool Application::AddProduct()
{
	if (m_List.IsFull()) // Check list is full
	{
		cout << "\n\t [!] List is Full" << endl;
		return false;
	}

	ItemType item;
	item.SetRecordFromKB();

	m_List.Add(item);

	return true;
}

/*
*	@brief  Search a record by resident number entered by keyboard.
*	@pre	list must have one or more item.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::RetrieveProductByCode()
{
	if (m_List.isEmpty()) // If list is empty, show below error
	{
		cout << "\t [!] There's no data to show" << endl;
		return false;
	}

	m_List.ResetList();		// m_pointercur = -1; 로 해줌
//	int length = m_List.GetLength(); // 굳이 안쓰니까 일단 주석..!

	ItemType item;
	item.SetCodeNumFromKB();

	int index = m_List.Retrieve(item);

	if (index == -1)
	{
		cout << "\t [!] There's no data with that Code\n";
		return false;
	}
	else
	{
		cout << "\t---------- Retrieved Item -----------" << endl;
		item.DisplayRecordOnScreen();
		cout << endl;
		return true;
	}
}

/*
*	@brief  Search a record by name entered by keyboard.
*	@pre	list must have one or more item.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::RetrieveProductByName()
{
	if (m_List.isEmpty()) // If list is empty, show below error
	{
		cout << "\t [!] There's no data to show" << endl;
		return false;
	}

	ItemType data;
	string inName;
	cout << "\t Enter the name of product -->";
	cin >> inName;
	m_List.ResetList();
	int index;
	// Loop all item in the list
	while ((index = m_List.GetNextItem(data)) != -1)
	{
		if (data.GetName() == inName)
		{
			cout << "\t---------- Retrieved Item -----------" << endl;
			data.DisplayRecordOnScreen();
			cout << endl;
			return true;
		}
	}

	// If item is not found...
	cout << "\t [!]ERROR There's no such item with that name" << endl;
	return false;
}

/*
*	@brief  Delete a record by using resident number entered by keyboard.
*	@pre	list must have one or more item.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::DeleteProduct()
{

	if (m_List.isEmpty()) // If list is empty, show below error
	{
		cout << "\t [!] There's no data to delete" << endl;
		return false;
	}

	m_List.ResetList();		// m_pointercur = -1; 로 해줌
//	int length = m_List.GetLength(); // 굳이 안쓰니까 일단 주석..!

	ItemType item;
	item.SetCodeNumFromKB();

	int index = m_List.Retrieve(item);

	if (index == -1)
	{
		cout << "\t [!] There's no data with that Resident Number\n";
		return false;
	}
	else
	{

		m_List.Delete(item);
		cout << "\t Successfuly deleted." << endl;
		return true;
	}
}

/*
*	@brief  Replace a record by using a record entered by keyboard.
*	@pre	list must have one or more item.
*	@post	none.
*	@return	return true if this function works well, otherwise false.
*/
bool Application::ReplaceProduct()
{
	if (m_List.isEmpty()) // If list is empty, show below error
	{
		cout << "\t [!] There's no data to delete" << endl;
		return false;
	}

	m_List.ResetList();		// m_pointercur = -1; 로 해줌
//	int length = m_List.GetLength(); // 굳이 안쓰니까 일단 주석..!

	ItemType item;
	item.SetCodeNumFromKB();

	int index = m_List.Retrieve(item);

	if (index == -1)
	{
		cout << "\t [!] There's no data with that Resident Number\n";
		return false;
	}
	else
	{
		cout << "\t (new name)\n";
		item.SetRecordExceptPrimaryKeyFromKB();
		m_List.Replace(item);
		cout << "\t Successfuly Replaced." << endl;
		return true;
	}
}