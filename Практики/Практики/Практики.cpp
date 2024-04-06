// 09.01.24 практика 1
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//class Person
//{
//public:
//	char* name = new char[200];
//	int age = 34;
//
//	Person() {
//		strcpy_s(name, 200, "Alexander");
//	}
//	~Person() {
//		delete[] name;
//	}
//};
//
//class SpaceMinibus {
//public:
//	int passengers_count;
//	Person** passengers = nullptr;
//
//	SpaceMinibus()
//	{
//		cout << "C-TOR WITHOUT PARAMS FOR MINIBUS\n";
//		passengers_count = 0;
//		passengers = new Person * [passengers_count];
//	}
//
//	void TakeBus(Person person)
//	{
//		passengers_count++;
//		passengers = new Person * [passengers_count];
//		passengers[0] = new Person(person);
//	}
//
//	void FlyToTheFreedom24()
//	{
//		cout << "Yeah, Alex is free!\n";
//	}
//	~SpaceMinibus()
//	{
//		delete[] passengers;
//	}
//};
//
//int main()
//{
//	Person Alex;
//	SpaceMinibus bus;
//	bus.TakeBus(Alex);
//	bus.FlyToTheFreedom24();
//}

// 18.01.24 praktika
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class String
//{
//    char* text = nullptr;
//    unsigned int length = 0;
//    unsigned int capacity = 80;
//
//public:
//    String() : String("", 80) {}
//
//    String(const char* text) : String(text, 80) {}
//
//    String(unsigned int capacity) : String("", capacity) {}
//
//    String(const String& original) : String(original.text, original.capacity) {}
//
//    String(const char* text, unsigned int capacity)
//    {
//        SetString(text, capacity);
//    }
//
//private:
//    void SetString(const char* text, unsigned int capacity = 80)
//    {
//        length = strlen(text);
//
//        if (length == 0)
//        {
//            this->capacity = 80;
//        }
//        else
//        {
//            if (capacity > length * 10)
//                capacity = length * 10;
//
//            if (capacity <= length)
//                capacity = length + 1;
//
//            this->capacity = capacity;
//        }
//
//        if (this->text != nullptr)
//            delete[] this->text;
//
//        this->text = new char[this->capacity];
//        strcpy_s(this->text, length + 1, text);
//    }
//
//public:
//    ~String()
//    {
//        if (text != nullptr)
//        {
//            delete[] text;
//            text = nullptr;
//        }
//    }
//
//    String GetString() const
//    {
//        String copy = text;
//        return copy;
//    }
//
//    int GetLength() const
//    {
//        return length;
//    }
//
//    int GetCapacity() const
//    {
//        return capacity;
//    }
//
//    void Clear()
//    {
//        text[0] = '\0';
//        length = 0;
//    }
//
//    void ShrinkToFit()
//    {
//        if (length + 1 <= capacity)
//        {
//            return;
//        }
//
//        capacity = length + 1;
//        char* temp = new char[capacity];
//        strcpy_s(temp, capacity, text);
//        delete[] text;
//        text = temp;
//    }
//
//    void Print() const
//    {
//        cout << "Text: " << text << "\n";
//        cout << "Length: " << length << "\n";
//        cout << "Capacity: " << capacity << "\n";
//    }
//
//    char GetCharAt(unsigned int index) const
//    {
//        if (index >= length)
//        {
//            throw std::out_of_range("Index out of bounds");
//        }
//        return text[index];
//    }
//};
//
//int main()
//{
//    String s("Alexander", 50);
//    try {
//        cout << s.GetCharAt(0) << "\n";
//        cout << s.GetCharAt(1) << "\n";
//        cout << s.GetCharAt(3) << "\n";
//    }
//    catch (const std::out_of_range& e) {
//        cout << "Error: " << e.what() << "\n";
//    }
//    return 0;
//}

