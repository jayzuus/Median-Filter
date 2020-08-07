
#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <stdio.h>

using namespace std;

namespace fileSysTem {
    /**
     Return the list of image files
     @return the list of images file
     **/
    vector<string> listImageFile(string filePath);
    
    
    /**
    Split and convert current pixel string to integer
    @param stringLine - current string line
    @param delimeter - delimeter in that string
    @return vector of string which is already split
    **/
    vector<string> split(string stringLine, char delimeter);
    
    /**
     Get List of Map
     @param listImage - vector of image
     @return list of hash which contain image data
     **/
    vector<map<int, vector<int>>> getListOfMap(vector<string> listImage); 

    /**
     Open up file to retrieve all image file data into hash map;
     @param fileName - name of Image file
     @return hash map of image data
     **/
     map<int, vector<int>> getImageData(string fileName);
    
    /**
     Convert vector to map
     @param pixelList - current pixel vector
     @return imageData - return approriate hash which contain pixel
     **/
    
    map<int, vector<int>> convertVectorToMap(vector<string> pixelList);
    
    /**
     Intialize the image
     @param imageName - name of Image
     @param imageFrom - image which will be copied header from
     **/
    void initializedImage (string imageName, string imageFrom); 
} 
#endif
