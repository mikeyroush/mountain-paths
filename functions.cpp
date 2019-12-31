//
//  functions.cpp
//  mountain paths
//
//  Created by Mikey Roush on 10/12/17.
//  Copyright © 2017 Michael Roush. All rights reserved.
//

#include "functions.h"

int findHeightChange(const vector<vector<double>>& mapData, int& row, int& column, int max, int direction){
    int heightChange = 0;
    int heightChange1, heightChange2, heightChange3;
    switch (direction) {
        case 1: {
            heightChange1 = abs(mapData.at(row).at(column)-mapData.at(row).at(column+1));
            if (row == 0)
                heightChange2 = max * max;
            else
                heightChange2 = abs(mapData.at(row).at(column)-mapData.at(row-1).at(column+1));
            if (row == mapData.size()-1)
                heightChange3 = max * max;
            else
                heightChange3 = abs(mapData.at(row).at(column)-mapData.at(row+1).at(column+1));
            if (heightChange1 <= heightChange2 && heightChange1 <= heightChange3){
                heightChange = heightChange1;
            }
            else if (heightChange3 <= heightChange2){
                heightChange = heightChange3;
                row += 1;
            }
            else {
                heightChange = heightChange2;
                row -= 1;
            }
        } break;
        case 2: {
            heightChange1 = abs(mapData.at(row).at(column)-mapData.at(row).at(column-1));
            if (row == 0)
                heightChange2 = max * max;
            else
                heightChange2 = abs(mapData.at(row).at(column)-mapData.at(row-1).at(column-1));
            if (row == mapData.size()-1)
                heightChange3 = max * max;
            else
                heightChange3 = abs(mapData.at(row).at(column)-mapData.at(row+1).at(column-1));
            if (heightChange1 <= heightChange2 && heightChange1 <= heightChange3){
                heightChange = heightChange1;
            }
            else if (heightChange2 <= heightChange3){
                heightChange = heightChange2;
                row -= 1;
            }
            else {
                heightChange = heightChange3;
                row += 1;
            }
        } break;
        case 3: {
            heightChange1 = abs(mapData.at(row).at(column)-mapData.at(row-1).at(column));
            if (column == 0)
                heightChange2 = max * max;
            else
                heightChange2 = abs(mapData.at(row).at(column)-mapData.at(row-1).at(column-1));
            if (column == mapData[0].size()-1)
                heightChange3 = max * max;
            else
                heightChange3 = abs(mapData.at(row).at(column)-mapData.at(row-1).at(column+1));
            if (heightChange1 <= heightChange2 && heightChange1 <= heightChange3){
                heightChange = heightChange1;
            }
            else if (heightChange3 <= heightChange2){
                heightChange = heightChange3;
                column += 1;
            }
            else {
                heightChange = heightChange2;
                column -= 1;
            }
        } break;
        case 4: {
            heightChange1 = abs(mapData.at(row).at(column)-mapData.at(row+1).at(column));
            if (column == 0)
                heightChange2 = max * max;
            else
                heightChange2 = abs(mapData.at(row).at(column)-mapData.at(row+1).at(column-1));
            if (column == mapData[0].size()-1)
                heightChange3 = max * max;
            else
                heightChange3 = abs(mapData.at(row).at(column)-mapData.at(row+1).at(column+1));
            if (heightChange1 <= heightChange2 && heightChange1 <= heightChange3){
                heightChange = heightChange1;
            }
            else if (heightChange2 <= heightChange3){
                heightChange = heightChange2;
                column -= 1;
            }
            else {
                heightChange = heightChange3;
                column += 1;
            }
        } break;
        default:
            break;
    }
    
    return heightChange;
}

int colorPath(const vector<vector<double>>& mapData, vector<vector<double>>& r, vector<vector<double>>& g, vector<vector<double>>& b, int color_r, int color_g, int color_b, int start_row, int max){
    
    int greedyPath = 0;
    int heightChange=0;
    int row = start_row;
    for (int i = 0; i < mapData[0].size()-1; ++i){
        heightChange = findHeightChange(mapData, row, i, max, 1);
        r.at(row).at(i+1) = color_r;
        g.at(row).at(i+1) = color_g;
        b.at(row).at(i+1) = color_b;
        greedyPath += heightChange;
    }
    return greedyPath;
}

void colorCross(const vector<vector<double>>& mapData, vector<vector<double>>& r, vector<vector<double>>& g, vector<vector<double>>& b, int color_r, int color_g, int color_b, int start_row, int start_col, int max, int direction){
    int heightChange=0;
    int row = start_row;
    int column = start_col;
    switch (direction) {
        case 1: {
            for (int i = column; i < mapData[0].size()-1; ++i){
                heightChange = findHeightChange(mapData, row, i, max, direction);
                r.at(row).at(i) = color_r;
                g.at(row).at(i) = color_g;
                b.at(row).at(i) = color_b;
            } break;
        }
        case 2: {
            for (int i = column; i > 0; --i){
                heightChange = findHeightChange(mapData, row, i, max, direction);
                r.at(row).at(i) = color_r;
                g.at(row).at(i) = color_g;
                b.at(row).at(i) = color_b;
            } break;
        }
        case 3: {
            for (int i = row; i > 0; --i){
                heightChange = findHeightChange(mapData, i, column, max, direction);
                r.at(i).at(column) = color_r;
                g.at(i).at(column) = color_g;
                b.at(i).at(column) = color_b;
            } break;
        }
        case 4: {
            for (int i = row; i < mapData.size()-1; ++i){
                heightChange = findHeightChange(mapData, i, column, max, direction);
                r.at(i).at(column) = color_r;
                g.at(i).at(column) = color_g;
                b.at(i).at(column) = color_b;
            } break;
        }
        default:
            break;
    }
}

void display(vector<vector<double>> &r, vector<vector<double>> &g, vector<vector<double>> &b, ofstream &fileOut){
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[0].size(); ++j) {
            fileOut << floor(r.at(i).at(j)) << " ";
            fileOut << floor(g.at(i).at(j)) << " ";
            fileOut << floor(b.at(i).at(j)) << " ";
            //if ((j+1)%20==0) fileOut << endl;
        }
        fileOut << endl;
    }
}
