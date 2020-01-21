/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author University of Illinois CS 225 Course Staff
 * @author Updated by University of Illinois CS 400 Course Staff
**/

#include "ImageTransform.h"
#include "uiuc/PNG.h"
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>
#include "utils.cpp"

int main() {

  //Directories
  char *dirOriginal = "/home/alvaro/Project CV/preprocessing-of-images/baseline/";
  std::string dirLeft = "/home/alvaro/Project CV/preprocessing-of-images/left-crop/";
  std::string dirRight = "/home/alvaro/Project CV/preprocessing-of-images/right-crop/";
 
  //
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
        if (png_crop_left.writeToFile(dirLeft + fileName)){
          std::cout << "---> Left crop completed. " << std::endl;
        }
        //Crop Right        
        png_crop_right = PNG(png_original);
        png_crop_right.crop(png_original.width()/2,0,png_original.width(),png_original.height());
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
  
  // string cdLeft, cdRight;
  // cdLeft = "/home/alvaro/Project CV/preprocessing-of-images/left-crop/";
  // cdRight = "/home/alvaro/Project CV/preprocessing-of-images/right-crop/";

  // uiuc::PNG png_original, png_crop_left, png_crop_right;
  // std::string fileFullName = "/home/alvaro/Project CV/preprocessing-of-images/images-taken/Explorer_HD1080_SN15489_16-07-59.png";
  // //test for name
  
  // std::cout << getFileName(fileFullName) << std::endl;

  // png_original.readFromFile(fileFullName);
 
  // png_crop_left = PNG(png_original);
  // png_crop_left.crop(png_original.width()/2,0,png_original.width(),png_original.height());
  // png_crop_left.writeToFile(cdLeft + "test1.png");
  
  return 0;
}
