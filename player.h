#include <string>
using namespace std;

class player {
    private:
        string nama;
        int nomer;

    public:
        void tambahData(string name, int no){
            nama=name;
            nomer=no;
        }
        string getNama(){
            return nama;
        }
        int getNomer(){
            return nomer;
        }
};