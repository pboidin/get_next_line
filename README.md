# get_next_line
Whether it's a file, stdin, or even later a network connection, you will always need a way to read the content line by line. It's time to start working on this feature, which will be essential for your future projects.

Goals
This project will not only allow you to add a very useful function to your collection, but also to learn about a surprising new element of C programming: static variables.

Description
Write a function that returns a line read from a file descriptor
- Successive calls to your get_next_line() function should allow you to read the entire text file referenced by the file descriptor, one line at a time.
- Your function should return the line that has just been read. If there is nothing left to read, or if there is an error, it must return NULL.
- Make sure your function behaves correctly whether it reads a file or reads from standard input.
- Important: You must always return the line that was read followed by the ending \n, except in the case where you have reached the end of the file and the file does not end with an \n.
- The get_next_line.h header file must contain at least the prototype of the function.
- The file get_next_line_utils.c will be used to add additional functions needed to realize your get_next_line().
- Your program must compile with the option: -D BUFFER_SIZE=n.
  This macro defined at the compiler invocation will be used to specify the size of the buffer when you call read() in your get_next_line() function.
  This value will be modified during the peer-evaluation and by the Moulinette in order to test your rendering. to test your rendering.
- Your program will be compiled in the following way (example below with a buffer size of 42):
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
- We consider that get_next_line() has an undetermined behavior if, between two calls, the file pointed to by the file descriptor has been modified, while the the first file has not been read in full.
- We also consider that get_next_line() has an undetermined behavior in case of when reading a binary file. However, if you wish, you can make this behavior consistent.

Bonus part
Because of its simplicity, the get_next_line project leaves little room for bonuses, but we are sure you have a lot of imagination. If you have succeeded in the mandatory part, then feel free to do the bonuses to go further.
Here are the bonuses to do:
- Do get_next_line() with a single static variable.
- Complete get_next_line() by allowing it to handle multiple fd.
For example, if fd's 3, 4 and 5 are readable, then it is possible to read them each in turn without ever losing the contents read on each of the fd's, and without returning the wrong line.
You should be able to call get_next_line() once with fd 3, then 4, then 5, then 3 again, then 5 again. 5, then 3 again, 4 again, etc.
Add the suffix _bonus[c\h] to the files in this part.
Thus, in addition to the 3 files in the required part, you will render the following 3 files:
- get_next_line_bonus.c
- get_next_line_bonus.h
- get_next_line_utils_bonus.c
