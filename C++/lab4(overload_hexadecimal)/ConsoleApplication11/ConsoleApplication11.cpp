#include <iostream>
#include <vector>
#include <limits>
#define base 16  //Основание системы счисления
using namespace std;


class MyInt {  //Класс (объект) – инкпасулированная абстракция с четким протоколом доступа
private:
    bool sign; //Переменная, как бы содержащая знак, но типa bool
public:
    bool forException = false;    //Переменная для работы с ошибками и исключениями (дальше используется в методе обработки исключений try / catch)
    vector<int> a;                //Массив, где будет находиться число

    MyInt() {};    //Конструктор по умолчанию - без параметров

    MyInt(const vector<int>& vec, bool sign = true) {  //Конструктор класса, производящий инициализацию полей класса, у нас класс состоит из переменных - массива а и переменной типа bool - знак числа, их нужно проинициализировать с помощью конструктора
        a = vec;          
        this->sign = sign;
        clearZeros();        //Стирает незначащие нули, реализована ниже
    }

    MyInt(string s) {   //Конструктор класса, инициализирующий поле класса а, как строку (короче то же самое делает, что и предыдущий, только другим методом инициализирует)
        a = {};         //Пустой массив
        int i;
        if (s[0] == '-') {   //Если первый элемент строки - минус, то запомним, что знак - , и начинать будем с элемента строки с индексом 1
            sign = false;
            i = 1;
        }
        else {             //Если положительное, то начинаем с элемнта с индексом 0
            sign = true;
            i = 0;
        }


        for (; i < s.length(); i++) {     //Идём по строке, левая часть цикла пустая, потому что выше мы задаем индекс элемента, с которого начинаем записывать - если оно отрицательное, то с i=1, если неотр. , то с i=0
            if ((int)s[i] <= 57 && (int)s[i] >= 48) {   //Делаем приведение типа элемента строки к int - теперь рассмтриваем не символ, а его числовой код, от 48 до 57 в таблице ASCII идут коды цифр 0-9
                a.push_back(((int)s[i] - 48) % base);   //Если цифра, то вставляем элемент в конец вектора, увеличивая его размер на 1 элемент. Элемент равен, допустим ввели 1 - тогда (49 - 48) % 16 = 1 - вставляем 1, и это уже int.
            }
            else {

                a.push_back(((int)s[i] - 55) % base);  //Если не цифра (значит ABCDEF), то вот объяснить очень тяжело, там типо код символа 'A' = 65, каким-то образом там надо именно + 10 прибавить к этому коду, я чет не могу сообразить((
            }
        }
        clearZeros();    //Убирает незначащие нули - реализована ниже
    }


    ~MyInt() {};   //Деструктор - это специальный метод, который вызывается при удалении объекта. Как правило, деструктор используется для освобождения памяти, динамично выделенной под внутренние данные класса. 

    void clearZeros() {  //Функция - как метод класса, так как описана в public, то доступна за пределами класса.
        while (a[0] == 0 && a.size() > 1) { //Пока элемент с индексом 0 равен нулю, и размер массива больше одного
            a.erase(a.begin());             //Будем удалять первый элемент, УМЕНЬШАЯ размер массива, то есть, если удалим в первый раз, то a[0] станет СЛЕД. элемент, и если он = 0, то опять удалим и так далее, пока не дойдем до ненулевого
        }
    }

    void setSign(bool _sign) {  //Функция - как метод класса, так как описана в public, то доступна за пределами класса.
        sign = _sign;           //Инициализируем переменную - поле класса sign
    }

    operator string() {      //Перегрузка оператора вывода строки на экран (я не понимаю зачем так сделано, можно было сделать operator<< - то есть нормальную перегрузку оператора вывода, так как ее нет, то НЕЛЬЗЯ вывести числа в 16 ричной в main)
        if (forException) {     //Если переменная = true, значит было найдено исключение (ошибка), здесь это - деление на 0.
            return "Division by zero";
        }
        string s = "";
        if (!sign) {       //Если число отрицательное, то в строку закидываем минус 
            s += "-";
        }
        for (int i = 0; i < a.size(); i++) {

            if (a[i] < 10) {   //Если элемент массива (разряд числа) - цифра от 0 до 9 
                s += (char)a[i] + 48;    //То закидываем ее в строку, но теперь делаем опять приведение к типу char - то есть выводим именно символ - например в числе разряд = 3, мы в строку должны закинуть символ '3', но ее код = 51, поэтому прибавляем 48 - код символа '0'
            }
            else {
                s += (char)a[i] + 55;  //Если не цифра (значит ABCDEF), то вот объяснить очень тяжело, там типо код символа 'A' = 65, каким-то образом там надо именно + 10 прибавить к этому коду, я чет не могу сообразить((
            }
        }
        return s;      
    }

