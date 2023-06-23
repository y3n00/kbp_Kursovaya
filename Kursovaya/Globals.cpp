#include "Globals.h"
std::string CaesarEncrypt(std::string_view str, int key) {
	std::string out{str};
	for (auto& ch : out)
		ch += key;
	return out;
}

std::string CaesarDecrypt(std::string_view str, int key) {
	return CaesarEncrypt(str, -key);
}

std::string string_cast(System::String^ str) {
	return msclr::interop::marshal_as<std::string>(str);
}

System::String^ string_cast(std::string str) {
	return msclr::interop::marshal_as<System::String^>(str);
}

std::string currentUsername;