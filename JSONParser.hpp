#ifndef JSON_PARSER
#define JSON_PARSER

#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"
#include "EntitySet.hpp"
#include <string>
#include <vector>
#include <utility>
#include <array>

class JSONParser {
    public:
        JSONParser(string InputFilename);
        void entityIntersection(EntitySet firstYear, EntitySet secondYear);
        bool ValidateOpenBrace();
        bool ValidateCloseBrace();
        bool ValidateEndOfFile();
        Pair parseAPair();
        EntityInstance parseJSONObject();
        void TokenPrint();
        void arrayPrint();//this will print out our two dimensional array
        EntitySet parseJSONEntity();

    private:
        JSONTokenizer _tokenizer;
        // JSONTokenizer _tokenizer2;
        JSONToken _token;
        void rowColumnCalculator(double firstYearGpa, double secondYearGpa);
        vector<pair<EntityInstance,EntityInstance> > commonElements;
};

#endif 