//25.01.24
//#include <iostream>
//using namespace std;
//
//class Fraction
//{
//    int numerator;
//    int denominator;
//
//public:
//    Fraction();
//    Fraction(int numerator, int denominator);
//    Fraction(int value);
//
//    double GetDecimal() const;
//    void Print() const;
//    void PrintDecimal() const;
//
//    int GetNumerator() const {
//        return numerator;
//    }
//
//    int GetDenominator() const {
//        return denominator;
//    }
//
//    void SetNumerator(int numerator) {
//        this->numerator = numerator;
//    }
//
//    void SetDenominator(int denominator) {
//        if (denominator == 0) denominator = 1;
//        this->denominator = denominator;
//    }
//
//    Fraction Sum(const Fraction& another) const;
//
//    bool operator<(const Fraction& another) const;
//    bool operator>=(const Fraction& another) const;
//    bool operator<=(const Fraction& another) const;
//    bool operator==(const Fraction& another) const;
//    bool operator!=(const Fraction& another) const;
//};
//
//Fraction::Fraction() : Fraction(0, 1)
//{
//    cout << "DEFAULT C-TOR!\n";
//}
//
//Fraction::Fraction(int value)
//{
//    cout << "конструктор преобразования\n";
//    numerator = value;
//    denominator = 1;
//}
//
//Fraction::Fraction(int numerator, int denominator)
//{
//    cout << "PARAM CTOR!\n";
//    this->numerator = numerator;
//    if (denominator == 0) denominator = 1;
//    this->denominator = denominator;
//}
//
//double Fraction::GetDecimal() const
//{
//    return (double)numerator / denominator;
//}
//
//void Fraction::Print() const
//{
//    cout << numerator << "/" << denominator << "\n";
//}
//
//void Fraction::PrintDecimal() const
//{
//    cout << GetDecimal() << "\n";
//}
//
//Fraction Fraction::Sum(const Fraction& another) const
//{
//    Fraction temp;
//    temp.numerator = numerator * another.denominator + another.numerator * denominator;
//    temp.denominator = denominator * another.denominator;
//    return temp;
//}
//
//bool Fraction::operator<(const Fraction& another) const
//{
//    return GetDecimal() < another.GetDecimal();
//}
//
//bool Fraction::operator>=(const Fraction& another) const
//{
//    return !(*this < another);
//}
//
//bool Fraction::operator<=(const Fraction& another) const
//{
//    return !(another < *this);
//}
//
//bool Fraction::operator==(const Fraction& another) const
//{
//    return GetDecimal() == another.GetDecimal();
//}
//
//bool Fraction::operator!=(const Fraction& another) const
//{
//    return !(*this == another);
//}
//
//int main()
//{
//    setlocale(0, "");
//
//    Fraction a(1, 2);
//    Fraction b(3, 4);
//
//    if (a >= b) {
//        cout << "A >= B\n";
//    }
//    else {
//        cout << "A < B\n";
//    }
//
//    if (a <= b) {
//        cout << "A <= B\n";
//    }
//    else {
//        cout << "A > B\n";
//    }
//
//    if (a == b) {
//        cout << "A == B\n";
//    }
//    else {
//        cout << "A != B\n";
//    }
//
//    if (a != b) {
//        cout << "A != B\n";
//    }
//    else {
//        cout << "A == B\n";
//    }
//
//    return 0;
//}

