#include"global.h"
void executeSOURCE() {

    std::ifstream queryFile("data/" + parsedQuery.sourceFileName + ".ra");
    std::string fileContent((std::istreambuf_iterator<char>(queryFile)),
                            std::istreambuf_iterator<char>());

    std::vector<std::string> queries;
    std::istringstream iss(fileContent);
    std::string query;
    while (std::getline(iss, query, '\n')) {
        queries.push_back(query);
    }


    for (const std::string &query : queries) {
        if (!query.empty()) {
            executeCommand(query); 
        }
    }
}

void executeCommand(){

    switch(parsedQuery.queryType){
        case CLEAR: executeCLEAR(); break;
        case CROSS: executeCROSS(); break;
        case DISTINCT: executeDISTINCT(); break;
        case EXPORT: executeEXPORT(); break;
        case INDEX: executeINDEX(); break;
        case JOIN: executeJOIN(); break;
        case LIST: executeLIST(); break;
        case LOAD: executeLOAD(); break;
        case PRINT: executePRINT(); break;
        case PROJECTION: executePROJECTION(); break;
        case RENAME: executeRENAME(); break;
        case SELECTION: executeSELECTION(); break;
        case SORT: executeSORT(); break;
        case SOURCE: executeSOURCE(); break;
        default: cout<<"PARSING ERROR"<<endl;
    }

    return;
}

void printRowCount(int rowCount){
    cout<<"\n\nRow Count: "<<rowCount<<endl;
    return;
}
