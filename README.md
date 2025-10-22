# 📈 Sharpe Oranı Hesaplayıcı (C Dili)

Bu proje, C dilinde yazılmış basit bir konsol uygulamasıdır. Kullanıcıdan bir yatırımın getirisi, risksiz faiz oranı ve standart sapması (risk) bilgilerini alır ve bu verilerle yatırımın **Sharpe Oranını** hesaplar. Hesaplanan orana göre yatırımın risk-ayarlı performansını basit bir derecelendirme sistemiyle değerlendirir.

## 🚀 Proje Yapısı ve Özellikler

- **Sharpe Oranı Hesaplama:** Temel finans formülünü kullanarak yatırımın risk başına ekstra getirisini (risk primi) hesaplar.
- **Performans Değerlendirmesi:** Hesaplanan orana göre yatırımı `KÖTÜ`, `İYİ`, `ÇOK İYİ` veya `MÜKEMMEL` olarak sınıflandırır.
- **Hata Yönetimi:** Girişlerin ve sıfır standart sapma durumlarının yönetimi için temel kontroller içerir.

## 🧮 Sharpe Oranı Formülü

Sharpe Oranı, yatırımcıya üstlenilen risk miktarı için ne kadar fazla getiri elde edildiğini gösterir.

$$\text{Sharpe Oranı} = \frac{\text{Yatırım Getirisi} - \text{Risksiz Faiz Oranı}}{\text{Standart Sapma}}$$

**Açıklamalar:**
- **Yatırım Getirisi:** Portföyün veya varlığın ortalama getirisi.
- **Risksiz Faiz Oranı:** Genellikle devlet tahvili gibi risksiz bir yatırımın getirisi.
- **Standart Sapma:** Yatırımın volatilitesi (risk) ölçüsü.

## 📊 Değerlendirme Kriterleri

Uygulama, hesaplanan Sharpe Oranını aşağıdaki kurallara göre yorumlar:

| Sharpe Oranı | Değerlendirme |
| :---: | :--- |
| $< 0$ | **KÖTÜ** |
| $0 \le \text{SR} < 1$ | **ZAYIF / KABUL EDİLEBİLİR** |
| $1 \le \text{SR} < 2$ | **İYİ** (Makul Getiri) |
| $2 \le \text{SR} < 3$ | **ÇOK İYİ** (Güçlü Getiri) |
| $\ge 3$ | **MÜKEMMEL** (Üstün Getiri) |

## ⚙️ Nasıl Derlenir ve Çalıştırılır?

Bu uygulama standart C derleyicileri (örneğin GCC) ile derlenebilir.

### 1. Kodu Kaydedin

Verilen C kodunu bir dosyaya kaydedin (örneğin: `sharpe_calculator.c`).

### 2. Derleme

Terminalinizde (Linux/macOS) veya Komut İsteminde (Windows) aşağıdaki komutu kullanarak kodu derleyin. `math.h` kütüphanesini kullanmak için `gcc` derleyicisine genellikle `-lm` bayrağının eklenmesi gerekir:

```bash
gcc sharpe_calculator.c -o sharpe_app -lm
