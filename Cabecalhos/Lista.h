#pragma once
#include <iostream>
using namespace std;
namespace Listas {
	template<class TL>class Lista {
	public:
		template<class TE>class Elemento {// Classe Elemento aninhada na classe Lista
		private:
			Elemento<TE>* pProx;
			TE* pInfo;
		public:

			Elemento() {
				pProx = nullptr;	pInfo = nullptr;
			}
			~Elemento() {
				pProx = nullptr;	pInfo = nullptr;
			}

			Elemento<TE>* getProx() {
				return pProx;
			}
			void setProx(Elemento<TE>* Prox) {
				if (Prox != nullptr) {
					pProx = Prox;
				}
			}
			TE* getInfo() {
				return pInfo;
			}

			void setInfo(TE* info) {
				if (info != nullptr) {
					pInfo = info;
				}
			}

		};
	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pAtual;
	public:

		Lista();
		~Lista();

		bool InserirElemento(TL* Elemento);

		Elemento<TL>* getPrimeiro() {
			return pPrimeiro;
		}

		Elemento<TL>* getAtual() {
			return pAtual;
		}

		bool RemoverElemento(TL* Elemen) {
		
			if (Elemen == nullptr) {
				cout << "Elemento invalido" << endl;
				return false;
			}

			if (pPrimeiro->getInfo() == Elemen) { // Remoção para caso o elemento a ser retirado coincida com primeiro.
				pPrimeiro = pPrimeiro->getProx();
				return true;
				cout << "Elemento removido da Lista.h com sucesso" << endl;
			}
		

			Elemento<TL>* pAux = pPrimeiro;
			Elemento<TL>* pAux2 = nullptr;
			while (pAux != pAtual) {
				pAux2 = pAux->getProx();
				if (pAux2->getInfo() == Elemen) {
					pAux->setProx(pAux2->getProx());
					if (pAux2 == pAtual) { // Remoção para caso o elemento a ser retirado coincida com o Ultimo.
						pAtual = pAux;
					}
					delete pAux2;
					return true;
					cout << "Elemento removido da Lista.h com sucesso" << endl;
				}
				pAux = pAux->getProx();
			}
		}

		void LimpaLista();
	};

	template<class TL>
	inline Lista<TL>::Lista() {
		pPrimeiro = nullptr;
		pAtual = nullptr;
	}

	template<class TL>
	inline Lista<TL>::~Lista() {
		LimpaLista();
	}

	template<class TL>
	inline bool Lista<TL>::InserirElemento(TL* Elemen) {

		if (Elemen != nullptr) {

			Elemento<TL>* pAux = new Elemento<TL>;	pAux->setInfo(Elemen);

			if (pPrimeiro == nullptr && pAtual == nullptr) {
				pPrimeiro = pAux;	pAtual = pAux;
				return true;
			}
			else {
				pAtual->setProx(pAux);
				pAtual = pAux;
				return true;
			}

		}
		else {
			cout << "Elemento Invalido" << endl;
			return false;
		}
	}

	template<class TL>
	inline void Lista<TL>::LimpaLista() {
		Elemento<TL>* aux = nullptr;

		while (pPrimeiro != nullptr) {
			aux = pPrimeiro->getProx();
			delete pPrimeiro;
			pPrimeiro = aux;
		}
	}
}