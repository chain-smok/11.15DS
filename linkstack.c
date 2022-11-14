#include <stdio.h>
#include <stdlib.h>
void Push(int);      //�ŧipush�Ƶ{�� 
int Pop( );          //�ŧipop�Ƶ{�� 
void PrintStack( );  //�ŧi�C�L���|���Ƶ{�� 
typedef struct node {
  int data;
  struct node *link;
} NODE;
NODE *top=NULL;
int main(void)   //�D�{��
{
    printf("===============�{���y�z=======================\n");
    printf("= �{���W�١Gch5-6.1.c                        =\n");
    printf("= �{���ت��G�ϥΦ�C�e�{���|                 =\n"); 
    printf("==============================================\n");    
  int op=0,item;
  while(1)
  {
    printf("==============================================\n");
    printf("=   1.push(�[�J)                             =\n");
    printf("=   2.pop(���X)                              =\n");
    printf("=   3.��ܥثeStack�����e(�q�ѤW�ӤUTop-Down)=\n");
    printf("=   4.����                                   =\n");    
    printf("==============================================\n");
    printf("�п�J�A���ާ@�G");
    scanf("%d",&op);
    switch(op)
    {
      case 1: printf("�п�J�A�npush����ơG");
              scanf("%d",&item);
              Push(item);   //�I�spush�Ƶ{�� 
              break;
      case 2: printf("%d �O�q���|�u�X�����\n",Pop( ));   //�I�spop�Ƶ{��
              break;
      case 3: PrintStack( );  //�I�s�C�L���|���Ƶ{�� 
              break;
      case 4: printf("\n");    //����
              return (0);              
    }
  }
  while(top) Pop( );
  system("pause");     //�ϵ{���Ȱ��b����e��
  return 0;
}

//�N��ƥ[�J���|
void Push(int data)  //push�Ƶ{��
{
  NODE *pt;
  if( (pt = (NODE*) malloc(sizeof(NODE))) == NULL ) {
    printf("�O���餣���I");
    exit(1);
  }  
  pt->data = data;
  pt->link = top;
  top = pt; 
}

//���X���|���
int Pop( )  //pop�Ƶ{��
{
  NODE *X;
  int item;
  if(top == NULL) {
    printf("���|�O�Ū�!");
    exit(1);
  } 
  X = top;
  item = X->data;
  top=top->link;
  free(X);
  return item;
}

//�C�L�ثe���|�����e
void PrintStack( )   //�C�L���|���Ƶ{��
{
  NODE *temp=top;   
  printf("�ثe���|�����e��: ");
  while(temp) {
    printf("%d ",temp->data);
    temp = temp->link;
  }
  printf("\n");
}
