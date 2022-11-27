#include "../include/joueur.h"



/* CONSTRUCTEURS *****************************************************************************/

Joueur::Joueur() {
    this->attacking_range = 5;
    this->defending_range = 5;
}

Joueur::Joueur(int ar, int dr, int p, int d, int nx) {
    this->attacking_range = ar;
    this->defending_range = dr;
	this->point = p;
	this->dir = d;
	this->x = nx;
}



/* MODIFICATEURS ET ACCESSEURS ***************************************************************/

int Joueur::get_dir() { return this->dir; }
void Joueur::set_dir(int a) { if(a==0 || a==1) this->dir = a; }

int Joueur::get_point() { return this->point; }
void Joueur::point_0() { this->point = 0; };

int Joueur::get_movement_speed() { return this->movement_speed; }
int Joueur::get_attack_speed() { return this->attacking_speed; }
int Joueur::get_block_time() { return this->block_time; }

int Joueur::get_can_move() { return this->can_move; }
void Joueur::set_can_move(int a) { if(a==0 || a==1) this->can_move = a; }

void Joueur::set_attribute(int a) { if(a==1 || a==2 || a == 3) this->attribute = a; }



/* MOUVEMENTS ********************************************************************************/


/* Bouge le personnage vers la droite */
int Joueur::can_move_right(std::vector<std::string> grid, int w, int h) {
    if((this->x + 1) < w-2) {
        if(grid[h-1][(this->x + 1 + 2)] == ' ' && grid[h-1][(this->x + 1 + 4)] == ' ') {
			return 0;
		}
    }
	return 1;
}


void Joueur::move_right(std::vector<std::string> &grid, int w, int h) {
    if(can_move_right(grid, w, h) == 0) {
        this->dir = 0;
        remove_position(grid, h);
		this->x += 1;
        replace_player_r(grid, 1, h);
    }
}


/* Bouge le personnage vers la gauche */
int Joueur::can_move_left(std::vector<std::string> grid, int w, int h) {
    if((this->x - 1) > 2) {
        if(grid[h-1][(this->x - 1 - 2)] == ' ' && grid[h-1][(this->x - 1 - 4)] == ' ') {
			return 0;
		}
    }
	return 1;
}


void Joueur::move_left(std::vector<std::string> &grid, int w, int h) {
    if(can_move_left(grid, w, h) == 0) {
		this->dir = 1;
		remove_position(grid, h);
		this->x -= 1;
		replace_player_l(grid, 1, h);
    }
}


/* Fais sauter le personnage vers la droite */
int Joueur::can_jump_right(std::vector<std::string> grid, int w, int h) {
    if(this->x+9 < w-2) {
        for(int i=2; i<10; ++i) {
            if(grid[h-1][(this->x+i)] != ' ' && grid[h-1][(this->x+i)] != 'X') {
				return 1;
			}
		}
        return 0;
    }
	return 1;
}


void Joueur::jump_right_pos1(std::vector<std::string> &grid, int w, int h) {
    if(can_jump_right(grid, w, h) == 0) {
		this->dir = 0;
		remove_position(grid, h);
		this->x += 4;
		replace_player_r(grid, 0, h);
    }
}


void Joueur::jump_right_pos2(std::vector<std::string> &grid, int w, int h) {
    remove_position(grid, h);
	this->x += 4;
	replace_player_r(grid, 0, h);
}


/* Fais sauter le personnage vers la gauche */
int Joueur::can_jump_left(std::vector<std::string> grid, int w, int h) {
    if(this->x-9 > 2) {
        for(int i=-9; i<-3; ++i) {
            if(grid[h-1][(this->x+i)] != ' ' && grid[h-1][(this->x+i)] != 'X') {
				return 1;
			}
        }
        return 0;
    }
	return 1;
}


void Joueur::jump_left_pos1(std::vector<std::string> &grid, int w, int h) {
    if(can_jump_left(grid, w, h) == 0) {
		this->dir = 1;
		remove_position(grid, h);
		this->x -= 4;
		replace_player_l(grid, 0, h);
    }
}


void Joueur::jump_left_pos2(std::vector<std::string> &grid, int w, int h) {
    remove_position(grid, h);
	this->x -= 4;
	replace_player_l(grid, 0, h);
}


/* Mets le personnage en mode ATTAQUE */
void Joueur::player_attack(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 1;
    update_position(grid, w, h, 1);
}


/* Mets le personnage en mode REST */
void Joueur::player_rest(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 3;
	update_position(grid, w, h, 1);
}


