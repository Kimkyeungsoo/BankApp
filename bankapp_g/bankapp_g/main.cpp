#include <iostream>
#include "AccountHandler.h"

int main()
{
	AccountHandler run;
	int choice = 0;
	bool loop = true;
	while (loop)
	{
		run.ShowMain();
		std::cout << "����: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			run.MakeAccount();
			break;
		case 2:
			run.DepositMoney();
			break;
		case 3:
			run.WithdrawMoney();
			break;
		case 4:
			run.ShowAllAccount();
			break;
		case 5:
			loop = false;
			break;
		default:
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			break;
		}
	}

	return 0;
}