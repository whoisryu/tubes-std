#include <iostream>
#include "tubes.h";

using namespace std;

int main()
{
    int menu;
    string fur;
    string org;
    string yn;
    adrParent adrP;
    adrChild adrC;
    adrRelasi adrR;

    listParent LP;
    listRelasi LR;
    listChild LC;

    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);



do{
    cout<<"MENU"<<endl;
    cout<<"1. Tambah Data"<<endl;
    cout<<"2. Tampilkan Semua Furniture"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"Pilih Menu: ";
    cin>>menu;

    switch(menu){
    case 1:
        cout<<"Masukkan Nama Furniture: ";
        cin>>fur;
        adrC = newElmchild(fur);
        addChild(LC, adrC);

        cout<<"Masukkan Nama Pengrajin: ";
        cin>>org;
        if(findParent(LP, org) == NULL){
            adrP = newElmParent(org);
            addParent(LP, adrP);
            addRelasi(LR, newElmRelasi(adrP, adrC));
        }else{
            adrR = newElmRelasi(findParent(LP, org), adrC);
            addRelasi(LR, adrR);
        }

        cout<<"ada lagi? (Y/N)";
        cin>>yn;
        if( yn == "Y"){
            cout<<"Masukkan Nama Pengrajin: "; cin>>org;
            if(findParent(LP, org) == NULL){
                adrP = newElmParent(org);
                addParent(LP, adrP);
                addRelasi(LR, newElmRelasi(adrP, adrC));
            }else{
                adrR = newElmRelasi(findParent(LP, org), adrC);
                addRelasi(LR, adrR);
            }
        }
        break;
    case 2:
        cout<<endl;
        showAllChild(LC, LR, LP);
        break;

    }
cout<<endl;
cout<<endl;
}while(menu != 0);



    return 0;
}
