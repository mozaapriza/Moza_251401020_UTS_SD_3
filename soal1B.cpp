#include <iostream>
using namespace std;

int main(){
    int nilai[5][4] = {
        {90, 90, 90, 90},
        {80, 85, 90, 87},
        {86, 90, 97, 92},
        {84, 93, 95, 91},
        {85, 90, 95, 92},
    };
    int rata;
    int tugas, kuis, uts, praktikum;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl; 
    }

    int max = nilai[0][0];
    cout << endl;
    for (int i = 0; i < 5; i++) {
        int totalNilai = 0; 
        for (int j = 0; j < 4; j++) {
            totalNilai += nilai[i][j]; 
            if (nilai[i][j] > max) {
                max = nilai[i][j];
            }
        }
        
        rata = float(totalNilai)/4;
        cout << "Rata-rata nilai mahasiswa ke-" << i << ": " << rata << endl;
    }


        cout << "Rata-rata tertinggi : " << max << endl;
    
}





































    