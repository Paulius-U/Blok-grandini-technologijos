#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
#include <bitset>
#include <chrono>
#include <random>
#include <cstring>

using namespace std;

int rand1[] = {129, 163, 44, 158, 178, 8, 161, 140, 59, 184, 240, 124, 245, 231, 167, 57, 115, 40, 222, 243, 209, 182, 128, 175, 82, 219, 215, 3, 206, 207, 230, 172, 114, 220, 185, 145, 22, 200, 227, 95, 1, 39, 188, 62, 56, 192, 6, 119, 69, 68, 236, 100, 205, 18, 5, 121, 116, 170, 41, 27, 241, 187, 67, 190, 255, 229, 99, 94, 148, 130, 111, 28, 251, 98, 147, 120, 55, 210, 127, 152, 226, 193, 165, 156, 43, 72, 80, 89, 83, 244, 4, 71, 7, 81, 169, 186, 141, 223, 97, 2, 201, 24, 155, 21, 191, 138, 248, 162, 131, 225, 45, 77, 204, 104, 19, 86, 224, 93, 211, 253, 61, 29, 10, 137, 91, 160, 70, 144, 37, 176, 103, 50, 157, 75, 213, 63, 16, 221, 208, 181, 32, 183, 149, 9, 112, 198, 23, 146, 134, 159, 249, 189, 42, 202, 135, 150, 96, 14, 105, 247, 139, 31, 212, 53, 132, 54, 154, 199, 17, 232, 0, 33, 109, 214, 133, 237, 25, 84, 88, 177, 79, 254, 125, 102, 92, 51, 64, 151, 49, 252, 228, 47, 15, 87, 174, 110, 76, 233, 13, 113, 216, 217, 46, 143, 122, 196, 108, 218, 101, 203, 194, 30, 126, 73, 11, 195, 52, 48, 90, 142, 171, 166, 180, 234, 60, 118, 12, 168, 74, 65, 66, 246, 20, 153, 38, 26, 136, 164, 85, 242, 173, 238, 197, 106, 35, 117, 250, 239, 107, 58, 78, 36, 179, 123, 34, 235};
int rand2[] = {184, 182, 100, 43, 212, 118, 84, 106, 107, 137, 130, 143, 144, 13, 181, 82, 113, 194, 198, 165, 28, 48, 91, 159, 67, 101, 63, 94, 190, 81, 231, 52, 10, 120, 131, 89, 221, 15, 253, 112, 121, 168, 85, 134, 98, 12, 228, 254, 241, 105, 5, 136, 108, 148, 183, 40, 191, 217, 246, 42, 201, 163, 76, 70, 92, 34, 64, 176, 60, 255, 111, 49, 116, 55, 50, 180, 205, 72, 233, 39, 122, 216, 31, 151, 45, 149, 22, 172, 135, 234, 117, 95, 152, 197, 59, 24, 86, 33, 248, 247, 235, 177, 96, 185, 87, 192, 0, 20, 30, 175, 103, 110, 97, 37, 179, 164, 204, 157, 2, 140, 133, 174, 51, 99, 200, 218, 109, 211, 243, 150, 88, 26, 14, 77, 220, 240, 7, 9, 169, 142, 162, 245, 223, 66, 167, 202, 32, 19, 236, 35, 102, 155, 154, 251, 222, 78, 83, 69, 58, 170, 123, 171, 114, 147, 250, 47, 53, 219, 16, 73, 242, 44, 161, 229, 11, 237, 17, 153, 252, 158, 187, 146, 8, 79, 56, 27, 90, 38, 129, 119, 249, 224, 1, 214, 124, 215, 3, 68, 239, 196, 213, 126, 145, 41, 125, 138, 80, 209, 62, 128, 61, 29, 238, 46, 36, 104, 203, 71, 230, 210, 195, 65, 6, 115, 57, 74, 54, 173, 178, 225, 226, 156, 23, 132, 232, 127, 21, 188, 227, 25, 189, 193, 160, 206, 186, 139, 4, 93, 207, 199, 208, 75, 18, 141, 244, 166};

