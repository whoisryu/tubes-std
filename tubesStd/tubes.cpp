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
    while (info(toParent(R)) == P) {
        if (R == first(L)) {
                first(L) = next(R);
                next(R) = NULL;
            }
            R = first(L);
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
                while (next(B) != R) {
                    B = next(B);
                }
                next(B) = next(R);
                next(R) = NULL;
            }
        }
        R = next(R);
    }
}

void showAllChild(listChild LC, listRelasi LR , listParent LP){
    adrChild C = first(LC);

    while(C != NULL){

        cout<<"Barang: ";
        cout<<info(C)<<", "<<endl;
        cout<<"Pengrajin: ";
        adrRelasi R = first(LR);
        while(R != NULL){
            if(toChild(R) == C){
                cout<<info(toParent(R))<<", ";
            }
            R = next(R);
        }
        cout<<endl;
        C = next(C);
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

