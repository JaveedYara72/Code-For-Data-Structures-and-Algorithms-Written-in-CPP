#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long
#define pb push_back

int last = 0;
int cliplen=0;

struct node{
    char c;
    struct node *n;
};

struct undo_h{
    int pos;
    char n;
    int seek;
    struct node r1, r2;
    int op;
};

// stack<undo_h> undos;
// stack<undo_h> redos;
// void delete_i(struct node** content, int pos){
//     struct node* t = *content;
//     int j=0;
//     while(j!=pos-1){
//         t = t->n;
//         j++;
//     }
//     undo_h *temp = new undo_h;
//     temp->n = t->n->c;
//     undos.pb()
//     t->n = t->n->n;  
// }

// void undo(struct node** content, struct node** clipboard, int* cursor){
//     // if(choices.size() <= 0){
//     //     cout<<"Inavlid\n";
//     //     return;
//     // }
//     // else{    
//     //     // if(choices.back() == 4){
//     //     //     *cursor = last_cur;
//     //     //     choices.pop_back();
//     //     // }
//     //     if(choices.back() == 3){
//     //         deletex(content, cursor, -1);
//     //         choices.pop_back();
//     //     }
//     // }
//     // node* N = stac.top().first;
//     int last_op = stac.top().second;
//     // if(last_op = 1) deletex() 
// }

void helptext(){
    cout<<"\n0: Exit\n1:Print\n2:Print Cursor position\n3:Insert element\n4:Seek Cursor\n5:Delete \n6:Copy \n7:PrintClip\n8:Cut\n9:Paste\n10:Undo\n11:Redo\n12:Save File\n13: Open File\n"<<endl;
}

void deletell(struct node** x){
    struct node* c = *x;
    struct node* n;

    while (c!=NULL)
    {
        n = c->n;
        free(c);
        c = n;
    }
    *x = NULL;
}

void insert(struct node** content, int *cursor){
    cout<<"Enter a char : ";
    char x;
    cin>>x;
    struct node* t = *content;
    struct node* N = (struct node*)malloc(sizeof(struct node));
    N->c = x;
    N->n =NULL;

    undo_h *und = new undo_h;
    und->pos = *cursor; 
    und->op = 3;

    if(*content==NULL){
        *content = N;
        *cursor+=1;
        last+=1;
        // und->pos = 0;
        // undos.push(und);
        return;
    }

    if(*cursor==0){
        N->n = *content;
        *content = N;
        *cursor+=1;
        last+=1;
        und->pos = 0;
        return;
    }

    int cu=0;
    while (cu!=*cursor-1 && t->n!=NULL)
    {
        t=t->n;
        cu+=1;
    }

    if(t->n){
        N->n = t->n;
    }
    t->n = N;
    *cursor+=1;
    last+=1;

    // stac.push(make_pair(*cursor-1,1));
}

void printstr(struct node* s){

    if(s==NULL){
        cout<<"Empty string\n";
    }

    while (s!=NULL)
    {
        cout<<s->c;
        s = s->n;
    }
        cout<<endl;
}

void seek(int *cursor){
    cout<<"Enter a new position : ";
    int x;
    cin>>x;
    
    // stac.push(make_pair(*cursor,4));

    if(x>last+1||x<-1){
        cout<<"Invalid position for cursor!"<<endl;
        return;
    }
    else if (x==-1){
        *cursor=last;
    }
    else{
    *cursor = x;
    }
       
}

void deletex(struct node** content, int* cursor, int x){
    cout<<"Current : 1 or Previous -1 : ";
    if(x==0) 
        cin>>x;
    int cu = 0;
    struct node* t = *content;
    struct node* temp;


    if(last==0){
        cout<<"Empty string\n";
        return;
    }

    if(x==1){
        if(*cursor==0){
            temp = *content;
            *content = temp->n;
            // free(temp);
            // stac.push(make_pair(temp,-1));
            last--;
            
            return;
        }
        else if(*cursor==last){
            cout<<"Invalid delete operation\n";
            return;
        }
        else{
            while (cu!=(*cursor)-1)
            {
                t=t->n;
                cu+=1;
            }
            temp = t;
            
            // stac.push(make_pair(t->n,1));

            if(*cursor==last-1) t->n = NULL;
            else t->n = t->n->n;
            // free(temp->n);
            
            last--;
            (*cursor)-=1;
            return;
        }
    }

    else if(x==-1){
        if(*cursor==0){
           cout<<"Invalid delete operation\n";
            return; 
        }

        else if(*cursor==last){    
            while (t->n->n!=NULL) t=t->n;
            temp = t->n;
            t->n = NULL;
            // free(temp);
            // stac.push(make_pair(temp,1));
            last-=1;
            (*cursor)-=1;
            return;
        }
        else if(*cursor==1){
                temp = *content;
                *content = temp->n;
                // free(temp);
                // stac.push(make_pair(temp,1));
                last--;
                *cursor-=1;
                return;
            }

        else{
            while (cu!=(*cursor)-2)
            {
                t=t->n;
                cu+=1;
            }
            // stac.push(make_pair(t->n,1));
            t->n=t->n->n;
            
            last--;
            (*cursor)-=1;
            return;
        }
    }

    else{
        cout<<"Invalid input\n\n";
        return;

        
    }

}

void pushclip(struct node** s, char x){

    struct node* N = (struct node*)malloc(sizeof(struct node));
    struct node* i = *s;

    N->c = x;
    N->n =NULL;
    while (i->n!=NULL) i=i->n;
    i->n = N;
    return;  
}

