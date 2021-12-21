#include <iostream>

#include <utility>

#include <algorithm>

#include <random>

#include <chrono>

#include <ctime>

using namespace std;
////////////////////////Użytkowe//////////////////////////////////
template < typename T >
ostream & operator << (ostream & os,
                       const vector < T > & vec) {
    for (const auto & item: vec) {
        os << item << " ";
    }
    os << endl;
    return os;
}

template < typename T >
T * copy(T array[], long length) {
    auto resoult = new T[length];
    for (long i = 0; i < length; i++) {
        resoult[i] = array[i];
    }

    return resoult;
}
template < typename T >
vector < T > copy(vector < T > array) {
    vector < T > resoult;

    return resoult.copy(array);

}

template < typename T >
T * generate(long length) {
    default_random_engine engine;
    uniform_int_distribution < T > distribution(-10000, 10000);
    auto resoult = new T[length];
    for (long i = 0; i < length; i++) {
        resoult[i] = distribution(engine);
    }

    return resoult;
}
template < typename T >
vector < T > generate_vec(long length) {
    default_random_engine engine;
    uniform_int_distribution < T > distribution(-10000, 10000);
    auto resoult = vector < T > (length);
    for (long i = 0; i < length; i++) {
        resoult[i] = distribution(engine);
    }

    return resoult;
}

template < typename T >
void sout(T arr, long length) {
    for (long l = 0; l < length - 1; l++) {
        cout << arr[l] << " ";
    }
    cout << endl;

}

template < typename T >
void sout(vector < T > arr) {
    cout << arr;
}
////////////////////////////////////////////////SORTOWANIA////////////////////////////////
template < typename T >
long partition(T * A, long l, long r) {
    T x = A[l];
    long i = l, j = r + 1;

    for (;;) {
        do ++i; while (i <= r && A[i] < x);
        do --j; while (A[j] > x);
        if (i > j) {
            break;
        }
        swap(A[i], A[j]);
    }
    A[l] = A[j];
    A[j] = x;
    return j;
}
template < typename T >
long partition(vector < T > A, long l, long r) {
    T x = A[l];
    long i = l, j = r + 1;

    for (;;) {
        do ++i; while (i <= r && A[i] < x);
        do --j; while (A[j] > x);
        if (i > j) {
            break;
        }
        swap(A[i], A[j]);
    }
    A[l] = A[j];
    A[j] = x;
    return j;
}

