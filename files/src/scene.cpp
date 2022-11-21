#include "../include/scene.h"


// CHARGER UNE SCENE AVEC UN FICHIER /////////////////////////////////////////////////////////

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
		if(nb_line != 1) return false;
		for(int i=0; i<line.length(); ++i) {
			if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) return 1;
		}
		in_stream.close();
		if(count_occurence(line) == 0) return 0;
	}
	return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////


// AFFICHER UNE SCENE AVEC UN STRING /////////////////////////////////////////////////////////

void Scene::text_center(std::string str) {
    int spacing = (WIDTH_SCENE - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

void Scene::separator() {
    std::string str2 = "";
    int size = WIDTH_SCENE;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

void Scene::print_first_line(std::string str) {
    std::cout << std::endl << std::endl;
    Scene::text_center(str);
    std::cout << std::endl;
    Scene::separator();
    std::cout << std::endl;
}

void Scene::print_scene(std::vector<std::string> lines, Joueur j1, Joueur j2) {
	Scene::print_first_line("FIGHT !");

	std::string line_p = "| " + std::to_string(j1.get_point()) + " | " + std::to_string(j2.get_point()) + " |";
	Scene::text_center(line_p);

    for(int i = 0; i < HEIGH_SCENE; ++i) {
        std::cout << lines[i] << std::endl;
    }

	for(int i=0; i<2; ++i) {
		for(int j=0; j<WIDTH_SCENE; ++j) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Scene::separator();
}


//////////////////////////////////////////////////////////////////////////////////////////////


/// CONVERTIR UNE SCENE EN GRID //////////////////////////////////////////////////////////////

void Scene::convert_block(std::vector<std::string>& grid, int x, int w) {
	int new_x = (x * WIDTH_SCENE) / w;
	grid[HEIGH_SCENE-1][new_x] = 'X';
	grid[HEIGH_SCENE-1][new_x-1] = 'X';
	grid[HEIGH_SCENE-1][new_x+1] = 'X';
	grid[HEIGH_SCENE-2][new_x] = 'X';
	grid[HEIGH_SCENE-2][new_x-1] = 'X';
	grid[HEIGH_SCENE-2][new_x+1] = 'X';
}

void Scene::replace_player_r(std::vector<std::string>& grid, Joueur j, int jump) {
	int h = HEIGH_SCENE;
	if(jump == 0) h = HEIGH_SCENE - 2;
	grid[h-5][j.get_x()-1] = '<';
	grid[h-5][j.get_x()] = 'o';
	grid[h-5][j.get_x()+1] = '>';

	grid[h-4][j.get_x()] = '|';
	grid[h-4][j.get_x()+1] = '\\';

	if(j.get_attribute() == 1) grid[h-4][j.get_x()+2] = '_';
	else if(j.get_attribute() == 2) grid[h-4][j.get_x()+2] = '|';
	else grid[h-4][j.get_x()+2] = '/';

	grid[h-3][j.get_x()] = '|';
	grid[h-2][j.get_x()] = '|';
	grid[h-1][j.get_x()] = '|';
	grid[h-1][j.get_x()-1] = '/';
}

void Scene::convert_player_r(std::vector<std::string>& grid, int x, int w, Joueur &j, int jump) {
	int new_x = (x * WIDTH_SCENE) / w;
	j.set_x(new_x);
	Scene::replace_player_r(grid, j, jump);

	/*

	<o>
	 |\/
	 |
	 |
	/|

	*/
}

void Scene::replace_player_l(std::vector<std::string>& grid, Joueur j, int jump) {
	int h = HEIGH_SCENE;
	if(jump == 0) h = HEIGH_SCENE - 2;
	grid[h-5][j.get_x()-1] = '<';
	grid[h-5][j.get_x()] = 'o';
	grid[h-5][j.get_x()+1] = '>';

	grid[h-4][j.get_x()] = '|';
	grid[h-4][j.get_x()-1] = '/';
	
	if(j.get_attribute() == 1) grid[h-4][j.get_x()-2] = '_';
	else if(j.get_attribute() == 2) grid[h-4][j.get_x()-2] = '|';
	else grid[h-4][j.get_x()-2] = '\\';

	grid[h-3][j.get_x()] = '|';
	grid[h-2][j.get_x()] = '|';
	grid[h-1][j.get_x()] = '|';
	grid[h-1][j.get_x()+1] = '\\';
}

void Scene::convert_player_l(std::vector<std::string>& grid, int x, int w, Joueur &j, int jump) {
	int new_x = (x * WIDTH_SCENE) / w;
	j.set_x(new_x);
	Scene::replace_player_l(grid, j, jump);

	/*

	 <o>
	\_|
	  |
	  |
	 /|

	*/
}

std::vector<std::string> Scene::convert_scene(std::string scene, Joueur &j1, Joueur &j2) {
	std::vector<std::string> lines (HEIGH_SCENE, "");
	for(int i=0; i<HEIGH_SCENE; ++i) {
        std::string line = "";
        for(int j=0; j<WIDTH_SCENE; ++j) {
            line += " ";
        }
        lines[i] = line;
    }
	
	for(int i=0; i<scene.length(); ++i) {
		switch (scene[i]) {
			case '1':
				if(j1.get_dir() == 0) Scene::convert_player_r(lines, i, scene.length(), j1, 1);
				else Scene::convert_player_l(lines, i, scene.length(), j1, 1);
				break;
			case '2':
				if(j2.get_dir() == 0) Scene::convert_player_r(lines, i, scene.length(), j2, 1);
				else Scene::convert_player_l(lines, i, scene.length(), j2, 1);
				break;
			case 'x':
				Scene::convert_block(lines, i, scene.length());
				break;
			default: break;
		}
	
	}
	return lines;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void Scene::remove_last_position(std::vector<std::string>& grid, Joueur jo) {
	for(int i=1; i<HEIGH_SCENE; ++i) {
		for(int j=-2; j<3; ++j) {
			if(grid[HEIGH_SCENE-i][jo.get_x()+j] != 'X') {
				grid[HEIGH_SCENE-i][jo.get_x()+j] = ' ';
			}
		}
	}

}