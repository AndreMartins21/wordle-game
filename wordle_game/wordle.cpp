#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>


using namespace std;


class WordleGame {
    private:
        int num_of_words;
        vector<string> list_of_words;
        vector<char> list_of_wrong_letters;
        string key, key_guess;
        int N_MAX_ATTEMPTS = 5;
        const string filename_txt = "palavras.txt";
        
    public:
        void run_game(){
            get_list_of_words_from_txt();
            get_word_key();

            int n_attempts = 0;

            while (true){
                if (check_player_won()){
                    cout << "GANHOU!" << endl;
                    break;
                }

                if (n_attempts >= N_MAX_ATTEMPTS){
                    cout << "PERDEU! " << key << endl;
                    break;
                }

                get_input_key_guess();

                handle_input_key_guess();
                
                n_attempts++;
            }
        }

        int get_list_of_words_from_txt(){
            ifstream file(filename_txt);

            if (!file.is_open()){
                cerr << "Error opening file 'palavras.txt'!" << endl;
                return -1;
            }

            string line;
            while (getline(file, line)){
                list_of_words.push_back(line);
            }

            // Casting the first line to int and remove it from vector
            num_of_words = stoi(list_of_words[0]);
            list_of_words.erase(list_of_words.begin());
            
            return 1;
        }

        string get_word_key(){
            int idx_key;

            do {
                cout << "/> Type a number between 1 and " << num_of_words << ": ";
                cin >> idx_key;
            } while (idx_key < 1 || idx_key > num_of_words);
        
            key = list_of_words[idx_key-1];
            
            return key;
        }

        bool check_player_won(){
            return key_guess == key ? true : false;
        }

        string get_input_key_guess(){
            cout << "/> Choose a word with 5 letters: ";
            cin >> key_guess;

            // Convert string to upper case:
            for (char& c : key_guess) {
                c = toupper(c);
            }

            return key_guess;
        }

        void handle_input_key_guess(){
            
            for (char letter : key_guess){
                // If the program finds the letter
                if (letter_is_in_string(key, letter)){
                    if (key.find(letter) == key_guess.find(letter)){
                        cout << letter;
                    } else {
                        cout << (char) tolower(letter);                        
                    }
                } else {
                    add_letter_to_list_of_wrong_letters(letter);
                    cout << "*";
                }
            }

            print_list_of_wrong_letters();
        }

        void add_letter_to_list_of_wrong_letters(const char letter) {
            // if letter not in list_of_wrong_letters => add 
            if (
                std::find(list_of_wrong_letters.begin(), list_of_wrong_letters.end(), letter) == list_of_wrong_letters.end()
            ) {
                list_of_wrong_letters.push_back(letter);
            }
        }

        bool letter_is_in_string(const string str, const char letter){
            return str.find(letter) == string::npos ? false : true;
        }

        void print_list_of_wrong_letters(){
            cout << " (";
            for (const char& letter : list_of_wrong_letters) {
                cout << letter;
            }

            cout << ")" << endl;
        }

};

int main(){
    
    WordleGame wordle_game = WordleGame();
    
    wordle_game.run_game();

    return 0;
}