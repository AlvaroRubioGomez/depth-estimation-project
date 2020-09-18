/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author University of Illinois CS 225 Course Staff
 * @author Updated by University of Illinois CS 400 Course Staff
**/

#include "ImageTransform.h"
#include "uiuc/PNG.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <dirent.h>

std::string getFileName(std::string fileFullName){
    size_t firstChar = fileFullName.find_last_of("/") + 1; //first char after last "/"
    std::string fileName = fileFullName.substr(firstChar);

    return fileName;
}

std::string getFileExtension(std::string fileFullName){
    size_t firstChar = fileFullName.find_last_of(".") + 1; //first char after last "/"
    std::string fileExtension = fileFullName.substr(firstChar);

    return fileExtension;
}

int main() {
  printf("entro");
  //Directories
  // char *dirOriginal = "/home/alvaro/Project CV/preprocessing-of-images/baseline/";
  // std::string dirLeft = "/home/alvaro/Project CV/preprocessing-of-images/left-crop/";
  // std::string dirRight = "/home/alvaro/Project CV/preprocessing-of-images/right-crop/";

  char *dirOriginal = "/home/alvaro/depth-estimation-project/preprocessing-of-images/test/";
  std::string dirLeft = "/home/alvaro/depth-estimation-project/preprocessing-of-images/test_result/";
  std::string dirRight = "/home/alvaro/depth-estimation-project/preprocessing-of-images/test_result/";
 
  uiuc::PNG png_original, png_crop_left, png_crop_right; 

  //Loop through files in a folder
  DIR *dir;
  struct dirent *ent;
  std::string fileName;

  if ((dir = opendir (dirOriginal)) != NULL) {
  //Loop through all files in the given directory
  while ((ent = readdir (dir)) != NULL) {   
    fileName = ent->d_name;
    //Check for files with png extension
    if(fileName.length() > 3){      
      if(getFileExtension(fileName ) == "png" ){
        std::cout << "Cropping file: " << fileName << std::endl;        
        //Read file        
        png_original.readFromFile(dirOriginal + fileName);          
        //Crop left        
        png_crop_left = PNG(png_original);
        png_crop_left.crop(png_original.width()/2,0,png_original.width(),png_original.height());
        //normalize
        png_crop_left.normalize_lighting();
        //Save file
        if (png_crop_left.writeToFile(dirLeft + fileName)){
          std::cout << "---> Left crop completed. " << std::endl;
        }
        //Crop Right        
        png_crop_right = PNG(png_original);
        png_crop_right.crop(png_original.width()/2,0,png_original.width(),png_original.height());
        //normalize
        png_crop_right.normalize_lighting();
        //Save file
        if(png_crop_right.writeToFile(dirRight + fileName)){
          std::cout << "---> Right crop completed. " << std::endl;
        }
      }
      else{std::cout << "NOT PNG" <<std::endl;}     
    }
  }
  closedir (dir);
    } else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
  }  
  return 0;
}