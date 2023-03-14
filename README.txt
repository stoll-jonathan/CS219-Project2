HOW TO RUN
To compile the main cpp file, use "g++ proj1.cpp -o proj1" in the terminal. You can then run the executable with "./proj1".

WORKING PROCESS
The main function opens and reads the input file. If the file cannot be read, the program will output "Could not read file" and close
with exit status 1. Assuming the file is opened successfully, the text will be parsed line by line, treating each as a separate instruction.
Each instruction will be stored in a string and that string will then be split to parse the operation and operands. The first four
characters are stored in the "op" variable, the next 7 in "arg1", and the remainder in "arg2". These substrings are parsed to remove any
whitespace, and the operands are converted to ints. Because the integers are stored as uint_32t, the "0x" prefixes are automatically ignored
during mathematical operations. Functions are then called to perform the operation and detect overflows, with their results saved in variables.
Finally, the program calls one last function to properly format and output the data.

OVERFLOW DETECTION LOGIC
In unsigned addition, an overflow occurs when there is a carry out from the MSB. Since any extra bits are removed automatically, 
we must detect overflow by analysing the results logically. When an addition is performed, the sum is always greater than either
of the addends. Therefore, if the result is smaller than one or both of the addends, we know that an overflow must have occurred.

RESULTS
0x1 + 0x1 = 0x2: This result is correct, and since both addends are less than the result, there is NO overflow.
0xAAA5555 + 0x555AAAA = 0xFFFFFFF: This result is correct, and since both addends are less than the result, there is NO overflow.
0xFFFFFFFF + 0x1 = 0x0: This result is correct, but the result is less than 0xFFFFFFFF, so there IS an overflow.
0x1234 + 0x8765 = 0x9999: This result is correct, and since both addends are less than the result, there is NO overflow.
0x72DF9901 + 0x2E0B484A = 0xA0EAE14B: This result is correct, and since both addends are less than the result, there is NO overflow.