template < typename T >
long partition2(T * A, long l, long r) {
    T x = A[r];
    long i = l - 1;
    for (; l < r; ++l) {
        if (A[l] <= x)
            swap(A[++i], A[l]);
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

template < typename T >
long partition2(vector < T > A, long l, long r) {
    T x = A[r];
    long i = l - 1;
    for (; l < r; ++l) {
        if (A[l] <= x)
            swap(A[++i], A[l]);
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
template < typename T >
long partition3(T* tab, long l, long r)
{
    if (r - l == 1)
    {
        if (tab[r] < tab[l])
        {
            swap(tab[r], tab[l]);
        }
        return l;
    }
    swap(tab[l + 1], tab[(l + r) >> 1]);

    if (tab[l + 1] > tab[r])
    {
        swap(tab[l + 1], tab[r]);
    }

    if (tab[l] > tab[r])
    {
        swap(tab[l], tab[r]);
    }

    if (tab[l + 1] > tab[l])
    {
        swap(tab[l + 1], tab[l]);
    }

    long x = tab[l];
    long i = l + 1, j = r;
    for (;;)
    {
        do ++i; while (tab[i] < x);
        do --j; while (tab[j] > x);
        if (i > j)
            break;
        swap(tab[i], tab[j]);
    }
    tab[l] = tab[j];
    tab[j] = x;
    return j;
}
template < typename T >
long partition3(vector<T> tab, long l, long r)
{
    if (r - l == 1)
    {
        if (tab[r] < tab[l])
        {
            swap(tab[r], tab[l]);
        }
        return l;
    }
    swap(tab[l + 1], tab[(l + r) >> 1]);

    if (tab[l + 1] > tab[r])
    {
        swap(tab[l + 1], tab[r]);
    }

    if (tab[l] > tab[r])
    {
        swap(tab[l], tab[r]);
    }

    if (tab[l + 1] > tab[l])
    {
        swap(tab[l + 1], tab[l]);
    }

    long x = tab[l];
    long i = l + 1, j = r;
    for (;;)
    {
        do ++i; while (tab[i] < x);
        do --j; while (tab[j] > x);
        if (i > j)
            break;
        swap(tab[i], tab[j]);
    }
    tab[l] = tab[j];
    tab[j] = x;
    return j;
}
template < typename T >
void quickSort(T arr[], long poczatek, long koniec) {
    if (poczatek < koniec) {
        long index = partition(arr, poczatek, koniec);
        quickSort(arr, poczatek, index - 1);
        quickSort(arr, index + 1, koniec);
    }
}
template < typename T >
void quickSort(vector < T > arr, long poczatek, long koniec) {
    if (poczatek < koniec) {
        long index = partition(arr, poczatek, koniec);
        quickSort(arr, poczatek, index - 1);
        quickSort(arr, index + 1, koniec);
    }
}

template < typename T >
void hybridQuickSort(T arr[], long poczatek, long koniec) {
    if (poczatek - koniec <= 10) {

        bubbleSort(arr, poczatek, koniec);
    } else
    if (poczatek < koniec) {
        long index = partition(arr, poczatek, koniec);
        hybridQuickSort(arr, poczatek, index - 1);
        hybridQuickSort(arr, index + 1, koniec);
    }
}
template < typename T >
void hybridQuickSort(vector < T > arr, long poczatek, long koniec) {
    if (poczatek - koniec <= 10) {

        bubbleSort(arr, poczatek, koniec);
    } else
    if (poczatek < koniec) {
        long index = partition(arr, poczatek, koniec);
        hybridQuickSort(arr, poczatek, index - 1);
        hybridQuickSort(arr, index + 1, koniec);
    }
}

template < typename T >
void bubbleSort(T arr[], long poczatek, long koniec) {
    int i, j, n = koniec;
    for (i = poczatek; i < n; i++)
        for (j = poczatek; j < n - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
template < typename T >
void bubbleSort(vector < T > arr, long poczatek, long koniec) {
    int i, j, n = koniec;
    for (i = poczatek; i < n; i++)
        for (j = poczatek; j < n - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

///////////////////// DRZEWA BST //////////////////////////////

struct drzewoBST {
    friend ostream &operator<<(ostream &os,  drzewoBST *&bst) {
        if (bst != nullptr) {
            os<<(bst -> left);
            os << bst -> val << " ";
            os<<(bst -> right);
        } else
            return os;
    }

    drzewoBST * up;
    drzewoBST * left;
    drzewoBST * right;
    int val;
    ///Wypisanie w porządku INORDER

};

///SPRAWDZONA
void addBstNode(drzewoBST * & root, int x, drzewoBST * lastRoot) {
    if (root == nullptr) {
        auto * w = new drzewoBST();
        w -> left = nullptr;
        w -> right = nullptr;
        w -> up = lastRoot;
        w -> val = x;

        root = w;

    } else {
        x>=root->val ? addBstNode(root -> right, x, root): addBstNode(root -> left, x, root);
    }
}

///SPRAWDZONA
void addBstNode(drzewoBST * & root, int x) {
    if (root == nullptr) {
        auto * w = new drzewoBST();
        w -> left = nullptr;
        w -> right = nullptr;
        w -> val = x;

        root = w;

    } else {
        x>=root->val ? addBstNode(root -> right, x, root): addBstNode(root -> left, x, root);

    }
}

///SPRAWDZONA
drzewoBST * znajdzMin(drzewoBST * root) {
    if (root != nullptr) {
        if (root -> left != nullptr)
            znajdzMin(root -> left);
        else return root;

    }

}
///SPRAWDZONA
drzewoBST * znajdzMax(drzewoBST * root) {
    if (root != nullptr) {
        if (root -> right != nullptr)
            znajdzMax(root -> right);
        else return root;

    }

}
///SPRAWDZONA
drzewoBST * nastepnik(drzewoBST * wezel) {
    drzewoBST * r;
    if (wezel) {
        if (wezel -> right) return znajdzMin(wezel -> right);
        else {
            r = wezel -> up;
            while (r && (wezel == r -> right)) {
                wezel = r;
                r = r -> up;
            }
            return r;

        }
    }
    return nullptr;
}
///SPRAWDZONA
drzewoBST * poprzednik(drzewoBST * wezel) {
    drzewoBST * r;
    if (wezel) {
        if (wezel -> left) return znajdzMin(wezel -> left);
        else {
            r = wezel -> up;
            while (r && (wezel == r -> left)) {
                wezel = r;
                r = r -> up;
            }
            return r;
        }

    }
    return nullptr;
}
///SPRAWDZONA
drzewoBST * szukaj(drzewoBST * root, int wartoscSzukana) {
    if (root != nullptr) {
        if (root -> val == wartoscSzukana) {
            return root;
        }
        if (wartoscSzukana > root -> val) {
            szukaj(root -> right, wartoscSzukana);
        } else szukaj(root -> left, wartoscSzukana);

        return nullptr;
    }

}
//funkcja usuwająca liście tego drzewa
void usunTo(drzewoBST * & root) {
    delete root;
    root = nullptr;
}
////Sprawdzona
void usunLiscie(drzewoBST * & root) {
    if (root != nullptr) {
        if (root -> left == nullptr && root -> right == nullptr) //gdy nie ma możliwości zejścia w dół
        {
            usunTo(root);
        } else {
            if (root -> left != nullptr) {
                usunLiscie(root -> left);
            }
            if (root -> right != nullptr) {
                usunLiscie(root -> right);
            }
        }

    }
}
///SPRAWDZONA
//inorder ( wyświetlanie )
void inorder(drzewoBST * & root) {
    if (root != nullptr) {
        inorder(root -> left);
        cout << root -> val << " ";
        inorder(root -> right);
    } else
        return;
}

void rotacjaWLewo(drzewoBST * & root, drzewoBST * & zamieniany) { //////////Nie przetestowana najprawdopodobniej TODO przetestować
    drzewoBST * b, * parent;
    b = zamieniany -> left;
    if (b == nullptr) {
        return;
    }
    parent = zamieniany -> up;
    zamieniany -> left = b -> right;
    if (zamieniany != nullptr) {
        zamieniany -> left -> up = zamieniany;
    }
    b -> right = zamieniany;
    b -> up = parent;
    zamieniany -> up = b;
    if (parent == nullptr) {
        root = b;
        return;
    }
    if (parent -> left == zamieniany) {
        parent -> left = b;
    } else parent -> right = b;

}

drzewoBST * usunElement(drzewoBST * &root, drzewoBST * x)
{
    drzewoBST * y = x->up, * z;

    if((x->left) && (x->right))
    {
        z = (rand() % 2) ? usunElement(root, poprzednik(x)) : usunElement(root, nastepnik(x));
        z->left = x->left;   if(z->left)  z->left->up  = z;
        z->right = x->right; if(z->right) z->right->up = z;
    }
    else z = (x->left) ? x->left : x->right;

    if(z) z->up = y;

    if(!y) root = z;
    else if(y->left == x) y->left = z; else y->right = z;

    return x;
}

//////////////////////////LISTY JEDNOSTRONNIE WIĄZANE /////////////////////////////////////////

struct Node {
    friend ostream & operator << (ostream & os, Node * node) {
        Node * p = node;
        while (p != nullptr) {
            os << p -> val << "->";
            p = p -> next;
        }
        os << "nullptr";
        return os;
    }

    int val;
    Node * next;

};
///SPRAWDZONA
void add(Node * & H, int value) {
    Node * p = new Node;
    p -> val = value;
    p -> next = H;
    H = p;

}
///SPRAWDZONA
void deleteFirst(Node * & H) {
    if (H != nullptr) {
        Node * p = H;
        H = H -> next;
        delete p;
    }
}
///SPRAWDZONA
void addNodeToEnd(Node * & head, Node * & tail, Node * e) {
    e -> next = nullptr;
    if (head == nullptr) {
        head = e;
        tail = e;
    } else {
        tail -> next = e;
        tail = e;
    }

}
///SPRAWDZONA
void swap(Node * & h) {
    if (h != nullptr && h -> next != nullptr) {
        Node * p = h;
        h = p -> next;
        p -> next = h -> next;
        h -> next = p;
    }
}

///SPRAWDZONA
void show_list_rek(Node * H) {
    if (H != nullptr) {
        cout << H -> val << "->";
        if (H -> next != nullptr)
            show_list_rek(H -> next);
        else cout << "nullptr";
    }
}

void swapSecond(Node * & head) {
    if (head && head -> next) {
        swap(head);
        Node * p = head -> next;
        while (p -> next && p -> next -> next) {
            swap(p -> next);
            p = p -> next -> next;
        }
    }
}
void deleteEven(Node * & H) {
    Node * head = nullptr;
    Node * p = H;
    int i = 0;
    while (p != nullptr) {
        if (i % 2 == 0)
            add(head, p -> val);
        i++;
        p = p -> next;
    }
    H = head;
}
///SPRAWDZONA
void multipleByTwo(Node * & h) {
    if (h != nullptr) {
        Node * head = nullptr;
        Node * p = h;
        while (p != nullptr) {

            add(head, p -> val);
            add(head, p -> val);

            p = p -> next;
        }
        show_list_rek(head);

    }
}
///SPRAWDZONA
void multipleByValueNumber(Node * & h) {
    if (h != nullptr) {
        Node * head = nullptr;
        Node * p = h;
        while (p != nullptr) {
            for (int i = 0; i < p -> val; i++) {
                add(head, p -> val);
            }
            p = p -> next;
        }

        h = head;
    }
}
void swapFirstWithSecond(Node * & head) {
    if (head != nullptr && head -> next != nullptr) {
        Node * forgotten = head;
        head = forgotten -> next;
        forgotten -> next = head -> next;
        head -> next = forgotten;
    }
}
void swapFirstWithLast(Node * & head) {
    if (head != nullptr) {
        Node * iterator = head;
        Node * headCopy = head;
        while (iterator != nullptr)
            iterator = iterator -> next;
        iterator -> next = head -> next;
        head -> next = iterator;

    }

}
///SPRAWDZONA
void swap2(Node * & H, Node * & replaced) {
    if (H != nullptr && replaced != nullptr) {
        Node * kopia_Glowy = H;
        Node * kopia_nastepnika_Glowy = kopia_Glowy -> next;
        kopia_Glowy = replaced;
        replaced -> next = kopia_nastepnika_Glowy;

    }
}

//void swap(Node *&H)
//{
//    if(H!= nullptr&&H->next!= nullptr)
//    {
//        Node *p=H;
//        H=p->next;
//        p->next=H->next;
//        H->next=p;
//    }
//}

void zamianaPierwszegoElementuZOstatnimNaLiscie(Node * & head) {
    if (head != nullptr) {
        Node * iterator = head;
        while (iterator -> next != nullptr) {
            cout << iterator -> val << " ";
            iterator = iterator -> next;

        }
        swap2(head, iterator -> next);

    }

}

void replaceXWithHisNext(Node * & head, int x) {
    if (head != nullptr && head -> next != nullptr) {
        Node * n = head;
        if (head -> val == x) {
            swap(head);
        } else {
            Node * p = head;
            while (p -> next != nullptr && p -> next -> val != x) {
                p = p -> next;
            }
            if (p -> next != nullptr && p -> next -> next != nullptr) {
                Node * e = p -> next;
                p -> next = e -> next;
                e -> next = e -> next -> next;
                p -> next -> next = e;
            }
        }
    }
}

void replaceXWithHisPervious(Node * & head, int x) {
    if (head != nullptr && head -> next != nullptr) {
        Node * n = head;
        while (n -> next != nullptr) {
            if (n -> next -> val == x) {
                cout << "\nZnalazlem" << endl;
                Node * forgotten = n;
                n = forgotten -> next;
                forgotten -> next = n -> next;
                n -> next = forgotten;
                cout << forgotten -> val << endl << n -> val << endl;
                break;
            } else n = n -> next;
        }
    }
}

void nextTryReplace(Node * & head, int x) {
    if (head != nullptr) {
        Node * p = head;
        if (head -> next == nullptr) {
            return;
        }
        if (head -> val == x) {
            return;
        } else
            while (p -> next != nullptr && p -> next -> val != x) {
                p = p -> next;
            }
        if (p -> next == nullptr) {
            return;
        } else {
            Node * copy = p;
            p -> next;
            p = p -> next;

        }

    }

}

void copy(Node * h) {
    if (h) {
        Node * h2 = nullptr;
        Node * p = h;
        while (p -> next != nullptr) {
            add(h2, p -> val);
            p = p -> next;
        }
        add(h2, p -> val);
        p -> next = h2;
        h2 = nullptr;
    }

}
///SPRAWDZONA
// zamienię miejscami całą tablicę
void reverse(Node * & h) {
    if (h != nullptr) {
        Node * p = h;
        Node * h2 = nullptr;
        while (p != nullptr) {
            add(h2, p -> val);
            p = p -> next;
        }
        h = h2;

    }
}
///SPRAWDZONA
//podziele na pół
void split(Node * & h) {
    Node * p = h;
    Node * copy = nullptr;
    int i = 0;
    while (p) // policz liczbę elementów
    {
        p = p -> next;
        i++;
    }
    i /= 2;
    while (i != 0) {
        i--;
        add(copy, h -> val);
        h = h -> next;
    }
    h = copy;

}
///SPRAWDZONA
void split(Node * & h, Node * & first, Node * & second) {
    Node * p = h;
    Node * iterator = h;
    first = nullptr;
    second = nullptr;
    int i = 0;
    while (p != nullptr) // policz liczbę elementów
    {
        p = p -> next;
        i++;
    }
    i /= 2;
    while (i != 0) {
        i--;
        add(first, iterator -> val);
        iterator = iterator -> next;
    }
    while (iterator != nullptr) {
        add(second, iterator -> val);
        iterator = iterator -> next;
    }

}



void swapValue( Node *a, Node *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}


void bubbleSort(Node *&head)
{
    int i;
    bool isSwapNessesary;
    struct Node *p;
    struct Node *lastStand = nullptr;
    if (head == nullptr)
        return;
    do
    {
        isSwapNessesary = false;
        p = head;

        while (p->next != lastStand)
        {
            if (p->val > p->next->val)
            {
                swapValue(p, p->next);
                isSwapNessesary = true;
            }
            p = p->next;
        }
        lastStand = p;
    }
    while (isSwapNessesary);
}

int calculateNumberOfElementsInLinkedList(Node *&head) {
    int licznik = 0;
    Node * p = head;
    while (p) // liczę ilość elementów w tablicy
    {
        licznik++;
        p = p -> next;

    }
    return licznik;
}

Node *jumpOverGapRange(int gap, int iterator, Node *tmpHead, Node *endingElement) {
    endingElement = tmpHead;
    iterator = 1;
    while (endingElement->next && iterator < gap) {
        endingElement = endingElement->next;
        iterator++;
    }
    return endingElement;
}
void sortowanieGrzebieniowe(Node*& head) {

    if (head) {
        if (head -> next == nullptr) ///jednoelementowa tablica
        {
            return;
        }
        else
        {
    int gap = calculateNumberOfElementsInLinkedList(head);
    int iterator = 0;
    bool replace = true;
    Node* before = nullptr;
    Node* tmp = nullptr;
    Node* tmpHead;
    Node* endingElement;
    Node* afterEndingElement = nullptr;

    while (gap > 1 || replace)
    {
        gap = gap * 10 / 13;
        if(gap==0)
        {
            gap=1;
        }
        endingElement =head;
        tmpHead = head;
        replace = false;
        if (gap == 1) {
            bubbleSort(head);
            continue;
        }
        while (tmpHead && endingElement->next->next) {

            endingElement = jumpOverGapRange(gap, iterator, tmpHead, endingElement);

            if (tmpHead->val > endingElement->next->val) {
                if (before == nullptr)
                {
                    tmp = endingElement->next;
                    afterEndingElement = tmp->next;
                    tmp->next = tmpHead->next;
                    endingElement->next = tmpHead;
                    tmpHead->next = afterEndingElement;

                    tmpHead = tmp;
                    head = tmp;
                }
                else
                {
                    tmp = endingElement->next;
                    afterEndingElement = tmp->next;
                    tmp->next = tmpHead->next;
                    endingElement->next = tmpHead;
                    before->next = tmp;
                    tmpHead->next = afterEndingElement;

                    tmpHead = tmp;
                }
            }
            before = tmpHead;
            tmpHead = tmpHead->next;
        }
    }
}}}

Node* sortedMerge(Node* a, Node* b)
{
    Node* result = nullptr;


    if (a == nullptr)
        return(b);
    else if (b == nullptr)
        return(a);

    if (a->val <= b->val)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return(result);
}

int main() {





    drzewoBST *drzewoBst= nullptr;

    addBstNode(drzewoBst,10);
    addBstNode(drzewoBst,5);
    addBstNode(drzewoBst,-3);
    addBstNode(drzewoBst,7);
    addBstNode(drzewoBst,22);
cout<<drzewoBst;
    std::cout << "Hello, World!" << std::endl;

    return 0;
}