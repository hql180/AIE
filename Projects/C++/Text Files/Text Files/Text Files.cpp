#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string command;
	
	while (true)
	{
		fstream file;

		file.open("MyLog.txt", ios::app | ios::in);

		cout << "Would you like to read, write, clear or exit?\n";
		getline(cin, command);

		if (command == "read" || command == "Read")
		{
			string readLine;
			while (getline(file, readLine))
			{
				cout << "\n" << readLine;
			}
			cout << "\n";
			cout << "\n End of file\n\n";
		}
		else if (command == "write" || command == "Write")
		{
			cout << "\n";
			cout << "What would you like to write to the file?\n";
			string input;
			getline(cin, input);
			file << input << "\n";
			cout << "\n Text has been written to file\n\n";
		}
		else if (command == "clear" || command == "Clear")
		{
			cout << "\n";
			file.close();
			file.open("MyLog.txt", ios::out | ios::trunc);
			cout << "File contents have been cleared\n\n";
		}
		else if (command == "exit" || command == "Exit")
		{
			cout << "\n";
			file.close();
			cout << "File closed\n";
			break;
		}
		file.close();
	}
	

	
	system("pause");
    return 0;
}

