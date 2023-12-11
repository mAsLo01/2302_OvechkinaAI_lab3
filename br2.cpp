#include "funct.h"

void brsuccessor(brtree** tmp, brtree** bro)
{
	brtree* vsp = *tmp;
	if (vsp == vsp->p->l)
	{
		brtree* tmb = vsp->p->r;
		if (tmb->s == 'b')
		{
			if (tmb->r == NULL and tmb->l != NULL)
			{
				tmb->l->s = 'b';
				brightrotate(tmb, bro);
				bleftrotate(vsp->p, bro);
			}
			else if (tmb->r != NULL)
			{
				tmb->r->s = 'b';
				bleftrotate(vsp->p, bro);
			}
			else if (tmb->r == NULL and tmb->l == NULL)
			{
				tmb->s = 'r';
				brtree* tmbb = tmb->p;
				if (tmbb->s == 'r')
					tmbb->s = 'b';
				else
				{
					if (tmb->p->p != NULL)
					{
						if (tmbb == tmbb->p->r)
						{
							if (tmbb->p->l->s == 'b')
							{
								if (tmbb->p->l->r->s == tmbb->p->l->l->s == 'b')
									tmbb->p->l->s = 'r';
								if (tmbb->p->l->r->s == tmbb->p->l->l->s == 'r')
								{
									tmbb->p->l->r->s = 'b';
									brightrotate(tmbb->p, bro);
								}
								if (tmbb->p->l->l->s == 'b' and tmbb->p->l->r->s == 'r')
								{
									tmbb->p->l->r->s = 'b';
									brightrotate(tmbb->p, bro);
								}
								if (tmbb->p->l->l->s == 'r' and tmbb->p->l->r->s == 'b')
								{
									tmbb->p->l->s = 'b';
									bleftrotate(tmbb->p->l, bro);
									brightrotate(tmbb->p, bro);
								}

							}
							else
							{
								tmbb->p->l->s = 'b';
								tmbb->p->l->r->l->s = tmbb->p->l->r->r->s = 'r';
								brightrotate(tmbb->p, bro);
							}
						}
						else
						{
							if (tmbb->p->r->s == 'b')
							{
								if (tmbb->p->r->l->s == tmbb->p->r->r->s == 'b')
									tmbb->p->r->s = 'r';
								if (tmbb->p->r->l->s == tmbb->p->r->r->s == 'r')
								{
									tmbb->p->r->r->s = 'b';
									bleftrotate(tmbb->p, bro);
								}
								if (tmbb->p->r->l->s == 'b' and tmbb->p->r->r->s == 'r')
								{
									tmbb->p->r->r->s = 'b';
									bleftrotate(tmbb->p, bro);
								}
								if (tmbb->p->r->l->s == 'r' and tmbb->p->r->r->s == 'b')
								{
									tmbb->p->r->s = 'b';
									brightrotate(tmbb->p->l, bro);
									bleftrotate(tmbb->p, bro);
								}

							}
							else
							{
								tmbb->p->r->s = 'b';
								tmbb->p->r->r->l->s = tmbb->p->r->r->r->s = 'r';
								bleftrotate(tmbb->p, bro);
							}
						}
					}
				}


			}
		}
		else
		{
			tmb->s = 'b'; tmb->l->s = 'r';
			bleftrotate(vsp->p, bro);
		}
	}
	else
	{
		brtree* tmb = vsp->p->l;
		if (tmb->s == 'b')
		{
			if (tmb->r == NULL and tmb->l != NULL)
			{
				tmb->l->s = 'b';
				bleftrotate(tmb, bro);
				brightrotate(vsp->p, bro);
			}
			else if (tmb->l != NULL)
			{
				tmb->l->s = 'b';
				brightrotate(vsp->p, bro);
			}
			else if (tmb->l == NULL and tmb->r == NULL)
			{
				tmb->s = 'r';
				brtree* tmbb = tmb->p;
				if (tmbb->s == 'r')
					tmbb->s = 'b';
				else
				{
					if (tmb->p->p != NULL)
					{
						if (tmbb == tmbb->p->l)
						{
							if (tmbb->p->r->s == 'b')
							{
								if (tmbb->p->r->r->s == tmbb->p->r->l->s == 'b')
									tmbb->p->r->s = 'r';
								if (tmbb->p->r->r->s == tmbb->p->r->l->s == 'r')
								{
									tmbb->p->r->r->s = 'b';
									bleftrotate(tmbb->p, bro);
								}
								if (tmbb->p->r->l->s == 'b' and tmbb->p->r->r->s == 'r')
								{
									tmbb->p->r->r->s = 'b';
									bleftrotate(tmbb->p, bro);
								}
								if (tmbb->p->r->l->s == 'r' and tmbb->p->r->r->s == 'b')
								{
									tmbb->p->r->s = 'b';
									brightrotate(tmbb->p->r, bro);
									bleftrotate(tmbb->p, bro);
								}

							}
							else
							{
								tmbb->p->r->s = 'b';
								tmbb->p->r->r->l->s = tmbb->p->r->r->r->s = 'r';
								bleftrotate(tmbb->p, bro);
							}
						}
						else
						{
							if (tmbb->p->l->s == 'b')
							{
								if (tmbb->p->l->l->s == tmbb->p->l->r->s == 'b')
									tmbb->p->l->s = 'r';
								if (tmbb->p->l->l->s == tmbb->p->l->r->s == 'r')
								{
									tmbb->p->l->r->s = 'b';
									brightrotate(tmbb->p, bro);
								}
								if (tmbb->p->l->l->s == 'b' and tmbb->p->l->r->s == 'r')
								{
									tmbb->p->l->r->s = 'b';
									brightrotate(tmbb->p, bro);
								}
								if (tmbb->p->l->l->s == 'r' and tmbb->p->l->r->s == 'b')
								{
									tmbb->p->l->s = 'b';
									bleftrotate(tmbb->p->r, bro);
									brightrotate(tmbb->p, bro);
								}

							}
							else
							{
								tmbb->p->l->s = 'b';
								tmbb->p->l->r->l->s = tmbb->p->l->r->r->s = 'r';
								brightrotate(tmbb->p, bro);
							}
						}
					}
				}


			}
		}
		else
		{
			tmb->s = 'b'; tmb->r->s = 'r';
			brightrotate(vsp->p, bro);
		}
	}
}
brtree* findmax(brtree* tmp, brtree** bro)
{
	tmp = tmp->l;
	while (tmp->r != NULL)
		tmp = tmp->r;
	if (tmp->s == 'b')
		brsuccessor(&tmp, bro);
	return tmp;
}
void delelel(brtree** bro, int x)
{
	brtree* tmp = *bro;
	while (tmp != NULL and tmp->key != x)
	{
		if (tmp->key > x)
			tmp = tmp->l;
		else
			tmp = tmp->r;
	}
	if (tmp == NULL)
		cout << "No";
	else
	{
		if (tmp->r == NULL and tmp->l == NULL and (tmp->s == 'r' or (tmp->p == NULL and (tmp->l == NULL or tmp->r == NULL))))

		{
			if (tmp->p == NULL and (tmp->r == NULL and tmp->r == NULL))
				delete* bro;
			else if (tmp->p == NULL and tmp->r != NULL)
			{
				*bro = tmp->r;
				delete tmp;
			}
			else if (tmp->p == NULL and tmp->l != NULL)
			{
				*bro = tmp->l;
				delete tmp;
			}
			else
				delete tmp;
		}
		else
		{
			brtree* vsp = new brtree;
			if (tmp->l != NULL)
				vsp = findmax(tmp, bro);
			else  vsp = tmp->r;
			if (vsp != tmp->l)
				vsp->l = tmp->l;
			if (vsp != tmp->r)
				vsp->r = tmp->r;
			vsp->p = tmp->p;
			if (tmp->p != NULL)
			{
				if (tmp == tmp->p->l)
					tmp->p->l = vsp;
				else
					tmp->p->r = vsp;
			}
			vsp->s = tmp->s;
		}

	}
}