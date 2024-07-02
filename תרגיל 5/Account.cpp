#include"Account.h"


bool isGoodEmail(string email) {
	int index = email.find('@');
	if ((!(email.find(".com", index + 1) == -1)) || !(email.find(".co.il", index + 1) == -1)) {
		return true;
	}
	return false;
}

Account::Account() {
	this->accountNumber = 0;
	this->code = 0;
	this->balance = 0;
	this->email = "";
}

Account::Account(int accountNumber, int code, int balance, string email) {
	if (accountNumber < 0 || code > 9999 || balance > 0 || !isGoodEmail(email) ) {
		this->accountNumber = 0;
		this->balance = 0;
		this->code = 0;
		this->email = "";
	}
	if (code > 9999 || code <= 999)
		throw "ERROR: code must be of 4 digits!\n";
	/*else if ()
		throw "ERROR: account number must be unique!\n";*/
	else if (email.find('@') == -1)
		throw "ERROR: email must contain @!\n";
	else if(!isGoodEmail(email))
		throw "ERROR: email must end at.com or .co.il!!\n";
	else
		this->code = code;
		this->balance = balance;
		this->email = email;
		this->accountNumber = accountNumber;
}

int Account::getAccountNumber() {
	return accountNumber;
}
int Account::getCode() {
	return code;
}
int Account::getBalance() {
	return balance;
}
string Account::getEmail() {
	return email;
}

istream& operator>>(istream& is, Account& A) {
	int accNum, code;
	string email;
	is >> accNum >> code >> email;
	if (accNum > 0 && code > 1000 && code < 9999 && isGoodEmail(email)) {
		Account tmp(accNum, code, 0, email);
		A = tmp;
		return is;
	}
	else
	{
		Account tmp(0, 0, 0, "");
		A = tmp;
		return is;
	}
}

Account Account::withdraw(int nis) {
	if (nis < 2500) {
		if(this->balance - nis < -6000)
			throw "cannot have less than - 6000 NIS!\n";
		else 
			this->balance -= nis;
			return *this;
	}
	else
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
}

Account Account::deposit(int nis) {
	if (nis < 10000) {
		this->balance += nis;
		return *this;
	}
	else
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
}

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

int Account::getSumWithdraw() {
	return sumWithdraw;
}
int Account::getSumDeposit() {
	return sumDeposit;
}