// 30.01.24
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//class Date {
//	unsigned short day;
//	unsigned short month;
//	long long year;
//public:
//	Date() : Date(30, 1, 2024) {}
//	Date(unsigned short day, unsigned short month, long long year);
//	Date(unsigned short day, unsigned short month) : Date(day, month, 2005) {}
//	void PrintDate() const;
//	void SetDay(unsigned short day);
//	unsigned short GetDay() const;
//	void SetMonth(unsigned short month);
//	unsigned short GetMonth() const;
//	void SetYear(long long year);
//	long long GetYear() const;
//};
//
//Date::Date(unsigned short day, unsigned short month, long long year) {
//	SetDay(day);
//	SetMonth(month);
//	SetYear(year);
//}
//
//void Date::PrintDate() const {
//	cout << day << "." << month << "." << year << "\n";
//}
//
//void Date::SetDay(unsigned short day) {
//	if (day == 0 || day > 31) throw "ERROR!!! The day must be from 0 to 31 !!!";
//	this->day = day;
//}
//
//unsigned short Date::GetDay() const {
//	return day;
//}
//
//void Date::SetMonth(unsigned short month) {
//	if (month == 0 || month > 12) throw "ERROR!!! The day must be from 1 to 12 !!!";
//	this->month = month;
//}
//
//unsigned short Date::GetMonth() const {
//	return month;
//}
//
//void Date::SetYear(long long year) {
//	this->year = year;
//}
//
//long long Date::GetYear() const {
//	return year;
//}
//
//istream& operator >> (const istream& i, Date& d)
//{
//	cout << "Введите число месяца (1-31): ";
//	unsigned short answer;
//	cin >> answer;
//	d.SetDay(answer);
//	cout << "Введите номер месяца (1-12): ";
//	cin >> answer;
//	d.SetMonth(answer);
//	cout << "Введите номер года (любой): ";
//	long long answer2;
//	cin >> answer2;
//	d.SetYear(answer2);
//	return cin;
//}
//
//ostream& operator << (const ostream& o, const Date& d)
//{
//	d.PrintDate();
//	return cout;
//}
//
//int main() {
//	setlocale(0, "");
//
//	Date d, a, b;
//	cin >> d >> a >> b;
//	cout << d << a << b << "\n";
//}

// 01.02.24
//#include <iostream>
//#include <ctime>
//#include <string>
//#include <sstream>
//using namespace std;
//
//class Date {
//    unsigned short day;
//    unsigned short month;
//    long long year;
//public:
//    Date() : Date(30, 1, 2024) {}
//    Date(unsigned short day, unsigned short month, long long year);
//    Date(unsigned short day, unsigned short month) : Date(day, month, 2005) {}
//    void PrintDate() const;
//    void SetDay(unsigned short day);
//    unsigned short GetDay() const;
//    void SetMonth(unsigned short month);
//    unsigned short GetMonth() const;
//    void SetYear(long long year);
//    long long GetYear() const;
//
//    operator string() const;
//};
//
//Date::Date(unsigned short day, unsigned short month, long long year) {
//    SetDay(day);
//    SetMonth(month);
//    SetYear(year);
//}
//
//void Date::PrintDate() const {
//    cout << day << "." << month << "." << year << "\n";
//}
//
//void Date::SetDay(unsigned short day) {
//    if (day == 0 || day > 31) throw "ERROR!!! The day must be from 0 to 31 !!!";
//    this->day = day;
//}
//
//unsigned short Date::GetDay() const {
//    return day;
//}
//
//void Date::SetMonth(unsigned short month) {
//    if (month == 0 || month > 12) throw "ERROR!!! The day must be from 1 to 12 !!!";
//    this->month = month;
//}
//
//unsigned short Date::GetMonth() const {
//    return month;
//}
//
//void Date::SetYear(long long year) {
//    this->year = year;
//}
//
//long long Date::GetYear() const {
//    return year;
//}
//
//Date::operator string() const {
//    stringstream ss;
//    ss << day << "." << month << "." << year;
//    return ss.str();
//}
//
//int main() {
//    setlocale(0, "");
//
//    Date d(1, 2, 2024);
//    string s = d;
//    cout << "Date as string: " << s << "\n";
//
//    return 0;
//}