void Nuskaitymas(int random);
string GetFile();
void Failo_Skaitymas(string FileName, string Eilute[], int& kiek);
void Failo_Generaviams();
string  gen_random(int len);
void Lyginimas();
void Bits();
void Hexas();
bitset<256> Hash(string inp);
string ATS(string temp);

int main()
{ 
    int random;
    std::cout << "Ar norite tikrinti faila po eilute? (1) " << endl; 
    std::cout << "Ar norite sukurti 100 000 eiluciu faila? (2) " << endl;
    std::cout << "Ar visa faila pakeisti i hash? (3)" << endl;
    std::cout << "Lyginimas hash (4) " << endl;
    std::cout << "Bitu / Hex lygmenys: (5) " << endl;
    cin >> random;
    if(random == 1)
        Nuskaitymas(2);
    if(random == 2)
        Failo_Generaviams();
    if(random == 3)
        Nuskaitymas(1);
    if(random == 4)
        Lyginimas();
    if(random == 5)
    {
        std::cout << "Sutapimas: " << endl;
        std::cout << "---------------------------------" << endl;
        Bits();
        Hexas();
    } 
    return 0;
}

void Nuskaitymas(int random)
{
    string FileName = GetFile();
    ofstream R("rez.txt");
    ofstream RR("bits.txt");
    double laikas = 0;
    int n, k = 0;
    string Tekstas = "", temp, laikinas;
    string * inp = new string[100000];
    bitset<256> out = 0;
    Failo_Skaitymas(FileName, inp, n);
    if (random == 1)
    {
        for (int i = 0; i < n; i++)
        {
            Tekstas += inp[i];
        }
        out = Hash(Tekstas);
        temp = out.to_string();
        Tekstas = ATS(temp);
        cout << Tekstas;

    }
    if (random == 2)
    {
        for (int i = 0; i < n; i++)
        {
            Tekstas = inp[i];
            out = Hash(Tekstas);
            temp = out.to_string();
            RR << temp << endl;
            auto Start = std::chrono::high_resolution_clock::now();
            laikinas = ATS(temp);
            auto End = std::chrono::high_resolution_clock::now();
            laikas += std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() / 1000.;
            R << laikinas << endl;
        }
        cout << "Is viso uztruko " << laikas << " s " << endl;
    }
    delete inp;
}

string GetFile() 
{
    bool Failas;
    std::string FileName;
    std::cout << "Failo pavadinimas: " << std::endl;
    std::cin >> FileName;
    do {
        try {
            std::ifstream D (FileName);
            if (!D.good())      
                throw 0;
            else {
                D.close();
                Failas = false;
            }
        } catch (int exception) {   
            Failas = true;
            std::cout << "Failas - " << FileName << " Neegzistuoja" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> FileName;
        }
    } while (Failas);             
    return FileName;
}

void Failo_Skaitymas(string FileName, string Eilute[], int& kiek)
{
    ifstream D (FileName);
    kiek = 0;
    string x;
    while (getline(D, x))
    {
        Eilute[kiek] = x;
        kiek++;
        // if ( kiek == 10000) break; 
    }        
}

void Failo_Generaviams()
{
    ofstream R ("random.txt");
    for(int i = 0; i < 25000; i++)
    {
        string raide = gen_random(10);
        R << raide << endl;
    }
    for(int i = 0; i < 25000; i++)
    {
        string raide = gen_random(100);
        R << raide << endl;       
    }
    for(int i = 0; i < 25000; i++)
    {
        string raide = gen_random(500);
        R << raide << endl;
    }
    for(int i = 0; i < 25000; i++)
    {
        string raide = gen_random(1000);
        R << raide << endl;
    }
}

