
#include "HashManager.h"
#include "Vowels.h"
#include "CountAsciiHash.h"
#include "CountConsonantHash.h"

int main() {
    HashManager hashes;
    hashes["count_vowels"] = new CountVowelsHash();
    hashes["count_consonant"] = new CountConsonantHash();
    hashes["count_ascii"] = new CountAsciiHash();
   // hashes["easy_ascii"] = new EasyHash();

    hashes.print_hashes("Did you ever hear the tragedy of Darth Plagueis the Wise?");
}