// 13.02.24 обе практики
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class SinglyLinkedList
//{
//public:
//    struct Node
//    {
//        int data = 0;
//        Node* next = nullptr;
//    };
//
//private:
//    Node* head = nullptr;
//    Node* tail = nullptr;
//    int count = 0;
//
//public:
//    void AddToHead(int data)
//    {
//        auto newElem = new Node;
//        newElem->data = data;
//        newElem->next = head;
//
//        if (head == nullptr)
//        {
//            tail = newElem;
//        }
//        head = newElem;
//        count++;
//    }
//
//    void AddToTail(int data)
//    {
//        auto newElem = new Node;
//        newElem->data = data;
//        if (tail == nullptr)
//        {
//            head = newElem;
//        }
//        else
//        {
//            tail->next = newElem;
//        }
//        tail = newElem;
//        count++;
//    }
//
//    void InsertInto(int data, int position)
//    {
//        if (position >= count)
//        {
//            AddToTail(data);
//            return;
//        }
//        else if (position <= 0)
//        {
//            AddToHead(data);
//            return;
//        }
//
//        Node* newElem = new Node;
//        newElem->data = data;
//        int i = 1;
//        Node* beforeNew = head;
//        while (i++ != position)
//        {
//            beforeNew = beforeNew->next;
//        }
//        newElem->next = beforeNew->next;
//        beforeNew->next = newElem;
//
//        count++;
//    }
//
//    void DeleteFromHead()
//    {
//        if (count == 0)
//        {
//            return;
//        }
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//        count--;
//        if (head == nullptr)
//        {
//            tail = nullptr;
//        }
//    }
//
//    void DeleteFromTail()
//    {
//        if (count == 0) {
//            return;
//        }
//        DeleteByIndex(count - 1);
//    }
//
//    void DeleteByIndex(int position)
//    {
//        if (position <= 0)
//        {
//            DeleteFromHead();
//            return;
//        }
//
//        if (position >= count)
//        {
//            position = count - 1;
//        }
//
//        int i = 1;
//        Node* beforeDel = head;
//        while (i++ != position)
//        {
//            beforeDel = beforeDel->next;
//        }
//        Node* sacrifice = beforeDel->next;
//        beforeDel->next = sacrifice->next;
//        delete sacrifice;
//        count--;
//        if (beforeDel->next == nullptr)
//        {
//            tail = beforeDel;
//        }
//    }
//
//    void Clear()
//    {
//        while (head != nullptr)
//        {
//            DeleteFromHead();
//        }
//    }
//
//    void Print() const
//    {
//        if (count == 0)
//        {
//            cout << "Empty list!\n";
//            return;
//        }
//        Node* current = head;
//        while (current != nullptr)
//        {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << "\n";
//    }
//
//    int GetCount() const
//    {
//        return count;
//    }
//
//    int IndexOf(int data) const
//    {
//        if (count == 0)
//        {
//            return -1;
//        }
//        Node* current = head;
//        int i = 0;
//        while (i < count)
//        {
//            if (data == current->data)
//            {
//                return i;
//            }
//            i++;
//            current = current->next;
//        }
//        return -1;
//    }
//
//    ~SinglyLinkedList() {
//        Clear();
//    }
//
//    SinglyLinkedList() {}
//
//    SinglyLinkedList(const SinglyLinkedList& original)
//    {
//        Node* current = original.head;
//        while (current != nullptr)
//        {
//            this->AddToTail(current->data);
//            current = current->next;
//        }
//    }
//
//    SinglyLinkedList& operator = (const SinglyLinkedList& original)
//    {
//        if (this == &original) return *this;
//
//        this->Clear();
//
//        Node* current = original.head;
//        while (current != nullptr)
//        {
//            this->AddToTail(current->data);
//            current = current->next;
//        }
//        return *this;
//    }
//
//    void SortAsc() {
//        if (count == 0 || count == 1) return;
//
//        vector<int> ar;
//        Node* current = head;
//        for (int i = 0; i < count; i++) {
//            ar.push_back(current->data);
//            current = current->next;
//        }
//        sort(ar.begin(), ar.end());
//
//        current = head;
//        for (int i = 0; i < count; i++) {
//            current->data = ar[i];
//            current = current->next;
//        }
//    }
//
//    void SortDesc() {
//        if (count == 0 || count == 1) return;
//
//        vector<int> ar;
//        Node* current = head;
//        for (int i = 0; i < count; i++) {
//            ar.push_back(current->data);
//            current = current->next;
//        }
//        sort(ar.begin(), ar.end(), greater<int>());
//
//        current = head;
//        for (int i = 0; i < count; i++) {
//            current->data = ar[i];
//            current = current->next;
//        }
//    }
//
//    void Reverse()
//    {
//        if (count <= 1) return;
//
//        Node* prev = nullptr;
//        Node* current = head;
//        Node* next = nullptr;
//
//        tail = head;
//
//        while (current != nullptr)
//        {
//            next = current->next;
//            current->next = prev;
//
//            prev = current;
//            current = next;
//        }
//
//        head = prev;
//    }
//};
//
//int main()
//{
//    SinglyLinkedList sll;
//
//    for (int i = 0; i < 5; i++)
//    {
//        sll.AddToTail(i * 10);
//    }
//
//    cout << "Original list:\n";
//    sll.Print();
//
//    cout << "\nReversed list:\n";
//    sll.Reverse();
//    sll.Print();
//
//    cout << "\nSorted in descending order:\n";
//    sll.SortDesc();
//    sll.Print();
//
//    return 0;
//}

