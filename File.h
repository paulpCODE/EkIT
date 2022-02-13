#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace Files {

	class oFile : public std::ofstream
	{
		oFile(const oFile&) = delete;
		const oFile& operator = (const oFile& of) = delete;

	public:
		oFile(const std::string& path) : std::ofstream(path) {
			if (!is_open()) {
				std::cout << "FILE DOES NOT OPENED!";
				exit(0);
			}
		};
		~oFile() {
			close();
		};
	};

	//Input file
	/*class iFile : public std::ifstream
	{

		iFile(const iFile&) = delete;
		const iFile& operator = (const iFile& of) = delete;

	public:
		iFile(const std::string& path) : std::ifstream(path) {
			if (!is_open()) {
				std::cout << "FILE " + path + " DOES NOT OPENED!";
				exit(0);
			}
		};
		~iFile() {
			close();
		};

		const std::string readAll() {
			std::string data;
			char ch;
			while (!eof()) {
				ch = get();
				data += ch;
			}
			
			return data;
		}
	};*/


	template<class T>
	void writeToOutputTxt(const T& data) {
		oFile("output.txt") << data;
	}

}

