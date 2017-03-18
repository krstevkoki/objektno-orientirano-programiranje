//
// Created by krstevkoki on 3/17/17.
//
#include <iostream>
#include <cstring>

using namespace std;

enum zanr {
    AKCIJA, KOMEDIJA, DRAMA
};

class Film {
private:
    char *name;
    int movie_size;
    zanr z;
public:
    Film(char *name = "", int movie_size = 0, zanr z = AKCIJA) {
        this->movie_size = movie_size;
        this->z = z;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Film(const Film &m) {
        this->movie_size = m.movie_size;
        this->z = m.z;
        this->name = new char[strlen(m.name) + 1];
        strcpy(this->name, m.name);
    }

    Film &operator=(Film &m) {
        if (this != &m) {
            this->movie_size = m.movie_size;
            this->z = m.z;
            delete[] this->name;
            this->name = new char[strlen(m.name) + 1];
            strcpy(this->name, m.name);
        }
        return *this;
    }

    ~Film() {
        delete[] name;
    }

    const void pecati() {
        cout << movie_size << "MB-\"" << name << "\"" << endl;
    }

};

class DVD {
private:
    Film movies[5];
    int num_movies;
    int dvd_capacity;
public:
    DVD(int dvd_capacity, int num_movies, Film *movies) {

    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    }
    return 0;
}
