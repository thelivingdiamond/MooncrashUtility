#include "mainwindow.h"

#include <QApplication>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::tuple;
using std::get;


void MainWindow::readLogFile(){
    std::ifstream inputFile;
    inputFile.open("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Prey\\Whiplash\\Game.log");
    vector<string> lineparse;

    string text, output;
        if(inputFile.is_open()) {
            while (!inputFile.eof()) {
                std::getline(inputFile, text, '\n');
                lineparse.push_back(text);
                text = "";
            }
        } else {
            std::cout << "nope";
        }
        string delimiter = ": ";
        for(string s :lineparse){
            for(int i = 0; i <= parameters.size()-1; i++) {
                tuple<string,string,int> par = parameters[i];
                if (s.find(get<0>(par)) != std::string::npos) {
                    get<int>(par) = -2;
                    size_t pos = 0;
                    string token;
                    pos = s.find(delimiter);
                    if (pos != std::string::npos) {
                        token = s.substr(pos + 2, pos + 2);
                        parameters[i] = std::make_tuple(get<0>(par),get<1>(par),stoi(token));
                    } else {
                        get<2>(par) = -1;
                    }
                }
            }
        }

        inputFile.close();
        for(tuple<string,string,int> par : parameters) {
            cout << get<1>(par) << ": " << get<2>(par) << endl;
        }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    auto hotkey = new QHotkey(QKeySequence("ctrl+f1"),true,&a);
    std::cout << "Is Registerd: " << hotkey->isRegistered();
    QObject::connect(hotkey, &QHotkey::activated, qApp, [&](){
            w.readLogFile();
            w.updateLabels();
        });



    return a.exec();
}



