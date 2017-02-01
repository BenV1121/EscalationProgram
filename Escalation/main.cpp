#include <fstream>
#include <sstream>
#include <iostream>

// open, close, is_open, <<, >>, getline
// app (opens at the end of a file for writing)
// in  (opens at beginning of the file for reading)
// out (create/overwrite the original file)

void main()
{
	std::fstream file;

	file.open("data.txt"); // try and open the file
	if (!file.is_open())   // if it fails to open, make it
	{
		file.close();	   // close the failed opening
		file.open("data.txt", std::ios_base::out); // make file
	}
	file.close(); // close the made file


	int option;
	do
	{
		std::cout << "Input 1,2,3,4 for app, in, clear, exit respectively: ";
		std::cin >> option;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		switch (option)
		{
		case 1: // appending from console to file			
			file.open("data.txt", std::ios_base::app);
			if (file.is_open())
			{
				std::cout << "Input line to append to file: ";
				std::string temp;
				std::getline(std::cin, temp);
				file << temp << std::endl;
			}
			else std::cout << "File failed to open for writing." << std::endl;
			file.close();
			break;

		case 2: // displaying the file
			file.open("data.txt", std::ios_base::in);
			if (file.is_open())
			{
				std::cout << "File Contents: " << std::endl;
				std::string temp;
				while (std::getline(file, temp))
					std::cout << temp << std::endl;
			}
			else std::cout << "File failed to open for reading." << std::endl;
			file.close();
			break;

		case 3: // clearing the file
			file.open("data.txt", std::ios_base::out);
			std::cout << "Clearing file contents." << std::endl;
			file.close();
			break;

		default:
			std::cout << "Please pick a valid option." << std::endl;
			break;
		case 4:
			std::cout << "Goodbye!" << std::endl;
			system("pause");
			break;
		}
		std::cout << std::endl;
	} while (option != 4);
}