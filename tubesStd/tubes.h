#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)
#define toParent(P)  (P)->toParent
#define toChild(P)  (P)->toChild

#include <typeinfo>
#include <iostream>
#include<limits>

using namespace std;

typedef string infotype;

typedef struct elmParent *adrParent;
typedef struct elmRelasi *adrRelasi;
typedef struct elmChild *adrChild;

struct elmParent{
    infotype info;
    adrParent next;
};
struct elmRelasi{
    adrParent toParent;
    adrChild toChild;
    adrRelasi next;
};
struct elmChild {
    infotype info;
    adrChild next;
};

struct listParent{
    adrParent first;
    adrParent last;
};
struct listRelasi{
    adrRelasi first;
    adrRelasi last;
};
struct listChild{
    adrChild first;
    adrChild last;
};

adrParent findParent(listParent L, infotype nama);
bool findChild(listChild L, infotype nama);
void createListParent(listParent &L);
void createListRelasi(listRelasi &L);
void createListChild(listChild &L);

adrParent newElmParent(infotype nama);
adrRelasi newElmRelasi(adrParent parent, adrChild child);
adrChild newElmchild(infotype barang);

void addParent(listParent &L, adrParent P);
void addChild(listChild &L, adrChild P);
void addRelasi(listRelasi &L, adrRelasi P);

void deleteParent(listRelasi &L, infotype P);
void deleteChild(listRelasi &L, infotype P);

void deleteFirstParent(listParent &L, adrParent &p);
void deleteLastParent(listParent &L, adrParent &p);
void deleteAfterPArent(listParent &L, adrParent prec, adrParent &p);
void hapusParent(listParent &L, adrParent &p);

int countFurniture(adrParent P, listRelasi L);

void showMax(listParent LP, listRelasi LR);
void showAllChild(listRelasi LR);
void showChild2(listChild LC, listRelasi LR);
void showPengrajinColab(listRelasi L);
void showParent(listParent L);

bool isValid(int menu, int num);
#endif // TUBES_H_INCLUDED
