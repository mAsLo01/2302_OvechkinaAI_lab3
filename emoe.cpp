#include "funct.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	char s; int qq = 0, k = 0;
	fstream f("200.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Файл не открывается";
	}
	else
	{
		f.get(s);
		if (s == '\n' || f.eof())
		{
			cout << "Файл пуст...";
			return 0;
		}
		else
		{
			f.seekg(-1, ios::cur);
			cout << "Выберите дерево:\n 1.бинарное дерево\n2.Красно-черное\n3.Avl";
			//cin >> k;
			k = 2;
			if (k == 1) {
				tree* root;
				root = NULL;
				createtree(&root, f, &qq);
				//treeoutput(root);
				preorder(root);
				cout << '\n';
				postorder(root);
				cout << '\n';
				inorder(root);
				deltree(root);
			}
			if (k == 2)
			{
				brtree* broot;
				brcreatetree(&broot, f, &qq);
				fstream d("del.txt", ios::in);
				int x;
				d >> x;
				delel(&broot, x);
				bprintInOrder(broot);
				delbrtree(broot);
			}
			if (k == 3)
			{
				avl* aroot;
				aroot = NULL;
				avlcreatetree(&aroot, f, &qq);
				cout << '\n';
				fstream d("del.txt", ios::in);
				int x;
				d >> x;
				delelem(&aroot, x);
				printInOrder(aroot);
				delavl(aroot);
			}
		}
	}
}