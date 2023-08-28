#include<iostream>
#include<string.h>
using namespace std;

struct encryption
{
    char enc[200];
    char plaintxt[200];
    char ciphertxt[200];
    int key;
};
int main()
{
    struct encryption e;
    
char username[20];
char password[20];
char uname[20] = "p1";
char pass[20] = "p2";
char choice;
int op;
cout << "\n                                      Security Matters, Secure your Data with US                               \n";
cout << "                                 --------------------------------------------------------\n";
cout << "Enter your USER:- ";
cin >> username;
cout << "Enter your Password:- ";
cin >> password;

if(strcmp(username,uname) == 0 && strcmp(password,pass) == 0)
{
  cout << "\n                                       Welcome to the Safe Enviorment                 \n";  
  cout << "\n                             ---------------------------------------------------------\n";
do{
cout <<"\n 1.Encryption \t 2.Decryption \t 3.Exit\n";
cout << "Enter your option:- \n";
cin >> op;
  switch (op)
  {
  case 1:
    cout << "Enter the Encryption KEY:";
    cin >> e.key;
    fflush(stdin);
    cout << "Enter the plaintext:-";
    cin.get(e.plaintxt,200);
    cout <<"THE Encrypted Message/Cipher Text is:- ";
    for(int i = 0;i<strlen(e.plaintxt);i++)
    {
        e.enc[i] = (int)e.plaintxt[i] + e.key;
      cout<<e.enc[i];
    }
    break;
     case 2:
     cout << "Enter the Decryption KEY:";
    cin >> e.key;
    fflush(stdin);
    cout << "Enter the Cyphertext:-";
    cin.get(e.ciphertxt,200);
    cout <<"THE Decrypted Message/Plain Text is:- ";
    for(int i = 0;i<strlen(e.ciphertxt);i++)
    {
        e.ciphertxt[i] = (int)e.ciphertxt[i] - e.key;
      cout<<e.ciphertxt[i];
    }
    break;
     case 3:
    cout << "Exit the Application:";
    break;
  
  default:
  cout << "Enter a correct input/wrong input";
    break;
  }

cout << "\nWould you like to Continue, Enter y/Y fot yes and any for close:- ";
cin >> choice;
   }while(choice == 'y' || choice =='Y');

}

else
{
    cout << "\n                                Try AGAIN , USERNAME or PASSWORD ARE Incorrect!!\n";
    cout << "\n                          -----------------------------------------------------------\n";

} 
}