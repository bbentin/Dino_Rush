#pragma once
#include <iostream>
using namespace std;
namespace Listas {
	template<class TL>class Lista {
	public:
		template<class TE>class Elemento {
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
				pProx = Prox;
			}
			TE* getInfo() {
				return pInfo;
			}

			void setInfo(TE* info) {
				pInfo = info;
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

			Elemento<TL>* pAux = pPrimeiro;

			while (pAux != pAtual) {
				if (pAux->getProx()->getInfo() == Elemen) {
					delete pAux->getProx();
					pAux->setProx(pAux->getProx()->getProx());
					cout << "Elemento removido com sucesso" << endl;
					return true;
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
			}

		}
		else {
			cout << "Elemento Invalido" << endl;
			return false;
		}
	}

	template<class TL>
	inline void Lista<TL>::LimpaLista() {
		Elemento<TL>* aux;

		while (pPrimeiro != nullptr) {
			aux = pPrimeiro->getProx();
			delete pPrimeiro;
			pPrimeiro = aux;
		}
	}
}