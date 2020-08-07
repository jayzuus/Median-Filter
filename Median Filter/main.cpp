#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include "utility.hpp"
#include "median.hpp"
#include "unistd.h"
#include <algorithm>
int main(int argc, const char * argv[]) {
    
    /**Get current working directory**/
    string filePath;
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
        perror("getcwd() error");
    }else{
        string s(cwd);
        filePath = s + "/images2";
    }
    cout << filePath << endl;
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    sort(listImageFile.begin(), listImageFile.end());
    vector<map<int, vector<int>>> imagesList = fileSysTem::getListOfMap(listImageFile);

    int sizeImage = imagesList[0].size();
    int imageListSize = imagesList.size();
    
    /**
     Initialize new image with header
     **/
    string imageName = "result.ppm";
    fileSysTem::initializedImage(imageName, listImageFile[0]);
    
    /**
     Continue writing to file
     **/
    ofstream outputFile;
    outputFile.open(imageName, ios::app);
    
    for (int lineNumber = 0; lineNumber < sizeImage; lineNumber++){
    
       calculateMedian redPixelMedian;
       calculateMedian greenPixelMedian;
       calculateMedian bluePixelMedian;

       for (int i = 0; i < imageListSize; i++) {

           vector<int> pixelLineList = imagesList[i][lineNumber];
           redPixelMedian.addNumber(pixelLineList[0]);
           greenPixelMedian.addNumber(pixelLineList[1]);
           bluePixelMedian.addNumber(pixelLineList[2]);
        }
        outputFile << redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << "\n";
        
        cout << redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;;

    }
    outputFile.close();
    return 0;
}
