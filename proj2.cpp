/**
 * Jonathan Stoll
 * 3-31-23
 * CS 219.1001
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

uint32_t performOperation(const std::string, const uint32_t, const uint32_t);
bool detectOverflow(const std::string, const uint32_t, const uint32_t, const uint32_t);
std::string removeSpaces(const std::string);
uint32_t convertToInt(const std::string);
void printOutput(const std::string, const uint32_t, bool);

int main() {
	// open the input file
  	std::ifstream inputFile("Programming-Project-2.txt");
  	
  	// ensure the file is successfully opened
  	if (!inputFile.is_open()) {
  		std::cout << "Could not open file" << std::endl;
  		return 1;
	}
	
	// iterate through the instructions
  	std::string instr;
	while (getline(inputFile, instr)) {
		// parse the instruction for its operation and arguments
	    std::string op = removeSpaces(instr.substr(0, 3));
	    uint32_t arg1  = convertToInt(removeSpaces(instr.substr(4, 11)));
	    uint32_t arg2  = convertToInt(removeSpaces(instr.substr(17)));
	    
	    // find the result and determine if an overflow occured
	    uint32_t result = performOperation(op, arg1, arg2);
		bool wasOverflow = detectOverflow(op, arg1, arg2, result);
		
		// print the findings
		printOutput(instr, result, wasOverflow);
	}
  	
  	// close the file
  	inputFile.close();
  	
  	return 0;
}

// Takes two unsigned 32 bit integers and an operation to be performed. Performs the operation and returns the result
uint32_t performOperation(const std::string op, const uint32_t a, const uint32_t b) {
	if (op == "ADD")
		std::cout << "adding " << std::hex << a << " + " << b << std::endl;
		return (a + b);
	// this if statement can be expanded to include more operations later
}

// Takes two unsigned 32 bit integers, an operation, and the result of that operation. Uses this information to determine if an overflow has occured
bool detectOverflow(const std::string op, const uint32_t a, const uint32_t b, const uint32_t res) {
	if (op == "ADD") {
		if (a > res || b > res) // When adding numbers, the result should never be less than either of the operands. If it is, an overflow has occured
			return true;
		else 
			return false;
	}
	// this if statement can be expanded to include more operations later
	
	return false;
}

// Takes a std::string possibly containing spaces and returns a version of that string with the spaces removed
std::string removeSpaces(const std::string str) {
	std::string str2 = "";
	
	// Iterate over the characters in str and add them to str2 if they are not spaces
	for (char x : str) {
		if (x != ' ')
			str2.push_back(x);
	}
	
	return str2;
}

// Takes a std::string containing a 32-bit number in hex format and converts it to an integer
uint32_t convertToInt(const std::string str) {
	uint32_t num;   
	std::stringstream ss;
	
	ss << std::hex << str;
	ss >> num;
	
	return num;
}

// Takes the details of an operation and output the results (including overflow detection) in the proper format
void printOutput(const std::string instr, const uint32_t result, const bool wasOverflow) {
	std::cout << instr << ": 0x" << std::uppercase << std::hex << result << std::endl;
	std::cout << "Overflow: " << (wasOverflow ? "yes" : "no") << std::endl;
	std::cout << std::endl;
}