//15.02.24 все практики
//#include <iostream>
//using namespace std;
//
//class Stack {
//private:
//    struct Node {
//        int data;
//        Node* next;
//        Node(int val) : data(val), next(nullptr) {}
//    };
//
//    Node* top;
//
//public:
//    Stack() : top(nullptr) {}
//
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//
//    bool isEmpty() const {
//        return top == nullptr;
//    }
//
//    void push(int val) {
//        Node* newNode = new Node(val);
//        newNode->next = top;
//        top = newNode;
//    }
//
//    int pop() {
//        if (isEmpty()) {
//            throw out_of_range("Stack is empty");
//        }
//        int val = top->data;
//        Node* temp = top;
//        top = top->next;
//        delete temp;
//        return val;
//    }
//
//    int peek() const {
//        if (isEmpty()) {
//            throw out_of_range("Stack is empty");
//        }
//        return top->data;
//    }
//
//    bool contains(int val) const {
//        Node* current = top;
//        while (current != nullptr) {
//            if (current->data == val) {
//                return true;
//            }
//            current = current->next;
//        }
//        return false;
//    }
//
//    void pushLessValue(int val) {
//        if (isEmpty() || val < top->data) {
//            push(val);
//        }
//    }
//
//    void pushUnique(int val) {
//        if (!contains(val)) {
//            push(val);
//        }
//    }
//};
//
//int main() {
//    Stack stack;
//    stack.push(5);
//    stack.push(10);
//    stack.push(15);
//    stack.push(20);
//
//    cout << "Peek: " << stack.peek() << "\n";
//
//    cout << "Contains 10: " << (stack.contains(10) ? "true" : "false") << "\n";
//    cout << "Contains 25: " << (stack.contains(25) ? "true" : "false") << "\n";
//
//    stack.pushLessValue(7);
//    stack.pushLessValue(12);
//    stack.pushLessValue(3);
//
//    cout << "Stack after PushLessValue: ";
//    while (!stack.isEmpty()) {
//        cout << stack.pop() << " ";
//    }
//    cout << "\n";
//
//    stack.pushUnique(15);
//    stack.pushUnique(25);
//    stack.pushUnique(15);
//
//    cout << "Stack after PushUnique: ";
//    while (!stack.isEmpty()) {
//        cout << stack.pop() << " ";
//    }
//    cout << "\n";
//
//    return 0;
//}

