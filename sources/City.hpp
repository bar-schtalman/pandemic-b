#pragma once
#include <string>

namespace pandemic{

    enum City{
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

    inline std::string city_by_string(City c) {
        
        switch (c){
            case City::Algiers:
                return "Algiers";
                break;
            
            case City::Atlanta:
                return "Atlanta";
                break;
       
            case City::Baghdad:
                return "Baghdad";
                break;
        
            case City::Bangkok:
                return "Bangkok";
                break;
            
            case City::Beijing:
                return "Beijing";
                break;
        

            case City::Bogota:
                return "Bogota";
                break;

            case City::BuenosAires:
                return "BuenosAires";
                break;

            case City::Cairo:
                return "Cairo";
                break;
        
            case City::Chennai:
                return "Chennai";
                break;

            case City::Chicago:
                return "Chicago";
                break;

            case City::Delhi:
                return "Delhi";
                break;

            case City::Essen:
                return "Essen";
                break;

            case City::HoChiMinhCity:
                return "HoChiMinhCity";
                break;
        
            case City::HongKong:
                return "HongKong";
                break;

            case City::Istanbul:
                return "Istanbul";
                break;

            case City::Jakarta:
                return "Jakarta";
                break;

            case City::Johannesburg:
                return "Johannesburg";
                break;
        
            case City::Karachi:
                return "Karachi";
                break;
        
            case City::Khartoum:
                return "Khartoum";
                break;

            case City::Kinshasa:
                return "Kinshasa";
                break;

            case City::Kolkata:
                return "Kolkata";
                break;

            case City::Lagos:
                return "Lagos";
                break;
  
            case City::Lima:
                return "Lima";
                break;
 
            case City::London:
                return "London";
                break;

            case City::LosAngeles:
                return "LosAngeles";
                break;

            case City::Madrid:
                return "Madrid";
                break;

            case City::Manila:
                return "Manila";
                break;
        
            case City::MexicoCity:
                return "MexicoCity";
                break;

            case City::Miami:
                return "Miami";
                break;

            case City::Milan:
                return "Milan";
                break;

            case City::Montreal:
                return "Montreal";
                break;

            case City::Moscow:
                return "Moscow";
                break;

            case City::Mumbai:
                return "Mumbai";
                break;

            case City::NewYork:
                return "NewYork";
                break;

            case City::Osaka:
                return "Osaka";
                break;

            case City::Paris:
                return "Paris";
                break;

            case City::Riyadh:
                return "Riyadh";
                break;

            case City::SanFrancisco:
                return "SanFrancisco";
                break;
 
            case City::Santiago:
                return "Santiago";
                break;

            case City::SaoPaulo:
                return "SaoPaulo";
                break;

            case City::Seoul:
                return "Seoul";
                break;

            case City::Shanghai:
                return "Shanghai";
                break;
        
            case City::StPetersburg:
                return "StPetersburg";
                break;
     
            case City::Sydney:
                return "Sydney";
                break;
        
            case City::Taipei:
                return "Taipei";
                break;
        
            case City::Tehran:
                return "Tehran";
                break;

            case City::Tokyo:
                return "Tokyo";
                break;

            case City::Washington:
                return "Washington";
                break;
        }  
    }
}