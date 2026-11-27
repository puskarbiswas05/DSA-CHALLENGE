/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        return NULL;
        Node *headcopy=new Node(0);
        Node *tailcopy=headcopy;
        Node *temp=head;
        while(temp!=NULL){
            tailcopy->next=new Node(temp->val);
            tailcopy=tailcopy->next;
            temp=temp->next;
        }
        tailcopy=headcopy;
        headcopy=headcopy->next;
        delete tailcopy;
        tailcopy=headcopy;
        temp=head;
        unordered_map<Node*,Node*>m;
        while(temp!=NULL){
            m[temp]=tailcopy;
            temp=temp->next;
            tailcopy=tailcopy->next;
        }
        temp=head;
        tailcopy=headcopy;
        while(temp!=NULL){
            if(temp->random!=NULL){
            tailcopy->random=m[temp->random];
        }
            temp=temp->next;
            tailcopy=tailcopy->next;
        }
        return headcopy;
    }
};