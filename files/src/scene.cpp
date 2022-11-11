#include "../include/scene.h"

bool Scene::count_occurence(std::string scene) {
	int c1 = 0;
	int c2 = 0;
	for(int i=0; i<scene.length(); ++i) {
		if(scene[i] == '1') c1 += 1;
		if(scene[i] == '2') c2 += 1;
	}
	return (c1 == 1 && c2 ==1);
}

void Scene::load_a_scene(std::string filename) {
    std::ifstream in_stream;
	in_stream.open(filename);
	if(in_stream.is_open()) {
		std::string line;
		while(in_stream >> line) {
			std::cout << line << std::endl;
		}
		in_stream.close();
	}
}

bool Scene::is_valid_scene(std::string filename) {
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
			if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) return false;
		}
		in_stream.close();
		if(count_occurence(line)) return true;
	}
	return false;
}