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

void Hash();
string GetFile();
bool Pirminis(int x);
void Failo_Skaitymas(string FileName, string& Eilute);
void Failo_Skaitymas_Eilutem();
void Failo_Generaviams();
string  gen_random(int len);
void Lyginimas();
void Bits();
void Hexas();

int main()
{ 
    int random;
    cout << "Ar norite tikrinti faila po eilute? (1) " << endl; 
    cout << "Ar norite sukurti 100 000 eiluciu faila? (2) " << endl;
    cout << "Ar visa faila pakeisti i hash? (3)" << endl;
    cout << "Lyginimas hash (4) " << endl;
    cout << "Bitu / Hex lygmenys: (5) " << endl;
    cin >> random;
    if(random == 1)
        Failo_Skaitymas_Eilutem();
    if(random == 2)
        Failo_Generaviams();
    if(random == 3)
        Hash();
    if(random == 4)
        Lyginimas();
    if(random == 5)
    {
        cout << "Sutapimas: " << endl;
        cout << "---------------------------------" << endl;
        Bits();
        Hexas();
    } 
    return 0;
}

void Hash()
{
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
                Laikinas += "ashijg"; 
            if(a == 'y')
                Laikinas += "asjhnk";
            if(a == 'u')
                Laikinas += "iudehfihjbn";
            if(a == 'i')
                Laikinas += "3wuiahsib5";
            if(a == 'o')
                Laikinas += "aas";
            if(a == 'p')
                Laikinas += "asookhbv";
            if(a == 'a')
                Laikinas += "asjsf"; 
            if(a == 's')
                Laikinas += "asdfashs9"; 
            if(a == 'd')
                Laikinas += "asfnoknbbs"; 
            if(a == 'f')
                Laikinas += "bolkbj"; 
            if(a == 'g')
                Laikinas += "09"; 
            if(a == 'h')
                Laikinas += "asfouipf"; 
            if(a == 'j')
                Laikinas += "basoidhassa"; 
            if(a == 'k')
                Laikinas += "bojbn"; 
            if(a == 'l')
                Laikinas += "asgnasd"; 
            if(a == 'z')
                Laikinas += "asga0jf";
            if(a == 'c')
                Laikinas += "gnvbfij"; 
            if(a == 'v')
                Laikinas += "asv"; 
            if(a == 'b')
                Laikinas += "amsofokas"; 
            if(a == 'n')
                Laikinas += "asvbo"; 
            if(a == 'm')
                Laikinas += "aihbajioy8u";
            if(a == '1')  
                Laikinas += "aoishij44535bi9uwa";
            if(a == '2')
                Laikinas += "suo";
            if(a == '3') 
                Laikinas += "bknsijghiu9as";
            if(a == '4')  
                Laikinas += "bjisajnoin32hnauioh"; 
            if(a == '5')  
                Laikinas += "3ri98guj97jgijbnu8ia";
            if(a == '6')  
                Laikinas += "5yi9ih9834g3g0ns8iugf";
            if(a == '7')  
                Laikinas += "b9t83uyuthijnvb";
            if(a == '8')  
                Laikinas += "pogbikgdjoiiuh09-wog";
            if(a == '9')  
                Laikinas += "35j9jg74gijsb89ugf"; 
            if(a == '0')  
                Laikinas += "4980uybniushgf8";
            if(a == ' ')  
                Laikinas += "45u9uh8g9fuh8t7gh23978h";
            if(a == 'E')
                Laikinas =+ "aoigjn9gn";
            if(a == 'R')
                Laikinas =+ "boiahs346y09s";
            if(a == 'T')
                Laikinas =+ "asgm9ihgj928uaj";
            if(a == 'Y')
                Laikinas =+ "asg0oijg923sg9i";
            if(a == 'U')
                Laikinas =+ "ag09idujg98";
            if(a == 'I')
                Laikinas =+ "bo9iajgu8jasgas";
            if(a == 'O')
                Laikinas =+ "hb909uashgiuasg";
            if(a == 'P')
                Laikinas =+ "gba9uiasng";
            if(a == 'A')
                Laikinas =+ "agoijguahjs";
            if(a == 'S')
                Laikinas =+ "489unio";
            if(a == 'D')
                Laikinas =+ "hnolk";
            if(a == 'F')
                Laikinas =+ "asgmh3gfhdgas";
            if(a == 'G')
                Laikinas =+ "t0i8guhti ";
            if(a == 'H')
                Laikinas =+ "h0uewg";
            if(a == 'J')
                Laikinas =+ "4e8098g9hgijseng";
            if(a == 'K')
                Laikinas =+ "yjh5hy87324g7";
            if(a == 'L')
                Laikinas =+ "y07q";
            if(a == 'Z')
                Laikinas =+ "yh8fu";
            if(a == 'C')
                Laikinas =+ "yhntmwo";
            if(a == 'V')
                Laikinas =+ "gf9uiiug7yu";
            if(a == 'B')
                Laikinas =+ "g84hty8";
            if(a == 'N')
                Laikinas =+ "t0ht";
            if(a == 'M')
                Laikinas =+ "hwuyfg";
            if(a == 'X')
                Laikinas =+ "t9023wqy9";
            if(a == ')')
                Laikinas =+ "623478yg8734";
            if(a == '-')
                Laikinas += "9887hg324";
        }
        Eilute += Laikinas;
        Eilute += Tekstas;
    }
    Eilute += '\0';
}

