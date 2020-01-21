#include<stdio.h>
#include<iostream>
#include<string.h>

/**
 * Return the name of a file from his full path name. 
 * @param fileFullName Full path name of a file.
 * @return File name (extension included).
 */
std::string getFileName(std::string fileFullName){
    size_t firstChar = fileFullName.find_last_of("/") + 1; //first char after last "/"
    std::string fileName = fileFullName.substr(firstChar);

    return fileName;
}

/**
 * Return the extension of a file from his full path name. 
 * @param  fileFullName Full path name of a file.
 * @return File extension
 */
std::string getFileExtension(std::string fileFullName){
    size_t firstChar = fileFullName.find_last_of(".") + 1; //first char after last "/"
    std::string fileExtension = fileFullName.substr(firstChar);

    return fileExtension;
}
