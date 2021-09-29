#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
#include <bitset>
#include <chrono>
#include <random>

using namespace std;

string GetFile();
bool Pirminis(int x);
void Failo_Skaitymas(string FileName, string& Eilute);
void Failo_Skaitymas_Eilutem();
void Failo_Generaviams();
string  gen_random(int len);

int main()
{ 
    int random;
    cout << "Ar norite tikrinti faila po eilute? (1/0) "; cin >> random;
    if(random == 1)
        Failo_Skaitymas_Eilutem();

    int random1;
    cout << "Ar norite sukurti 100 000 eiluciu faila? (1/0) "; cin >> random1;
    if(random1== 1)
        Failo_Generaviams();
    
    
    string FileName = GetFile();
    string inp;

    bitset<256> out = 0;
    int kiek = 0;
    int pirm[10000];    
    for (int i = 0; i <= 100000; i++)
    {
        if(Pirminis(i))
        {
            pirm[kiek] = i;
            kiek++;
        }
    }
    Failo_Skaitymas(FileName, inp);
    for(int in = 0; in < inp.length() % 1000000; in++)
    {
        for(int i = 0; i < 256; i++)
        {
            bitset <256> t = inp[in];
            t ^= pirm [(i * in) % kiek];
            t <<= i;
            out ^= t;
            if (in > 16)
            {
                out[(in + 1) % 256] = out[i];
                out.flip(8);
            }
            else if(in > 8)
                {               
                    out[in - 4] = out[i];
                    out.flip(4);
                }  
                else if (in > 4)
                    {
                        out[in + 16] = out[i];
                        t <<= 5;
                    }
                    else
                    {
                        out[in + 5] = out[i];
                        out.flip(9);
                        t <<= 3;
                    }
            if (i % 3 == 0)
            {
                out[(in + 24) % 256] = out[i];
                out.flip(2);
                t <<= 4;
            }
            else if (i % 5 == 0)
                {
                    out[in % 256] = out[i];
                    t >>= 3;
                }
                else
                {
                    out.flip(7);
                    out[in % 256] = out[i * 18];
                    t <<= 6;
                }
            if (i == 2)
            {
                out[(in + 14) % 256] = out[i + 6];
                out.flip(5);
                t >>= 1;
            }
            if (i + in > 16)
            {
                out[(in + 4) % 256] = out[i * 9];
                t <<= 3;
                out[(in * 10) % 256] = out[i + 4];
                t >>= 2;
                out[(in + 5) % 256] = out[i + 12];
                t <<= 7;
            }
        }                  
    }
    string temp = out.to_string();
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
        cout << out;
    }
    return 0;
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

bool Pirminis(int x) 
{
    if (x % 2 == 0) {
        return false;
    }
    
    for (int i = 3; i <= sqrt(x); i += 2)
    {
        if (x % i == 0) 
        {
            return false;
        }
    }
    return true;
}

