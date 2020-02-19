#include <iostream>
#include <stdlib.h>//stdlib ve process exit fonk. kullanmak için
#include <process.h>

using namespace std;

void kontrol(int n,int alt,int ust){

    /*fonksiyona gönderilen n sayisi,
    gönderilen alt ve ust degerler arasinda degilse veya tek degilse 3 defa sorar
    yine bu degerler arasinda degilse programin
    çalismasini bitirir*/

    int i;

    if(n>ust || n<alt || n%2 ==0){//bu fonksiyonda i indeksi hata sayisidir
        for(i=0;i<3;i++){
            cout<<alt<<" ve "<<ust<<" "<<"arasinda tek deger girin"<<endl;
            cin>>n;
            if(n<=ust && n>=alt && n%2==1)
                break;
        }
        if(i == 3)//eger 3 kez hata yaparsan program kendini kapatır
            exit(0);
    }
}

void duzUcgen(int n){//duz ucgen cizdiren fonksiyon

    int satir,bosluk,yildiz,k,m;//burada k ve m indis

    k=(n-1)/2;//k bosluk loopunun dönmesini sagliyan indis
    m=1;//m yildiz loopunun dönmesini sagliyan indis
    for(satir=0;satir<(n+1)/2;satir++){
        for(bosluk=0;bosluk<k;bosluk++){
            cout<<" ";// ucgen piramit seklini verebilmemiz icin oncelikle bosluklari yazdiririz
        }
        k--;//bosluklar birer azaldigi icin
        for(yildiz=0;yildiz<m;yildiz++){//sonra hemen ardindan yildizlari yazdiririz
            cout<<"*";
        }
        m+=2;//yildiz sayisi ikiser arttigi icin
    cout<<endl;
    }

}
void tersUcgen(int n){//ters ucgen yazdiran fonksiyon

    int satir,yildiz,bosluk,k,m;//duzUcgen fonksiyonu ile neredeyse aynidir fark bosluk ve yildiz rol degistirir

    satir=(n+1)/2;//ayrıca loop turu whiledir
    yildiz=0;
    k=n;
    bosluk=0;
    m=0;

    while(satir>0){

        while(bosluk<m){//baslangicta m=0 olmali ki ilk seferde bosluk yazdirilmasin
            cout<<" ";
            bosluk++;//sonrasinda bosluk sayisi artarak devam etsin
        }

        while(yildiz<k){//ilk seferde n degeri ile esit sayida yildiz yazilsin
            cout<<"*";
            yildiz++;
        }

        yildiz=0;
        k-=2;//sonrasinda  ikiser azalarak devam etsin

        bosluk=0;
        m++;
        satir--;

        cout<<endl;
    }


}

void elmas(int n){//elmas sekli yazdiran fonksiyon

    duzUcgen(n);//tekrardan yazmamiza gerek yok yukarıda yazdigimiz fonksiyonlari arka arkaya calistirmamiz yeterli
    tersUcgen(n);

}

int main()
{
    int boyut,secim;

    cout<<"Ucgen cizdirmek icin 1'e"<<endl;
    cout<<"Ters ucgen cizdirmek icin 2'e"<<endl;
    cout<<"Elmas cizdirmek icin 3'e basiniz"<<endl;

    cin>>secim;

    if(secim ==1 ||secim ==2 ||secim ==3 ){
    cout<<"Simdi ise hangi boyutta cizdirmek istediginizi girin"<<endl;

    cin>>boyut;
    }
    switch(secim){
        case 1:
            kontrol(boyut,3,15);
            duzUcgen(boyut);
            break;
        case 2:
            kontrol(boyut,3,15);
            tersUcgen(boyut);
            break;
        case 3:
            kontrol(boyut,5,15);
            elmas(boyut);
            break;

        default:
            cout<<"1 3 arasinda girmelisiniz!!";

    }



    return 0;
}
