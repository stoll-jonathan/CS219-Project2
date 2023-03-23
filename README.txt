HOW TO RUN
To compile the main cpp file, use "g++ proj2.cpp -o proj2" in the terminal. You can then run the executable with "./proj2".

WORKING PROCESS
The main function opens and reads the input file. Assuming the file is opened successfully, the text will be parsed line by line, treating each 
as a separate instruction. Each instruction will be stored in a string and that string will then be split to parse the operation and operands. 
The first four characters are stored in the "op" variable, the next 7 in "arg1", and the remainder in "arg2". These substrings are parsed to 
remove any whitespace, and the operands are converted to ints. Because the integers are stored as uint_32t, the "0x" prefixes are automatically 
ignored during mathematical operations. The performOperation function is then called, and its return value is stored in the "result" variable. 
The function consists of an if statement which will perform the appropriate bitwise operation according to the instruction. All operations are
performed using built-in C++ operators. Flags are then detected based on the result and a final function is called to format and output the data.

FLAG DETECTION LOGIC
The N flag is set if the result is less than zero, the Z flag is set if the result equals 0.

RESULTS
explain the result
