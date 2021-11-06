//Задача №2817. Стильная одежда (2)

//Глеб обожает шоппинг. Как-то раз он загорелся идеей подобрать себе кепку, майку, штаны и ботинки так, чтобы выглядеть в них максимально стильно. В понимании Глеба стильность одежды тем больше, чем меньше разница в цвете элементов его одежды.

//В наличии имеется N1 кепок, N2 маек, N3 штанов и N4 пар ботинок (1 ≤ Ni ≤ 100 000). Про каждый элемент одежды известен его цвет (целое число от 1 до 100 000). Комплект одежды — это одна кепка, майка, штаны и одна пара ботинок. Каждый комплект характеризуется максимальной разницей между любыми двумя его элементами. Помогите Глебу выбрать максимально стильный комплект, то есть комплект с минимальной разницей цветов.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    
    int n1;
    std::cin >> n1;
    std::vector<int> a1(n1);
    for(int i = 0; i < n1; i++){
        std::cin >> a1[i];
    }
    
    int n2;
    std::cin >> n2;
    std::vector<int> a2(n2);
    for(int i = 0; i < n2; i++){
        std::cin >> a2[i];
    }
    
    int n3;
    std::cin >> n3;
    std::vector<int> a3(n3);
    for(int i = 0; i < n3; i++){
        std::cin >> a3[i];
    }
    
    int n4;
    std::cin >> n4;
    std::vector<int> a4(n4);
    for(int i = 0; i < n4; i++){
        std::cin >> a4[i];
    }
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    sort(a4.begin(), a4.end());
    
    int m = min(min(a1[0],a2[0]), min(a3[0],a4[0]));
    int mm = max(max(a1[0],a2[0]), max(a3[0],a4[0]));
    int diff = abs(mm - m);
    
    int min1 = i1, min2 = i2, min3 = i3, min4 = i4;
    
    while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4) {
        int m = min(min(a1[i1],a2[i2]), min(a3[i3],a4[i4]));
        int mm = max(max(a1[i1],a2[i2]), max(a3[i3],a4[i4]));
        int diff2 = abs(mm - m);
        
        if (diff2 < diff){
            diff = diff2;
            min1 = i1;
            min2 = i2;
            min3 = i3;
            min4 = i4;
        }
        
        if (diff2 < 1){
            break;
        }
        
        while (m == a1[i1]) {
            i1++;
        }
        
        while (m == a2[i2]) {
            i2++;
        }
        
        while (m == a3[i3]) {
            i3++;
        }
        
        while (m == a4[i4]) {
            i4++;
        }
    }
    
    std::cout << a1[min1] << " " << a2[min2] << " " << a3[min3] << " " << a4[min4] << endl;
}
