#include <filesystem>
#include <iostream>
#include <fstream>
namespace fs = std::filesystem;

    void printCurrentPath(fs::path path){
        std::cout << "\n\n-->[" << path.string() << "]\n$";
        return;
    }

    // show the current working dir
    void pwd(fs::path currentPath){
        std::cout << currentPath.string();
        return;
    }

    // lists directory's content
    void ls(fs::path currentPath){
        int counter = 0;
        for (const auto & entry : fs::directory_iterator(currentPath)){
            std::cout << entry.path().filename().string();
            counter++;
            counter % 4 == 0 ? std::cout << "\n" : std::cout << "\t\t";
        }
        return;
    }

    // changes working directory
    fs::path cd(std::string directoryName, fs::path currentPath) {
        if(directoryName == "..")
            currentPath = currentPath.parent_path();

        else{
            fs::directory_entry newEntry{currentPath.string() + "/" + directoryName};
            if(newEntry.is_directory())
                currentPath = currentPath.append(directoryName);
            else std::cout << "not a directory";
        }

        if(!fs::exists(currentPath)) std::cout << "No such file or directory"; 
        return currentPath;
    }

    bool nameInUse(std::string name, fs::path currentPath){
        for (const auto & entry : fs::directory_iterator(currentPath)){
            if(entry.path().filename().string() == name) {
                return true;
            }
        }
        return false;
    }

    void mkdir(std::string dirName, fs::path currentPath){
        fs::path temp = currentPath;
        if(nameInUse(dirName, currentPath))
            std::cout << "cannot create directory : Name already in use";
        else 
            fs::create_directory(currentPath.append(dirName)) ? std::cout << "directory created" : std::cout << "an error occured";
        currentPath = temp;
        return;
    }

    void rm(std::string name, fs::path currPath, bool isFile){
        if(fs::exists(currPath.append(name))){
            uintmax_t n{fs::remove_all(currPath)};
            isFile ? std::cout << "Deleted " << n << " files" : std::cout << "Deleted " << n << " directories";
            currPath.parent_path();
            return;
        }

        std::cout << "no such file or directory";
        return;
    }

    void createNewfile(std::string fileName, fs::path currPath){
        if(nameInUse(fileName, currPath)){
            std::cout << "cannot create directory : Name already in use";
            return;
        }
        std::fstream file;
        file.open(currPath.append(fileName).string(), std::ios::out);
        !file ? std::cout << "an error occured while creating the file" : 
                std::cout << "file " << fileName << " was successfully created.";
        file.close();
        currPath.parent_path();
        return;
    }

    void copy(std::string fileToCopy, std::string fileCopied, fs::path currPath, fs::path destinationPath){;
        fs::path pathTemp = currPath;

        if(nameInUse(fileToCopy, currPath)){
            if(!nameInUse(fileCopied, destinationPath)){
                std::cout << destinationPath << currPath;
                std::filesystem::copy(pathTemp.append(fileToCopy), destinationPath.append(fileCopied), 
                                        std::filesystem::copy_options::recursive);
                std::cout << "successfully copied to " << destinationPath.parent_path();
            }
            else
                std::cout << "cannot copy with name: file already exists";
        }
        else std::cout << "no such file or directory";
        return;
    }

    void mv(std::string fileName, fs::path currPath){
        std::string secondInput;
        std::cin >> secondInput;
        if(!nameInUse(fileName, currPath)) std::cout << "no such file or directory";
    
        else if(secondInput.find("/") != std::string::npos){
            fs::path destinationPath{secondInput};
            if(fs::exists(destinationPath)){
                copy(fileName, fileName, currPath, destinationPath);
                rm(fileName, currPath, false);
            }
            else
                std::cout << "the path specified doesn't exists";
            return;
        }
        fs::directory_entry dir{fs::current_path().append(fileName)};
        if(dir.is_directory() && secondInput.find(".") != std::string::npos) 
            std::cout << "cannot rename";
        else{
            fs::rename(fs::current_path().append(fileName), fs::current_path().append(secondInput));
            std::cout << "file or directory renamed successfully";
        }
        return;
    }

    int main()
    {
        fs::path currentPath {"/mnt/c/Users/norah/Desktop/workingdir"};
        std::cout << "Welcome to MyConsole version 1\nEnter 'q' to exit\n";
        printCurrentPath(currentPath);
        std::string input;
        std::cin >> input;

        while(input != "q"){

            if(input == "pwd") 
                pwd(currentPath);
            else if(input == "ls")
                ls(currentPath);
            else if(input == "cd"){
                std::cin >> input;
                currentPath = cd(input, currentPath);}
            else if(input == "mkdir"){
                std::cin >> input;
                mkdir(input, currentPath);
            }
            else if(input == "rmdir"){
                std::cin >> input;
                rm(input, currentPath, false);
            }
            else if(input == "rm"){
                std::cin >> input;
                rm(input, currentPath, true);
            }
            else if(input == "touch"){
                std::cin >> input;
                createNewfile(input, currentPath);
            }
            else if(input == "cp"){
                std::string secondInput;
                // std::string destination;
                std::cin >> input >> secondInput;
                copy(input, secondInput, currentPath, currentPath);
            }
            else if(input == "tree"){
                static_cast<void>(std::system("tree"));
                printCurrentPath(currentPath);
            }
            else if(input == "mv"){
                std::cin >> input;
                mv(input, currentPath);
            }
            else if(input == "tail"){
                // prints last 10 lines of the file
            }
            else if(input == "head"){
                // print first 10 lines
            }
            else if(input == "cat"){
                // cat > file creates new file
                // cat file1 file2 > file3 merge them and saves the result in file3
            }
            printCurrentPath(currentPath);

            std::cin >> input;
            std::cout << "\n";
        }

        return 0;

    }