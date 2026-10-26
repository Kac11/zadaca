#include <iostream>

using namespace std;

const double CIJENA_ULAZNICE = 5.0;
const int PRAG_POPUSTA = 5;
const double STOPA_POPUSTA = 0.10;

int ukupnoUlaznica = 0;
double ukupniPrihod = 0.0;

bool ispravanUnos(int kolicina);
double izracunajIznos(int kolicina);
void evidentirajKupnju(int kolicina, double iznos);
void ispisiKupnju(int redniBroj, double iznos);
void ispisiSazetak();

int main() {
    for (int redniBroj = 1; redniBroj <= 3; redniBroj++) {
        int kolicina;  
         cout << "Kupnja " << redniBroj << " unesi broj ulaznica (1-30): ";
            cin >> kolicina;
         while (!ispravanUnos(kolicina)){
             cout << "Kupnja " << redniBroj << " unesi broj ulaznica (1-30): ";
            cin >> kolicina;}

        double iznos = izracunajIznos(kolicina);
        evidentirajKupnju(kolicina, iznos);
        ispisiKupnju(redniBroj, iznos);
    }

    ispisiSazetak();

    return 0;
}

bool ispravanUnos(int kolicina) {
    if (kolicina >= 1 && kolicina <= 30) {
        return true;
    }
    return false;
}

double izracunajIznos(int kolicina) {
    double osnovniIznos = kolicina * CIJENA_ULAZNICE;
    double konacniIznos;

    if (kolicina >= PRAG_POPUSTA) {
        konacniIznos = osnovniIznos - (osnovniIznos * STOPA_POPUSTA);
    } else {
        konacniIznos = osnovniIznos;
    }

    return konacniIznos;
}

void evidentirajKupnju(int kolicina, double iznos) {
    ukupnoUlaznica += kolicina;
    ukupniPrihod += iznos;
}

void ispisiKupnju(int redniBroj, double iznos) {
    cout << "Kupnja " << redniBroj << ": " << iznos << " EUR" << endl;
}

void ispisiSazetak() {
    cout << "Ukupno prodanih ulaznica: " << ukupnoUlaznica << endl;
    cout << "Ukupni prihod: " << ukupniPrihod << " EUR" << endl;
}

