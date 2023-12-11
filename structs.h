#pragma once

struct tree
{
	int key;
	tree* p;
	tree* l;
	tree* r;
	tree* node;
};
struct brtree
{
	int key;
	brtree* p;
	brtree* l;
	brtree* r;
	brtree* node;
	char s;
};
struct avl
{
	int key;
	avl* p;
	avl* r;
	avl* l;
	avl* node;
	int b;
};