#include <iostream>
#include <stack>
#include <vector>
#include <regex>
#include <string>

//#include "cola.h"

using namespace std;

const int NUM_GENERACIONES = 500;
const int MaxH= 3;
const int NUM_INICIAL_ARBOLES = 10;
const int NUM_TAM = 21;
const float pc = 0.9; //probabilidad de hacer crossover
const float pr = 0.1; //probabilidad de hacer reproduccion
const float pm = 0; //probabilidad de hacer mutacion


float calcularArbol(char a[], int j)
{
    //cout << sizeof(a) << endl;
    stack<char> pila;

    for (int i = 0; i < j; i++)
    {
        if (a[i] <= 9)
            cout << "Entra " << +a[i] << endl;
        else
            cout << "Entra " << a[i]  << endl;

        if (pila.empty()) //si es vacia solo mete a la cola
        {
            pila.push(a[i]);
            cout << "mete " << a[i] << endl;
        }
        else
        {
            char val = a[i]; //saber el que entra y el que debe meter en la cola
            char temp = pila.top(); //saber quien esta a la cabeza


            cout << "   val " << +val << " temp " << +temp << endl;

            while ((temp < 42) && (val < 42))
            {
                pila.pop(); //saca el valor de la cabaza, el siguiente es el operador
                char op = pila.top();
                pila.pop();

                switch (op)
                {
                    //hace los calculos
                    case '+':
                    {
                        char temp1 = temp + val;
                        cout << "   Calcula " << +temp << " + " << +val << " = " << +temp1 << endl;
                        val = temp1;
                    }
                        break;
                    case '-':
                    {
                        char temp1 = temp - val;
                        cout << "   Calcula " << +temp << " - " << +val << " = " << +temp1<< endl;
                        val = temp1;
                    }
                        break;
                    case '*':
                    {
                        char temp1 = temp * val;
                        cout << "   Calcula " << +temp << " * " << +val << " = " << +temp1 << endl;
                        val = temp1;
                    }
                        break;
                    case '/':
                    {
                        char temp1 = temp / val;
                        cout << "   Calcula " << +temp << " / " << +val << " = " << +temp1 << endl;
                        val = temp1;
                    }
                }
                //si el tope de la pila no es operador continua la ejecucion del arbol hasta el proximo operador
                temp = pila.top();
                cout << "   val " << +val << " temp " << +temp << endl;
            }
            cout << "Despues de while " << endl;
            pila.push(val);
            if (val <= 30)
                cout << "Mete " << +val << endl;
            else
                cout << "Mete " << val  << endl;
        }

    }
    return 0;
}

int randNum(int min, int max)
//the parameters must be min = 3, max = 3;
{
    int x = rand() % min +  max;
    return x;
}

char rOperador()
{
    char op;
    int temp = rand() % 4; //Random de 0 a 3
    switch (temp)
    {
        //Saber cual operacion corresponde
        case 0:
            op = '+';
            break;
        case 1:
            op = '-';
            break;
        case 2:
            op = '*';
            break;
        case 3:
            op = '/';
            break;
    }

    return op;
}

bool rExpande()
{
    return rand() % 2;
}

//funcion que calcula un valor aleatorio
char rValor ()
{
    //Por el momento lo hace de 1 a 9
    int a = rand() % 9 + 1;
    char temp = (char)a;

    return temp;
}

float fitness (char arbol[]){
    float total = 0;
    const float tau = 0.02;
    return total;
}


void crossover(vector<char> arbol1, vector<char> arbol2){
    vector<char> frag1;
    vector<char> frag2;
    int indice1 = 0;
    int indice2 = 0;
    regex r("\\d");
    //obtiene los fragmentos de los arboles usando un numero random menos el indice 0(raiz)
    int rand1 = (rand() % (arbol1.size() - 1)) + 1;
    int rand2 = (rand() % (arbol2.size() - 1)) + 1;
    if (arbol1[rand1] == '+' || arbol1[rand1] == '-' || arbol1[rand1] == '*' || arbol1[rand1] == '/'){
        bool terminado = false;
        indice1 = rand1 + 1;
        //si el indice es un operador el fragmento obtiene el sub-arbol hasta el final
        while (!terminado){
            string s(1, arbol1[indice1]);
            string a(1, arbol1[indice1+1]);
            if (regex_search(s, r) && regex_search(a, r)){
                terminado = true;
            }

            indice1++;
        }
        std::vector<char>::const_iterator first = arbol1.begin() + rand1;
        std::vector<char>::const_iterator last = arbol1.begin() + indice1 + 1;
        vector<char> newVec(first, last);
        frag1.swap(newVec);
    }
    else {
        frag1.push_back(arbol1.at(rand1));
    }
    if (arbol2[rand2] == '+' || arbol2[rand2] == '-' || arbol2[rand2] ==  '*' || arbol2[rand2] == '/'){
        bool terminado = false;
        indice2 = rand2 + 1;
        //si el indice es un operador el fragmento obtiene el sub-arbol hasta el final
        while (!terminado){
            string s(1, arbol2[indice2]);
            string a(1, arbol2[indice2+1]);
            if (regex_search(s, r) && regex_search(a, r)){
                terminado = true;
            }
            indice2++;
        }
        std::vector<char>::const_iterator first = arbol2.begin() + rand2;
        std::vector<char>::const_iterator last = arbol2.begin() + indice2 + 1;
        vector<char> newVec(first, last);
        frag2.swap(newVec);
    }
    else {
        frag2.push_back(arbol2.at(rand2));
    }
    for(int i = 0; i < frag1.size(); i++){
        cout<<frag1[i];
    }
    cout<<endl;
    for(int i = 0; i < frag2.size(); i++){
        cout<<frag2[i];
    }
    cout<<endl;

    for(int i = 0; i < arbol1.size(); i++){
        cout << arbol1[i];
    }
    cout<<endl;

    for(int i = 0; i < arbol2.size(); i++){
        cout << arbol2[i];
    }
    cout<<endl;

    //empezar el cambio de subarboles
    //eliminar la porcion que se quiere cambiar
    if(frag1.size() > 1){
        arbol1.erase(arbol1.begin()+rand1, arbol1.begin()+indice1+1);
    }
    else{
        arbol1.erase(arbol1.begin()+rand1);
    }
    if(frag2.size() > 1){
        arbol2.erase(arbol2.begin()+rand2, arbol2.begin()+indice2+1);
    }
    else{
        arbol2.erase(arbol2.begin()+rand2);
    }

    //insertar los subarboles en la misma posicion donde se eliminaron
    arbol1.insert(arbol1.begin()+rand1, frag2.begin(), frag2.end());
    arbol2.insert(arbol2.begin()+rand2, frag1.begin(), frag1.end());

    for(int i = 0; i < arbol1.size(); i++){
        cout << arbol1[i];
    }
    cout<<endl;

    for(int i = 0; i < arbol2.size(); i++){
        cout << arbol2[i];
    }
    cout<<endl;




}

