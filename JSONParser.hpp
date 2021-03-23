#ifndef JSON_PARSER
#define JSON_PARSER

#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"
#include <string>

class JSONParser {
    public:
        JSONParser(string InputFilename);
        bool ValidateOpenBrace();
        bool ValidateCloseBrace();
        bool ValidateEndOfFile();
        Pair parseAPair();
        EntityInstance parseJSONObject();
        void TokenPrint();
        // Entity parseJSONEntity();

    private:
        JSONTokenizer _tokenizer;
        JSONToken _token;
};

#endif 