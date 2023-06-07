#include "../Cabecalhos/ListaEntidades.h"

Listas::ListaEntidades::ListaEntidades():LEs(){
}

Listas::ListaEntidades::~ListaEntidades(){
	LEs.LimpaLista();
}

bool Listas::ListaEntidades::InserirEntidade(Entidades::Entidade* inserida){
	return LEs.InserirElemento(inserida);
}

bool Listas::ListaEntidades::RemoverEntidade(Entidades::Entidade* removida) {
	return LEs.RemoverElemento(removida);
}

void Listas::ListaEntidades::executar(){
	Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pAux = LEs.getPrimeiro();

	if (pAux != nullptr) {
		while (pAux != LEs.getAtual()){
			pAux->getInfo()->executar();
			pAux = pAux->getProx();
		}
	}
}

void Listas::ListaEntidades::Inicializar(){
	Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pAux = LEs.getPrimeiro();

	if (pAux != nullptr) {
		while (pAux != LEs.getAtual()) {
			pAux->getInfo()->Inicializa();
			pAux = pAux->getProx();
		}
	}
}


