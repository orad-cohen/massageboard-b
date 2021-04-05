#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
using namespace std;

const char EmpSpace = '_';

void ariel::Board::post(unsigned int row, unsigned int col, enum ariel::Direction dir, const string &demomsg){
    //set maximum and minimum for show borders
    setMinimum(col,row);
    if(dir==Direction::Horizontal){
        setMaximum(col+demomsg.size(),row);
    }
    else{
        setMaximum(col,row+demomsg.size());
    }
    //insert according to key and direction
    for (size_t i = 0; i < demomsg.size(); i++)
    {
        if(dir==Direction::Horizontal){
            BoardInsert(row,col+i,demomsg.at(i));
        }
        else{
            BoardInsert(row+i,col,demomsg.at(i));
        }
        
    }
}

std::string ariel::Board::read(unsigned int row, unsigned int col, enum ariel::Direction dir, unsigned int length){
    string res;

    for (unsigned int i = 0; i < length; i++){
        //build string according to parameters, if no key value pair found put _ instead;
        if(dir==Direction::Horizontal){
            auto it = boardmap.find(make_pair(row,col+i));
            if(it!=boardmap.end()){res+=it->second;}
            else{res+=EmpSpace;}
        }    
        else{
            auto it = boardmap.find(make_pair(row+i,col));
            if(it!=boardmap.end()){res+=it->second;}
            else{res+=EmpSpace;}
        }    }
    

    return res;
}
void ariel::Board::show(){
    //print entire board according to border set by post, if no key value pair found put _ instead;
    for (unsigned int i = this->minRow; i <= this->maxRow; i++){        
        for (unsigned int j = this->minCol; j <= this->maxCol; j++){            
            if(boardmap.find(make_pair(i,j))==boardmap.end()){
                cout << EmpSpace;
            }
            else{
                cout << boardmap.at(make_pair(i,j));
            }
        }
    
        cout << endl;       
        
    }

}

