#include <iostream>
#include "mat.hpp"
#include <stdexcept>
#include <vector>


using namespace std;

string ariel::mat(int col, int row, char c1, char c2){
    // Setting Up min and max value for the Input Chars.
    int const max = 126;
    int const min = 33;

    // If statements to check the validationof the input.
    if(col%2==0 || row%2==0){
        throw std::invalid_argument("Caught Exception: Mat size must be odd.");
    }
    if(col < 0 || row < 0){
        throw std::invalid_argument("Caught Exception: Col / Row can not be negative.");
    }
    
    if(c1<min|| c1>max){
        throw std::invalid_argument("Caught Exception: Char 1 is not acceptable.");
    }
    if(c2<min|| c2>max){
        throw std::invalid_argument("Caught Exception: Char 2 is not acceptable.");
    }

    // Setting up data structure (that will be represent matrix). 
    std::vector<std::vector<char>> mat(row,std::vector<char>(col));
    string ans;
    /**
    * First step is to initialize the matrix to the second symbol.
    * time complicity - O(n^2)
    */

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j] = c2;
        }
    }

    /**
    * @brief Setting up the four indexes, we will write the first symbol two times:
    * 1. First iteration - for all the Columns.
    * 2. Second iteration - for all the Rows. 
    * In each iteration, we will replace the defult symbol (c2) with the first one (c1).
    */
    int index_up = 0;
    int index_down =row-1;
    int index_left = 0;
    int index_right = col-1;
    // First iteration.
    while(index_up <= index_down && index_left <= index_right){
        for(int i=index_left; i<=index_right; i++){
            mat[index_up][i] = c1;
            mat[index_down][i] = c1;
        }
        index_up += 2;
        index_down -= 2;
        index_left += 2;
        index_right -= 2;
        }
    // Resetting the arguments.
        index_up = 0;
        index_down =row-1;
        index_left = 0;
        index_right = col-1;
        // Second iteration.
        while(index_up <= index_down && index_left <= index_right){
            for(int i=index_up; i<=index_down; i++){
                mat[i][index_left] = c1;
                mat[i][index_right] = c1;
            }
            index_up += 2;
            index_down -= 2;
            index_left += 2;
            index_right -= 2;
        }
        // Basic print loop for matrix.
        for(int i=0;i<row;i++){
            for(int j=0; j<col;j++){
                ans += mat[i][j];
                if(j == col-1 && i != row-1){
                    ans += '\n';
                }
            }
        }
        return ans;
    }