void copyxy(struct node** content, struct node** clipboard){
    cout<<"Enter the range to copy : ";
    int x,y,cu=0;
    cin>>x>>y;

    if(x<0||y<0||x>=last||y>=last||x>y){
        cout<<"Invalid Operation\n";
        return;
    }
    deletell(clipboard);
    struct node* t = *content;
    while (x!=cu)
    {
       t=t->n;
       cu+=1;
    }
    struct node* N = (struct node*)malloc(sizeof(struct node));
    N->c = t->c;
    N->n =NULL;
    *clipboard = N;   

    int it=1;
    while (it<=y-x)
    {
        t = t->n;
        char x = t->c;
        pushclip(clipboard,x);
        it+=1;
    }
    
    cliplen=y-x+1;
}

void cutxy(struct node** content, struct node** clipboard){
    cout<<"Enter the range to cut : ";
    int x,y,cu=0;
    cin>>x>>y;

    if(x<0||y<0||x>=last||y>=last||x>y){
        cout<<"Invalid Operation\n";
        return;
    }
    deletell(clipboard);
    if(x==0){
        *clipboard = *content;
        
        struct node* t = *content;
        struct node* u = t;
        int it=0;
        while (it!=y-x)
        {
            u=u->n;
            it+=1;
        }
        *content = u->n;
        u->n = NULL;
        last-=y-x+1;
        cliplen = y-x+1;
        return;
    }

    struct node* t = *content;
    while (x-1!=cu)
    {
       t=t->n;
       cu+=1;
    }
    struct node* u = t;
    
    *clipboard = t->n;

    int it=0;
    while (it!=y-x+1)
    {
        u=u->n;
        it+=1;
    }
    t->n = u->n;
    u->n = NULL;
    last-=y-x+1;
    cliplen = y-x+1;
}

void pastex(struct node** content, struct node** clipboard){
    cout<<"Enter the position to paste : ";
    int x;
    cin>>x;
    if(x<0||x>=last){
        cout<<"Invalid Operation\n";
        return;
    }

    if(x==0){
        struct node* t = *clipboard;
        while (t->n!=NULL) t=t->n;
        t->n = *content;
        *content = *clipboard;
        *clipboard = NULL;
        last+=cliplen;
        cliplen = 0;
        return;
    }
    int it=0;
    struct node* t = *content;
    while (it!=x)
    {
        it+=1;
        t=t->n;
    }
    struct node* temp = t->n;
    t->n = *clipboard;
    while (t->n!=NULL) t=t->n;
    t->n = temp;
    *clipboard = NULL;
    last+=cliplen;
    cliplen = 0; 
}

void savefile(struct node** content){
    string filename;
    cout<<"Enter the filename:\n";
    cin>>filename;
    filename = filename + ".txt";

    ofstream fout;
    fout.open(filename.c_str());

    struct node* t = *content;
    while (t!=NULL)
    {
        fout<<t->c;
        t=t->n;
    }
    fout<<"\n";
    
    fout.close();
    cout<<"A file named "<<filename<<" was created"<<endl;
}

void openfile(struct node** content, struct node** clipboard, int* cursor){
    deletell(clipboard);
    deletell(content);

    last = 0;cliplen = 0; 

    string filename,word,finalstr;
    cout<<"Enter the filename to open without te extension:\n";
    cin>>filename;
    filename = filename + ".txt";

    

    ifstream fin;
    fin.open(filename.c_str(), ios::in);

    if(fin.fail()){
        cout<<"The file wasn't found int the current reg\n";
        return;
    }

    int line=0;
    while (getline(fin,word)){
        finalstr+=word;
    }
    fin.close();
    int n = finalstr.size(); 
    struct node* N = (struct node*)malloc(sizeof(struct node));
    N->c = finalstr.at(0);
    N->n =NULL;
    *content = N;
    last = 1;   

    int it=1;
    while (it<n)
    {
        char x = finalstr.at(it);
        pushclip(content,x);
        it+=1;
        last+=1;
    }
    *cursor = last;

    cout<<"CONTENT is set to the file contents\nResetting CLIPBOARD\nflusing UNDO & REDO\n"<<endl;
}

int main(){


    int op;
    struct node* content = NULL;
    struct node* clipboard=NULL;

    int cursor=0;
    int last_cur = 0;
    // int last_op = -1;
    // vector<int> choices;
    
    while (1)
    {   
        helptext();
        cin>>op;
        // if(op!=2 && op!=1 && op!=10 && op!=11 && op!=12 && op!=13)
        //     choices.pb(op);

        switch (op)
        {
        case 0: _Exit(10);
        break;

        case 1:printstr(content);
        break;

        case 2:cout<<cursor<<endl;
        break;

        case 3:
        insert(&content,&cursor);
        break;

        case 4:
        last_cur = cursor;
        seek(&cursor);
        break;

        case 5:
        deletex(&content,&cursor, 0);
        break;

        case 6:
        copyxy(&content,&clipboard);
        break;

        case 7:
        printstr(clipboard);
        break;

        case 8:
        cutxy(&content,&clipboard);
        break;

        case 9:
        pastex(&content,&clipboard);
        break;

        // case 10:
        // undo(&content, &clipboard, choices, last_cur, &cursor);
        // break;

        // case 11:
        // redo();
        // break;

        case 12:
        savefile(&content);
        break;

        case 13:
        openfile(&content,&clipboard,&cursor);
        break;

       default:
           break;
       }
    }





}
