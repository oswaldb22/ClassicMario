#include"Jeu.h"

void jeuInit(Jeu *j){
    Position posMar;
    Position posMons;
    posSetX(&posMar,2);
    posSetY(&posMar,2);

    marInit(&j->mar);
    marSetPosition(&j->mar,&posMar);
    marSetDirection(&j->mar,4);

    monsInit(&j->mons);
    posSetX(&posMons,14);
    posSetY(&posMons,10);
    monsSetPosition(&j->mons,&posMons);
    monsSetDirection(&j->mons,4);

    nivInit(&j->niv,"data/terrain1.txt");

}

void jeuVerificationPosition(Jeu *j){
        Position posMario=marGetPosition(&j->mar);
        Position posMons=monsGetPosition(&j->mons);
        Position pos;
            posSetX(&pos,2);
            posSetY(&pos,2);

        if (posGetX(&posMario)==posGetX(&posMons)&&posGetY(&posMario)==posGetY(&posMons)){

            marSetPosition(&j->mar,&pos);

        }
}



const Mario* jeuGetConstMario(const Jeu *j){
    return &j->mar;
}

const Monster* jeuGetConstMonster(const Jeu *j){
    return &j->mons;
}

const Niveau* jeuGetConstNiveau(const Jeu *j){
    return &j->niv;
}

void jeuActionsAutomatiques(Jeu *j){
    monsBougeAuto(&j->mons,&j->niv);

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
		case 'h' :
				marHaut(&j->mar, &j->niv);
				break;
		case 'b' :
				marBas(&j->mar, &j->niv);
				break;
        case 's' :
				marSaut(&j->mar, &j->niv);
				break;

	}
}

