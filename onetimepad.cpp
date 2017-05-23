#include <iostream>
#include <string>

std::string one_time_pad(const std::string message, const std::string key)
{
	std::string encrypted{ message };
	for (unsigned int i = 0; i < message.size(); i++) {
		encrypted.at(i) = (message.at(i) ^ key.at(i));  //Encryption Code
	}
	return encrypted;
}

int main()
{
	std::string message{};
	std::string key{};

	std::getline(std::cin, key);
	std::cout << "Original key [" << key << "]" << std::endl;

	while (std::getline(std::cin, message)) {                          // Program continues until no more messages can be read
		std::cout << "Original message [" << message << "]" << std::endl;
		if (message.size() > key.size()) {  //Error case
			std::cout << "Error: the length of the key [" << key.size() << "] is smaller than the length of the message to encrypt [" << message.size() << "]" << std::endl;
			exit(1);
		}
		std::cout << "Encrypted [" << one_time_pad(message, key) << "]" << std::endl;       //Encrypted message
		std::cout << "Decrypted [" << one_time_pad(one_time_pad(message, key), key) << "]" << std::endl;            //Decrypted message
	}

	return 0;
}
