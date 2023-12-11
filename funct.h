#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include "structs.h"
using namespace std;
int createkey(fstream& f, int* qq);
tree* createroot(fstream& f, int* qq, int x);
tree* addend(tree* node, int x, tree* parent);
void createtree(tree** root, fstream& f, int* qq);
tree* tree_search(tree* x, int k);
void tree_insert(tree** root, int k);
tree* findmax(tree* tmp);
void delelem(tree** root, int x);
void deltree(tree* node);
int  treeoutput(tree* el);
int preorder(tree* el);
int postorder(tree* el);
int inorder(tree* el);

avl* createaroot(int x);
void rightrotate(avl** node, avl** aroot, int q, int x);
void leftrotate(avl** node, avl** aroot, int q, int x);
void fixavl(avl* node, avl** aroot, int x);
avl* avladdend(int x, avl** aroot);
void printInOrder(avl* aroot);
//int  atreeoutput(avl* aroot);
int apreorder(avl* aroot);
int apostorder(avl* aroot);
void avlcreatetree(avl** aroot, fstream& f, int* qq);
int fixdel(avl* vsp, avl** aroot);
avl* findmax(avl* tmp);
void delelem(avl** aroot, int x);
void delavl(avl* node);


brtree* createbroot(int x);
void bleftrotate(brtree* node, brtree** bro);
void brightrotate(brtree* node, brtree** bro);
brtree* fixbr(brtree* node, brtree* bro);
brtree* braddend(int x, brtree** bro);
void brcreatetree(brtree** bro, fstream& f, int* qq);
brtree* btreemin(brtree* node);
brtree* btreemax(brtree* node);
brtree* brsuccessor(brtree* node);
void rbdelfix(brtree* x, brtree** broot);
void delel(brtree** bro, int x);
void delbrtree(brtree* node);
void bprintInOrder(brtree* bro);
void brsuccessor(brtree** tmp, brtree** bro);
brtree* findmax(brtree* tmp, brtree** bro);
void delelel(brtree** bro, int x);