
#include <iostream>
#include <string>

std::string inputString;
std::string outputString;

typedef enum{
    cipher_gaderypoluki = 0,
    cipher_koniecmatury,
    cipher_max,
}cipher_t;

std::string cipherNames[] = {
    "GA-DE-RY-PO-LU-KI",
    "KO-NI-EC-MA-TU-RY",
};

std::string encrypt(std::string stringToEncrypt, cipher_t cipher);

int main()
{
    cipher_t selectedCipher = cipher_gaderypoluki;

    std::cout << "Select cipher: " << std::endl;
    for(int i = 0; i < sizeof(cipherNames); i++){
        if(cipherNames[i] == "") break;
        std::cout << i << ") " << cipherNames[i] << std::endl;
    }
    std::string inputCipherString;
    std::cin >> inputCipherString;
    selectedCipher = (cipher_t)stoi(inputCipherString);
    if((selectedCipher < 0) || (selectedCipher >= cipher_max)){
        std::cout << "Wrong cipher selected" << std::endl;
        return -1;
    }

    std::cout << "Enter message to encrypt: " << std::endl;

    std::cin >> inputString;
    outputString = encrypt(inputString, selectedCipher);



    return 0;
}

std::string gaDeRyPoLuKi(std::string stringToEncrypt){
    std::string encryptedString;
    char c;
    std::cout << "Encrypting string " << stringToEncrypt << " with GA-DE-RY-PO-LU-KI" << std::endl;
    for(int i = 0; i < stringToEncrypt.length(); i++){
        c = stringToEncrypt[i];
        //std::cout << c;
        /* GA */
        switch(c){
        case 'G':
            encryptedString += 'A';
            break;
        case 'g':
            encryptedString += 'a';
            break;
        case 'A':
            encryptedString += 'G';
            break;
        case 'a':
            encryptedString += 'g';
            break;
        /* DE */
        case 'D':
            encryptedString += 'E';
            break;
        case 'd':
            encryptedString += 'e';
            break;
        case 'E':
            encryptedString += 'D';
            break;
        case 'e':
            encryptedString += 'd';
            break;
        /* RY */
        case 'R':
            encryptedString += 'Y';
            break;
        case 'r':
            encryptedString += 'y';
            break;
        case 'Y':
            encryptedString += 'R';
            break;
        case 'y':
            encryptedString += 'r';
            break;
        /* PO */
        case 'P':
            encryptedString += 'O';
            break;
        case 'p':
            encryptedString += 'o';
            break;
        case 'O':
            encryptedString += 'P';
            break;
        case 'o':
            encryptedString += 'p';
            break;
        /* LU */
        case 'L':
            encryptedString += 'U';
            break;
        case 'l':
            encryptedString += 'u';
            break;
        case 'U':
            encryptedString += 'L';
            break;
        case 'u':
            encryptedString += 'l';
            break;
        /* KI */
        case 'K':
            encryptedString += 'I';
            break;
        case 'k':
            encryptedString += 'i';
            break;
        case 'I':
            encryptedString += 'K';
            break;
        case 'i':
            encryptedString += 'k';
            break;

        default:
            encryptedString += c;
            break;

        }
    }




    std::cout << encryptedString << std::endl;
    return encryptedString;
}

std::string encrypt(std::string stringToEncrypt, cipher_t cipher){
    std::string encryptedString;
    switch(cipher){
    case cipher_gaderypoluki:
        encryptedString = gaDeRyPoLuKi(stringToEncrypt);
        break;

    default:
        std::cout << "This cipher is not supported yet" << std::endl;
    }

    //std::cout << encryptedString;
    return encryptedString;
}