string  gen_random(int len) 
{
    string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

void Lyginimas()
{
    ofstream R ("random.txt");
    int kiek = 0, in = 0;
    string a;
    string * laikinas1 = new string[100000];
    Failo_Skaitymas("rez.txt", laikinas1, in);
    for(int i = 0; i < in - 1; i++)
        for(int j = i + 1; j < in; j++)
        {
            if(laikinas1[i] == laikinas1[j])
            {
                std::cout << i + 1 << " " << j + 1 << endl;
                kiek++;
            }   
        }
    if(kiek > 0)
        std::cout << "Vienodu hash buvo " << kiek << " kartai / kartu" << endl;
    else std::cout << "Visi Hash skirtingi ";
    delete[] laikinas1;
}

void Bits()
{
    double Bats;
    double Bviso = 0;
    int Bmin = 1000;
    int Bmax = 0;
    int in = 0;
    string * bits = new string[100000];
    string a;
    Failo_Skaitymas("bits.txt", bits, in);
    for(int i = 0; i < in; i++)
        for(int j = i + 1; j < in - 1; j++)
        {
            int kiek = 0;
            const char *str = bits[i].c_str();
            const char *str2 = bits[j].c_str();
            for(int k = 0; k < 256; k++)
            {
                if (str[k] == str2[k])
                {
                    kiek++;
                }
            }
            Bviso += (double) kiek / 256;
            if(kiek < Bmin) Bmin = kiek;
            if(kiek > Bmax) Bmax = kiek;
        }
    Bats = Bviso / (in * (in - 1)) * 100;
    std::cout << "Bits min: " << Bmin << "   Bits max:   " << Bmax << "  Vidurkis " << Bats << " %" << endl;
    delete[] bits;
}

void Hexas()
{
    double Hats;
    double Hviso = 0;
    int Hmin = 1000;
    int Hmax = 0;
    int n = 0;
    char ssr[64], ssr2[64];
    string * hex = new string[100000]; 
    string b;
    Failo_Skaitymas("rez.txt", hex, n);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n - 1; j++)
        {
            int kiek = 0;
            strcpy(ssr, hex[i].c_str());
            strcpy(ssr2, hex[j].c_str());
            for(int k = 0; k < 64; k++)
            {
                if(ssr[k] == ssr2[k])
                {
                    kiek++;
                }
            }
            if(kiek < Hmin) Hmin = kiek;
            if(kiek > Hmax) Hmax = kiek;
            Hviso += (double) kiek / 64;
        }
    Hats = Hviso / (n * (n - 1)) * 100;
    std::cout << "Hex  min: " << Hmin << "    Hex  max:   " << Hmax << "    Vidurkis " << Hats << " %" << endl;
    delete[] hex;
}

bitset<256> Hash(string inp)
{
    if (inp == "")inp = "absdthu45th389wi";
    std::bitset<256> hash;
    for (int a = 0; a < inp.length(); a++)
    {
        for (int i = 0; i < 32; i++)
        {
            std::bitset<256> temp;
            int randomiser = rand1[(((int)inp[a] * 5 + i + a) % 256)] % 30;
            if(randomiser <= 7)
            {
                temp = inp[a];
                temp <<= randomiser;
                temp <<= (i * 8);
                hash ^= temp;
            }
            else if(randomiser <= 14)
            {
                temp = ~inp[a];
                temp <<= (randomiser - 8);
                temp <<= (i * 8);          
                hash ^= temp;
            }
            else{
                temp = rand2[(((int)inp[a] * 17 + i + a) % 256)];
                temp <<=(i * 8);
                hash ^= temp;
                temp = rand1[(((int)inp[a] * 3 + i + a) % 256)] % 30;
                hash ^= temp;
            }
        }
    }
    return hash;
}

string ATS(string temp)
{
    string a = "";
    for(int i = 0; i < 64; i++)
    {
        bitset <4> bss1( temp.substr (i * 4, (i + 1) * 4) );
        string out = "";
        if(bss1.to_ulong() <= 9)
        {
            out += bss1.to_ulong() + '0';
        }
        else
        {
            out += bss1.to_ulong() + 'a' - 10;
        }
        a += out;
    }
    return a;
}
