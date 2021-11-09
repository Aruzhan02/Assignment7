#include <iostream>
#include "Text_Preprocessor.h"

using namespace std;
int main() {

    Text_Preprocessor n("Text_1.txt");

    n.openFile();
    n.deleteNeNuzhnoe();
    n.deletePrev();
}