vector<char> expandir (vector<char> arbol, char x, int j)
{
    int i = j;
    while (arbol[i] != 0)
    {
        i++;
    }

    for (int k = i; k > j; k--)
    {
        arbol[k + 2] = arbol[k];
    }
    arbol[j] = 'X';
    arbol.insert(arbol.begin() + j + 1, x+1);
    arbol.insert(arbol.begin() + j + 2, x+1);
    return arbol;
}

vector<char> crearArbol(vector<char> arbol, int maxH)
{
    arbol.push_back('X');
    arbol.push_back(1);
    arbol.push_back(1);
    bool terminado = false;

    int i = 0;
    while (!terminado)
    {
        if (arbol[i] == 'X')
        {
            arbol[i] = rOperador(); //Sustituye la x por un operador
            i++;
        }
        else
        {
            if (arbol[i] < maxH) //Comprueba que el nivel del arbol no supere el limite
            {
                if (rExpande())
                {
                    arbol = expandir (arbol, arbol[i], i);
                }
                else
                {
                    arbol[i] = rValor();
                    i++;
                }
            }
            else
            {
                arbol[i] = rValor();
                i++;
            }
        }
        if (arbol[i] == 'X')
        {
            arbol[i] = rOperador(); //Sustituye la x por un operador
            i++;
        }
        int k = 0;
        /**
        while (arbol[k] != 0)
        {
            if (arbol[k] <= 9)
                cout << +arbol[k];
            else
                cout << arbol[k];

            k++;
        }

        cout<<endl;*/
        if(arbol[i] == 0){
            terminado = true;
        }

    }
    return arbol;
}

int main()
{

    //https://www.researchgate.net/publication/2742146_A_C_Implementation_of_Genetic_Programming

    cout << "Hello world!" << endl;

    const int NUM_ENTRADA = 12;
    const int NUM_SALIDA = 1;
    double entradas[NUM_ENTRADA] = {2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13};

    //Arbol ejemplo del profe
    vector<char> arbol;

    //se crea un array para guardar n arboles de la primera generacion
    vector<vector<char>> primGen;
    //inicializa el la primera generacion
    for (int i = 0; i < NUM_INICIAL_ARBOLES; i++){
        primGen.push_back(arbol);
    }


    //se crea la poblacion inicial de arboles
    for (int i=0; i<NUM_INICIAL_ARBOLES; i++){
        primGen[i] = crearArbol(primGen[i], MaxH);

        int j = 0;
        while (primGen[i][j] != 0)
        {
            if (primGen[i][j] <= 9)
                cout << +primGen[i][j];
            else
                cout << primGen[i][j];

            j++;
        }
        cout<<endl;
    }

    /**for (int gen = 0; gen < NUM_GENERACIONES; gen++){
        //test del rendimiento de cada uno (fitness)
        //desechar los perdedores (natural selection)
        //clonar uno de los sobrevivientes elegido al azar
        //crossover con el mejor
        //mutar
    }*/


    /*char arbol[21] = {'+', '*', '+', 2, 3, '-', 5, '*', '+', '-', 7, 8, 1, '+', 4, 6, '+', 1, '+', 9, 7};

    for (int i = 0; i < 21; i++)
    {
        if (arbol[i] <= 9)
            cout << +arbol[i];
        else
            cout << arbol[i];
    }

    cout << endl;*/

    //calcularArbol(arbol, 21);

    //crearArbol(arbol, MaxH);

    cout << endl;

    /**int i = 0;
    while (arbol[i] != 0)
    {
        if (arbol[i] <= 9)
            cout << +arbol[i];
        else
            cout << arbol[i];

        i++;
    }*/

    vector<char> t, y;
    t.push_back('+');
    t.push_back('*');
    t.push_back('9');
    t.push_back('/');
    t.push_back('5');
    t.push_back('8');
    t.push_back('-');
    t.push_back('9');
    t.push_back('-');
    t.push_back('2');
    t.push_back('7');
    y.push_back('+');
    y.push_back('*');
    y.push_back('9');
    y.push_back('3');
    y.push_back('-');
    y.push_back('9');
    y.push_back('-');
    y.push_back('4');
    y.push_back('*');
    y.push_back('1');
    y.push_back('7');
    crossover(t, y);




    return 0;
}
