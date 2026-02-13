#include <iostream>
#include <fstream>
#include <random>

int randomChar() {
	int min = 1;
	int max = 27;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	// Сгенерировать случайное число в диапазоне [min, max]
	return distrib(gen);
}

char encode_char(char letter, int position) {
	int encode_letter = (letter + position) % 27;
	if (encode_letter > 9) {
		encode_letter += 55;
	}
	else {
		encode_letter += 48;
	}
	return (char)encode_letter;
}

int to_num(char letter) {
	if (letter == ' ') {
		return 27;
	}
	return letter - 96;
}

void generateInputFile() {
	std::ofstream file("INPUT.txt", std::ios::out | std::ios::trunc);
	for (int i = 1; i <= 256; i++) {
		int letter = randomChar();
		file.put((char)encode_char(letter, i));
	}
	file.close();
}

void sample_file() {
	std::string wrd = " deco ding";
	std::ofstream out_file("INPUT.txt", std::ios::out, std::ios::trunc);
	int position = 1;
	for (int i = 1; i <= 10; i++) {
		for (int c = 0; c < wrd.length(); c++) {
			out_file << encode_char(to_num(wrd.at(c)), position++);
		}
	}
	out_file.close();
}

void sample_file_2() {
	std::string wrd = "from fairest creatures we desire increasethat thereby beautys rose might never diebut as the riper should by time deceasehis tender heir might bear his memorybut thou contracted to thine own bright eyesfeedst";
	std::ofstream out_file("INPUT.txt", std::ios::out, std::ios::trunc);
	int position = 1;
	for (int c = 0; c < wrd.length(); c++) {
		out_file << encode_char(to_num(wrd.at(c)), position++);
	}
	out_file.close();
}

int decode_char(int encoded_char, int position) {
	int decoded_char;
	int k = 0;
	if (encoded_char >= 65) {
		encoded_char -= 55;
	} 
	else {
		encoded_char -= 48;
	}
	do {
		decoded_char = 27 * k + encoded_char - position;
		k++;
	} while (decoded_char > 27 || decoded_char <= 0);
	return decoded_char;
}

int main() {
	//generateInputFile();
	//sample_file();
	sample_file_2();
	std::ifstream in_file("INPUT.txt");
	char ch;
	std::ofstream out_file("OUTPUT.txt", std::ios::out | std::ios::trunc);
	int position = 1;
	while (in_file.get(ch)) {
		int decoded_char = decode_char((int)ch, position++);
		if (decoded_char == 27) {
			decoded_char = 32;
		}
		else {
			decoded_char += 96;
		}
		out_file.put(decoded_char);
	}
	out_file.close();
	in_file.close();
	std::cout << "DONE!";
}

//test
//L7MO

// 576J9FLF

// F9JBCF9MK03B102ABJDHB1037C2448L5J4F70E45QMB5P3JE5QK511DN7ON6A24O28OJKOKNA91Q9MGFBH4CL2PN0JB31419HGANP9Q91OMICC4AH9OO920NA0Q87M4JL71K3914KE95I6IK5IK01FCOA7ND5P2OJP7483LEQJ912DK4B7B9L4AKJ3OLC7G057M2C2PB2NE2MB86748PMOFDGCK51AI8MK7F3H0B4FQL75007H5PBJB86P61CIGE
