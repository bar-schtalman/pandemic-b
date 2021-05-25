#include "Researcher.hpp"
using namespace std;
const int MaxCard = 5;

namespace pandemic{
        Player& pandemic::Researcher::discover_cure(Color color){
        bool ans = this->board.exists_cure(color);
        int count = 0;
        for (City c : this -> pcards){
            if (this->board.get_color(c) == color){
                count ++;
            }
        }
        if (count < MaxCard){
            throw invalid_argument{"Researcher: not enough cards"};
        }

        if (!ans){
            set<City> temp;
            for(City c : this -> pcards){
                temp.insert(c);
            }
            
            int counter = 0;
            for (City c : this ->pcards){
                if(this -> board.get_color(c) == color){
                    temp.erase(c);
                    if (counter == MaxCard -1){
                        break;
                    }
                    counter ++;
                }
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