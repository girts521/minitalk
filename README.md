# Minitalk

This is a simple program that does one thing: sends a message from client to server. Client and server are 2 different processes. 

## How it works?

The way it sends that message is the interesting part. 
The client is communicating to the server using 2 signals: SIGUSR1 and SIGUSR2. Thats it! The client is able to send only SIGUSR1 or SIGUSR2 to the server there is nothing else its able to send. 
Thus, in order to send text message with only 2 signals we have to convert each character in the text message to ASCII number, and then convert that number to binary. 
That way we have the binary representation of each character. At the end of each word I add 00000000 to indicate that the word has ended. 
Now, we are able to use SIGUSR1 or SIGUSR2  to send signal representing 0 or 1 to the server. 

The server then receives these signals and interprets them as a one long binary string. Then decodes it character by character, word by word. And of course displays it. 

It all sounds like a lot of work, but the programm is able to send and display the message almost immediately. 

## How to use?

You can simply clone the repository: 

```git clone git@github.com:girts521/minitalk.git ```

Then compile it with the Makefile: 

``` make ```

After that you will have 2 executable files: server and client. first you need to run the server: ```./server``` then it will output its process id. 
You have to copy the id and leave the server process running. 

In a new terminal window open the folder and run ```./client <process id>  <message> ``` 

##  License

This project is distributed under the MIT License. See the LICENSE file for details.

## Contact
If you have any questions or feedback, feel free to create an issue on this repository.