MiniTalk Project
Overview
The MiniTalk project is a simple client-server communication program that uses UNIX signals (SIGUSR1 and SIGUSR2) to transmit messages. The client sends a message to the server by converting the message into binary format and transmitting each bit as a signal. The server receives these signals, reconstructs the binary message, converts it back to ASCII, and prints the resulting message to the console.

How It Works
Client-Side (client.c):

The client takes two arguments: the server's PID (Process ID) and the message to send.
The message is converted into a binary string using the ft_to_bit function. Each character is represented by 8 bits.
The client sends each bit of the binary string to the server using the kill function:
SIGUSR1 is sent for a binary 1.
SIGUSR2 is sent for a binary 0.
A small delay (usleep(80)) is added between signals to ensure the server has time to process each signal.
Server-Side (server.c):

The server prints its PID at startup and waits for signals indefinitely using the signal function.
When a signal is received:
SIGUSR1 is interpreted as a binary 1.
SIGUSR2 is interpreted as a binary 0.
The server collects 8 bits at a time, converts them into an ASCII character using the ft_convert function, and prints the character to the console.
Signal-Based Communication
Signals Used:

SIGUSR1: Represents a binary 1.
SIGUSR2: Represents a binary 0.
Bit Conversion:

The client converts each character of the message into an 8-bit binary representation.
These bits are sent one by one to the server as signals.
The server reconstructs the binary representation and converts it back to the original character.
Example Usage
Start the server:

The server will print its PID, e.g., Server PID: 12345.

Send a message from the client:

The server will print the message Hello to the console.

Evaluation Questions
Question: What signals are used to represent binary 1 and 0 in the MiniTalk project?
Answer: SIGUSR1 represents binary 1, and SIGUSR2 represents binary 0.

Question: How does the client ensure that the server has enough time to process each signal?
Answer: The client uses usleep(80) to add a delay between sending each signal.

Question: What happens if the client fails to allocate memory for the binary string?
Answer: The client prints an error message ("U goofed the alloc") and exits without sending the message.

Question: How does the server handle the conversion of binary data back into ASCII characters?
Answer: The server collects 8 bits, calculates the ASCII value using powers of 2, and prints the corresponding character.

Question: What is the purpose of the ft_to_bit function in the client?
Answer: The ft_to_bit function converts the message string into a binary representation, where each character is represented by 8 bits.

Question: What is the purpose of the ft_convert function in the server?
Answer: The ft_convert function takes a binary string, converts it into its ASCII equivalent, and prints the corresponding character to the console.

Question: How does the server determine when it has received a full character?
Answer: The server counts the number of bits received using a static variable (bitcount). Once 8 bits are received, it converts the binary string into an ASCII character.

Question: What happens if the bits string in ft_confirm is NULL?
Answer: If bits is NULL, it is initialized using ft_strdup(""), and bitcount is reset to 1.

Question: Why does the ft_convert function use powers of 2 during the conversion process?
Answer: Powers of 2 are used to calculate the decimal value of the binary string, as each bit represents a power of 2 in binary-to-decimal conversion.

Question: What is the role of the write function in ft_convert?
Answer: The write function outputs the converted ASCII character to the standard output (console).
