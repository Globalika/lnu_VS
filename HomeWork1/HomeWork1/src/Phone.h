#pragma once
#include <string>

class Phone
{
public:
	Phone(int phoneNumber, std::string phoneModel, int phoneDiagonal);

	void SetPhoneNumber(int phoneNumber);
	void SetPhoneModel(std::string phoneModel);
	void SetPhoneDiagonal(int phoneDiagonal);

	void PrintPhoneInfo();

	int GetPhoneNumber();
	std::string GetPhoneModel();
	int GetPhoneDiagonal();

private:
	int phoneNumber;
	std::string phoneModel;
	int phoneDiagonal;
};