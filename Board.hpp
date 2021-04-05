
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <limits.h>
#include <map>

using namespace ariel;


namespace ariel{

    class Board{

        std::map<std::pair<unsigned int, unsigned int>,char> boardmap;
        unsigned int minCol=UINT_MAX, maxCol=0, minRow=UINT_MAX, maxRow=0;
        public:
            Board(){
                
            }              
            //check border and update if necessery;
            void setMinimum(unsigned int col, unsigned int row){
                
                if(this->minCol>col){
                    this->minCol=col;                    
                }
                if(this->minRow>row){
                    this->minRow=row;                    
                }}
            void setMaximum(unsigned int col, unsigned int row){
                if(this->maxCol<col){
                    this->maxCol=col;                   
                }
                if(this->maxRow<row){
                    this->maxRow=row;                   
                }     
            }
            //insert acording to key pair;
            void BoardInsert(unsigned int row, unsigned int col, char c){
                boardmap[std::pair<unsigned int,unsigned int>(row,col)]=c;
            }
            void post(unsigned int ,unsigned int , enum ariel::Direction, const std::string &);
            std::string read(unsigned int row, unsigned int col, enum ariel::Direction, unsigned int length);
            void show();


    };




}