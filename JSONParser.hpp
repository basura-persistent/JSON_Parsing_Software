#ifndef JSON_PARSER
#define JSON_PARSER

#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "JSONTokenizer.hpp"
#include <string>

class JSONParser {
    public:
        JSONParser(string InputFilename);
        bool ValidateOpenBrace();
        bool ValidateCloseBrace();
        Pair parseAPair();
        EntityInstance parseJSONObject();
        // Entity parseJSONEntity();

    private:
        JSONTokenizer _tokenizer;
        JSONToken _token;
};

#endif 