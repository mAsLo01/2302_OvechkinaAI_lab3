#include "funct.h"
avl* createaroot(int x)
{
	avl* tmp = new avl;
	tmp->key = x;
	tmp->l = tmp->r = NULL;
	tmp->b = 0;
	tmp->p = NULL;
	tmp->node = tmp;
	return tmp;
}
void rightrotate(avl** node, avl** aroot, int q, int x)
{

	avl* tmp = (*node)->l;
	avl* tmb = *node;
	if (q == -2)
	{
		if (tmp->b == -1)
			tmb->b = 0;
		else
			tmb->b = -1;
		tmp->b = 0;
	}
	if (q == -4)
	{
		tmb->b = 1;
		tmp->b = -1;
	}
	if (q == -5)
	{
		if (tmp->b == 1)
			tmb->b = -1;
		else
			tmb->b = 0;
	}
	if (q == 4)
	{
		tmp->b = 0;
		tmb->b = 0;
	}
	if (q == 2)
	{
		tmp->b = 0;
		if (tmp->r != NULL)
			tmb->b = 0;
		else if ((tmb->b == 0 and x < tmp->key) or (tmb->b == 2 and x < tmp->key))
			tmb->b = -1;
		else tmb->b = 0;
	}
	if (q == 5)
	{
		tmp->b = 0;
		if (tmb->b == 0 and x < tmp->key)
			tmb->b = -1;
		else tmb->b = 0;
	}
	tmb->l = tmp->r;
	if (tmp->r != NULL)
		tmp->r->p = tmb;
	tmp->p = tmb->p;
	if (tmb->p == NULL)
	{
		*aroot = tmp;
	}
	else {
		if (tmb == tmb->p->r)
		{
			tmb->p->r = tmp;
		}
		else
			tmb->p->l = tmp;
	}
	tmp->r = tmb;
	tmb->p = tmp;

}
void leftrotate(avl** node, avl** aroot, int q, int x)
{
	avl* tmp = (*node)->r;
	avl* tmb = *node;
	if (q == -2)
	{
		if (tmp->b == 1)
			tmb->b = 0;
		else
			tmb->b = 1;

	}
	if (q == -3)
	{
		tmb->b = -1;
		tmp->b = 1;
	}
	if (q == -5)
	{
		if (tmp->b == 1)
			tmb->b = 0;
		else
			tmb->b = 1;
		tmp->b = 0;
	}
	if (q == 3)
	{
		tmb->b = 0;
		tmp->b = 0;
	}
	if (q == 2)
	{
		if ((tmb->b == 0 and x > tmp->key))
			tmb->b = 1;
		else
			tmb->b = 0;
		tmp->b = 0;
	}
	if (q == 5)
	{
		tmp->b = 0;
		if (tmp->l != NULL)
			tmb->b = 0;
		else if ((tmb->b == 0 and x > tmp->key) or (tmb->b == -2 and x > tmp->key))
			tmb->b = 1;
		else tmb->b = 0;
	}
	if (tmp->l != NULL)
		tmp->l->p = tmb;
	tmb->r = tmp->l;
	tmp->p = tmb->p;
	if (tmb->p == NULL)
	{
		*aroot = tmp;
	}
	else {
		if (tmb == tmb->p->l)
		{
			tmb->p->l = tmp;
		}
		else
			tmb->p->r = tmp;
	}
	tmp->l = tmb;
	tmb->p = tmp;
}

