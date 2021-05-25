#include "OperationsExpert.hpp"
using namespace pandemic;


    void OperationsExpert::build(){
        if (!this -> board.has_st(this -> curr_city) ){
            this -> board.build_st(this -> curr_city);
        }
        
}
