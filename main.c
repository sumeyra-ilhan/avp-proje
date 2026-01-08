#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Gunes_Sisteminde_Bulunan_Gezegen_Sayisi 8


const float PI = 3.14159;

// Sýrasýyla gezegen isimleri ve gezegenlerin yerçekimi ivmeleri(m/s^2)
const char *gezegenIsimleri[Gunes_Sisteminde_Bulunan_Gezegen_Sayisi] = {"Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"};

double yercekimleri[Gunes_Sisteminde_Bulunan_Gezegen_Sayisi] = {3.7, 8.87, 9.81, 3.71,
    24.79, 10.44, 8.69, 11.15};

// Negatif girilen deðerlerin mutlaðýný alan fonksiyon
double mutlakal() {
    double x;
    scanf("%lf", &x);
    return (x < 0) ? -x : x;
}

//Seçim sayý mý harf mi kontrol fonksiyonu
int secimYap() {
    int secim;
    while (scanf("%d", &secim) != 1) {
        // scanf != 1 : Girilen deðer sayý deðil
        printf("HatalÝ giris! Lutfen sadece rakam giriniz: ");
        // Yazýlý kalan o hatalý deðeri temizlemek için
        while (getchar() != '\n');
    }
    return secim;
}
// 1 - Serbest Dusme Deneyi ( h=1/2*g*t^2)
void serbestDusme(double *g) {
    double t;
    printf("Dusme suresini giriniz (s): ");
    t = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double h = 0.5 * (*(g + i)) * t * t;
        printf("%s gezegeninde alinan yol: %.2f metre\n",
               *(gezegenIsimleri + i), h);
    }
    printf("-------------------------------------\n");
}
// 2 - Yukari Atis Deneyi ( (hmax=(ilk hiz)^2)/(2*g) )
void yukariAtis(double *g) {
    double v0;
    printf("Ilk hizi giriniz (m/s): ");
    v0 = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double hmax = (v0 * v0) / (2 * (*(g + i)));
        printf("%s gezegeninde maksimum yukseklik: %.2f metre\n",
               *(gezegenIsimleri + i), hmax);
    }
    printf("-------------------------------------\n");
}
// 3 - Agirlik Deneyi ( G=m*g )
void agirlik(double *g) {
    double m;
    printf("Cismin kutlesini giriniz (kg): ");
    m = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double G = m * (*(g + i));
        printf("%s gezegeninde agirlik: %.2f Newton\n",
               *(gezegenIsimleri + i), G);
    }
    printf("-------------------------------------\n");
}
// 4 - Kutlecekimsel Potansiyel Enerji ( Ep=m*g*h)
void potansiyelEnerji(double *g) {
    double m, h;
    printf("Kutleyi giriniz (kg): ");
    m =mutlakal();
    printf("Yuksekligi giriniz (m): ");
    h = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double Ep = m * (*(g + i)) * h;
        printf("%s gezegeninde potansiyel enerji: %.2f Joule\n",
               *(gezegenIsimleri + i), Ep);
    }
    printf("-------------------------------------\n");
}
// 5 - Hidrostatik Basinc ( P=d*g*h )
void hidrostatikBasinc(double *g) {
    double rho, h;
    printf("Sivi yogunlugunu giriniz (kg/m^3): ");
    rho = mutlakal();
    printf("Derinligi giriniz (m): ");
    h = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double P = rho * (*(g + i)) * h;
        printf("%s gezegeninde hidrostatik basinc: %.2f Pascal\n",
               *(gezegenIsimleri + i), P);
    }
    printf("-------------------------------------\n");
}
// 6 - Arsimet Kaldirma Kuvveti ( Fk=d*g*V )
void arsimet(double *g) {
    double rho, V;
    printf("Sivi yogunlugunu giriniz (kg/m^3): ");
    rho = mutlakal();
    printf("Cismin batan hacmini giriniz (m^3): ");
    V = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double Fk = rho * (*(g + i)) * V;
        printf("%s gezegeninde kaldirma kuvveti: %.2f Newton\n",
               *(gezegenIsimleri + i), Fk);
    }
    printf("-------------------------------------\n");
}
// 7 - Basit Sarkac Periyodu ( T=2*Pý*( L/g )^(1/2))
void basitSarkac(double *g) {
    double L;
    printf("Sarkac ip uzunlugunu giriniz (m): ");
    L = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double T = 2 * PI * sqrt(L / (*(g + i)));
        printf("%s gezegeninde sarkac periyodu: %.2f saniye\n",
               *(gezegenIsimleri + i), T);
    }
    printf("-------------------------------------\n");
}
// 8 - Sabit Ip Gerilmesi ( T=m*g )
void ipGerilmesi(double *g) {
    double m;
    printf("Asili cismin kutlesini giriniz (kg): ");
    m = mutlakal();

    printf("-------------------------------------\n");
    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double T = m * (*(g + i));
        printf("%s gezegeninde ip gerilmesi: %.2f Newton\n",
               *(gezegenIsimleri + i), T);
    }
    printf("-------------------------------------\n");
}
// 9 - Asansorde Aðýrlýk Deneyi ( N=m*(g+-a))
void asansor(double *g) {
    double m, a;
    int durum;

    printf("Cismin kutlesini giriniz (kg): ");
    m = mutlakal();
    printf("Asansor ivmesini giriniz (m/s^2): ");
    a = mutlakal();
//    scanf("%lf",&a);

    printf("Durum seciniz:\n");
    printf("1 - Yukari ivmelenme / Asagi yavaslama\n");
    printf("2 - Asagi ivmelenme / Yukari yavaslama\n");
    printf("Durumunuz: ");
    scanf("%d", &durum);

    printf("-------------------------------------\n");


    for (int i = 0; i < Gunes_Sisteminde_Bulunan_Gezegen_Sayisi; i++) {
        double N;
//        N = m * ((*(g + i)) + a);

        if (durum == 1)
            N = m * ((*(g + i)) + a);
        else
            N = m * ((*(g + i)) - a);

        printf("%s gezegeninde hissedilen agirlik: %.2f Newton\n",
               *(gezegenIsimleri + i), N);
    }
    printf("-------------------------------------\n");
}
// Deney Listesi
void liste() {
    printf("\n========= DENEY LISTESI ===========\n");
    printf("== 1 -> Serbest Dusme Deneyi     ==\n");
    printf("== 2 -> Yukari Atis Deneyi       ==\n");
    printf("== 3 -> Agirlik Deneyi           ==\n");
    printf("== 4 -> Potansiyel Enerji Deneyi ==\n");
    printf("== 5 -> Hidrostatik Basinc Deneyi==\n");
    printf("== 6 -> Arsimet Kaldirma Kuvveti ==\n");
    printf("== 7 -> Basit Sarkac Periyodu    ==\n");
    printf("== 8 -> Sabit Ip Gerilmesi       ==\n");
    printf("== 9 -> Asansor Deneyi           ==\n");
    printf("==-1 -> !!PROGRAMDAN CIKIS!!     ==\n");
    printf("===================================\n");
}


int main() {
    char bilimInsani[50];
    int secim;

    printf("Bilim insaninin adini giriniz(!tek kelime olacak sekilde!): ");
    scanf("%s",bilimInsani);
    printf("\nHos geldiniz %s...\n", bilimInsani);

    do {
        liste();
        printf("Listeden tum gezegenler icin yapilmasi istenen deneyi seciniz: ");
        secim = secimYap();

        switch (secim) {
            case 1: serbestDusme(yercekimleri); break;
            case 2: yukariAtis(yercekimleri); break;
            case 3: agirlik(yercekimleri); break;
            case 4: potansiyelEnerji(yercekimleri); break;
            case 5: hidrostatikBasinc(yercekimleri); break;
            case 6: arsimet(yercekimleri); break;
            case 7: basitSarkac(yercekimleri); break;
            case 8: ipGerilmesi(yercekimleri); break;
            case 9: asansor(yercekimleri); break;
            case -1:
                printf("Program sonlandirildi.\n");
                break;
            default:
                printf("\nHatali secim yaptiniz. Lutfen listeden bir sayi giriniz!\n");
        }
  } while (secim != -1);

 return 0;
}
