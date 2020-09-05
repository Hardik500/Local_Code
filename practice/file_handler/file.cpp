#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <experimental/filesystem>
#include <fstream>
#include <unistd.h>

using namespace std;

void createFile(char *argv[], int size)
{
    fstream file;

    for (int i = 2; i < size; i++)
    {
        file.open(argv[i], ios::out);

        if (!file)
        {
            cout << "Error in creating file!!!"
                 << "\n";
            break;
        }

        cout << "File created successfully."
             << "\n";

        file.close();
    }
}

void readFile(string filename)
{
    fstream file;
    string word;

    file.open(filename.c_str());

    while (file >> word)
        cout << word << "\n";
}

void replaceWord(string filename, string from, string to)
{
    fstream file;

    string newText = "", word;

    //Copy the content into the string word

    file.open(filename.c_str());

    while (file >> word)
    {
        if (word == from)
            newText += to;
        else
            newText += word;

        newText += " ";
    }

    file.close();

    //Write the content in the file

    file.open(filename, ios::out);
    file << newText << "\n";
    file.close();
}

void deleteFile(char *filename)
{
    if (remove(filename) == 0)
        cout << "Deleted successfully\n";
    else
        cout << "Unable to delete the file\n";
}

void listDirectory()
{
    struct dirent *entry;
    DIR *dir = opendir(".");
    if (dir == NULL)
        return;

    while ((entry = readdir(dir)) != NULL)
        cout << entry->d_name << "\n";

    closedir(dir);
}

void moveFile(string filename, string location, string newFileName = "")
{
    //Compile it using 
    //g++ -lstdc++fs -std=c++17 -o file file.cpp -lstdc++fs
    
    // try
    // {
    //     experimental::filesystem::rename(filename, location + "/" + (newFileName != "" ? newFileName : filename));
    // }
    // catch (experimental::filesystem::filesystem_error& e)
    // {
    //     cout << "Error Occured" << '\n';
    // }
}

void linkFile(char* currentFile, char* linkedFile)
{
    symlink(currentFile, linkedFile);
}

int main(int argc, char *argv[])
{
    string command;

    if (argc > 1)
    {
        command = argv[1];

        if (command == "create")
            createFile(argv, argc);
        else if (command == "read")
            readFile(argv[2]);
        else if (command == "replace")
            replaceWord(argv[2], argv[3], argv[4]);
        else if (command == "delete")
            deleteFile(argv[2]);
        else if (command == "list")
            listDirectory();
        else if (command == "move")
        {
            if (argc == 5)
                moveFile(argv[2], argv[3], argv[4]);
            else
                moveFile(argv[2], argv[3]);
        }
        else if (command == "link")
            linkFile(argv[2], argv[3]);
    }
}