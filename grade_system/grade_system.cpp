#include <iostream>
#include <map>
#include <string>

using namespace std;

void mapYazdir(const map<string, float>& map);
float dortlukDonustur(double ort);

int main() 
{
    setlocale(LC_ALL, "Turkish");
    int dersSayisi;
    cout << "Donem suresince aldiginiz ders adedini giriniz: ";
    cin >> dersSayisi;

    map<string, float> lessonsNameandCredit;
    for (int i = 0; i < dersSayisi; ++i) 
    {
        string lessonName;
        float lessonCredit;
        cout << "Aldiginiz ders adini giriniz: ";
        cin >> lessonName;
        cout << "Aldiginiz dersin kredisini giriniz: ";
        cin >> lessonCredit;
        lessonsNameandCredit.insert({ lessonName, lessonCredit });
        cout << "Ders adi ve kredisi eklendi.\n\n";
    }
    mapYazdir(lessonsNameandCredit);


    map<string, pair<int, int>> visaandFinalGrades;
    for (const auto& ders : lessonsNameandCredit) 
    {
        int visaGrade, finalGrade;
        cout << ders.first << " dersinin vize notunu giriniz: ";
        cin >> visaGrade;
        cout << ders.first << " dersinin final notunu giriniz: ";
        cin >> finalGrade;
        visaandFinalGrades.insert({ ders.first, {visaGrade, finalGrade} });
        cout << "Dersin vize ve final notu eklendi.\n\n";
    }

    cout << "\n--- Ders Bazinda Ortalamalar (0.4 Vize, 0.6 Final) ---\n";
    double toplamAgirlikli = 0.0;
    double toplamKredi = 0.0;

    for (const auto& ders : lessonsNameandCredit) 
    {
        const string& ad = ders.first;
        float kredi = ders.second;

        auto notlar = visaandFinalGrades.at(ad);
        double ort = 0.4 * notlar.first + 0.6 * notlar.second;

        cout << ad << " -> Vize : " << notlar.first
            << ", Final : " << notlar.second
            << ", Ort : " << ort
            << ", Kredi : " << kredi << endl;

        toplamAgirlikli += ort * kredi;
        toplamKredi += kredi;
    }

    double donemOrt = (toplamKredi > 0.0) ? (toplamAgirlikli / toplamKredi) : 0.0;
    cout << "\n>>> Kredi Agirlikli Donem Ortalamasi : " << donemOrt << endl;
	cout << ">>> Dortluk Sisteme Gore Donem Ortalamasi : " << dortlukDonustur(donemOrt) << endl;

    return 0;
}


void mapYazdir(const map<string, float>& map)
{
    cout << "\n--- Dersler ve Krediler ---\n";
    for (const auto& gelenMap : map)
        cout << gelenMap.first << " : " << gelenMap.second << endl;
}
float dortlukDonustur(double ort)
{
    if (ort >= 90) 
        return 4.0;
    else if (ort >= 85) 
        return 3.5;
    else if (ort >= 80) 
        return 3.0;
    else if (ort >= 75) 
        return 2.5;
    else if (ort >= 65) 
        return 2.0;
    else if (ort >= 58) 
        return 1.5;
    else if (ort >= 50) 
        return 1.0;
    else return 0.0;
}