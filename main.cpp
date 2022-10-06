#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <string>
#include <math.h>

int main(int argc, char **argv){
    using namespace std;

    map<string,function<string(vector<string>)>> mapa;
    mapa[""] = [](vector<string> wektor){
        return "Wymagany jeden z parametrow: [sin] [add] [mod]";
    };
    mapa["add"] = [](vector<string> wektor)
    {
        string pierwsza = wektor.at(2);
        string druga = wektor.at(3);
        string wynik = to_string(stof(pierwsza)+stof(druga));
        //cout<<"wektor at(0) = "<<wektor.at(0)<<" wektor at(1) = " << wektor.at(1);
        return wynik;
    };
    mapa["mod"] = [](vector<string> wektor)
    {
        string pierwsza = wektor.at(2);
        string druga = wektor.at(3);
        return to_string(stoi(pierwsza)%stoi(druga));
    };
    mapa["sin"] = [](vector<string> wektor)
    {
        string pierwsza = wektor.at(2);
        double sinus = stod(pierwsza);
        return to_string(sin(sinus));
    };

    vector<string> argumenty(argv, argv + argc);
    function<string(vector<string>)> funkcja = mapa.at(argumenty.at(1));
    try{
        cout<<funkcja(argumenty);
    }catch (exception &e){
        cout<<"Blad. Wymagany jeden z parametrow: [sin] [add] [mod]";
    }
    return 0;
}