void Failo_Skaitymas_Eilutem()
{
    double laikas = 0;
    int n = 0;
    string FileName = GetFile();
    ifstream D (FileName);
    ofstream R ("rez.txt");
    ofstream RR ("bits.txt");
    string Tekstas, starter = "asgiuhbgsiuhaiushfijgb9iugaf", Laikinas, s = " ";
    string Eilute = starter;
    bitset<256> out = 0;
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
                Laikinas += "ashijg"; 
            if(a == 'y')
                Laikinas += "asjhnk";
            if(a == 'u')
                Laikinas += "iudehfihjbn";
            if(a == 'i')
                Laikinas += "3wuiahsib5";
            if(a == 'o')
                Laikinas += "aas";
            if(a == 'p')
                Laikinas += "asookhbv";
            if(a == 'a')
                Laikinas += "asjsf"; 
            if(a == 's')
                Laikinas += "asdfashs9"; 
            if(a == 'd')
                Laikinas += "asfnoknbbs"; 
            if(a == 'f')
                Laikinas += "bolkbj"; 
            if(a == 'g')
                Laikinas += "09"; 
            if(a == 'h')
                Laikinas += "asfouipf"; 
            if(a == 'j')
                Laikinas += "basoidhassa"; 
            if(a == 'k')
                Laikinas += "bojbn"; 
            if(a == 'l')
                Laikinas += "asgnasd"; 
            if(a == 'z')
                Laikinas += "asga0jf";
            if(a == 'c')
                Laikinas += "gnvbfij"; 
            if(a == 'v')
                Laikinas += "asv"; 
            if(a == 'b')
                Laikinas += "amsofokas"; 
            if(a == 'n')
                Laikinas += "asvbo"; 
            if(a == 'm')
                Laikinas += "aihbajioy8u";
            if(a == '1')  
                Laikinas += "aoishij44535bi9uwa";
            if(a == '2')
                Laikinas += "suo";
            if(a == '3') 
                Laikinas += "bknsijghiu9as";
            if(a == '4')  
                Laikinas += "bjisajnoin32hnauioh"; 
            if(a == '5')  
                Laikinas += "3ri98guj97jgijbnu8ia";
            if(a == '6')  
                Laikinas += "5yi9ih9834g3g0ns8iugf";
            if(a == '7')  
                Laikinas += "b9t83uyuthijnvb";
            if(a == '8')  
                Laikinas += "pogbikgdjoiiuh09-wog";
            if(a == '9')  
                Laikinas += "35j9jg74gijsb89ugf"; 
            if(a == '0')  
                Laikinas += "4980uybniushgf8";
            if(a == ' ')  
                Laikinas += "45u9uh8g9fuh8t7gh23978h";
            if(a == 'E')
                Laikinas =+ "aoigjn9gn";
            if(a == 'R')
                Laikinas =+ "boiahs346y09s";
            if(a == 'T')
                Laikinas =+ "asgm9ihgj928uaj";
            if(a == 'Y')
                Laikinas =+ "asg0oijg923sg9i";
            if(a == 'U')
                Laikinas =+ "ag09idujg98";
            if(a == 'I')
                Laikinas =+ "bo9iajgu8jasgas";
            if(a == 'O')
                Laikinas =+ "hb909uashgiuasg";
            if(a == 'P')
                Laikinas =+ "gba9uiasng";
            if(a == 'A')
                Laikinas =+ "agoijguahjs";
            if(a == 'S')
                Laikinas =+ "489unio";
            if(a == 'D')
                Laikinas =+ "hnolk";
            if(a == 'F')
                Laikinas =+ "asgmh3gfhdgas";
            if(a == 'G')
                Laikinas =+ "t0i8guhti ";
            if(a == 'H')
                Laikinas =+ "h0uewg";
            if(a == 'J')
                Laikinas =+ "4e8098g9hgijseng";
            if(a == 'K')
                Laikinas =+ "yjh5hy87324g7";
            if(a == 'L')
                Laikinas =+ "y07q";
            if(a == 'Z')
                Laikinas =+ "yh8fu";
            if(a == 'C')
                Laikinas =+ "yhntmwo";
            if(a == 'V')
                Laikinas =+ "gf9uiiug7yu";
            if(a == 'B')
                Laikinas =+ "g84hty8";
            if(a == 'N')
                Laikinas =+ "t0ht";
            if(a == 'M')
                Laikinas =+ "hwuyfg";
            if(a == 'X')
                Laikinas =+ "t9023wqy9";
            if(a == ')')
                Laikinas =+ "623478yg8734";
            if(a == '-')
                Laikinas += "9887hg324";
        }
        Eilute += Tekstas;
        Eilute += Laikinas;
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
        for(int in = 0; in < inp.length() % 100000; in++)
        {
            for(int i = 0; i < 256; i++)
            {
                bitset <256> t = inp[in];
                t ^= pirm [(i * in) % kiek];
                t <<= i;
                out ^= t;
                if(in > 128)
                {
                    t ^= pirm [(i * in * 4) % kiek];
                    out ^= t;
                    if(i > 48)
                    {
                        ~out;
                    }
                }
                if(in > 48)
                {
                    if(i > 32)
                        t <<= 3;
                    else if(i > 48)
                            t ^= pirm [(i * in * 6) % kiek];
                         else if(i > 70 || 100)
                                out |= t;
                              else if(i > 150)
                                    out[(in + 14) % 256] = out[i];
                    out ^= t;
                }
                else if (in > 16)
                {
                    out[(in + 1) % 256] = out[i];
                    out.flip(8);
                    out |= t;
                }
                else if(in > 8)
                    {               
                        out[in - 4] = out[i];
                        out.flip(4);
                        if(i > 32)
                            out |= t;
                        else if(i > 48)
                                t <<= 16;
                             else if(i > 64)
                                     t ^= pirm [(i * in * 42) % kiek];
                                  else if(i > 128)
                                        t ^= pirm [(i * in * 123) % kiek];                                                       
                        out ^= t;
                        if(i > 200)
                        {
                            ~out;
                        }
                    }   
                    else if (in > 4)
                        {
                            out[in + 64] = out[i];
                            out[in + 56] = out[i];
                            out[in + 23] = out[i];
                            out[in + 16] = out[i];
                            out[in + 87] = out[i];
                            t <<= 5;
                            t ^= pirm [(i * in * 12) % kiek];
                            out ^= t;
                            if(i > 100) 
                            {
                                out |= t;
                                ~out;
                                if(i > 128)
                                {
                                    t ^= pirm [(i * in * 9) % kiek];
                                    t <<= 7;
                                }
                                else if(i > 200)
                                        out <<= 5;
                            }
                            else
                            {
                                if(i > 128)
                                    t ^= pirm [(i * in * 18) % kiek];
                                else if(i > 64)
                                        out ^= t;
                                if(i < 32)
                                    ~out;
                                out ^= t;
                            }                       
                        }
                        else
                        {
                            out[in + 5] = out[i];
                            out.flip(9);
                            t <<= 3;
                            ~out;
                            out ^= t;
                            out.flip(i);
                        }
                if(i == 32)
                {
                    out[in % 256] = 0;
                    out <<= 3;
                    out ^= t;
                }
                if(i == 84)
                    out[in % 256] = 1;
                if(i == 120)
                    ~out;
                if(i == 178)
                    out[in % 256] = 0;
                if(i == 150)
                    out ^= t;
                if(i == 40)
                    out <<= 12;
                if (i % 7 == 0)
                {
                    out.flip(in % 256);
                    out >>= 3;
                }
                if(i % 10 == 0)
                {
                    out.flip((in * i) % 256);
                    t ^= pirm [(i * in) % kiek];
                    out |= t;
                }
                if(i )
                if(i % 2 == 0)
                {
                    out ^= t;
                    out <<= 1;
                }
                if(i % 80 == 0)
                {
                    out.flip(in % 256);
                    out <<= 14;
                }
                if(i % 16 == 0)
                {
                    t ^= pirm [(i * in * 2) % kiek];
                    out ^= t;
                    out <<= 3;
                    out[(in * 36) % 256] = out[i];
                    out[(in * 14) % 256] = out[i];
                    out[(in * 42) % 256] = out[i];
                    out |= t;
                }
                if(i % 64 == 0)
                {
                    t ^= pirm [(i * in * 26) % kiek];
                    out ^= t;
                    out[(in * 12) % 256] = out[i];
                    out[(in * 76) % 256] = out[i];
                    out[(in * 84) % 256] = out[i];
                }
                if (i % 3 == 0)
                {
                    out[(in + 24) % 256] = out[i];
                    out.flip(2);
                    t <<= 4;
                    out ^= t;
                }
                else if (i % 5 == 0)
                    {
                        out[in % 256] = out[i];
                        t >>= 3;
                        out |= t;
                    }
                    else
                    {
                        out.flip(7);
                        out[in % 256] = out[i * 18];
                        t <<= 6;
                    }
                if (i % 16 == 2)
                {
                    out[(in + 14) % 256] = out[i + 6];
                    out.flip(5);
                    t >>= 1;
                    out ^= t;
                }
                if (i + in > 16)
                {
                    if(i > 0 || i < 10)
                    {
                        t ^= pirm [(i * in * 8) % kiek];
                        out ^= t;                        
                    }
                    if(i < 10)
                    {
                        out[(in + 4) % 256] = out[i * 9];
                        t <<= 3;                        
                    }
                    else ~t;
                    out[(in * 10) % 256] = out[i + 4];
                    t >>= 2;
                    out[(in + 5) % 256] = out[i + 12];
                    t <<= 7;
                    out ^= t;
                }
            }
        }                  
        auto Start = std::chrono::high_resolution_clock::now();
        string temp = out.to_string();
        RR << temp << endl;
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
            // cout << out;
            R << out;
        }
        auto End = std::chrono::high_resolution_clock::now();
        laikas += std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() / 1000.;
        s = Tekstas;
        if(s.length() > 10000)
            s = Tekstas;
        R << endl;
        Eilute = " ";
        Tekstas = " ";
        Laikinas = " ";
        inp = " ";
        temp = " ";
        out = 0;
        Eilute += s + s + s + s + s + s;
        n++;
    }
    cout << "is viso uztruko: " << laikas << endl;
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
    ifstream D ("rez.txt");
    ofstream R ("random.txt");
    int kiek = 0, in = 0;
    string a, laikinas[50000];
    while(getline(D, a))
    {      
        laikinas[in] = a;
        in++;
    }
    for(int i = 0; i < in - 1; i++)
        for(int j = i + 1; j < in; j++)
        {
            if(laikinas[i] == laikinas[j])
            {
                kiek++;
            }   
        }
    if(kiek > 0)
        cout << "Vienodu hash buvo " << kiek << " kartai / kartu" << endl;
    else cout << "Visi Hash skirtingi ";
}

