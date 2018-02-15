#include <iostream>
#include <chrono>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <clocale>
using namespace std;

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i]]-1]=ar[i];
         cr[ar[i]]-=1;
      }
  }

void selection(int *ar, int siz){
    int i, j, mx, nmx;
    for(i = 0; i < siz-1; i++){
        mx=ar[i];
        nmx=i;
        for(j = i+1; j < siz; j++){
            if (ar[j]<mx){
                mx=ar[j];
                nmx=j;
            }
        }
        ar[nmx]=ar[i];
        ar[i]=mx;
     }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    int rotat[21];
    cout << "Input size: ";
    cin >> n;
    int *mass=new int [n];
    int *out=new int [n];
    for (int j=0;j<n;j++)
        mass[j]=0+rand()%20;

    //Ввывод сгенерированного массива на экран
    /*for (int j=0;j<n;j++)
        cout << mass[j] << " ";*/

    clock_t start2 = clock();
    auto begin = chrono::steady_clock::now();
    radix(mass,out,rotat,20,n);
    clock_t end2 = clock();
    auto end = chrono::steady_clock::now();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);

    //подсчет времени сортировки выбором
    /*clock_t start1 = clock();
    selection(mass, n);
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;*/

    //ввывод на экран отсортированных массивов
    /*for (int j=0;j<n;j++)
        cout << out[j] << " ";
    for (int j=0;j<n;j++)
        cout << mass[j] << " ";*/

    //ввывод на экран времени сортировки выбором
    //cout << "Time selection with Time.h: " << (int)(seconds1*1000) << " ms\n";

    cout << "Time radix with Chrono: " << elapsed_ms.count() << " ms\n";
    cout << "Time radix with Time.h: " << (int)(seconds2*1000) << " ms\n";
}
