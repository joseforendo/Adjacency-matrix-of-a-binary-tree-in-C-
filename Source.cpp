#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
struct Nodo {
	T dato;
	int nombreAt;
	Nodo *left, *right;

	Nodo(T dato)
	{
		nombreAt = 0;
		this->dato = dato;
		left = right = nullptr;
	}
};

template<typename T>
class BST {
private:

	Nodo<T> *root;
	int nodes;
	vector<Nodo<T>> listaEnOrden;
	vector<Nodo<T>> listaPostOrden;

public:

	BST()
	{
		nodes = 0;
		this->root = nullptr;
	}

	void insert(T dato)
	{
		insert(root, dato);
	}

	void inorder()
	{
		inorder(root);
	}

	void Dimension()
	{
		Dimension(root, 1);
	}

	void Dimension(Nodo<T> *&aux, int espacios)
	{
		if (aux == nullptr)
		{
			return;
		}
		else
		{
			espacios += 10;
			Dimension(aux->right, espacios);
			cout << endl;

			for (int i = 10; i < espacios; i++)
			{
				cout << " ";
			}
			cout << aux->dato << "\n";

			Dimension(aux->left, espacios);
		}
	}

	void insert(Nodo<T> *&aux, T dato)
	{
		if (aux == nullptr)
		{
			nodes++;
			aux = new Nodo<T>(dato);
			aux->nombreAt = nodes;
		}
		else
		{
			if (aux->dato > dato)
			{
				if (aux->left != nullptr)
				{
					insert(aux->left, dato);
				}
				else
				{
					nodes++;
					aux->left = new Nodo<T>(dato);
					aux->left->nombreAt = nodes;
				}
			}
			else if(aux->dato < dato)
			{
				if (aux->right != nullptr)
				{
					insert(aux->right, dato);
				}
				else
				{
					nodes++;
					aux->right = new Nodo<T>(dato);
					aux->right->nombreAt = nodes;
				}
			}
		}
	}

	vector<Nodo<T>> getInorder() { return listaEnOrden; }

	void inorder(Nodo<T> *aux)
	{
		if (aux != nullptr)
		{
			inorder(aux->left);
			listaEnOrden.push_back(*aux);
			cout << aux->dato << ", ";
			inorder(aux->right);
		}
	}
};

int main()
{
	BST<int> *tree = new BST<int>{ };
	int **matriz2;

	tree->insert(10);
	tree->insert(9);
	tree->insert(11);
	tree->insert(5);
	tree->insert(4);
	tree->insert(8);
	tree->insert(7);
	tree->insert(16);
	tree->insert(2);
	tree->insert(5);
	tree->insert(21);
	tree->insert(15);

	tree->inorder();

	cout << endl << endl;

	tree->Dimension();

	cout << endl << endl;

	vector<Nodo<int>> listaIn = tree->getInorder();

	matriz2 = new int*[listaIn.size()];

	cout << "\t";
	for (int i = 0; i < listaIn.size(); i++)
	{
		cout << listaIn.at(i).dato << "\t";
	}
	cout << endl;
	
	for (int i = 0; i < listaIn.size(); i++)
	{
		matriz2[i] = new int[listaIn.size()];
	}
	for (int i = 0; i < listaIn.size(); i++)
	{
		for (int j = 0; j < listaIn.size(); j++)
		{
			matriz2[i][j] = 0;
		}
	}
	for (int i = 0; i < listaIn.size(); i++)
	{
		for (int j = 0; j < listaIn.size() ; j++)
		{
			if (listaIn.at(i).left != nullptr)
			{
				if (listaIn.at(i).left->nombreAt == listaIn.at(j).nombreAt)
				{
					matriz2[i][j] = 1;
				}
			}
			if (listaIn.at(i).right != nullptr)
			{
				if (listaIn.at(i).right->nombreAt == listaIn.at(j).nombreAt)
				{
					matriz2[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < listaIn.size(); i++)
	{
		cout << listaIn.at(i).dato << "\t";
		for (int j = 0; j < listaIn.size(); j++)
		{
			cout << matriz2[i][j] << "\t";
		}
		cout << endl;
	}

	_getch();
}
