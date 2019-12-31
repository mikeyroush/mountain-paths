//
//  main.cpp
//  mountain paths
//
//  Created by Mikey Roush on 9/28/17.
//  Copyright © 2017 Michael Roush. All rights reserved.
//

#include "functions.h"

int main() {
    //Initializing variables and asking for user inputs.
    //**********************************************************************
    string inFilename;
    int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    cout << "Enter input filename: ";
    cin >> inFilename;
    string outFilename = inFilename;
    outFilename += ".ppm";
    vector<vector<double>> mapData(rows,vector<double>(columns));
    
    //Attempting to open input file and checking for error
    //**********************************************************************
    ifstream fileIn;
    fileIn.open(inFilename);
    
    if(!fileIn.is_open()){
        cerr << "Error: Could not open input file" << endl;
        return 1;
    }
    
    //Assigning the elements of the input file to their corresponding
    //index in a matrix and then closing the input file
    //**********************************************************************
    int x;
    for (unsigned int i = 0; i < rows; ++i){
        for (unsigned int j = 0; j < columns && fileIn >> x; ++j)
            mapData.at(i).at(j)=x;
    }
    fileIn.close();
    //display(mapData);
    
    //Finding the min and max values in the matrix
    //**********************************************************************
    double min = mapData.at(0).at(0);
    double max = mapData.at(0).at(0);
    for (unsigned int i = 0; i < mapData.size(); ++i) {
        for (unsigned int j = 0; j < mapData[0].size(); ++j) {
            if (mapData.at(i).at(j) < min) min = mapData.at(i).at(j);
            if (mapData.at(i).at(j) > max) max = mapData.at(i).at(j);
        }
    }
    cout << "min value: " << min << endl << "max value: " << max << endl;
    
    //Putting the corresponding grey scale values into a new matrix
    //then into corresponding red, blue and green matrices
    //**********************************************************************
    vector<vector<double>> greyScale = mapData;
    for (unsigned int i = 0; i < greyScale.size(); ++i) {
        for (unsigned int j = 0; j < greyScale[0].size(); ++j)
            greyScale.at(i).at(j) = (greyScale.at(i).at(j) - min)/(max-min)*255;
    }
    vector<vector<double>> red = greyScale;
    vector<vector<double>> green = greyScale;
    vector<vector<double>> blue = greyScale;
    
    //Finding greedy paths and highlighting the best of the greedy paths
    //**********************************************************************
    int greediestPath = rows * columns;
    int greediestRow = 0;
    for (unsigned int i = 0; i < mapData.size(); ++i){
        red.at(i).at(0) = 252;
        green.at(i).at(0) = 25;
        blue.at(i).at(0) = 63;
        int greedyPath = colorPath(mapData, red, green, blue, 252, 25, 63, i, max);
        if (greedyPath < greediestPath) {
            greediestPath = greedyPath;
            greediestRow = i;
        }
    }
    red.at(greediestRow).at(0) = 31;
    green.at(greediestRow).at(0) = 253;
    blue.at(greediestRow).at(0) = 13;
    greediestPath = colorPath(mapData, red, green, blue, 31, 253, 13, greediestRow, max);
    cout << "greediest path: " << greediestPath << endl;
    
    //Finding greedy paths to the 4 edges of the map from a give point
    //**********************************************************************
    int ec_row, ec_column;
    if (cin >> ec_row >> ec_column){
        //int direction = 2;
        for (int direction = 1; direction < 5; ++direction)
            colorCross(mapData, red, green, blue, 19, 254, 253, ec_row, ec_column, max, direction);
    }
    
    //Attempting to open output file and checking for error
    //then printing greyscale values to the output file
    //**********************************************************************
    ofstream fileOut;
    fileOut.open(outFilename);
    
    if (!fileOut.is_open()){
        cerr << "Error: Could not open output file" << endl;
        return 1;
    }
    //fileOut << fixed << setprecision(0);
    fileOut << "P3" << endl;
    fileOut << columns << " " << rows << endl;
    fileOut << "255" << endl;
    display(red, green, blue, fileOut);
    fileOut.close();
    return 0;
}
