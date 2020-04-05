#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)
#define toParent(P)  (P)->toParent
#define toChild(P)  (P)->toChild

#include <iostream>

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

void createListParent(listParent &L);
void createListRelasi(listRelasi &L);
void createListChild(listChild &L);

adrParent newElmParent(infotype nama);
adrRelasi newElmRelasi(adrParent parent, adrChild child);
adrChild newElmchild(infotype barang);

void addParent(listParent &L, adrParent P);
void addChild(listChild &L, adrChild P);
void addRelasi(listRelasi &L, adrRelasi P);

void showAllChild(listChild LC, listRelasi LR , listParent LP);
void showParent(listParent L);
#endif // TUBES_H_INCLUDED
