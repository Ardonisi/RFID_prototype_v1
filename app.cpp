#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
const int allStud = 3; 
const int k = 0;
const int n = 0;
int main()
{
    int i;
    int n; 
    int currentNrStud;
    int idStud[allStud];
    int X[allStud];
    char studName[allStud][20];



    cout << "\n ******** E V I D E N C A ********\n";
    cout << "\n ********      U K Z      ********\n";
     
    cout << "\n *********************************\n";



    cout << " Ne kete lend jane regjistruar: " << allStud << " student" << endl;

    cout << " Numri i tanishem i studentve ";
    cin >> currentNrStud;
    const int m = currentNrStud;
    cout << "\n *********************************\n";

    cout << " Ne kte lend jane rezervuar " << currentNrStud << " vende per te regjistruar ne list studentet " << endl;
    cout << " Sa studente doni t'i regjistroni ne liste ,nese nuk shtoni studente shtyp (zero 0): ";
    cin >> n;
        if (n > m)
        {
            cout << "\nNuk mundet, sepse jane rezervuar " << m << " vende per studente \n"
                << "Ndrysho vleren per numrin e studenteve \n" << endl;
            exit(0);
        }
    cout << endl;


    //Time variables 
    time_t currentTime = time(0);
    char* currentDate = ctime(&currentTime);
    tm* dateTimeUTC = gmtime(&currentTime);
    currentDate = asctime(dateTimeUTC);
    tm* localTime = localtime(&currentTime);


    for (i = 0; i < n; i++)
    {
        cout << "Shkruani ID e studentit:" << endl;

        cin >> idStud[i];
        cout << "Shkruani Emrin dhe Mbiemrin e studentit(formati Emri_Mbiemri shtyp enter): " << endl;

        cin >> studName[i];
        ofstream write("codes.bin", ios::out | ios::binary);
        write.write((char*)&idStud, sizeof(idStud));

        ofstream write1("names.bin", ios::out | ios::binary);
        write1.write((char*)&studName, sizeof(studName));

        cout << "\n Regjistrimi perfundoi me sukses \n\n";
        write.close(); write1.close();

        ofstream write6("codes.xls", ios::app);
        write6 << idStud[i] << " " << studName[i] << " " << localTime->tm_mday <<
            "." <<
            1 + localTime->tm_mon << "." << 1900 + localTime->tm_year <<
            "; " << " " << localTime->tm_hour << ":" << localTime->tm_min <<
            ":" << localTime->tm_sec << endl;
        write6.close();
    }
    // Reading from files codes.bin and names.bin
    ifstream read("codes.bin", ios::in | ios::binary);
    read.read((char*)&idStud, sizeof(idStud));
    ifstream read1("names.bin", ios::in | ios::binary);
    read1.read((char*)&studName, sizeof(studName));


    cout << "\nStudentet e regjistruar jane: \n";

    cout << " ID        Emri dhe Mbiemri     Data\n";
    for (i = 0; i < m; i++)
        cout << "\n " << idStud[i] << "    " << studName[i] << "   "
        << " " << localTime->tm_mday << "."
        << 1 + localTime->tm_mon << "." << 1900 + localTime->tm_year <<
        "; " << endl;
    cout << "\n\n";
Evidentimi:
    cout << "Cilin student deshironi te kerkoni sipas ID-se: \n";
    cout << "Nese deshironi te dilni nga programi shtyp nje komand \n";
    cout << "------------------------------------------------------------------------------------------- \n";
    cout << "ID eshte: ";
    cin >> X[m];


    ofstream write2("evidenca.bin", ios::out | ios::binary);
    write2.write((char*)&X, sizeof(X));
    cout << "\nstudenti eshte regjistruar me sukses\n\n";
    write2.close();


    ifstream read2("evidenca.bin", ios::in | ios::binary);
    read2.read((char*)&X, sizeof(X));
    cout << "\nID e lexuar e studentit eshte: "; cout << X[m] << "\n";


    ifstream read3("codes.bin", ios::in | ios::binary);
    read3.read((char*)&idStud, sizeof(idStud));
    ifstream write3("names.bin", ios::in | ios::binary);
    write3.read((char*)&studName, sizeof(studName));


    ifstream write4("codes.xls", ios::in);
    i = 0;
    while (i == m)
    {
        cout << idStud[i] << " " << studName[i] << endl;
    }
    i = i++;
    i = 0;

    while (i < m)
    {
        if (X[m] == idStud[i])
        {
            cout << "Studenti me ID " << idStud[i] << " eshte " << studName[i] << "  \n";


            ofstream write5("evidenca.xls", ios::app);
            {
                write5 << studName[i] << " " << localTime->tm_mday << "." <<
                    1 + localTime->tm_mon << "." << 1900 + localTime->tm_year <<
                    "; " << " " << localTime->tm_hour << ":" <<
                    localTime->tm_min << ":" << localTime->tm_sec << endl;
                write5.close();
            }
            cout << "\nRegjistrimi perfundoi me sukses\n\n";
            cout << "-------------------------------------------------------------------------\n";

            goto Evidentimi;
            exit(0);
        }
        i = i + 1;
    }

    cout << "Studenti me ID " << X[m] << " Nuk eshte i regjistruar; Prandaj, regjistrone duke ekzekutu serish programin \n";
    exit(1);
    system("pause");
    return 0;
}
