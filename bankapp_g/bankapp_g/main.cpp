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
		std::cout << "선택: ";
		std::cin >> choice;

		switch (choice)
		{
		case Sellect::MAKE:
			run.AccountType();
			break;
		case Sellect::DEPOS:
			run.DepositMoney();
			break;
		case Sellect::WITHDRAW:
			run.WithdrawMoney();
			break;
		case Sellect::SHOW:
			run.ShowAllAccount();
			break;
		case Sellect::EXIT:
			loop = false;
			break;
		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			break;
		}
	}

	return 0;
}