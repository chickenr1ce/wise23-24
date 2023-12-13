#include <iostream>

using namespace std;

class Logger
{   
    private:

        string name;

    public:

        //Konstruktor der Klasse
        Logger(string n)
        {   
            name = n;

            cout<< "Eine neue Instanz der Klasse Logger wurder erzeugt.\n";
        }

        void logmsg(string txt)
        {
            cout << name <<  " - Neue Lognachricht:" << txt << endl;
        }
        
        ~Logger()
        {
            cout << "Ciao sagt " << name << "\n";
        }

};

int main()
{
    cout << "Hello world!" << endl;

    Logger* l1;
    l1 = new Logger("L1");
    l1 -> logmsg("Programm wird gestartet!");

    for (int i=0; i<5; i++)
        l1 -> logmsg(to_string(i));

    l1->logmsg("Programm wird beendet!");

    Logger l2 = Logger("L2");

    Logger l3 = Logger("L3");
}