//29.02.24
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//void swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//void selectionSort(int arr[], int size) {
//    for (int pr = 0; pr < size; pr++) {
//        int minIndex = pr;
//        int minValue = arr[pr];
//
//        for (int j = pr + 1; j < size; j++) {
//            if (arr[j] < minValue) {
//                minIndex = j;
//                minValue = arr[j];
//            }
//        }
//        arr[minIndex] = arr[pr];
//        arr[pr] = minValue;
//    }
//}
//
//void bubbleSort(int arr[], int size) {
//    for (int pr = 0; pr < size; pr++) {
//        for (int k = size - 1; k > 0; k--) {
//            if (arr[k - 1] > arr[k]) {
//                swap(arr[k], arr[k - 1]);
//            }
//        }
//    }
//}
//
//void insertionSort(int arr[], int size) {
//    for (int pr = 0; pr < size; pr++) {
//        int value = arr[pr];
//        int index;
//
//        for (index = pr - 1; index >= 0 && arr[index] > value; index--) {
//            arr[index + 1] = arr[index];
//        }
//        arr[index + 1] = value;
//    }
//}
//
//void quickSort(int arr[], int start, int end) {
//    int L = start, R = end;
//    int M = arr[(start + end) / 2];
//
//    do {
//        while (arr[L] < M)
//            L++;
//
//        while (arr[R] > M)
//            R--;
//
//        if (L <= R) {
//            swap(arr[L], arr[R]);
//            L++;
//            R--;
//        }
//
//    } while (L <= R);
//
//    if (start < R)
//        quickSort(arr, start, R);
//
//    if (L < end)
//        quickSort(arr, L, end);
//}
//
//int main() {
//    const int size = 10;
//    int ar[size];
//
//    srand(time(0));
//    rand();
//
//    for (int i = 0; i < size; i++) {
//        ar[i] = rand() % 100;
//        cout << ar[i] << " ";
//    }
//    cout << "\n\n";
//
//    int choice;
//    cout << "Choose sorting method (1 - Selection, 2 - Bubble, 3 - Insertion, 4 - Quick): ";
//    cin >> choice;
//
//    switch (choice) {
//    case 1:
//        selectionSort(ar, size);
//        break;
//    case 2:
//        bubbleSort(ar, size);
//        break;
//    case 3:
//        insertionSort(ar, size);
//        break;
//    case 4:
//        quickSort(ar, 0, size - 1);
//        break;
//    default:
//        cout << "Invalid choice!";
//        return 1;
//    }
//
//    for (int i = 0; i < size; i++) {
//        cout << ar[i] << " ";
//    }
//    cout << "\n";
//
//    return 0;
//}

// 05.03.24

//Примеры агрегации

//Автомобиль и двигатель
//Библиотека и книги
//Студент и курсы

//Примеры композиции

//Автомобиль и колеса
//Дом и комнаты
//Часы и стрелки

