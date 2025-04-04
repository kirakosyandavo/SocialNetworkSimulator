#include"Utility.h"
using namespace std;
bool Utility::isvalidEmail(const std::string& email){
    int flag=1;
    for(int i=0;i<email.size();i++){
        if(email[i]=='@'){
            flag=0;
            break;
        }
    }
    if(flag==1){
        return false;
    }
    for(int i=0;i<email.size();i++){
        if(email[i]=='.'){
            return true;
        }
    }
    return false;
}