    long int toDecimal() {  //Функция - как метод класса - перевод в 10-чную сс (типо потом в main он выводит все и в 16-сс и в 10-сс)
        try {          //Как бы пробуем сделать, если нет ошибок(исключений) - то все норм, если будут ошибки, то чтобы прога не упала - мы должны это исключение правильно обработать
            long int s = 0;
            for (int i = 0; i < len(); i++) {  //Идем по сторке
                s += a[i] * (int)pow(base, len() - i - 1);  //Прибавляем к числу элемент , ну там типо как перевод обычный из 10-сс в 16-сс: 2012 = 2 * 16^3 + 0 * 16^2 + 1 * 16^1 + 2 * 16^0 (короче посмотри как переводится из десятичной в 16-сс число любое, все понятно станет)
            }
            if (isPositive())   //Вот тут как раз возвращает либо отрицательное, либо положительное
                return s;
            else
                return -s;
        }
        catch (exception& e) {  //Здесь правильно обработается исключение (ошибка) - здесь если число больше LONG_MAX, то прога бы упала, а так мы это искючение обработали и все норм
            return numeric_limits<long>::max();
        }
    }
    void operator=(MyInt a1) { //Перегрузка оператора присваивания - ну тут понятно че происходит, но по теории я тут проседаю, не могу четко сказать что отвечать (короче это оператор, реализованный как член класса, но как функция)
        a = a1.a;                //Типо мы объясняем, что значит одно число равно другому - если равны и массивы и знаки 
        sign = a1.isPositive();
    }

    bool operator==(MyInt rhs) { //Перегрузка оператора проверки на равенство, если равны, то вернет true, если нет - то false
        bool b;
        if (len() != rhs.len()) { //Если у них разная длина, значит не равны 
            return false;
        }
        for (int i = 0; i < len(); i++) {   //Сравнивает поэлементно два массива(числа)
            if (a[i] != rhs.a[i]) {   //Если хоть один элемент не равен, то не равны
                return false;
            }
        }
        return true; //Если никуда не попали, то они равны
    }

    void swap(MyInt& lhs, MyInt& rhs) { //Не знаю зачем, но это функция - обменивающая числа местами
        std::swap(lhs.a, rhs.a);
        std::swap(lhs.sign, rhs.sign);
    }

    void set2zero() {   //Походу превращает число в 0
        int l = len(); //len() - возвращает размер массива, в котором поразрядно храним число - ниже реализована
        for (int i = 0; i < l - 1; i++) {  //Просто проходит по массиву 
            a.pop_back();                 //И удаляет каждый элемнт с конца, но a[0] остается
        }
        a[0] = 0;                        
        sign = true;
    }

    bool isPositive() {  //Проверяет, какой знак у числа, переменная sign - возвращает true, если положительное число - false - если отрицательное
        return sign;
    }

    bool isZero() {   //Проверяет на равенство числа нулю
        return a.size() == 0 && a[0] == 0;
    }

    MyInt inv() {      //Возвращает число с обратным знаком - типо на -1 умножает
        MyInt c = MyInt(a, !sign);
        return c;
    }
    MyInt abs() {     //Возвращает модуль числа
        MyInt c = MyInt(a, sign);
        if (c.isPositive()) {
            return c;
        }
        else {
            return c.inv();
        }
    }
    int len() {   //Возвращает размер массива, в котором поразрядно храним число
        return a.size();
    }
    MyInt shiftRight(int k) {   
        MyInt c = MyInt(a, sign);
        for (int i = 0; i < k; i++) {
            c.a.pop_back();
        }
        return c;
    }
    MyInt shiftLeft(int k) {
        MyInt c = MyInt(a, sign);
        for (int i = 0; i < k; i++) {
            c.a.push_back(0);
        }
        return c;
    }

};   //КОНЕЦ ОПИСАНИЯ КЛАССА

