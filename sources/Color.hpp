#pragma once
#include <vector>
#include <string>

namespace pandemic{

    enum Color{
        Yellow,
        Blue,
        Red,
        Black
    };  
    
    inline const std::string colors_by_string(Color c){
        switch (c){
            case Color::Yellow:
                return "Yellow";
                break;
        
            case Color::Blue:
                return "Blue";
                break;

            case Color::Red:
                return "Red";
                break;

            case Color::Black:
                return "Black";
                break;
        }
    }
}