void Failo_Skaitymas(string FileName, string& Eilute)
{
    ifstream D (FileName);
    string Tekstas, starter = "asgiuhbgsiuhaiushfijgb9iugaf", Laikinas = " ";
    Eilute = starter;
    char a;
    while (getline(D, Tekstas))
    {
        for (int i = 0; i < Tekstas.length(); i++)
        {
            a = Tekstas[i];
            if(a == 'e')
                Laikinas += starter; 
            if(a == 'r')
                Laikinas += starter + starter; 
            if(a == 't')
                Laikinas += "ashijiuhg"; 
            if(a == 'y')
                Laikinas += "asjhnkfuijdgniua";
            if(a == 'u')
                Laikinas += "iudehfasinbuihjbn";
            if(a == 'i')
                Laikinas += "3wuiahijngijnaijsib5";
            if(a == 'o')
                Laikinas += "asmlksdjnfgijas";
            if(a == 'p')
                Laikinas += "asoidfhaiujgbaijshokhbv";
            if(a == 'a')
                Laikinas += "asjoidjgibasf"; 
            if(a == 's')
                Laikinas += "asdfoibhvniouashs9"; 
            if(a == 'd')
                Laikinas += "asfnoknbiuabs"; 
            if(a == 'f')
                Laikinas += "bolkasndovindibj"; 
            if(a == 'g')
                Laikinas += "asfoijbv09iasjoi"; 
            if(a == 'h')
                Laikinas += "asfouiuhbiojasoipf"; 
            if(a == 'j')
                Laikinas += "basoidhgoiasjgsa"; 
            if(a == 'k')
                Laikinas += "boijuhansijbn"; 
            if(a == 'l')
                Laikinas += "asgnoibhiuhiu vasd"; 
            if(a == 'z')
                Laikinas += "asgvoi h9ifja0jf";
            if(a == 'c')
                Laikinas += "gnviajbihasbfij"; 
            if(a == 'v')
                Laikinas += "asvoijhgv98ahs"; 
            if(a == 'b')
                Laikinas += "amsofjkbnjhbasokas"; 
            if(a == 'n')
                Laikinas += "asvboijbg9iuahso"; 
            if(a == 'm')
                Laikinas += "asgoihbijnkplkoihbajioy8u";               
        }
        Eilute += Tekstas;
        Eilute += Laikinas;
    }
    Eilute += '\0';
}

void Failo_Skaitymas_Eilutem()
{
    double laikas = 0;
    string FileName = GetFile();
    ifstream D (FileName);
    ofstream R ("rez.txt");
    string Tekstas, starter = "asgiuhbgsiuhaiushfijgb9iugaf";
    string Eilute = starter;
    bitset<256> out = 0;
    char a;
    while (getline(D, Tekstas))
    {
        for (int i = 0; i < Tekstas.length(); i++)
        {
            a = Tekstas[i];
            if(a == 'e')
                Eilute += starter; 
            if(a == 'r')
                Eilute += starter + starter; 
            if(a == 't')
                Eilute += "ashijiuhg"; 
            if(a == 'y')
                Eilute += "asjhnkfuijdgniua";
            if(a == 'u')
                Eilute += "iudehfasinbuihjbn";
            if(a == 'i')
                Eilute += "3wuiahijngijnaijsib5";
            if(a == 'o')
                Eilute += "asmlksdjnfgijas";
            if(a == 'p')
                Eilute += "asoidfhaiujgbaijshokhbv";
            if(a == 'a')
                Eilute += "asjoidjgibasf"; 
            if(a == 's')
                Eilute += "asdfoibhvniouashs9"; 
            if(a == 'd')
                Eilute += "asfnoknbiuabs"; 
            if(a == 'f')
                Eilute += "bolkasndovindibj"; 
            if(a == 'g')
                Eilute += "asfoijbv09iasjoi"; 
            if(a == 'h')
                Eilute += "asfouiuhbiojasoipf"; 
            if(a == 'j')
                Eilute += "basoidhgoiasjgsa"; 
            if(a == 'k')
                Eilute += "boijuhansijbn"; 
            if(a == 'l')
                Eilute += "asgnoibhiuhiu vasd"; 
            if(a == 'z')
                Eilute += "asgvoi h9ifja0jf";
            if(a == 'c')
                Eilute += "gnviajbihasbfij"; 
            if(a == 'v')
                Eilute += "asvoijhgv98ahs"; 
            if(a == 'b')
                Eilute += "amsofjkbnjhbasokas"; 
            if(a == 'n')
                Eilute += "asvboijbg9iuahso"; 
            if(a == 'm')
                Eilute += "asgoihbijnkplkoihbajioy8u";              
        }
        Eilute += Tekstas;
        int kiek = 0;
        int pirm[10000];    
        for (int i = 0; i <= 100000; i++)
        {
            if(Pirminis(i))
            {
                pirm[kiek] = i;
                kiek++;
            }
        }
        string inp = Eilute;
        for(int in = 0; in < inp.length(); in++)
        {
            for(int i = 0; i < 256; i++)
            {
                bitset <256> t = inp[in];
                t ^= pirm [(i * in) % kiek];
                t <<= i;
                out ^= t;
                if (in > 16)
                {
                    out[(in + 1) % 256] = out[i];
                    out.flip(8);
                }
                else if(in > 8)
                    {               
                        out[in - 4] = out[i];
                        out.flip(4);
                    }  
                    else if (in > 4)
                        {
                            out[in + 16] = out[i];
                            t <<= 5;
                        }
                        else
                        {
                            out[in + 5] = out[i];
                            out.flip(9);
                            t <<= 3;
                        }
                if (i % 3 == 0)
                {
                    out[(in + 24) % 256] = out[i];
                    out.flip(2);
                    t <<= 4;
                }
                else if (i % 5 == 0)
                    {
                        out[in % 256] = out[i];
                        t >>= 3;
                    }
                    else
                    {
                        out.flip(7);
                        out[in % 256] = out[i * 18];
                        t <<= 6;
                    }
                if (i == 2)
                {
                    out[(in + 14) % 256] = out[i + 6];
                    out.flip(5);
                    t >>= 1;
                }
                if (i + in > 16)
                {
                    out[(in + 4) % 256] = out[i * 9];
                    t <<= 3;
                    out[(in * 10) % 256] = out[i + 4];
                    t >>= 2;
                    out[(in + 5) % 256] = out[i + 12];
                    t <<= 7;
                }
            }                  
        }
        string temp = out.to_string();
        auto Start = std::chrono::high_resolution_clock::now();
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
            // R << out;
        }
        auto End = std::chrono::high_resolution_clock::now();
        laikas += std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() / 1000.;
        // R << endl;
        inp = " ";
        temp = " ";
        out = 0;
    }
    cout << "is viso uztruko: " << laikas << endl;
}

