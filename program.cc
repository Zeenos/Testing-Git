#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

void display_menu();
void encrypt();
void decrypt(); //Function prototypes

int main()
{
  char user_response;
  
  do  //do-while loop to continuously display menu until 3 is inputted
  {
    display_menu(); //Function call to display menu and response options
  
    cin >> user_response; //User enters response to menu options
  
    switch(user_response) //switch loop to allow user to input answers to menu
    {
      case '1':
        encrypt();  //Calls encryption function if 1 is selected
        break;
      case '2':
        decrypt();  //Calls decryption function if 2 is selected
        break;
      case '3':
        cout << endl << "Goodbye.\n\n"; //Ends program and outputs farewell when 3 is entered
        break;
      default:
        cout << "\nThat is not a valid response. Try again.\n"; //Outputs this when neither 1, 2, nor 3 are entered
        cin.clear();
        cin.ignore(10000, '\n');  //These clear cin so that the input entered into user_response don't carry over to the later cin.getline functions and cause them to skip
    }
  }
  while (user_response != '3'); //Exits loop when user_response = 3

  return EXIT_SUCCESS;
}

void display_menu() //Function that displays menu to screen
{
  cout << "\n1. Encrypt a message.\n2. Decrypt a message.\n3. Quit\n\n";
}

void encrypt()  //Function to encrypt a message
{
  int count = 100, even_subscript = 0, odd_subscript = 1, char_count = 0, even_count = 0, odd_count = 0;
  char message[count];
  char even_segment[count];
  char odd_segment[count];
  char character; //Necessary declarations and initializations
  
  cin.clear();
  cin.ignore(10000, '\n');  //Clears input from user_response so it won't carry over to cin.getline and cause it to skip
  
  cout << endl << "Please enter a message that you would like to be encrypted.\n";
  cin.getline(message, count);  //Recieves messages that user inputs into terminal and puts it into an array of characters
  
  for (int i = 0; i < count; i++) //For loop to count how many characters the user entered into the char array
  {
    if (message[i] == '\0')
      break;
    else
      char_count++;
  }
  
  for (int i = 0; i < char_count; i++)  //For loop to input into even_segment char array
  {
    if (even_subscript > char_count)  //If the count of even subscripts surpasses the actual amount of characters in the previously initialized array the for loop will break
      break;
    else  //Inputs characters corresponding to even subscripts from initialized array into a new array
    {
      character = message[even_subscript];
      even_segment[i] = character;
      even_subscript += 2;
      even_count++;
    }
  }
  
  for (int i = 0; i < char_count; i++)  //For loop to input into odd_segment char array
  {
    if (odd_subscript > char_count)  //If the count of odd subscripts surpasses the actual amount of characters in the previously initialized array the for loop will break
      break;
    else  //Inputs characters corresponding to odd subscripts from initialized array into a new array
    {
      character = message[odd_subscript];
      odd_segment[i] = character;
      odd_subscript += 2;
      odd_count++;
    }
  }
  
  cout << endl;
  
  for (int i = 0; i < even_count; i++)  //Outputs the encrypted message to the screen, concatenating the characters corresponding to the odd subscripts onto the characters corresponding to the even subscripts
    cout << even_segment[i];
  for (int i = 0; i < odd_count; i++)
    cout << odd_segment[i];
  cout << endl;
}

void decrypt()  //Function to decrypt a message
{
  int count = 100, even_subscript, odd_subscript, decrypted_subscript, char_count = 0, even_count = 0, odd_count = 0;
  char encrypted_message[count];
  char decrypted_message[count];
  char character; //Necessary declarations and initializations
  
  cin.clear();
  cin.ignore(10000, '\n');  //Clears input from user_response so it won't carry over to cin.getline and cause it to skip
  
  cout << endl << "Please enter a message that you would like to be decrypted.\n";
  cin.getline(encrypted_message, count); //User inputs a message that he would like to be decrypted
  
  for (int i = 0; i < count; i++) //For loop to count the number of characters that the user entered into the array
  {
    if (encrypted_message[i] == '\0')
      break;
    else
      char_count++;
  }
  
  for (even_subscript = 0; even_subscript < char_count; even_subscript += 2)  //For loop to count the number of characters that correspond to even subscripts in the array
    even_count++;
  for (odd_subscript = 1; odd_subscript < char_count; odd_subscript += 2)  //For loop to count the number of characters that correspond to odd subscripts in the array
    odd_count++;
  
  decrypted_subscript = 0;  //Initialize the subscript used to count characters in the original character array to 0 for evens
  
  for (int i = 0; i < even_count; i++)  //For loop to read the characters in the decrypted message up until there are no more characters that would have originally corresponded to even subscripts into the even_subscripts in the new character array
  {
    character = encrypted_message[i];
    decrypted_message[decrypted_subscript] = character;
    decrypted_subscript += 2;
  }
  
  decrypted_subscript = 1;  //Initialize the subscript used to count characters in the original character array to 1 for odds
  
  for (int i = even_count; i < char_count; i++) //For loop that begins counting after the characters in the original array that would have originally corresponded to odd subscripts until the total number of characters in that array. It then puts those characters into the odd subscripts in the new array
  {
    character = encrypted_message[i];
    decrypted_message[decrypted_subscript] = character;
    decrypted_subscript += 2;
  }
  
  cout << endl;
  
  for (int i = 0; i < char_count; i++)  //For loop to output the decrypted message
    cout << decrypted_message[i];
  cout << endl;
}
