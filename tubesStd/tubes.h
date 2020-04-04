#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define relasi(P) (P)->relasi
#define parent(P) (P)->parent
#define child(P) (P)->child
#include <iostream>

using namespace std;

typedef string infotype;

typedef elmParent *adrParent;
typedef elmRelasi *adrRelasi;
typedef elmChild *adrChild;

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
};
struct listRelasi{
    adrRelasi first;
};
struct listChild{
    adrChild first;
};


void createListParent(listParent &L);
void createListRelasi(listRelasi &L);
void createListChild(listChild &L);

adrParent newElmParent(infotype nama);
adrRelasi newElmRelasi(adrParent parent, adrChild child);
adrChild newElmchild(infotype barang);

void addParent(listParent &L, adrParent P);
void addChild(listChild &L, adrChild P);
void addRelasi(listRelasi &L, adrRelasi P);

#endif // TUBES_H_INCLUDED
