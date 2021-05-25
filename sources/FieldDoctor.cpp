#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic{

    Player& FieldDoctor::treat(City city){
        if ( this -> board[city] == 0){
            throw invalid_argument{"city has no disease"};
        }
        if( ! Board::is_ni(this -> curr_city, city) && this -> curr_city != city ){
           
            throw invalid_argument{"cities not neighbors"};
        
        }
        if ( this -> board.exists_cure(this -> board.get_color(city))){
            this -> board [city] = 0;
        }
        else{
            this -> board[city] = this -> board[city] -1;
        }
        return *this;
    }
}