void Failo_Generaviams()
{
    ofstream R ("100k.txt");
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


        // if(Tekstas == "e")
        //     Eilute += starter; 
        // if(Tekstas == "r")
        //     Eilute += starter + starter; 
        // if(Tekstas == "t")
        //     Eilute += starter + "ashijiuhg"; 
        // if(Tekstas == "y")
        //     Eilute += starter + "asjhnkfuijdgniua";
        // if(Tekstas == "u")
        //     Eilute += starter + "iudehfasinbuihjbn";
        // if(Tekstas == "i")
        //     Eilute += starter + "3wuiahijngijnaijsib5";
        // if(Tekstas == "o")
        //     Eilute += starter + "asmlksdjnfgijas";
        // if(Tekstas == "p")
        //     Eilute += starter + "asoidfhaiujgbaijshokhbv";
        // if(Tekstas == "a")
        //     Eilute += starter + "asjoidjgibasf"; 
        // if(Tekstas == "s")
        //     Eilute += starter + "asdfoibhvniouashs9"; 
        // if(Tekstas == "d")
        //     Eilute += starter + "asfnoknbiuabs"; 
        // if(Tekstas == "f")
        //     Eilute += starter + "bolkasndovindibj"; 
        // if(Tekstas == "g")
        //     Eilute += starter + "asfoijbv09iasjoi"; 
        // if(Tekstas == "h")
        //     Eilute += starter + "asfouiuhbiojasoipf"; 
        // if(Tekstas == "j")
        //     Eilute += starter + "basoidhgoiasjgsa"; 
        // if(Tekstas == "k")
        //     Eilute += starter + "boijuhansijbn"; 
        // if(Tekstas == "l")
        //     Eilute += starter + "asgnoibhiuhiu vasd"; 
        // if(Tekstas == "z")
        //     Eilute += starter + "asgvoi h9ifja0jf";
        // if(Tekstas == "c")
        //     Eilute += starter + "gnviajbihasbfij"; 
        // if(Tekstas == "v")
        //     Eilute += starter + "asvoijhgv98ahs"; 
        // if(Tekstas == "b")
        //     Eilute += starter + "amsofjkbnjhbasokas"; 
        // if(Tekstas == "n")
        //     Eilute += starter + "asvboijbg9iuahso"; 
        // if(Tekstas == "m")
        //     Eilute += starter + "asgoihbijnkplkoihbajioy8u";  