void Bits()
{
    ifstream D ("bits.txt");
    double Bats;
    int Bviso = 0;
    int Bmin = 1000;
    int Bmax = 0;
    int in = 0;
    string bits[50000], a;
    while (getline(D, a))
    {
        bits[in] = a;
        in++;
    }
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
                    Bviso++;
                }
            }
                if(kiek < Bmin) Bmin = kiek;
                if(kiek > Bmax) Bmax = kiek;
        }

    Bats = (double) Bviso / (256 * in * (in - 1)) * 100;
    cout << "Bits min: " << Bmin << "   Bits max:   " << Bmax << "  Vidurkis " << Bats << " %" << endl;
}

void Hexas()
{
    ifstream DD ("rez.txt");
    double Hats;
    int Hviso = 0;
    int Hmin = 1000;
    int Hmax = 0;
    int n = 0;
    string hex[50000], b;

    while (getline(DD, b))
    {
        hex[n] = b;
        n++;
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n - 1; j++)
        {
            int kiek = 0;
            const char *ssr = hex[i].c_str();
            const char *ssr2 = hex[j].c_str();
            for(int k = 0; k < 64; k++)
            {
                if(ssr[k] == ssr2[k])
                {
                    kiek++;
                    Hviso++;
                }
            }
            if(kiek < Hmin) Hmin = kiek;
            if(kiek > Hmax) Hmax = kiek;
        }
    Hats = (double) Hviso / (64 * n * (n - 1)) * 100;
    cout << "Hex  min: " << Hmin << "    Hex  max:   " << Hmax << "    Vidurkis " << Hats << " %" << endl;
}
