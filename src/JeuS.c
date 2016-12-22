#include"JeuS.h"

void jeuInit(Jeu *j,const char *filename){

	PositionSdl posMar;
	PositionSdl posMons;
	posSetX(&posMar,2*TAILLE_SPRITE);
	posSetY(&posMar,2*TAILLE_SPRITE);

	marInit(&j->mar);
	marSetPositionSdl(&j->mar,&posMar);
	marSetDirection(&j->mar,4);

	monsInitSdl(&j->mons);
	posSetX(&posMons,14);
	posSetY(&posMons,12);
	monsSetPositionSdl(&j->mons,&posMons);
	monsSetDirectionSdl(&j->mons,4);

	/*-------------------Initialisation de MarioSdl en SDL--------------*/
	MarioSdl* mar = jeuGetMarioSdl(j);
	mar->x=2*TAILLE_SPRITE;
	mar->y=5*TAILLE_SPRITE;
	mar->timerMort=0;
	mar->life=3;
	mar->animFrame=0;

	MonsterSdl *mons =jeuGetMonsterSdl(j);
	mons->x=10*TAILLE_SPRITE;
	mons->y=12*TAILLE_SPRITE;

	nivInit(&j->niv,filename);

}

const MarioSdl* jeuGetConstMarioSdl(const Jeu *j){
	return &j->mar;
}

MarioSdl* jeuGetMarioSdl( Jeu *j){
	return &j->mar;
}

/*const MonsterSdl* jeuGetConstMonster(const Jeu *j){
	return &j->mons;
}*/

MonsterSdl* jeuGetMonsterSdl( Jeu *j){
	return &j->mons;
}

const Niveau* jeuGetConstNiveau(const Jeu *j){
	return &j->niv;
}

Niveau* jeuGetNiveau(Jeu *j){
	return &j->niv;
}

void jeuActionsAutomatiques(Jeu *j){
	monsBougeAutoSdl(&j->mons,&j->niv);
}

void jeuActionClavier(Jeu *j, const char touche){

	switch(touche)
	{
		case 'g' :
			marGauche(&j->mar, &j->niv);
			break;
		case 'd' :
			marDroite(&j->mar, &j->niv);
			break;

		case 's' :
			marSaut(&j->mar, &j->niv);
			break;
	}
}
