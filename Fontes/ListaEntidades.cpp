#include "../Cabecalhos/ListaEntidades.h"

Listas::ListaEntidades::ListaEntidades():LEs(){
	LEs.LimpaLista();
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


void Listas::ListaEntidades::executar_entidades(){
	Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pAux = LEs.getPrimeiro();

	if (pAux != nullptr) {
		while (pAux != LEs.getAtual()->getProx()) {
			pAux->getInfo()->executar();
			pAux = pAux->getProx();
		}
	}
}

void Listas::ListaEntidades::executar(){
	executar_entidades();
}

void Listas::ListaEntidades::Inicializar(){
	Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pAux = LEs.getPrimeiro();

	if (pAux != nullptr) {
		while (pAux != LEs.getAtual()->getProx()) {
			pAux->getInfo()->Inicializa();
			pAux = pAux->getProx();
		}
	}
}


