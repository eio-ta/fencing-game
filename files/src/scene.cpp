#include "../include/scene.h"

void Scene::print_text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

void Scene::print_separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

void Scene::print_fight() {
    std::cout << std::endl << std::endl;
    Scene::print_text_center("FIGHT !!!");
    std::cout << std::endl;
	Scene::print_separator();
}


int Scene::count_occurence(std::string scene) {
	int c1 = 0;
	int c2 = 0;
	for(int i=0; i<scene.length(); ++i) {
		if(scene[i] == '1') c1 += 1;
		if(scene[i] == '2') c2 += 1;
	}
	return (c1 == 1 && c2 ==1);
}

std::string Scene::load_a_scene(std::string filename) {
    std::ifstream in_stream;
	in_stream.open(filename);
	std::string line;
	if(in_stream.is_open()) {
		in_stream >> line;
		in_stream.close();
	}
	return line;
}

int Scene::is_valid_scene(std::string filename) {
	std::ifstream in_stream;
	in_stream.open(filename);
	if(in_stream.is_open()) {
		std::string line;
		int nb_line = 0;
		while(in_stream >> line) {
			nb_line += 1;
		}
		if(nb_line != 1) return 1;
		for(int i=0; i<line.length(); ++i) {
			if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) return 1;
		}
		in_stream.close();
		if(count_occurence(line) == 0) return 0;
	}
	return 1;
}

void Scene::create_grid_block(std::vector<std::string>& grid, int x, int w) {
	int new_x = (x * WIDTH_MENU) / w;

	/*

	XXX
	XXX

	*/
	
	grid[HEIGH_MENU-1][new_x] = 'X';
	grid[HEIGH_MENU-1][new_x-1] = 'X';
	grid[HEIGH_MENU-1][new_x+1] = 'X';
	grid[HEIGH_MENU-2][new_x] = 'X';
	grid[HEIGH_MENU-2][new_x-1] = 'X';
	grid[HEIGH_MENU-2][new_x+1] = 'X';	
}

void Scene::remove_last_position(std::vector<std::string>& grid, int &joueur_x) {
	for(int i=1; i<6; ++i) {
		for(int j=-2; j<3; ++j) {
			grid[HEIGH_MENU-i][joueur_x-j] = ' ';
		}
	}
}

// RIGHT
void Scene::replace_new_position_r(std::vector<std::string>& grid, int &joueur_x, int &joueur_attribut) {
	grid[HEIGH_MENU-5][joueur_x-1] = '<';
	grid[HEIGH_MENU-5][joueur_x] = 'o';
	grid[HEIGH_MENU-5][joueur_x+1] = '>';

	grid[HEIGH_MENU-4][joueur_x] = '|';
	grid[HEIGH_MENU-4][joueur_x+1] = '_';

	if(joueur_attribut == 1) grid[HEIGH_MENU-4][joueur_x+2] = '/';
	else if(joueur_attribut == 2) grid[HEIGH_MENU-4][joueur_x+2] = '|';
	else grid[HEIGH_MENU-3][joueur_x+2] = '\\';

	grid[HEIGH_MENU-3][joueur_x] = '|';
	grid[HEIGH_MENU-2][joueur_x] = '|';
	grid[HEIGH_MENU-1][joueur_x] = '|';
	grid[HEIGH_MENU-1][joueur_x-1] = '/';
}

// LEFT
void Scene::replace_new_position_l(std::vector<std::string>& grid, int &joueur_x, int &joueur_attribut) {
	grid[HEIGH_MENU-5][joueur_x-1] = '<';
	grid[HEIGH_MENU-5][joueur_x] = 'o';
	grid[HEIGH_MENU-5][joueur_x+1] = '>';

	grid[HEIGH_MENU-4][joueur_x] = '|';
	grid[HEIGH_MENU-4][joueur_x-1] = '_';
	
	if(joueur_attribut == 1) grid[HEIGH_MENU-4][joueur_x-2] = '\\';
	else if(joueur_attribut == 2) grid[HEIGH_MENU-4][joueur_x-2] = '|';
	else grid[HEIGH_MENU-3][joueur_x-2] = '/';

	grid[HEIGH_MENU-3][joueur_x] = '|';
	grid[HEIGH_MENU-2][joueur_x] = '|';
	grid[HEIGH_MENU-1][joueur_x] = '|';
	grid[HEIGH_MENU-1][joueur_x+1] = '\\';
}



void Scene::create_grid_player_r(std::vector<std::string>& grid, int x, int w, int &joueur_x, int &joueur_attribut) {
	int new_x = (x * WIDTH_MENU) / w;
	joueur_x = new_x;
	Scene::replace_new_position_r(grid, joueur_x, joueur_attribut);

	/*

	<o>
	 |_/
	 |
	 |
	/|

	*/
}

void Scene::create_grid_player_l(std::vector<std::string>& grid, int x, int w, int &joueur_x, int &joueur_attribut) {
	int new_x = (x * WIDTH_MENU) / w;
	joueur_x = new_x;
	Scene::replace_new_position_l(grid, joueur_x, joueur_attribut);

	/*

	 <o>
	\_|
	  |
	  |
	 /|

	*/
}

std::vector<std::string> Scene::convert_scene(std::string scene, int &joueur1_x, int &joueur1_attribut, int &joueur1_dir, int &joueur2_x, int &joueur2_attribut, int &joueur2_dir) {
	std::vector<std::string> lines (HEIGH_MENU, "");
    for(int i=0; i<HEIGH_MENU; ++i) {
        std::string line = "";
        for(int j=0; j<WIDTH_MENU; ++j) {
            line += " ";
        }
        lines[i] = line;
    }

	for(int i=0; i<scene.length(); ++i) {
		switch (scene[i]) {
			case '1':
				if(joueur1_dir == 0) Scene::create_grid_player_r(lines, i, scene.length(), joueur1_x, joueur1_attribut);
				else Scene::create_grid_player_l(lines, i, scene.length(), joueur1_x, joueur1_attribut);
				break;
			case '2':
				if(joueur2_dir == 0) Scene::create_grid_player_r(lines, i, scene.length(), joueur2_x, joueur2_attribut);
				else Scene::create_grid_player_l(lines, i, scene.length(), joueur2_x, joueur2_attribut);
				break;
			case 'x':
				Scene::create_grid_block(lines, i, scene.length());
				break;
			default: break;
		}
	}
	return lines;
}

void Scene::print_scene(std::vector<std::string> lines) {
    for(int i = 0; i < HEIGH_MENU; ++i) {
        std::cout << lines[i] << std::endl;
    }

	for(int i=0; i<2; ++i) {
		for(int j=0; j<WIDTH_MENU; ++j) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}