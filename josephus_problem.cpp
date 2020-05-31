#include <iostream>
#include <vector>
using namespace std;


int Iosip(vector <int> a, unsigned int n, unsigned int m) {
    for (unsigned int i = a.size(); i > 1; i--) { //задаємо цикл, який виконується n-1 разів
        if (m > a.size()) {
            m = a.size() % m - 1; //m не більше n => (люди в круза, використовуємо операцію %)
        }
        a.erase(a.begin() + m - 1);//=> послідовно стираємо
        for (unsigned int i = 0; i < m - 1; i++) {
            a.push_back(a[i]); // для зручності перші елементи до m продублюємо в кінець вектора
        }
        a.erase(a.begin(), a.begin() + m - 1);//стираємо все до m.
    }
    return a[0]; //відповідь буде збергігатися в a[0].
}

int main() {
    bool is = false;
    vector <int> a;//для зручності я використовую ветор, а не масив
    unsigned int n, m;
    cin >> n >> m; // 
    for (unsigned int i = 1; i <= n; i++) { // заповнюємо вектор числами від 1 до n
        a.push_back(i);
    }
    cout << Iosip(a, n, m) << " ["; // перша чатина задачі на цьому завершена.
    //підставимо всі можливі m в виді k і зафіксуємо k при Iosip(a, n, k) = 1
    for (unsigned int k = 2; (k <= n) && (is == false); k++) {// m>1 => k = 2
        if (Iosip(a, n, k) == 1) { // якщо находимо таке k, що виживає перший номер,
            is = true;//виключаємо цикл
            cout << k << "]";// виводимо k
        }
    }
    if (is == false) { // якщо такого k не найшлося
        cout << "Not exist]";
    }

}
