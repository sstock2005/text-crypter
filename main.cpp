#include <iostream>
#include "b64.h"

std::string encrypt(std::string input, std::string password) 
{
	std::string encrypted{};
	for (int i = 0; i < password.size(); i++)
	{
		for (int l = 0; l < input.size(); l++)
		{
			encrypted += static_cast<char>((static_cast<int>(input[l]) - static_cast<int>(password[i])));
		}
		break;
	}
	return b64encode(encrypted);
}

std::string decrypt(std::string encrypted, std::string password) 
{
	std::string input{ b64decode(encrypted) };
	std::string decrypted{};
	for (int m = 0; m < password.size(); m++)
	{
		for (int p = 0; p < input.size(); p++)
		{
			decrypted += static_cast<char>((static_cast<int>(input[p]) + static_cast<int>(password[m])));
		}
		break;
	}
	return decrypted;
}

int main() 
{
	std::cout << "						   Sam's Crypter | V1" << "\n";
	std::string password{};
	std::cout << "Password: ";
	std::getline(std::cin, password);
	std::string input{};
	std::cout << "Input: ";
	std::getline(std::cin, input);
	std::string encrypted = encrypt(input, password);
	std::cout << "Encrypted String: " << encrypted << "\n";
	std::cout << "Decrypted String: " << decrypt(encrypted, password) << "\n";
}