bool operator>(MyInt lhs, MyInt rhs) {   //Перегрузка опертора больше(объясняем, что значит число в 16-сс больше другого), теперь мы в функции перегрузки передаем ДВА аргумента типа MyInt - rhs и lhs, потому что мы ЗА пределами класса
    if (lhs.isPositive() && !rhs.isPositive()) {    //Ну тут если одно положительное, второе отрицательное - то первое больше - значит true, дальше просто все случаи, когда мы говорим, что одно больше другого
        return true;
    }
    if (!lhs.isPositive() && rhs.isPositive()) {
        return false;
    }
    if (!lhs.isPositive() && !rhs.isPositive()) {
        return !(lhs > rhs);
    }
    if (lhs == rhs) {
        return false;
    }
    if (lhs.len() > rhs.len()) {
        return true;
    }
    if (rhs.len() > lhs.len()) {
        return false;
    }
    for (int i = 0; i < rhs.len(); i++) {
        if (lhs.a[i] > rhs.a[i]) {
            return true;
        }
        if (rhs.a[i] > lhs.a[i]) {
            return false;
        }
    }
}

bool operator>=(MyInt lhs, MyInt rhs) { //Все аналогично
    if (lhs == rhs) {
        return true;
    }
    return lhs > rhs;
}

bool operator<(MyInt lhs, MyInt rhs) { //Мы уже описали, что значит одно число больше другого, и что значит одно равно другому, отрицание оператора > и равенства ДАЕТ МЕНЬШЕ (<)
    if (lhs == rhs) {
        return false;
    }
    return !(lhs > rhs);
}

bool operator<=(MyInt lhs, MyInt rhs) { //Аналогично
    if (lhs == rhs) {
        return true;
    }
    return lhs < rhs;
}

bool operator!=(MyInt lhs, MyInt rhs) { //Аналогично
    return !(lhs == rhs);
}

MyInt sumPos(MyInt lhs, MyInt rhs) { //Описываем, что такое сумма двух положительных чисел (объетков типа MyInt)
    int buffer = 0;
    vector<int> sums = {};
    int leftl = lhs.len();
    int rightl = rhs.len();
    if (leftl > rightl) {
        for (int i = 0; i < leftl - rightl; i++) {
            rhs.a.insert(rhs.a.begin(), 0);
        }
    }
    if (leftl < rightl) {
        for (int i = 0; i < rightl - leftl; i++) {
            lhs.a.insert(lhs.a.begin(), 0);
        }
    }
    for (int i = lhs.len() - 1; i >= 0; i--) {
        sums.insert(sums.begin(), (lhs.a[i] + rhs.a[i] + buffer) % base);
        buffer = (lhs.a[i] + rhs.a[i] + buffer) / base;
    }
    if (buffer != 0) {
        sums.insert(sums.begin(), buffer);
    }
    MyInt ans = MyInt(sums, true);
    return ans;
}

MyInt difPos(MyInt lhs, MyInt rhs) { //Описываем, что такое разность двух положительных (объетков типа MyInt)
    if (rhs > lhs) {
        return difPos(rhs, lhs).inv();
    }
    else {
        vector<int> dif = {};
        int leftl = lhs.len();
        int rightl = rhs.len();
        MyInt lhscopy = lhs;
        if (leftl > rightl) {
            for (int i = 0; i < leftl - rightl; i++) {
                rhs.a.insert(rhs.a.begin(), 0);
            }
        }
        for (int i = leftl - 1; i >= 0; i--) {
            if (lhs.a[i] < rhs.a[i]) {
                int j = 0;
                while (true) {
                    j++;
                    if (lhs.a[i - j] != 0) {
                        lhs.a[i - j] = lhs.a[i - j] - 1;
                        break;
                    }
                    else {
                        lhs.a[i - j] = base - 1;

                    }
                }
                lhs.a[i] = base + lhs.a[i];
            }
            dif.insert(dif.begin(), lhs.a[i] - rhs.a[i]);
        }
        lhs = lhscopy;
        MyInt ans = MyInt(dif, true);
        return ans;
    }
}

MyInt operator+(MyInt lhs, MyInt rhs) {  //До этого описали, что такое сумма положительных, теперь можем наглядно перегрузить оператор +, используя в описании всех случаев - функции, которые сверху реализованы
    if (lhs.isPositive() && rhs.isPositive())
        return sumPos(lhs, rhs);

    if (!lhs.isPositive() && rhs.isPositive())
        return difPos(rhs, lhs.inv());

    if (lhs.isPositive() && !rhs.isPositive())
        return difPos(lhs, rhs.inv());

    if (!lhs.isPositive() && !rhs.isPositive())
        return sumPos(lhs.inv(), rhs.inv()).inv();
}

