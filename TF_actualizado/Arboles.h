#pragma once
#include <string>

using namespace std;

template <typename T>
class TreeNode {
public:
    T* key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T* _key) {
        key = _key;
        left = right = nullptr;
    }
    T* retornarDatos() {
        return key;
    }
};

template <typename T>
class BST {
private:
    TreeNode<T>* root;
    int contador;
    T* t;
public:
    BST() {
        root = nullptr;
    }
    bool insertacion(T* key) {
        return insert(root, key);
    }
    /*
    bool insert(TreeNode<T>*& node, T* key) {
        if (node == nullptr) {
            node = new TreeNode<T>(key);
            return true;
        }
        if (key->GetYear() < node->key->GetYear()) {
            return insert(node->left, key);
        }
        else if (key->GetYear() == node->key->GetYear()){
            if (key->GetMonth() < node->key->GetMonth()) {
                return insert(node->left, key);
            }
            else if (key->GetMonth() == node->key->GetMonth()){
                if (key->GetDay() < node->key->GetDay()) {
                    return insert(node->left, key);
                }
                return insert(node->right, key);
            }
            return insert(node->right, key);
        }
        return insert(node->right, key);
    }
    */
    bool insert(TreeNode<T>*& node, T* key) {
        if (node == nullptr) {
            node = new TreeNode<T>(key);
            return true;
        }
        if (key->GetIdPlan() < node->key->GetIdPlan()) {
            return insert(node->left, key);
        }
        return insert(node->right, key);
    }
    void preorderdacion() {
        preorder(root);
    }
    void preorder(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        node->key->Show();
        preorder(node->left);
        preorder(node->right);
    }
    void inorderdacion(int id) {
        inorder(root, id);
    }
    void inorder(TreeNode<T>* node, int id) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, id);
        if (node->key->GetIdUser() == id) {
            node->key->Show();
            cout << endl << "------------------------------------------------------------" << endl;
        }
        inorder(node->right, id);
    }
    void counts() {
        contador = 0;
        countador(root);
    }
    void countador(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        countador(node->left);
        contador++;
        countador(node->right);
    }

    T* BuscarIndice(long id) {
        IndiceProcces(root, id);
        return t;
    }
    bool IndiceProcces(TreeNode<T>* node, long id) {
        if (node == nullptr) {
            return false;
        }
        else if (node->key->GetIdPlan() == id) {
            t = node->key;
            return true;
        }
        else if (node->key->GetIdPlan() > id) {
            IndiceProcces(node->left, id);
        }
        IndiceProcces(node->right, id);
    }

    TreeNode<T>* sucesor(TreeNode<T>* node) {
        TreeNode<T>* aux = node->right;
        while (aux && aux->left) {
            aux = aux->left;
        }
        return aux;
    }

    bool deleteNode(long id) {
        return deleterNode(root, id);
    }
    bool deleterNode(TreeNode<T>*& node, long id) {
        if (node == nullptr) {
            return false;
        }
        else if (node->key->GetIdPlan() > id) {
            return deleterNode(node->left, id);
        }
        else if (node->key->GetIdPlan() < id) {
            return deleterNode(node->right, id);
        }
        else {
            //caso 1:
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
                return true;
            }
            //caso 2:
            else if (node->left == nullptr) {
                TreeNode<T>* aux = node;
                node = node->right;
                delete aux;
                return true;
            }
            else if (node->right == nullptr) {
                TreeNode<T>* aux = node;
                node = node->left;
                delete aux;
                return true;
            }
            //caso 3:
            TreeNode<T>* siguiente = sucesor(node);
            node->key = siguiente->key;
            return deleterNode(root->right, siguiente->key->GetIdPlan());
        }
    }

    int GetCount() { return contador; }
};