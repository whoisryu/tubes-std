#include <iostream>
#include <typeinfo>
#include<limits>
#include "tubes.h";

using namespace std;

int main()
{
    bool cek = true;
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



    do
    {
        cout<<"MENU"<<endl;
        cout<<"1. Tambah Data"<<endl;
        cout<<"2. Tampilkan Semua Furniture"<<endl;
        cout<<"3. Hapus Data"<<endl;
        cout<<"4. Tampilkan Furnitur Yang dikerjan 2 Pengrajin"<<endl;
        cout<<"5. Tampilkan Pengrajin Yang Pernah BekerjaSama Dengan Pengrajin Lain"<<endl;
        cout<<"6. Tampilkan Pengrajin Yang Paling Banyak Membuat Furniture"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"Pilih Menu: ";
        while(!(cin>>menu) || isValid(menu, 6))
        {
            cout<<endl;
            cin.clear();
            cin.ignore(123, '\n');
            cout<<"Masukkan angka menu dengan benar!!"<<endl;
            cout<<endl;
            cout<<"Pilih Menu: ";
        }
        cout<<endl;
        switch(menu)
        {
        case 1:
        {
            yn = "y";
            while(yn == "Y" || yn == "y")
            {
                cout<<"Masukkan Nama Furniture: ";
                cin>>fur;
                while(findChild(LC, fur))
                {
                    cout<<endl;
                    cout<<"Nama Furniture Sudah Ada"<<endl;
                    cout<<endl;
                    cout<<"Masukkan Nama Furniture: ";
                    cin>>fur;
                }
                adrC = newElmchild(fur);
                addChild(LC, adrC);

                cout<<"Masukkan Nama Pengrajin: ";
                cin>>org;
                cout<<endl;
                if(findParent(LP, org) == NULL)
                {
                    adrP = newElmParent(org);
                    addParent(LP, adrP);
                    addRelasi(LR, newElmRelasi(adrP, adrC));
                }
                else
                {
                    adrR = newElmRelasi(findParent(LP, org), adrC);
                    addRelasi(LR, adrR);
                }

                cout<<"Apakah pengrajin bekerja sama? (Y/N) ";
                cin>>yn;
                if( yn == "Y" || yn == "y")
                {
                    cout<<"Masukkan Nama Pengrajin: ";
                    cin>>org;
                    cout<<endl;
                    if(findParent(LP, org) == NULL)
                    {
                        adrP = newElmParent(org);
                        addParent(LP, adrP);
                        addRelasi(LR, newElmRelasi(adrP, adrC));
                    }
                    else
                    {
                        adrR = newElmRelasi(findParent(LP, org), adrC);
                        addRelasi(LR, adrR);
                    }
                }
                cout<<"Ingin menambah data lagi? (Y/N) ";
                cin>>yn;
                cout<<endl;
            }
        }
        break;
        case 2:
        {
            cout<<endl;
            showAllChild(LR);
        }
        break;

        case 3:
        {
            cout<<"MENU HAPUS"<<endl;
            cout<<"1. Hapus Pengrajin"<<endl;
            cout<<"2. Hapus Furniture"<<endl;
            cout<<"3. Kembali"<<endl;
            cout<<"Pilih Menu: ";
            while(!(cin>>menu) || isValid(menu, 3))
            {
                cout<<endl;
                cin.clear();
                cin.ignore(123, '\n');
                cout<<"Masukkan angka menu dengan benar!!"<<endl;
                cout<<endl;
                cout<<"Pilih Menu: ";
            }
            switch(menu)
            {
            case 1:
            {
                cout<<"Nama Pengrajin : ";
                cin>>org;
                deleteParent(LR, org);
            }
            case 2:
            {
                cout<<"Nama Furniture : ";
                cin>>fur;
                deleteChild(LR, fur);
            }
            case 3:
            {
                break;
            }
            }

        }
        break;
        case 4:
        {
            showChild2(LC,LR);
        }
        break;
        case 5:
        {
            showPengrajinColab(LR);
        }
        break;
        case 6:
        {
            showMax(LP, LR);
        }
        break;
        case 0:
            {
                cout<<"Yakin Ingin Keluar ? (Y/N) ";
                cin>>yn;
                if(yn == "Y" || yn == "y"){
                    cek = false;
                }
            }
        break;
        }

        cout<<endl;
        cout<<endl;
    }
    while(cek);



    return 0;
}
