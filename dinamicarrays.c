
#include "testheader.h"
//arreglo de las resistencias
void create_list(PTR2NODET * ptop) //aca entras con un puntero valija
{
	*ptop=NULL;
}

void add_node_RES (PTR2NODET * ptop , RESISTENCIA * pres) //aca entras con los datos de la resistencia y la manija
{
	
 NODET * temp;	
 NODET * pnewnode= (PTR2NODET) malloc(sizeof(NODET)); // Create space for node

	if( *ptop == NULL) 	// First time ?
		*ptop=pnewnode; //

	temp=*ptop;
 
	while(temp -> next)							// find last node
  		temp = temp -> next;
	
	temp -> next= pnewnode;						// Link new node with last one
 
	pnewnode->resist=* pres;					// copy data
 
    pnewnode->next= NULL;  						// set newly created node as last node
    pnewnode->prev=temp;
 
}




void del_node(PTR2NODET * ptop,char *nomb) //aca entras con la manija y el nombre
{

 NODET * temp;
	temp=*ptop;
	while(strcmp( (temp->resist).nombre, nomb) && temp->next!=NULL )
		temp=temp->next;



	if(temp==*ptop) {
		*ptop=temp->next;
	}
	else if(temp->next==NULL)
	{
		(temp->prev)->next=NULL;
		free(temp);
	}

	else{
		(temp->prev)->next=temp->next;
		(temp->next)->prev=temp->prev;
	free(temp);
	}

}


//arreglo de lineaaaaaaaaaaaaaaaaaaaaaaaaaaas


void add_node_line (PTR2LINE * ptop , LINEA * pline) //aca entras con los datos de la linea y la manija
{
	
 NODETLINE * temp;	
 NODETLINE * pnewnode= (PTR2LINE) malloc(sizeof(NODETLINE)); // Create space for node

	if( *ptop == NULL) 	// First time ?
		*ptop=pnewnode; //

	temp=*ptop;
 
	while(temp -> nextli)							// find last node
  		temp = temp -> nextli;
	
	temp -> nextli= pnewnode;						// Link new node with last one
 
	pnewnode->line=* pline;					// copy data
 
    pnewnode->nextli= NULL;  						// set newly created node as last node
    pnewnode->prevli=temp;
 
}
