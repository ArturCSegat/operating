#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

void help();
void clear();
void displayVersion();
void makefile();
void edit();

int main(){
    string verNumber = "Version 1.2R";
    string username;
    string password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);
    system("CLS");

    cout << "Operating Rewrite " << verNumber << endl;
    cout << "Current user is " << username << endl;
    
    bool running = "true";
    while (running == true){
        string command;
        cout << "Command: ";
        getline(cin, command);

        if (command == "help"){
            help();
        }
        if (command == "clear"){
            clear();
        }
        if (command == "version"){
            displayVersion();
        }
        if (command == "exit"){
            running = false;
        }
        if (command == "makefile"){
            makefile();
        }
        if (command == "view"){
            edit();
        }
    }
    return 0;
}

void help(){
    cout << "   help - Displays all available commands. \n   version - Displays Operating Version.\n   clear - Clears the screen.\n   makefile - Creates files.\n   view - Outputs text file contents to console.\n";
}
void clear(){
    system("CLS");
}
void displayVersion(){
    cout << "   Version 1.2R" << endl;
}
void makefile(){
    string filename;
    string path;
    string text;
    cout << "   Filename: ";
    getline(cin, filename);
    cout << "   Path: ";
    getline(cin, path);
    ofstream File(path + filename);
    cout << "   Text (Optional): ";
    getline(cin, text);
    File << text;
    cout << "\n   File " << filename << " created." << endl;
    File.close(); 
}
void edit(){
    string editorfile;
    string myText;
    cout << "   Full path to file: ";
    getline(cin, editorfile);
    ifstream ReadFile(editorfile);
    while (getline (ReadFile, myText)) {
        cout << myText << endl;
    } 
}