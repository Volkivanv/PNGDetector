#include <iostream>
#include <string>
#include <fstream>

bool extensionPNG(std::string filepath){
    std::string extension = filepath.substr(filepath.length()-3,filepath.length()-1);
    //std::cout << extension;
    return (extension == "png")||(extension == "PNG");
}

int main() {
    std::ifstream checkedFile;
    std::string filepath;
    std::cout<<"Please, input filepath!" << std::endl;
    getline(std::cin, filepath);

    checkedFile.open(filepath, std::ios::binary);
    if(checkedFile) {
        char buffer[4];
        bool isPNG = extensionPNG(filepath);

        checkedFile.read(buffer, sizeof(buffer));

        if((isPNG)&&((int)buffer[0] == -119)&&(buffer[1]=='P')&&(buffer[2]=='N')&&(buffer[3]=='G')){
            std::cout<<"This is PNG file!"<< std::endl;
        } else {
            std::cout<<"This is not PNG file!" << std::endl;
        }
        checkedFile.close();
    } else {
        std::cerr<<"File is not found!" << std::endl;
    }
    return 0;
}
