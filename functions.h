//
//  functions.h
//  mountain paths
//
//  Created by Mikey Roush on 10/12/17.
//  Copyright © 2017 Michael Roush. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ios>
#include <cmath>
#include <math.h>
using namespace std;

int findHeightChange(const vector<vector<double>>& mapData, int& row, int& column, int max, int direction);
int colorPath(const vector<vector<double>>& mapData, vector<vector<double>>& r, vector<vector<double>>& g, vector<vector<double>>& b, int color_r, int color_g, int color_b, int start_row, int max);
void colorCross(const vector<vector<double>>& mapData, vector<vector<double>>& r, vector<vector<double>>& g, vector<vector<double>>& b, int color_r, int color_g, int color_b, int start_row, int start_col, int max, int direction);
void display(vector<vector<double>> &r, vector<vector<double>> &g, vector<vector<double>> &b, ofstream &fileOut);

#endif /* functions_h */
