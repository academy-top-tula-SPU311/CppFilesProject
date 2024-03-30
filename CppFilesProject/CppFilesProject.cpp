#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    FILE* file = fopen("file01.dat", "w");
    fputs("100", file);
    fclose(file);

    //FILE* file = fopen("file01.dat", "r");

    //char ch = fgetc(file);
    //std::cout << ch << "\n";
    
    /*char* buffer = new char[1024];
    while (!feof(file))
    {
        fgets(buffer, 1024, file);
        std::cout << buffer << "\n";
    }*/
    
    /*FILE* file = fopen("file01.dat", "r+");

    char* buffer = new char[1024];
    fseek(file, 5, SEEK_SET);
    fgets(buffer, 1024, file);
    fclose(file);

    file = fopen("file01.dat", "r+");
    fseek(file, 5, SEEK_SET);
    fputs("*****", file);
    fputs(buffer, file);
    fclose(file);*/

    FILE* fileBin = fopen("file01.bin", "wb");
    int number = 1602781329;

    fwrite(&number, sizeof(int), 1, fileBin);
    fclose(fileBin);

    fileBin = fopen("file01.bin", "rb");
    int n;
    float x;

    fread(&x, sizeof(x), 1, fileBin);
    fseek(fileBin, 0, SEEK_SET);
    fread(&n, sizeof(n), 1, fileBin);

    std::cout << n << " " << x << "\n";
    fclose(fileBin);
}
