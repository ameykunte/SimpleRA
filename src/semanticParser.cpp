#include"global.h"

void ParsedQuery::semanticParseSOURCE()
{

    std::ifstream queryFile("data/" + sourceFileName + ".ra");
    std::string fileContent((std::istreambuf_iterator<char>(queryFile)),
                            std::istreambuf_iterator<char>());


    std::vector<std::string> queries;
    std::istringstream iss(fileContent);
    std::string query;
    while (std::getline(iss, query, ';'))
    {
        queries.push_back(query);
    }


    for (const std::string &query : queries)
    {
        if (!query.empty())
        {

            executeQuery(query);
        }
    }
}


bool semanticParse(){
    logger.log("semanticParse");
    switch(parsedQuery.queryType){
        case CLEAR: return semanticParseCLEAR();
        case CROSS: return semanticParseCROSS();
        case DISTINCT: return semanticParseDISTINCT();
        case EXPORT: return semanticParseEXPORT();
        case INDEX: return semanticParseINDEX();
        case JOIN: return semanticParseJOIN();
        case LIST: return semanticParseLIST();
        case LOAD: return semanticParseLOAD();
        case PRINT: return semanticParsePRINT();
        case PROJECTION: return semanticParsePROJECTION();
        case RENAME: return semanticParseRENAME();
        case SELECTION: return semanticParseSELECTION();
        case SORT: return semanticParseSORT();
        case SOURCE: return semanticParseSOURCE();
        default: cout<<"SEMANTIC ERROR"<<endl;
    }

    return false;
}
