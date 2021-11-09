
#ifndef CLIONPROJECTS_TEXT_PREPROCESSOR_H
#define CLIONPROJECTS_TEXT_PREPROCESSOR_H
#include "fstream"
#include <string>

using namespace std;


class Text_Preprocessor {

public:

    string nameTxt;

    int counter = 0;
    int counter1 = 0;
    int c = 0;

    Text_Preprocessor(string nameTxt){
        this->nameTxt = nameTxt;
    };

    ofstream fout;

    ifstream fin;




    void openFile(){


        fin.open(nameTxt);

        fout.open(nameTxt, ofstream::app);

        if (!fin.is_open())
        {
            cout << "Файл не открылся..." << endl;
        }
        else {

            cout << "Файл открылся!" << endl;

            string str;

            int counterForCounter = 0;

            char ch;

            while(fin.get(ch)){

                counterForCounter++;

            }

            setCounter(counterForCounter);

        }

        fin.close();
        fout.close();
    }

    void deleteNeNuzhnoe(){
        fin.open(nameTxt);

        fout.open(nameTxt, ofstream::app);

            string str;

            char ch;
            fout << endl;
            while(fin.get(ch)){

                string s;

                if(ch == 44 || ch == 46 || ch == 34 || ch == 58 || ch == 59 || ch == 63 || ch == 33){}

                else if(ch > 64 && ch < 91){

                    ch = ch + 32;

                    fout << ch;

                    cout << ch;

                }

                else{

                    fout << ch;

                    cout << ch;

                }

                counter1++;

                if(getCounter() == counter1){
                    break;
                }

            }

        fin.close();
        fout.close();
        }

    void deletePrev(){
        fin.open(nameTxt);

        fout.open(nameTxt, ofstream::in);

        string s;

        char ch;

        while(fin.get(ch)){

            ch = 0;

                fout << ch;


            c++;

            if(getCounter() + 11 == c){
                break;
            }

        }

        fin.close();
        fout.close();
    }

    int getCounter() const {
        return counter;
    }

    void setCounter(int counter) {
        Text_Preprocessor::counter = counter;
    }

}; // Записать данные в текстовый файл, думаю я показал что я это более менее умею в первом таске, дедлайн горит)


#endif //CLIONPROJECTS_TEXT_PREPROCESSOR_H
