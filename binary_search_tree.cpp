#include <iostream> 
using namespace std;

/*

                    7

                  6     8

                  


*/

struct node 
{
    int info;
    node *right, *left;
};

class BST 
{
    node  *temp, *temp1 , *temp2;

    public:
    node *root;

    BST()
    {
        root = NULL;
        temp = NULL;
        temp1 = NULL;
        temp2 = NULL;

    }

    void insert(node * , int);
    void search(node *, int);
    void del(node * , int);
    void inorder(node *);
    void in_successor(node *);
    void in_predecessor(node *, int);


};

void BST::inorder( node *r)
{
    if(r != NULL)
    {
        inorder(r->left);
        cout<<r -> info<<" ";
        inorder(r -> right);
    }
    return;

}



void BST::insert(node *r , int key)
{
    

  if(root == NULL)
  {
      root = new node;

      root -> info = key;
      root -> left = NULL;
      root -> right = NULL;

      return;

  }

 if(key < r -> info && r-> left == NULL)
 {
    r -> left = new node;
    r -> left -> info = key;
    r-> left -> right = NULL;
    r -> left -> left = NULL;
    return;

 }



 if(key > r->info && r -> right == NULL)
 {
    r -> right = new node;
    r -> right -> info = key;
    r ->right -> left = NULL;
    r -> right -> right = NULL;
    return;


 }

  if(key < r -> info)
  {
      insert(r -> left , key);
  }

  if(key > r -> info)
  {
      insert(r -> right ,key);
  }


   

    
}

void BST::in_successor(node *r)
{
    if(temp -> right != NULL)
    {
        r = temp -> right;

    }

    while( r -> left -> left != NULL)
    {
        r = r -> left;
    }
    temp2 = r;
    return;
}


void BST::del(node *r, int key)
{
    
        temp = r;
    
  
    
    
    //leaf node

   

    if(temp -> left != NULL )
    {
        if(temp -> left -> info == key)
        {
            if((temp -> left -> left == NULL) && temp -> left -> right == NULL)
            {
                delete temp -> left;
                temp -> left = NULL;
                
                return;

            }
        }
        
    }

    if(temp -> right != NULL)
    {
        if(temp -> right -> info == key)
        {
            if(temp ->right -> left == NULL && temp -> right -> right == NULL)
            {
                delete temp -> right ;
                temp -> right = NULL;
                return;

            }
        }
    }


    //one child


    // if(temp -> left -> info == key)
    // {
    //     if(temp -> left -> left != NULL && temp -> left -> right == NULL)
    //     {
    //         temp1 = temp -> left ;
    //         temp -> left = temp1-> left;
    //         delete temp1;
    //         temp1 = NULL;
    //         return;
            

    //     }

    //     if(temp -> left -> left == NULL && temp -> left -> right != NULL)
    //     {
    //         temp1 = temp -> left;
    //         temp -> left = temp1 -> right;
    //         delete temp1;
    //         temp1 = NULL;
    //         return;


    //     }
    // }

    // if(temp -> right -> info == key)
    // {
    //     if(temp -> right -> left != NULL && temp -> right -> right == NULL)
    //     {
    //         temp1 = temp -> right;
    //         temp -> right = temp1 -> left;
    //         delete temp1;
    //         temp1 = NULL;
    //         return;

    //     }

    //     if(temp -> right -> left == NULL && temp -> right -> right != NULL)
    //     {
    //         temp1 = temp -> right;
    //         temp -> right = temp1 -> right;
    //         delete temp1;
    //         temp1 = NULL;
    //         return;

    //     }
    // }

    // two children
 

    // if(temp -> left -> info == key)
    // {
    //     if(temp -> left -> left != NULL && temp -> left -> right != NULL)
    //     {
    //         temp1 = temp-> left;
    //         temp2 = temp1;

    //         //finding inorder successor
    //         if(temp2 -> right != NULL)
    //         {
    //             temp2 = temp2 -> right;
    //         }
    //         while(temp2 -> left != NULL)
    //         {
    //             temp2 = temp2 -> left;
    //         }

    //         temp1 -> info = temp2 -> info;
    //         del(temp1 -> right,temp2->info);



            


    //     }

       

    // }


    // if(temp -> right -> info == key)
    // {
    //     if(temp -> right -> left != NULL && temp -> right -> right != NULL)
    //     {
    //         temp1 = temp-> right;
    //         temp2 = temp1;

    //         //finding inorder successor
    //         if(temp2 -> right != NULL)
    //         {
    //             temp2 = temp2 -> right;
    //         }
    //         while(temp2 -> left != NULL)
    //         {
    //             temp2 = temp2 -> left;
    //         }

    //         temp1 -> info = temp2 -> info;
    //         del(temp1 -> right,temp2->info);
            

    //     }

    // }

    if(key < temp->info)
    {
        del(temp -> left,key);
        return;
    }

    if(key > temp->info)
    {
        del(temp -> right,key);
        return;
    }







    
    
   

    



}

int main()
{
    BST obj;

    obj.insert(obj.root, 4);
    obj.insert(obj.root, 2);
    obj.insert(obj.root, 8);
    obj.insert(obj.root, 1);
    obj.insert(obj.root, 3);
    obj.insert(obj.root, 10);
    obj.insert(obj.root, 9);
    
    

    obj.inorder(obj.root);
    obj.del(obj.root, 1);
    cout<<endl;
    obj.inorder(obj.root);
    

    obj.del(obj.root, 3);
    cout<<endl;
    obj.inorder(obj.root);

    obj.del(obj.root, 9);
    cout<<endl;
    obj.inorder(obj.root);
    

    // obj.del(obj.root, 20);
    // cout<<endl;
    // obj.inorder(obj.root);

    // obj.del(obj.root, 15);
    // cout<<endl;
    // obj.inorder(obj.root);

    obj.del(obj.root, 10);
    cout<<endl;
    obj.inorder(obj.root);

    obj.del(obj.root, 8);
    cout<<endl;
    obj.inorder(obj.root);

    obj.del(obj.root, 2);
    cout<<endl;
    obj.inorder(obj.root);


    

}