MyInt operator-(MyInt lhs, MyInt rhs) {   //До этого описали, что такое сумма положительных, теперь можем наглядно перегрузить оператор -, используя в описании всех случаев - функции, которые сверху реализованы
    if (lhs.isPositive() && rhs.isPositive())
        return difPos(lhs, rhs);

    if (!lhs.isPositive() && rhs.isPositive())
        return sumPos(rhs, lhs.inv()).inv();

    if (lhs.isPositive() && !rhs.isPositive())
        return sumPos(lhs, rhs.inv());

    if (!lhs.isPositive() && !rhs.isPositive())
        return difPos(lhs.inv(), rhs.inv()).inv();
}

MyInt shortMultiply(MyInt lhs, int k) {  
    int buffer = 0;
    for (int i = lhs.len() - 1; i >= 0; i--) {
        int bc = buffer;
        buffer = (bc + lhs.a[i] * k) / base;
        lhs.a[i] = (bc + lhs.a[i] * k) % base;
    }
    if (buffer != 0) {
        lhs.a.insert(lhs.a.begin(), buffer);
    }
    return lhs;
}

MyInt mulPos(MyInt lhs, MyInt rhs) { 
    lhs = lhs.abs();
    rhs = rhs.abs();
    if (rhs.len() == 1) {
        return shortMultiply(lhs, rhs.a[0]);
    }
    int modbase = rhs.a[rhs.len() - 1];
    if (modbase == 0) {
        return mulPos(lhs.shiftLeft(1), rhs.shiftRight(1));
    }
    else {
        rhs.a[rhs.len() - 1] = 0;
        MyInt c1 = mulPos(lhs, rhs);
        MyInt c2 = shortMultiply(lhs, modbase);
        return c1 + c2;
    }
}

MyInt operator*(MyInt lhs, MyInt rhs) {  //Описали умножение, используя функции выше для упрощения записи
    bool flag = (lhs.isPositive() && rhs.isPositive()) || (!lhs.isPositive() && !rhs.isPositive());
    MyInt ans = mulPos(lhs, rhs);
    ans.setSign(flag);
    ans.clearZeros();
    return ans;
}

MyInt operator/(MyInt lhs, MyInt rhs) { //Описали деление, используя функции выше для упрощения записи

    bool sign = (lhs.isPositive() && rhs.isPositive()) || (!lhs.isPositive() && !rhs.isPositive());
    lhs = lhs.abs();
    rhs = rhs.abs();
    vector<int> vec = { 0 };
    vector<int> ans = { 0 };
    MyInt d = MyInt(vec);
    for (int i = 0; i < lhs.len(); i++) {
        d.a.push_back(lhs.a[i]);
        d.clearZeros();
        if (d >= rhs) {
            int c = 0;
            while (c < base) {
                c++;
                if (shortMultiply(rhs, c) > d) {
                    break;
                }
            }
            ans.push_back(c - 1);
            d = d - shortMultiply(rhs, c - 1);
        }
    }
    MyInt answer = MyInt(ans, sign);
    if (rhs == MyInt("0")) {
        answer.forException = true;
    }
    return answer;
}

MyInt operator%(MyInt lhs, MyInt rhs) {  //Описали деление и умножение - теперь легко описать деление с остатком - используя то, что выше
    return lhs - (lhs / rhs) * rhs;
}

int main()
{
    string s;
    cout << "Enter a: ";
    cin >> s;   //Ввели ШЕСТНАДЦАТЕРИЧНОЕ  число
    MyInt a = MyInt(s); //Создаем переменную типа нашего класса, инициализируем как строку,  
    cout << "\nEnter b: ";
    cin >> s;   //Ввели ШЕСТНАДЦАТЕРИЧНОЕ число
    MyInt b = MyInt(s);  //Создаем переменную типа нашего класса, инициализируем как строку, (там был конструктор, который как строку инициализирует) 
    cout << endl << "a: " << a.toDecimal() << ", b: " << b.toDecimal();  //Вот так как нет перегрузки оператора обычного вывода, можно вывести только в десятеричной 
    cout << "\na+b: " << (string)(a + b) << "    " << (a + b).toDecimal();  //Ну тут типо выводим результаты всех этих перегруженных операций, сначала в 16-ричной сс, потом в 10-сс
    cout << "\na-b: " << (string)(a - b) << "    " << (a - b).toDecimal();
    cout << "\na*b: " << (string)(a * b) << "    " << (a * b).toDecimal();
    try {               //Пробуем делить, если разделим на 0, выведется исключение в catch
        cout << "\na/b: " << (string)(a / b);
    }
    catch (exception e) {    
        cout << "Division by zero";
    }
    cout << "\na%b: " << (string)(a % b) << "    " << (a % b).toDecimal();
}