// 07.03.24
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Visa {
//private:
//    string country;
//    string type;
//    string expiryDate;
//
//public:
//    Visa(const string& country, const string& type, const string& expiryDate)
//        : country(country), type(type), expiryDate(expiryDate) {}
//
//    void printVisaDetails() const {
//        cout << "Country: " << country << ", Type: " << type << ", Expiry Date: " << expiryDate << endl;
//    }
//};
//
//class Passport {
//private:
//    string fullName;
//    string passportNumber;
//    string nationality;
//    string dateOfBirth;
//    string expiryDate;
//
//public:
//    Passport(const string& fullName, const string& passportNumber, const string& nationality,
//        const string& dateOfBirth, const string& expiryDate)
//        : fullName(fullName), passportNumber(passportNumber), nationality(nationality),
//        dateOfBirth(dateOfBirth), expiryDate(expiryDate) {}
//
//    void printPassportDetails() const {
//        cout << "Full Name: " << fullName << ", Passport Number: " << passportNumber
//            << ", Nationality: " << nationality << ", Date of Birth: " << dateOfBirth
//            << ", Expiry Date: " << expiryDate << "\n";
//    }
//};
//
//class ForeignPassport : public Passport {
//private:
//    vector<Visa> visas;
//
//public:
//
//    ForeignPassport(const string& fullName, const string& passportNumber, const string& nationality,
//        const string& dateOfBirth, const string& expiryDate)
//        : Passport(fullName, passportNumber, nationality, dateOfBirth, expiryDate) {}
//
//    void addVisa(const string& country, const string& type, const string& expiryDate) {
//        visas.emplace_back(country, type, expiryDate);
//    }
//
//    void printForeignPassportDetails() const {
//        printPassportDetails();
//        cout << "Visas:" << "\n";
//        for (const auto& visa : visas) {
//            visa.printVisaDetails();
//        }
//    }
//};
//
//int main() {
//    ForeignPassport foreignPassport("John Doe", "AB123456", "Ukrainian", "01.01.1980", "01.01.2030");
//    foreignPassport.addVisa("USA", "Tourist", "01.01.2023");
//    foreignPassport.addVisa("UK", "Business", "01.01.2024");
//
//    foreignPassport.printForeignPassportDetails();
//
//    return 0;
//}

//12.03.24
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class BaseClass {
//private:
//    string name;
//    string surname;
//    int age;
//
//public:
//    BaseClass(const string& name, const string& surname, int age)
//        : name(name), surname(surname), age(age) {}
//};
//
//class DerivedClass : public BaseClass {
//private:
//    string position;
//
//public:
//    DerivedClass(const string& name, const string& surname, int age, const string& position)
//        : BaseClass(name, surname, age), position(position) {}
//};
//
//int main() {
//    DerivedClass c("Александр", "Загоруйко", 35, "кормилец котов");
//    return 0;
//}

//19.03.24
//#include <iostream>
//using namespace std;
//
//class Wings {
//public:
//    double size;
//
//    void Print() {
//        cout << "I'm a Wigs\n";
//    }
//};
//
//class Horns {
//public:
//    double size;
//
//    void Print() {
//        cout << "I'm a Horn\n";
//    }
//};
//
//class Horse {
//public:
//    string color;
//    string count_of_legs;
//    bool tail;
//
//    void Print() {
//        cout << "I'm a horse\n";
//    }
//};
//
//class Unicorn : public Horse, public Horns {
//public:
//    int horn_length;
//
//    void Print() {
//        cout << "I'm a Unicorn\n";
//    }
//};
//
//class Pegas : public Horse, public Wings {
//public:
//    bool wings;
//
//    void Print() {
//        cout << "I'm a Pegas\n";
//    }
//};
//
//class Alicorn : public Unicorn, public Wings {
//
//public:
//    double size; // 8    112?
//    void Print() {
//        cout << "I'm an Alicorn\n";
//    }
//};
//
//int main()
//{
//    Alicorn a;
//    a.Print();
//
//    a.Wings::size = 10;
//    a.Horns::size = 20;
//    a.size = 30;
//    a.Print();
//
//    cout << sizeof(Alicorn) << "\n";
//}

//26.03.24
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Animal {
//public:
//    virtual void sleep() const { cout << "Animal is sleeping\n"; }
//    virtual void eat() const { cout << "Animal is eating\n"; }
//    virtual void makeSound() const { cout << "Animal is making sound\n"; }
//};
//
//class Dog : public Animal {
//public:
//    void makeSound() const override { cout << "Woof! Woof!\n"; }
//};
//
//class Cat : public Animal {
//public:
//    void makeSound() const override { cout << "Meow! Meow!\n"; }
//};
//
//class Cow : public Animal {
//public:
//    void makeSound() const override { cout << "Moo! Moo!\n"; }
//};
//
//int main() {
//    vector<Animal*> animals = {
//        new Dog(), new Cat(), new Cow(), new Dog(), new Cat(),
//        new Cow(), new Dog(), new Cat(), new Cow(), new Dog()
//    };
//
//    for (Animal* animal : animals) {
//        animal->makeSound();
//    }
//
//    for (Animal* animal : animals) {
//        delete animal;
//    }
//
//    return 0;
//}