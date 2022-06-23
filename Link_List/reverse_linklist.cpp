#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 10000000000000000
#define input freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define endl "\n"
#define INT_M 1000000007
#define SET(n) cout << fixed << setprecision(n)
#define fo(i, j, n) for (ll i = j; i < n; ++i)
#define dbg(x) cout << #x << ": " << x << endl;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
const int N = 1e5 + 10;
// link-list basic code
// based on pointer
class node {
public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert_Tail(node* &head, int val)
{

    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}
void insert_Head(node* &head, int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}
void display(node* head) {
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}
bool search(node* head, int key)
{
    while (head != NULL)
    {
        if (head->data == key) return true;
        head = head->next;
    }
    return false;
}
void delete_node(node* &head, int key)
{
    if (search(head, key))
    {
        if (head->data == key)
        {
            node* to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }
        node* tmp = head;
        while ((head->next)->data != key)
        {
            head = head->next;
        }
        node* to_delete = head->next;
        head->next = head->next->next;
        head = tmp;
        delete to_delete;
    }
    else cout << "NODE doesn't exist." << endl;
}
void reverse_list(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* nxt =  head->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
    }
    head = prev;
}
void best()
{
    node* head = NULL;
    insert_Tail(head, 1);
    insert_Tail(head, 2);
    // insert_Tail(head, 3);
    // insert_Tail(head, 4);
    // insert_Head(head, 0);
    display(head);
    reverse_list(head);
    display(head);
}
int main()
{
    fast;
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        best();
    }
}