#include <stdio.h>
#include <math.h>

// sharpe oranını hesaplayan fonksiyon
double hesaplaSharpeOrani(double getiri, double risksizFaiz, double standartSapma) {
    if (standartSapma == 0.0) {
        // sıfır standart sapma durumu için özel bir değer veya hata yönetimi
        // burada basitçe çok büyük bir değer döndürebiliriz veya hata mesajı verebiliriz.
        // ancak sharpe oranı formülünde sıfıra bölme hatası oluşmaması için kontrol önemlidir.
        // gerçekte, sıfır risk (standart sapma) varsa, getiri risksiz faizden büyükse
        // sharpe oranı sonsuza gider. Bu uygulamada basitlik adına bir kontrol yapalım.
        if (getiri > risksizFaiz) {
            return 0.0;
        } else {
            return 0.0; // risksiz faizden düşükse, risksiz yatırıma eşittir
        }
    }
    return (getiri - risksizFaiz) / standartSapma;
}

// sharpe oranına göre performansı değerlendiren fonksiyon
void degerlendirSharpeOrani(double sharpeOrani) {
    printf("\n--- Yatirim Performansi Degerlendirmesi ---\n");

    if (sharpeOrani < 0.0) {
        printf("Sonuc (%f): KOTU (Risk Almaya Degmez)\n", sharpeOrani);
    } else if (sharpeOrani >= 0.0 && sharpeOrani < 1.0) {
        printf("Sonuc (%f): ZAYIF / KABUL EDILEBILIR (Ekstra Risk Getirisi Dusuk)\n", sharpeOrani);
    } else if (sharpeOrani >= 1.0 && sharpeOrani < 2.0) {
        printf("Sonuc (%f): IYI (Risk icin Makul Getiri)\n", sharpeOrani);
    } else if (sharpeOrani >= 2.0 && sharpeOrani < 3.0) {
        printf("Sonuc (%f): COK IYI (Risk icin Guclu Getiri)\n", sharpeOrani);
    } else { // sharpeorani >= 3.0
        printf("Sonuc (%f): MUKEMMEL (Risk icin Ustun Getiri)\n", sharpeOrani);
    }
}

int main() {
    double getiri, risksizFaiz, standartSapma, sharpeOrani;

    // kullanıcıdan giriş alma
    printf(" SHARPE ORANI HESAPLAMA UYGULAMASI\n");
    printf("Yatirim Gelirisini girin: ");
    if (scanf("%lf", &getiri) != 1) {
        fprintf(stderr, "Hata: Gecersiz giris.\n");
        
    }

    printf("Risksiz Faiz Oranini girin: ");
    if (scanf("%lf", &risksizFaiz) != 1) {
        fprintf(stderr, "Hata: Gecersiz giris.\n");
        
    }

    printf("Standart Sapmayi girin: ");
    if (scanf("%lf", &standartSapma) != 1) {
        fprintf(stderr, "Hata: Gecersiz giris.\n");
        
    }

    // hesaplama
    sharpeOrani = hesaplaSharpeOrani(getiri, risksizFaiz, standartSapma);

    // değerlendirme ve sonuç
    degerlendirSharpeOrani(sharpeOrani);

    return 0;
}
