#include "funct.h"

brtree* createbroot(int x)
{
	brtree* tmp = new brtree;
	tmp->key = x;
	tmp->l = tmp->r = tmp->p = NULL;
	tmp->s = 'b';
	tmp->node = tmp;
	return tmp;
}
void bleftrotate(brtree* node, brtree** bro)
{
	brtree* tmp = node->r;
	if (tmp->l != NULL)
		tmp->l->p = node;
	node->r = tmp->l;
	tmp->p = node->p;
	if (node->p == NULL)
	{
		*bro = tmp;
	}
	else {
		if (node == node->p->l)
		{
			node->p->l = tmp;
		}
		else
			node->p->r = tmp;
	}
	tmp->l = node;
	node->p = tmp;
}
void brightrotate(brtree* node, brtree** bro)
{
	brtree* tmp = node->l;
	node->l = tmp->r;
	if (tmp->r != NULL)
		tmp->r->p = node;
	tmp->p = node->p;
	if (node->p == NULL)
	{
		*bro = tmp;
	}
	else {
		if (node == node->p->r)
		{
			node->p->r = tmp;
		}
		else
			node->p->l = tmp;
	}
	tmp->r = node;
	node->p = tmp;
}
brtree* fixbr(brtree* node, brtree* bro)
{

	while (node->p->s != 'b')
	{
		if (node->p->node == node->p->p->l)
		{
			if (node->p->p->r != NULL)
			{
				brtree* tmp = node->p->p->r;
				if (tmp->s == 'r')
				{
					node->p->s = 'b';
					tmp->s = 'b';
					if (node->p->p->p != NULL and node->p->p->p!=bro)
						node->p->p->s = 'r';
					else break;
					node = node->p->p->node;
				}
				else {
					if (node == node->p->r)
					{
						node = node->p;
						bleftrotate(node, &bro);
					}
					node->p->s = 'b';
					node->p->p->s = 'r';
					brightrotate(node->p->p, &bro);
				}
			}
			else
			{
				if (node == node->p->r)
				{
					if (node->p == node->p->p->l)
					{
						node->s = 'b';
						node->p->s = 'r';
						node->p->p->s = 'r';
						bleftrotate(node->p, &bro);
						brightrotate(node->p, &bro);

					}
					else
					{
						node->s = 'r';
						node->p->s = 'b';
						node->p->p->s = 'r';
						bleftrotate(node->p, &bro);
					}
				}
				else
				{
					if (node->p == node->p->p->l)
					{
						node->s = 'r';
						node->p->s = 'b';
						node->p->p->s = 'r';
						brightrotate(node->p, &bro);
					}
					else
					{
						node->s = 'b';
						node->p->s = 'r';
						node->p->p->s = 'r';
						brightrotate(node->p, &bro);
						bleftrotate(node->p, &bro);
					}
				}
			}
		}
		else
		{
			brtree* tmp = node->p->p->l;
			if (tmp != NULL and tmp->s == 'r')
			{
				node->p->s = 'b';
				tmp->s = 'b';
				if (node->p->p->p != NULL)
					node->p->p->s = 'r';
				else break;
				node = node->p->p->node;
			}
			else {
				if (node == node->p->l)
				{
					node = node->p;
					brightrotate(node, &bro);
				}
				node->p->s = 'b';
				node->p->p->s = 'r';
				bleftrotate(node->p->p, &bro);
			}
		}
	}


	return node;
}
brtree* braddend(int x, brtree** bro)
{
	brtree* tmp = *bro;
	brtree* node = new brtree;
	node->key = x;
	node->node = node;
	node->l = node->r = NULL;
	node->s = 'r';
	while ((tmp->r != NULL and x > tmp->key) or (tmp->l != NULL and x < tmp->key))
	{
		if (x > tmp->key)
			tmp = tmp->r;
		else
			tmp = tmp->l;
	}
	if (x > tmp->key)
	{
		tmp->r = node;
		node->p = tmp;
	}
	else
	{
		tmp->l = node;
		node->p = tmp;
	}
	fixbr(node, *bro);
	return node;
}
void brcreatetree(brtree** bro, fstream& f, int* qq)
{
	int x = createkey(f, qq);
	*bro = createbroot(x);
	brtree* tmp = *bro;
	brtree* vsp = tmp;
	x = createkey(f, qq);
	
	while (*qq != 1 && *qq != 5)
	{
		tmp = braddend(x, &(*bro));
		vsp = tmp;
		while (vsp->p != NULL) vsp = vsp->p;
		*bro = vsp;
		//cout << '\n'; bprintInOrder(*bro);
		x = createkey(f, qq);
	}
	
	
}
brtree* btreemin(brtree* node)
{
	while (node->l != NULL)
		node = node->l;
	return node;
}
brtree* btreemax(brtree* node)
{
	while (node->r != NULL)
		node = node->r;
	return node;
}
brtree* brsuccessor(brtree* node)
{
	if (node->r != NULL)
		return btreemin(node->r);
	brtree* tmp = node->p;
	while (tmp != NULL and node == tmp->r)
	{
		node = tmp;
		tmp = tmp->p;
	}
	return tmp;
}
void rbdelfix(brtree* x, brtree** broot)
{
	while (x != *broot and x->s == 'b')
	{
		if (x = x->p->l)
		{
			brtree* w = x->p->r;
			if (w->s == 'r')
			{
				x->p->s = 'r';
				bleftrotate(x->p, &(*broot));
				w = x->p->r;
			}
			if (w->l->s == 'b' and w->r->s == 'b')
			{
				w->s = 'r';
				x = x->p;
			}
			else
			{
				if (w->r->s == 'b')
				{
					w->l->s = 'b';
					w->s = 'r';
					brightrotate(w, &(*broot));
					w = x->p->r;
				}
				w->s = x->p->s;
				x->p->s = 'b';
				w->r->s = 'b';
				bleftrotate(x->p, &(*broot));
				x = *broot;
			}
		}
		else
		{
			brtree* w = x->p->l;
			if (w->s == 'r')
			{
				x->p->s = 'r';
				brightrotate(x->p, &(*broot));
				w = x->p->l;
			}
			if (w->r->s == 'b' and w->l->s == 'b')
			{
				w->s = 'r';
				x = x->p;
			}
			else
			{
				if (w->l->s == 'b')
				{
					w->r->s = 'b';
					w->s = 'r';
					bleftrotate(w, &(*broot));
					w = x->p->l;
				}
				w->s = x->p->s;
				x->p->s = 'b';
				w->r->s = 'b';
				brightrotate(x->p, &(*broot));
				x = *broot;
			}
		}
	}
}
void delel(brtree** bro, int x) 
{
	brtree* tmp = *bro;
	while (tmp != NULL and tmp->key != x)
	{
		if (x > tmp->key)
			tmp = tmp->r;
		else
			tmp = tmp->l;
	}
	if (tmp == NULL)
	{
		cout << "Такого элемента не найдено";
	}
	else 
	{
		if (tmp->l == NULL or tmp->r == NULL)
		{
			if (tmp->p == NULL)
				delete* bro;
			else
			{
				if (tmp == tmp->p->r)
				{

				}
			}
		}
	}
}
void delbrtree(brtree* node)
{
	if (node != NULL)
	{
		delbrtree(node->l);
		delbrtree(node->r);
		delete node;
	}

}
void bprintInOrder(brtree* bro)
{
	if (bro == NULL)
		return;
	bprintInOrder(bro->l);
	std::cout << bro->key << " " << bro->s << '\n';
	bprintInOrder(bro->r);
}