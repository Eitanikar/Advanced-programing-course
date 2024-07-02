#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
	int accountNumber,
		code,
		balance;
	string email;

public:
	Account();
	Account(int accountNumber, int code, int balance, string email);

	int getAccountNumber();
	int getCode();
	int getBalance();
	string getEmail();

	friend istream& operator>>(istream& is, Account& A);

	Account withdraw(int nis);
	Account deposit(int);

	static int sumWithdraw;
	static int sumDeposit;

	static int getSumWithdraw();
	static int getSumDeposit();
};