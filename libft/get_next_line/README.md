*This project has been created as part of the 42 curriculum by moalnajj*

## Description
This project aims to build a function that make yoou able to read one line a time from a file discreptor,and it makes sure not to cause any memory leak.

## Instructions
In order to compile the project, you should follow the following steps :\
1. clone the repository.

2. Write a main.c file or whatever you name it

3. compile your file with get_next_line.c and get_next_line_utils.c (do not forget do include the get_next_line.h library)
## Resources
I relied in understanding File Descriptors on these youtube videos :
- [Educational innovation](https://youtu.be/WCrTRPu1bQk?si=n9pR5Qae2xlUiXSp)
- [Tech Fairy](https://youtu.be/saMebwRO-Q8?si=vpU6sAfZ1-feYaNL)

 I used AI just to give me test cases including edge cases.

 ## Additional sections
The algorthim used is about reading from the file BUFFER_SIZE amount of bytes the user enter (or default value if he did not enter), then I look in the string returned from the read operation for an '\n' or '\0' (using ft_find_chr function)then i store its index in index variable and then I do strjoin for the string returned from the read (lets say its name is string1) and the string reserved from previous read operations (if there were other previous operations) and i make a new string that has the whole string preserved from previous read operations and string1 till the index that has the same value of variable index then i check if the index refers to '\n' if so then I read a whole line so i call a function called cut to make sure that i have not read bytes from upcoming lines, if i did so then i have to cut those remainning and store them in static variable (so I can store them for next calls of get_next_line function), for the next calls I make sure that remainning variable is empty (that means I did not read bytes from next lines) if not empty then i have to do the same operation as mentioned above,but if i did not find '\n' in the remainning that means that i have not finished reading the whole line which requries me to continue reading.   