void fixavl(avl* node, avl** aroot, int x)
{
	int q = 0;
	avl* tmp = node->p->p;
	avl* vsp = node->p;
	while (tmp->b != 2 and tmp->b != -2)
	{
		vsp = tmp;
		tmp = tmp->p;
		if (vsp == tmp->r)
			q = -1;
		else
			q = 1;
	}
	if ((tmp->b == 2 or tmp->b == -2) and q == 0)
	{
		if (vsp == tmp->r)
			q = -1;
		else
			q = 1;
	}
	if (q == -1 and x < vsp->key)
	{
		q = 5;
		rightrotate(&vsp, &(*aroot), q, x);
		leftrotate(&tmp, &(*aroot), q, x);
	}
	if (q == 1 and x > vsp->key)
	{
		q = 2;
		leftrotate(&vsp, &(*aroot), q, x);
		rightrotate(&tmp, &(*aroot), q, x);
	}
	if (q == -1 and x > vsp->key)
	{
		q = 3;
		leftrotate(&vsp->p, &(*aroot), q, x);
	}
	if (q == 1 and x < vsp->key)
	{
		q = 4;
		rightrotate(&vsp->p, &(*aroot), q, x);
	}
}
avl* avladdend(int x, avl** aroot)
{
	avl* tmp = *aroot;
	avl* node = new avl;
	node->key = x;
	node->l = node->r = NULL;
	node->b = 0;
	int q = 0;
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
		tmp->b--;
	}
	else
	{
		tmp->l = node;
		node->p = tmp;
		tmp->b++;
	}
	while (tmp->p != NULL)
	{
		if (tmp->b == 2 or tmp->b == -2)
		{
			q++;
			break;
		}
		if (tmp == tmp->p->l and tmp->b != 0)
		{
			tmp->p->b++;
		}
		else if (tmp == tmp->p->r and tmp->b != 0)
		{
			tmp->p->b--;
		}
		tmp = tmp->p;
	}
	if (tmp->b == 2 or tmp->b == -2)
	{
		q++;
	}
	node->node = node;//sleva
	if (q != 0)
		fixavl(node, &(*aroot), x);
	/*if (q>0)
		fixavl1(node, &(*aroot));
	if (q < 0)
		fixavl2(node, &(*aroot));*/
	return node;
}
void printInOrder(avl* bro)
{
	if (bro == NULL)
		return;
	printInOrder(bro->l);
	std::cout << bro->key << " " << bro->b << '\n';
	printInOrder(bro->r);
}
void avlcreatetree(avl** aroot, fstream& f, int* qq)
{
	int x = createkey(f, qq);
	*aroot = createaroot(x);
	avl* tmp = *aroot;
	avl* vsp = tmp;
	x = createkey(f, qq);
	while (*qq != 1 && *qq != 5)
	{
		tmp = avladdend(x, &(*aroot));
		vsp = tmp;
		while (vsp->p != NULL) vsp = vsp->p;
		*aroot = vsp;
		//cout << '\n'; printInOrder(*aroot);
		x = createkey(f, qq);
	}
}
/*
/*void fixdel(avl*vsp, avl** aroot)
{
	avl* vsp = vsp;
	if
	avl* tmp = vsp->p;
}

void searchKey(avl*& curr, int key, avl*& parent)
{
	while (curr != nullptr && curr->key != key)
	{
		parent = curr;
		if (key < curr->key)
		{
			curr = curr->l;
		}
		else
		{
			curr = curr->r;
		}
	}
}
avl* findmin(avl* curr)
{
	while (curr->l != NULL)
		curr = curr->l;
	return curr;
}
void delelem(avl** aroot, int x)
{
	avl* parent = NULL;
	avl* curr = *aroot;
	searchKey(curr, x, parent);
	if (curr == NULL)
		return;
	if (curr->l == NULL and curr->r == NULL)
	{
		if (curr == *aroot)
			*aroot = NULL;
		else
		{
			if (parent->l == curr)
				parent->l = NULL;
			else
				parent->r = NULL;
		}
		delete curr;
	}
	else if (curr->l and curr->r)
	{
		avl* s = findmin(curr->r);
		int val = s->key;
		delelem(&(*aroot), s->key);
		curr->key = val;
	}
	else
	{
		avl* c = (curr->l) ? curr->l : curr->r;
		if (curr != *aroot)
		{
			if (curr == parent->l) {
				parent->l = c;
			}
			else {
				parent->r = c;
			}
		}

		// если удаляемый узел является корневым узлом, то установить корень дочернему
		else {
			*aroot = c;
		}
		delete curr;
	}

}
*/
int fixdel(avl* vsp, avl** aroot)
{
	avl* tmp = vsp;
	if (tmp->p == NULL)
	{
		if (tmp->b == 2)
		{
			if (tmp->l->b == -1)
			{
				leftrotate(&(tmp)->l, &(*aroot), -2, 1);
				rightrotate(&tmp, &(*aroot), -2, 1);
			}
			else
			{
				rightrotate(&tmp, &(*aroot), -4, 1);
			}
		}
		else
		{
			if (tmp->r->b == 1)
			{
				rightrotate(&(tmp)->r, &(*aroot), -5, 1);
				leftrotate(&tmp, &(*aroot), -5, 1);
			}
			else
			{
				leftrotate(&tmp, &(*aroot), -3, 1);
			}
		}return 0;
	}
	while (tmp->p and (tmp->b != 1 and tmp->b != -1))
	{
		if (tmp->b == 0 and tmp == tmp->p->r)
			tmp->p->b++;
		if (tmp->b == 0 and tmp == tmp->p->l)
			tmp->p->b--;
		if (tmp->b == 2)
		{
			if (tmp->l->b == -1)
			{
				leftrotate(&(tmp)->l, &(*aroot), -2, 1);
				rightrotate(&tmp, &(*aroot), -2, 1);
			}
			else
			{
				rightrotate(&tmp, &(*aroot), -4, 1);
			}
		}
		if (tmp->b == -2)
		{
			if (tmp->r->b == 1)
			{
				rightrotate(&(tmp)->r, &(*aroot), -5, 1);
				leftrotate(&tmp, &(*aroot), -5, 1);
			}
			else
			{
				leftrotate(&tmp, &(*aroot), -3, 1);
			}
		}
		tmp = tmp->p;
	}return 0;
}
avl* findmax(avl* tmp)
{
	avl* tmpp = tmp;
	avl* vsp = tmp;
	int f = tmpp->l->b;
	if (tmp->l != NULL) {
		tmp = tmp->l;
		f = tmp->b;
		if (tmp->r == NULL)
		{
			tmp->b = vsp->b - 1;
		}
		else {
			while (tmp->r != NULL)
			{
				tmp = tmp->r;
			}
			if (tmp->l != NULL)
			{
				tmp->p->r = tmp->l;
				tmp->l->p = tmp->p;
			}
			else
				tmp->p->r = NULL;
			avl* tmb = tmp;
			tmb->p->b++;
			tmb = tmb->p;
			while (tmb != tmpp)
			{
				if (tmb->b != 1)
				{
					tmb->p->b++;
					if (tmb->p->b == 2)
					{
						rightrotate(&tmb->p, &tmpp, -4, 0);
						tmb->p->p->b++;
					}
				}
				else break;
				tmb = tmb->p;
			}
			if (tmb == tmpp and tmb->b == 1 and tmb->l->b != f)
			{
				tmb->b--;
				tmp->b = tmb->b;
			}
			else
				tmp->b = tmpp->b;
		}
	}
	else
	{
		tmp = tmp->r;
		tmp->b = vsp->b + 1;
	}
	return tmp;
}
void delelem(avl** aroot, int x)
{
	avl* tmp = *aroot;
	while (tmp != NULL and tmp->key != x)
	{
		if (tmp->key > x)
			tmp = tmp->l;
		else tmp = tmp->r;
	}
	if (tmp == NULL)
		cout << "Такого элемента не найдено";
	else
	{
		if (tmp->r == NULL and tmp->l == NULL)
		{
			if (tmp->p == NULL)
				delete* aroot;
			else {
				if (tmp == tmp->p->r)
				{
					tmp->p->r = NULL;
					tmp->p->b++;
				}
				else {
					tmp->p->l = NULL;
					tmp->p->b--;
				}
				avl* vsp = tmp->p;

				delete tmp;
				if (vsp->b != 2 and vsp->b != -2) {
					while (vsp->b != -1 and vsp->b != 1 and vsp->p != NULL)
					{
						if (vsp == vsp->p->r and vsp->b == 0)
							vsp->p->b++;
						if (vsp == vsp->p->l and vsp->b == 0)
							vsp->p->b--;
						if ((vsp == vsp->p->r and vsp->p->b == -1) or (vsp == vsp->p->l and vsp->p->b == 1))
							vsp->p->b = 0;

						vsp = vsp->p;
					}
				}
				if ((vsp->b != 1 and vsp->b != -1) or (vsp->p != NULL and vsp->b != 0))
				{
					auto begin = std::chrono::steady_clock::now();
					fixdel(vsp, &(*aroot));
					auto end = chrono::steady_clock::now();

					auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
					std::cout << "The time: " << (elapsed_ms.count()) << " ns\n";
				}
			}
		}
		else {
			avl* vsp = new avl;
			if (tmp->l != NULL)
				vsp = findmax(tmp);
			else vsp = tmp->r;
			if (tmp->p == NULL)
			{
				*aroot = vsp;
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
					if (tmp->r != NULL)
						tmp->r->p = vsp;
					if (vsp != tmp->l)
					{
						vsp->l = tmp->l;
						tmp->l->p = vsp;
					}
					else
					{
						if (vsp->l != NULL)
							vsp->l = vsp->l->l;
						if (vsp->l != NULL and vsp->l->l != NULL)
							vsp->l->l->p = vsp;
					}
				}
				else
				{
					vsp->r = tmp->r->r;
					if (tmp->r->r != NULL)
						tmp->r->r->p = vsp;
					vsp->l = tmp->l;
					if (tmp->l != NULL)
						tmp->l->p = vsp;
				}
			}
			if ((vsp->b != 1 and vsp->b != -1) or (vsp->p != NULL and vsp->b != 0))
			{
				auto begin = std::chrono::steady_clock::now();

				fixdel(vsp, &(*aroot));
				auto end = chrono::steady_clock::now();

				auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
				std::cout << "The time: " << (elapsed_ms.count()) << " ns\n";
			}
			delete tmp;
		}


	}
}
void delavl(avl* node)
{
	if (node != NULL)
	{
		delavl(node->l);
		delavl(node->r);
		delete node;
	}
}

int apreorder(avl* aroot)
{
	if (aroot == NULL)
		return 0;
	else
	{
		cout << aroot->key << ' ';
		if (aroot->l != NULL)
			apreorder(aroot->l);
		if (aroot->r != NULL)
			apreorder(aroot->r);
	}
};
int apostorder(avl* aroot)
{
	if (aroot == NULL)
		return 0;
	else
	{
		apostorder(aroot->l);
		apostorder(aroot->r);
		cout << aroot->key << ' ';
	}
}