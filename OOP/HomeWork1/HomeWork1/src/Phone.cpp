#include "Phone.h"
#include "iostream"

Phone::Phone(int phoneNumber, std::string phoneModel, int phoneDiagonal)
{
	this->phoneNumber = phoneNumber;
	this->phoneModel = phoneModel;
	this->phoneDiagonal = phoneDiagonal;
}

void Phone::SetPhoneNumber(int phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Phone::SetPhoneModel(std::string phoneModel)
{
	this->phoneModel = phoneModel;
}

void Phone::SetPhoneDiagonal(int phoneDiagonal)
{
	this->phoneDiagonal = phoneDiagonal;
}

void Phone::PrintPhoneInfo()
{
	std::cout << "Phone Info :";
	std::cout << "\nNumber : " << this->phoneNumber
			  << "\nModel : " << this->phoneModel
			  << "\nDiagonal : " << this->phoneDiagonal;
}

int Phone::GetPhoneNumber()
{
	return this->phoneNumber;
}

std::string Phone::GetPhoneModel()
{
	return this->phoneModel;
}

int Phone::GetPhoneDiagonal()
{
	return this->phoneDiagonal;
}
