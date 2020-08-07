
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <dirent.h>
#include "utility.hpp"

/**
 Return the list of image files
 @param filePath - path of images
 **/
vector<string> fileSysTem::listImageFile(string filePath){
    vector<string> listFile; 
    DIR* dirp = opendir(filePath.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        string fileName = dp->d_name;
        if (fileName == "." || fileName == "..")
            continue;
        string fullPath = filePath + "/" + fileName;
        listFile.push_back(fullPath);
    }
    closedir(dirp);
    return listFile;
}

/**
 Get List of Map
 @param listImage - vector of image
 @return list of hash which contain image data
 **/
vector<map<int, vector<int>>> fileSysTem::getListOfMap(vector<string> listImage){
    vector<map<int, vector<int>>> listMapOfImage;
    for (int i = 0; i < listImage.size(); i++) {
        listMapOfImage.push_back(getImageData(listImage[i]));
    }
    return listMapOfImage; 
}
/**
 Split and convert current pixel string to integer
 @param stringLine - current string line
 @param delimeter - delimeter in that string
 @return vector of string which is already split
 **/
vector<string> fileSysTem::split(string stringLine, char delimeter){
    stringstream ss(stringLine);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delimeter)) {
        istringstream iss (item);
        tokens.push_back(item);
    }
    return tokens;
}

/**
 Convert vector to map
 @param pixelList - current pixel vector
 @return imageData - return approriate hash which contain pixel
 **/

map<int, vector<int>> fileSysTem::convertVectorToMap(vector<string> pixelList){
    map<int, vector<int>> imageData;
    int i = 0;
    int counter = 0;
    int hashLineNumber = 0;
    int sizePixelList = pixelList.size();
    while (i < sizePixelList){
        vector<int>rbgList;
        if (counter < 4){
            counter = counter + 1;
            i = i + 1;
            continue;
        }
        for (int j = 0; j < 3 && i < sizePixelList; j++){
            rbgList.push_back(stoi(pixelList[i]));
            i = i + 1;
        }
        imageData[hashLineNumber] = rbgList;
        hashLineNumber = hashLineNumber + 1;
    }
    return imageData;
}

/**
 Open up file to retrieve all image file data into hash map;
 @param fileName - name of Image file
 @return hash map of image data
 **/
map<int, vector<int>> fileSysTem::getImageData(string fileName) {
    ifstream imageFile(fileName);
    string line;
    vector<string> lineList;
    while(!imageFile.eof()) {
        getline (imageFile,line);
        vector<string> currentLine = split(line, ' ');
        lineList.insert(lineList.end(), currentLine.begin(), currentLine.end());
    }
    imageFile.close();
    
    map<int, vector<int>> imageData = convertVectorToMap(lineList);
    return imageData;
}

/**
 Intialize the image
 @param imageName - name of Image
 @param imageFrom - image which will be copied header from
 **/
void fileSysTem::initializedImage (string imageName, string imageFrom){
    ofstream outputFile (imageName);
    ifstream imageFile(imageFrom);
    string line;
    int counting = 1;
    while(!imageFile.eof()) {
        getline (imageFile,line);
        if (counting < 4){
            outputFile << line << "\n";
        }else{
            break;
        }
        counting = counting + 1;
    }
    outputFile.close();
    imageFile.close(); 
}
