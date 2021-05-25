#include "GeneSplicer.hpp"
using namespace std;
const int MaxCard = 5;

namespace pandemic{

    Player& GeneSplicer::discover_cure(Color color){
        int count = this -> pcards.size();
        bool ans = this->board.exists_cure(color);
        bool ans_st = this -> board.has_st(this -> curr_city);
        int counter = 0;
        if (count < MaxCard){
            throw invalid_argument{"not enough cards"};
        }
        if (!ans_st){
            throw invalid_argument {"no reasearch station"};
        }

    
        if (!ans){
            
            set<City> temp;
            //coppy the cards
            for(City c : this -> pcards){
                temp.insert(c);
            }
            
            int counter = 0;
            for (City c : this ->pcards){
                    temp.erase(c);
                    if (counter == MaxCard -1){
                        break;
                    }
                    counter ++;
                
            }
            this -> pcards.clear();
            
            for (City c : temp){
                this -> pcards.insert(c);
            }
            this -> board.new_cure_dis(color);
        }
        return *this;
    }
}