/* Mets le personnage en mode BLOQUE */
void Joueur::player_block(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 2;
	update_position(grid, w, h, 1);
} 



/* ATTAQUE UN AUTRE PERSONNAGE ***************************************************************/

/* Retourne 0 si l'attaque a eu lieu
            1 sinon
*/
int Joueur::attack(Joueur j2) {
    if(j2.attribute == 1) {
		return 1;
	} else {
        int dist = abs(j2.x - this->x);
		if(dist > this->attacking_range) {
			return 1;
		} else {
			if(j2.attribute == 2) {
				if(dist <= j2.defending_range) {
					return 1;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
    }
}


/* Rajoute un point si l'attaque a eu lieu */
void Joueur::add_point(Joueur j2) {
	if(attack(j2) == 0) {
		this->point += 1;
	}
}


/* AFFICHAGE SUR LE TERMINAL *********************************************************/

/* Affiche un personnage vers la direction DROITE sur une scène */
void Joueur::replace_player_r(std::vector<std::string>& grid, int jump, int height) {
	int h = height;
	if(jump == 0) h = height - 2;
	grid[h-5][this->x-1] = '<';
	grid[h-5][this->x] = 'o';
	grid[h-5][this->x+1] = '>';

	grid[h-4][this->x] = '|';
	grid[h-4][this->x+1] = '\\';

	if(this->attribute == 1) grid[h-4][this->x+2] = '_';
	else if(this->attribute == 2) grid[h-4][this->x+2] = '|';
	else grid[h-4][this->x+2] = '/';

	grid[h-3][this->x] = '|';
	grid[h-2][this->x] = '|';
	grid[h-1][this->x] = '|';
	grid[h-1][this->x-1] = '/';
}


void Joueur::convert_player_r(std::vector<std::string>& grid, int new_x, int jump, int height) {
	this->x = new_x;
	replace_player_r(grid, jump, height);

	/*

	<o>
	 |\/
	 |
	 |
	/|

	*/
}


/* Affiche un personnage vers la direction GAUCHE sur une scène */
void Joueur::replace_player_l(std::vector<std::string>& grid, int jump, int height) {
	int h = height;
	if(jump == 0) h = height - 2;
	grid[h-5][this->x-1] = '<';
	grid[h-5][this->x] = 'o';
	grid[h-5][this->x+1] = '>';

	grid[h-4][this->x] = '|';
	grid[h-4][this->x-1] = '/';
	
	if(this->attribute == 1) grid[h-4][this->x-2] = '_';
	else if(this->attribute == 2) grid[h-4][this->x-2] = '|';
	else grid[h-4][this->x-2] = '\\';

	grid[h-3][this->x] = '|';
	grid[h-2][this->x] = '|';
	grid[h-1][this->x] = '|';
	grid[h-1][this->x+1] = '\\';
}


void Joueur::convert_player_l(std::vector<std::string>& grid, int new_x, int jump, int height) {
    this->x = new_x;
    replace_player_l(grid, jump, height);

	/*

	 <o>
	\_|
	  |
	  |
	 /|

	*/
}



/* SUPPRESSION DU TERMINAL ***********************************************************/

/* Supprime le personnage d'une scène */
void Joueur::remove_position(std::vector<std::string>& grid, int height) {
	for(int i=1; i<height; ++i) {
		for(int j=-2; j<3; ++j) {
			if(grid[height-i][this->x+j] != 'X') {
				grid[height-i][this->x+j] = ' ';
			}
		}
	}

}


/* Supprime un personnage d'une scène et ajoute sa nouvelle position */
void Joueur::update_position(std::vector<std::string>& grid, int w, int h, int jump) {
	remove_position(grid, h);
    if(this->dir == 0) {
		replace_player_r(grid, jump, h);
	} else {
		replace_player_l(grid, jump, h);
	}
}



/* MISE À 0 DU JOUEUR ************************************************************************/

/* Remet un personnage les attributs d'orginie */
void Joueur::update_player() {
    this->attribute = 3;
	this->dir = 0;
	this->x = -1;
	this->can_move = 0;
}


std::string Joueur::player_to_string() {
	std::string res = "";
	res += std::to_string(this->attacking_range) + " ";
	res += std::to_string(this->defending_range) + " ";
	res += std::to_string(this->point) + " ";
	res += std::to_string(this->dir) + " ";
	res += std::to_string(this->x);
	return res;
}



/*********************************************************************************************/
