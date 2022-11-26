#include "../include/joueur.h"

/* Constructeurs ****************************************************************************/

Joueur::Joueur() {
    this->attacking_range = 6;
    this->defending_range = 6;
}

Joueur::Joueur(int ar, int dr) {
    this->attacking_range = ar + 6;
    this->defending_range = dr + 6;
}

/* Accesseurs et modificateurs **************************************************************/

int Joueur::get_dir() { return this->dir; }
void Joueur::set_dir(int a) { if(a==0 || a==1) this->dir = a; }

int Joueur::get_point() { return this->point; }

int Joueur::get_movement_speed() { return this->movement_speed; }
int Joueur::get_attack_speed() { return this->attacking_speed; }
int Joueur::get_block_time() { return this->block_time; }

int Joueur::get_can_move() { return this->can_move; }
void Joueur::set_can_move(int a) { if(a==0 || a==1) this->can_move = a; }

void Joueur::set_attribute(int a) { if(a==1 || a==2 || a == 3) this->attribute = a; }









/* Mouvements *******************************************************************************/

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
	this->x += 3;
	replace_player_r(grid, 0, h);
}

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
	this->x -= 3;
	replace_player_l(grid, 0, h);
}

void Joueur::move_attack_pos1(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 1;
    update_position(grid, w, h, 1);
}

void Joueur::move_attack_pos2(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 3;
	update_position(grid, w, h, 1);
}


int Joueur::attack(Joueur j2) {
    if(j2.attribute == 2 || j2.attribute == 1) {
		return 1;
	} else {
        int dist = j2.x - this->x;
        if(dist > 0) {   // 1_____2
            if(j2.x > (this->attacking_range + this->x)) {
				return 1;
			}
        } else { // 2____1
            if(j2.x < (this->attacking_range - this->x)) {
				return 1;
			}
        }
		return 0;
    }
}

void Joueur::add_point(Joueur j2) {
	if(attack(j2) == 0) {
		this->point += 1;
	}
}

void Joueur::move_block(std::vector<std::string> &grid, int w, int h) {
	this->attribute = 2;
	update_position(grid, w, h, 1);
} 



/* Affichage sur la scène *******************************************************************/

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

/* Supprimer l'affichage du joueur */
void Joueur::remove_position(std::vector<std::string>& grid, int height) {
	for(int i=1; i<height; ++i) {
		for(int j=-2; j<3; ++j) {
			if(grid[height-i][this->x+j] != 'X') {
				grid[height-i][this->x+j] = ' ';
			}
		}
	}

}

void Joueur::update_position(std::vector<std::string>& grid, int w, int h, int jump) {
	remove_position(grid, h);
    if(this->dir == 0) {
		replace_player_r(grid, jump, h);
	} else {
		replace_player_l(grid, jump, h);
	}
}

void Joueur::update_player() {
    this->attribute = 3;
	this->dir = 0;
	this->x = -1;
	this->can_move = 0;
}