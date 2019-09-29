#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList {
	int data;
	struct LinkList* next;
}Node,*PNode;

PNode CreateList() {
	int num;
	int i;
	int newdata;

	PNode PHead = (PNode)malloc(sizeof(PNode));
	PNode PTail = PHead;
	PTail->next = NULL;
	printf("Please input number of LinkList:");
	scanf("%d",&num);

	for(i=0; i<num; i++) {
		PNode PNew = (PNode)malloc(sizeof(PNode));
		if(PNew == NULL){
			printf("Fail to Create List\n");
			return NULL;
		}
		printf("Please input data of List %d: ", i+1);
		scanf("%d",&newdata);
		PNew->data = newdata;
		PTail->next = PNew;
		PNew->next = NULL;
		PTail = PNew;
	}
	return PHead;
}

void ShowLink(PNode Header) {
	PNode P = Header->next;		// NOT putout first struct data!!
	if (P == NULL) {
		printf("LinkList is NULL.\n");
		return ;
	}
	printf("LinkList data is:");
	while(P != NULL)	{
		printf("%d ",P->data);
		P = P->next;
	}
	printf("\n");
}

PNode InsertList(PNode Header, int pos, int data) {
	int position = 0;
	PNode P = Header;
	while( Header!=NULL && position<pos-1){
		P = P->next;
		position++;
	}
	//printf("Please input the number position: ");
	//scanf("%d"&pos);
	PNode Tmp = (PNode)malloc(sizeof(PNode));
	Tmp->data = data;
	Tmp->next = P;
	P->next = Tmp;

	return Header;
}

int main() {
	PNode text = CreateList();
	ShowLink(text);
	return 0;
}
