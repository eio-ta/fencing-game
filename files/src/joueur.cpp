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

int Joueur::get_is_on_movement() { return this->is_on_movement; }
void Joueur::set_is_on_movement(int a) { if(a==0 || a==1) this->is_on_movement = a; }

void Joueur::set_attribute(int a) { if(a==1 || a==2 || a == 3) this->attribute = a; }
void Joueur::set_x(int a) { this->x = a; }



/* MOUVEMENTS ********************************************************************************/


/* Vérifie si le joueur peut se déplacer horizontalement */
int Joueur::can_move_to(std::vector<std::string> grid, int w, int h, int move) {
	if(move == RIGHT) {
		if((this->x + RIGHT) < w-2) {
			if(grid[h-1][(this->x + RIGHT + 1)] == ' ' && grid[h-1][(this->x + RIGHT + 2)] == ' ' && grid[h-4][(this->x + RIGHT + 2)] == ' ') {
				return 0;
			}
		}
	} else {
		if((this->x + LEFT) > 2) {
			if(grid[h-1][(this->x + LEFT - 1)] == ' ' && grid[h-1][(this->x + LEFT - 2)] == ' ' && grid[h-4][(this->x + LEFT - 2)] == ' ') {
				return 0;
			}
		}
    }
	return 1;
}


/* Fais bouger le joueur suivant la direction */
void Joueur::move_to(std::vector<std::string> &grid, int w, int h, int move) {
	this->dir = (move == RIGHT) ? 0 : 1;
    remove_position(grid, h);
	this->x += (move == RIGHT) ? 1 : -1;
	replace_player(grid, 1, h, move);
}


/* Vérifie si le joueur peut sauter */
int Joueur::can_jump_to(std::vector<std::string> grid, int w, int h, int move) {
	if(move == JUMP_RIGHT) {
		if((this->x + JUMP_RIGHT) < w-2) {
			for(int i=0; i<h-1; ++i) {
				for(int j=(this->x + 3); j < (this->x + 6); ++j) {
					if(!(grid[i][j] == ' ' || grid[i][j] == 'X')) return 1;
				}
			}

			for(int i=0; i<h-1; ++i) {
				for(int j=(this->x + 6); j < (this->x + 10); ++j) {
					if(!(grid[i][j] == ' ')) return 1;
				}
			}
			return 0;
		}
	} else {
		if((this->x + JUMP_LEFT) > 0) {
			for(int i=0; i<h-1; ++i) {
				for(int j=(this->x - 3); j > (this->x - 6); --j) {
					if(!(grid[i][j] == ' ' || grid[i][j] == 'X')) return 1;
				}
			}

			for(int i=0; i<h-1; ++i) {
				for(int j=(this->x - 6); j > (this->x - 10); --j) {
					if(!(grid[i][j] == ' ')) return 1;
				}
			}
			return 0;
		}
	}
	return 1;
}


/* Les différentes positions pour sauter */
void Joueur::jump_to_pos1(std::vector<std::string> &grid, int w, int h, int move) {
	this->dir = (move == JUMP_RIGHT) ? 0 : 1;
	remove_position(grid, h);
	this->x += (move == JUMP_RIGHT) ? 4 : -4;
	replace_player(grid, 0, h, move);
}


/* Les différentes positions pour sauter */
void Joueur::jump_to_pos2(std::vector<std::string> &grid, int w, int h, int move) {
    remove_position(grid, h);
	this->x += (move == JUMP_RIGHT) ? 3 : -3;
	replace_player(grid, 0, h, move);
}


/* Mets le personnage en mode ATTAQUE */
void Joueur::player_attack(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 1;
    update_position(grid, w, h, 1, (this->dir == 0) ? RIGHT : LEFT);
}


/* Mets le personnage en mode REST */
void Joueur::player_rest(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 3;
	update_position(grid, w, h, 1, (this->dir == 0) ? RIGHT : LEFT);
}


/* Mets le personnage en mode BLOQUE */
void Joueur::player_block(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 2;
	update_position(grid, w, h, 1, (this->dir == 0) ? RIGHT : LEFT);
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

/* Affiche un personnage suivant la direction sur une scène */
void Joueur::replace_player(std::vector<std::string>& grid, int jump, int height, int move) {
	int h = height;
	if(jump == 0) h = height - 2;
	grid[h-5][this->x-1] = '<';
	grid[h-5][this->x] = 'o';
	grid[h-5][this->x+1] = '>';

	grid[h-4][this->x] = '|';

	if(move == RIGHT || move == JUMP_RIGHT) {
		grid[h-4][this->x+1] = '\\';
		if(this->attribute == 1) grid[h-4][this->x+2] = '_';
		else if(this->attribute == 2) grid[h-4][this->x+2] = '|';
		else grid[h-4][this->x+2] = '/';
		grid[h-1][this->x-1] = '/';
	} else {
		grid[h-4][this->x-1] = '/';
		if(this->attribute == 1) grid[h-4][this->x-2] = '_';
		else if(this->attribute == 2) grid[h-4][this->x-2] = '|';
		else grid[h-4][this->x-2] = '\\';
		grid[h-1][this->x+1] = '\\';
	}

	grid[h-3][this->x] = '|';
	grid[h-2][this->x] = '|';
	grid[h-1][this->x] = '|';
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
void Joueur::update_position(std::vector<std::string>& grid, int w, int h, int jump, int move) {
	remove_position(grid, h);
	replace_player(grid, jump, h, move);
}



/* MISE À 0 DU JOUEUR ************************************************************************/

/* Remet un personnage les attributs d'origine */
void Joueur::update_player() {
    this->attribute = 3;
	this->dir = 0;
	this->x = -1;
	this->is_on_movement = 0;
}


/* Convertie un personnage en STRING */
std::string Joueur::player_to_string() {
	std::string res = "";
	res += std::to_string(this->attacking_range) + " ";
	res += std::to_string(this->defending_range) + " ";
	res += std::to_string(this->point) + " ";
	res += std::to_string(this->dir) + " ";
	res += std::to_string(this->x);
	return res;
}


/* Copie un joueur */
void Joueur::copy(Joueur j) {
	this->attacking_range = j.attacking_range;
	this->defending_range = j.defending_range;
	this->point = j.point;
	this->dir = j.dir;
	this->x = j.x;
}



/*********************************************************************************************/
