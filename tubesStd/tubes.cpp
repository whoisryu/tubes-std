#include <iostream>
#include "tubes.h"

using namespace std;


adrParent findParent(listParent L, infotype nama){
    adrParent P = first(L);

    if(first(L) == NULL){
        return NULL;
    }else{
        while(info(P) != nama && next(P) != NULL){
        P = next(P);
    }

    if(info(P) == nama){
        return P;
    }
    }
    return NULL;
}

void createListParent(listParent &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListRelasi(listRelasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListChild(listChild &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrParent newElmParent(infotype nama){
    adrParent  P = new elmParent;
    info(P) = nama;
    next(P) = NULL;
    return P;
}

adrRelasi newElmRelasi(adrParent Parent, adrChild Child){
    adrRelasi P = new elmRelasi;
    toParent(P) = Parent;
    toChild(P) = Child;
    next(P) = NULL;
    return P;
}

adrChild newElmchild(infotype barang){
    adrChild P = new elmChild;
    info(P) = barang;
    next(P) =NULL;
    return P;
}

void addParent(listParent &L, adrParent P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}
void addChild(listChild &L, adrChild P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}
void addRelasi(listRelasi &L, adrRelasi P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteParent(listRelasi &L, infotype P) {
    adrRelasi R = first(L);
        if (P == info(toParent(R))) {
                first(L) = next(R);
                next(R) = NULL;
            }
    R = first(L);
    while (R != NULL) {
        if (info(toParent(R)) == P) {
            if (R == first(L) && R == last(L)) {
                first(L) = NULL;
                last(L) = NULL;
            } else if (R == last(L)) {
                adrRelasi A = first(L);
                while (next(next(A)) != NULL) {
                    A = next(A);
                }
                last(L) = A;
                next(A) = NULL;
            } else {
                adrRelasi B = first(L);
                while (next(next(B)) != R) {
                    B = next(B);
                }
                next(B) = next(R);
                next(R) = NULL;
            }
        }
        R = next(R);
    }
}

void showAllChild(listRelasi LR){
    adrRelasi R = first(LR);
    if(R == NULL){
        cout<<"Data Kosong"<<endl;
    }
    while(R != NULL){
        cout<<"Barang: "<<info(toChild(R))<<endl;
        cout<<"Pengrajin: ";
        if(next(R) != NULL){
            if(toChild(R) != toChild(next(R))){
                cout<<info(toParent(R))<<endl;
                R = next(R);
            }else{
                adrRelasi R2 = next(R);
                while(toChild(R2) != toChild(R) && R2 != NULL){
                    R2 = next(R2);
                }
                if(toChild(R2) == toChild(R)){
                    cout<<info(toParent(R))<<", "<<info(toParent(R2))<<endl;
                    R = next(R2);
                }
            }
        }else{
            cout<<info(toParent(R))<<endl;
            R = next(R);
        }
        cout<<endl;
    }
}

void showChild2(listChild LC, listRelasi LR){
    adrChild C = first(LC);
    int i;
    while(C != NULL){
        adrRelasi R = first(LR);
        i = 0;
        while(R != NULL && i != 2){
            if(C == toChild(R)){
                i++;
            }
            R = next(R);
        }
        if(i == 2){
           cout<<"Furnitur: "<<info(C)<<endl;
        }
        C = next(C);
    }

    adrRelasi r1 = first(LR);
    if(next(r1) == NULL){
        cout<<"tidak ada furnitur yang dikerjakan oleh 2 pengrajin"<<endl;
    }else{
        int jml;
        while(r1 != NULL){
            jml = 0;
            adrRelasi r2 = first(LR);
            while(r2 != NULL){
                if(toChild(r2) == toChild(r1)){
                    jml++;
                }
                r2 = next(r2);
             }
             r1 = next(r1);
        }
        if(jml < 2){
            cout<<"tidak ada furnitur yang dikerjakan oleh 2 pengrajin"<<endl;
        }
    }
}

void showParent(listParent L){
    adrParent P = first(L);

    if(first(L) == last(L)){
        cout<<info(P)<<endl;
    }else{
        while(next(P) != NULL){
        cout<<info(P)<<endl;
        P = next(P);
    }
    }
}

