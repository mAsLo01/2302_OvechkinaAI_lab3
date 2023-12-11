#include "funct.h"
int createkey(fstream& f, int* qq)
{
	int  s;
	if (!f.eof())
	{

		f >> s;
		return s;
	}
	else
		*qq = 1;
}
tree* createroot(fstream& f, int* qq, int x)
{
	tree* tmp = new tree;
	tmp->key = x;
	tmp->l = NULL;
	tmp->r = NULL;
	tmp->p = NULL;
	tmp->node = tmp;
	return tmp;
}
tree* addend(tree* node, int x, tree* parent)
{

	if (node == NULL)
	{
		node = new tree;
		node->p = parent;
		node->key = x;
		node->l = NULL;
		node->r = NULL;
		node->node = node;
	}
	else if (x < node->key)
		node->l = addend(node->l, x, node->node);
	else
		node->r = addend(node->r, x, node->node);
	return node;

}
void createtree(tree** root, fstream& f, int* qq)
{
	int x = createkey(f, qq);//16
	*root = createroot(f, qq, x); /*= createroot(f, qq);*/
	tree* tmp = *root;
	x = createkey(f, qq);
	while (*qq != 1 && *qq != 5)
	{
		tmp = addend(tmp, x, tmp);
		x = createkey(f, qq);
	}
}

tree* treemin(tree* node)
{
	while (node->l != NULL)
		node = node->l;
	return node;
}
tree* treemax(tree* node)
{
	while (node->r != NULL)
		node = node->r;
	return node;
}
tree* treesuccessor(tree* node)
{
	if (node->r != NULL)
		return treemin(node->r);
	tree* tmp = node->p;
	while (tmp != NULL and node == tmp->r)
	{
		node = tmp;
		tmp = tmp->p;
	}
	return tmp;
}
tree* treedel(tree* node, tree* root)
{
	tree* tmp = new tree;
	if (node->l == NULL or node->r == NULL)
		tmp = node;
	else
		tmp = treesuccessor(node);
	if (tmp->l != NULL)
		node = tmp->l;
	else
		node = tmp->r;
	if (node != NULL)
		node->p = tmp->p;
	if (tmp->p = NULL)
		root = node;
	else {
		if (tmp = tmp->p->l)
			tmp->p->l = node;
		else
			tmp->p->r = node;
	}
	if (tmp != node)
	{
		node->key = tmp->key;
		node->l = tmp->l;
		node->r = tmp->r;
		node->p = tmp->p;
	}
	return tmp;
}
tree* tree_search(tree* x, int k)
{
	if (x == NULL or k == x->key)
		return x;
	if (k < x->key)
		return tree_search(x->l, k);
	else
		return tree_search(x->r, k);
}
void tree_insert(tree** root, int k)
{
	tree* tmb = new tree;
	tmb->key = k;
	tmb->l = tmb->p = tmb->r = NULL;
	tmb->node = tmb;
	tree* tmp = *root;
	tree* vsp = new tree;
	if (*root == NULL)
	{
		*root = tmb;

	}
	else
	{
		while (tmp != NULL)
		{
			vsp = tmp;
			if (tmp->key > k)
				tmp = tmp->l;
			else
				tmp = tmp->r;
		}
		tmp = tmb;
		tmb->p = vsp;
	}

}
tree* findmax(tree* tmp)
{
	if (tmp->l != NULL) {
		tmp = tmp->l;
		while (tmp->r != NULL)
			tmp = tmp->r;
		if (tmp->l != NULL)
		{
			tmp->p->r = tmp->l;
			tmp->l->p = tmp->p;
		}
	}
	else
		tmp = tmp->r;
	return tmp;
}
void delelem(tree** root, int x)
{
	tree* tmp = *root;
	while (tmp->key != x and tmp != NULL)
	{
		if (tmp->key > x)
			tmp = tmp->l;
		else tmp = tmp->l;
	}
	if (tmp == NULL)
		cout << "Такого элемента не найдено";
	else
	{
		if (tmp->r == NULL and tmp->l == NULL)
		{
			if (tmp->p == NULL)
				delete* root;
			else {
				if (tmp == tmp->p->r)
					tmp->p->r = NULL;
				else
					tmp->p->l = NULL;
				delete tmp;
			}
		}
		else {
			tree* vsp = findmax(tmp);
			if (tmp->p == NULL)
			{
				*root = vsp;
				vsp->p = NULL;
				if (vsp != tmp->r)
				{
					vsp->r = tmp->r;
					tmp->r->p = vsp;
				}
			}
			else {
				if (tmp == tmp->p->r)
					tmp->p->r = vsp;
				else
					tmp->p->l = vsp;
				vsp->p = tmp->p;
				if (vsp != tmp->r)
				{
					vsp->r = tmp->r;
					tmp->r->p = vsp;
				}
			}
			delete tmp;
		}
	}
}
void deltree(tree* node)
{
	if (node != NULL)
	{
		deltree(node->l);
		deltree(node->r);
		delete node;
	}
}
int  treeoutput(tree* el)
{
	if (el == NULL)
		return 0;

}

int preorder(tree* el)
{
	if (el == NULL)
		return 0;
	else
	{
		cout << el->key << ' ';
		if (el->l != NULL)
			preorder(el->l);
		if (el->r != NULL)
			preorder(el->r);
	}
}
int postorder(tree* el)
{
	if (el == NULL)
		return 0;
	else
	{
		postorder(el->l);
		postorder(el->r);
		cout << el->key << ' ';
	}
}
int inorder(tree* el)
{
	if (el == NULL)
		return 0;
	else
	{
		inorder(el->l);
		cout << el->key << ' ';
		inorder(el->r);
	}
}