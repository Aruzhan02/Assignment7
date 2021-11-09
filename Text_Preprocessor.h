
#ifndef CLIONPROJECTS_TEXT_PREPROCESSOR_H
#define CLIONPROJECTS_TEXT_PREPROCESSOR_H
#include "fstream"
#include <string>

using namespace std;


class Text_Preprocessor{

public:
    string text2;
    ifstream textfile;
    Text_Preprocessor(char *text_name){
        cout << text_name << endl;
        textfile.open(text_name, ios::in);
        char soz;
        string soz1 = "";
        string soz2;
        while(getline(textfile, soz2, '\0')){
            for(int i = 0; i < soz2.size(); ++i){
                soz = soz2[i];
                soz1 += soz;
            }
            if(textfile.eof()){
                break;
            }
        }
        this->text2 = soz1;
    }
    ~Text_Preprocessor(){//destructor
        textfile.close();
    }
    void preprocess_text(){
        string result = "";
        string file = this->text2;
        for(int i = 0; i < file.size(); ++i){
            if(file[i] != ',' && file[i] != '"' && file[i] != '.' && file[i] != ';' && file[i] != ':' && file[i] != '!' && file[i] != '?'){
                if(isalpha(file[i])) {
                    result += tolower(file[i]);
                }
                else{
                    result += file[i];
                }
            }
        }
        string birdene1 = "";
        string answer = "";
        for(int i = 0; i < result.size(); ++i){
            if(result[i] == ' '){
                if(birdene1 != "a" && birdene1 != "an" && birdene1 != "the" && birdene1 != "in" && birdene1 != "on"
                   && birdene1 != "at" && birdene1 != "since" && birdene1 != "for" && birdene1 != "before" && birdene1 != "ago" && birdene1 != "to" && birdene1 != "by"){
                    answer += birdene1;
                    answer += " ";
                }
                birdene1.clear();
            }
            else{
                birdene1 += result[i];
            }
        }
        if(birdene1 != "a" && birdene1 != "an" && birdene1 != "the" && birdene1 != "in" && birdene1 != "on"
           && birdene1 != "at" && birdene1 != "since" && birdene1 != "for" && birdene1 != "before" && birdene1 != "ago" && birdene1 != "to" && birdene1 != "by"){
            answer += birdene1;
            answer += " ";
        }
        birdene1.clear();
        this->text2 = answer;
    }

};



#endif //CLIONPROJECTS_TEXT_PREPROCESSOR_H
