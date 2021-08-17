#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,NE,i;
FILE *fp;
struct student{
  char ID[50];
  char Name[60];
  char Address[100];
  char DOB[10];
  char Mail[50];
  char Phone[12];
  char Course[50];
  char Branch[50];
};
typedef struct student STU;
//*********** FUNCTIONS *************
STU* struct_to_file(STU *s);
//INSERT FUNCTION
STU* insert(STU *s){
 STU temp;
 NE=NE+1;
 if(NE>n){
  n= NE*2;
  s=(STU *)realloc(s,sizeof(STU)*n);
 }
 printf("Enter information in the order :\nID\nName\nAddress\nDOB\nMail\nPhone\nCourse\nBranch\n");
scanf("%s%s%s%s%s%s%s%s",temp.ID,temp.Name,temp.Address,temp.DOB,temp.Mail,temp.Phone,temp.Course,temp.Branch);
 
for(i=NE-2 ;i>=0 && (strcmp((s+i)->ID,temp.ID))>0 ;i--) {
  strcpy((s+i+1)->ID,(s+i)->ID);
  strcpy((s+i+1)->Name,(s+i)->Name);
  strcpy((s+i+1)->Address,(s+i)->Address);
  strcpy((s+i+1)->DOB,(s+i)->DOB);
  strcpy((s+i+1)->Mail,(s+i)->Mail);
  strcpy((s+i+1)->Phone,(s+i)->Phone);
  strcpy((s+i+1)->Course,(s+i)->Course);
  strcpy((s+i+1)->Branch,(s+i)->Branch);
  }
 strcpy((s+i+1)->ID,temp.ID);
 strcpy((s+i+1)->Name,temp.Name);
 strcpy((s+i+1)->Address,temp.Address);
 strcpy((s+i+1)->DOB,temp.DOB);
 strcpy((s+i+1)->Mail,temp.Mail);
 strcpy((s+i+1)->Phone,temp.Phone);
 strcpy((s+i+1)->Course,temp.Course);
 strcpy((s+i+1)->Branch,temp.Branch);
 return s;
}

//DISPLAY FUNCTIONS
void dis_attr() {
printf("ID\t\tName\t\tAddress\t\tDOB\t\tMail\t\tPhone\t\tCourse\t\tBranch\n");
}
void display(STU *s){
printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
printf("\n");
}


//For Copying the Structure items to File
STU* struct_to_file(STU *s) {
 fp=fopen("student_info.txt","w");
 for(i=0;i<NE;i++) {
fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
 fprintf(fp,"\n");
  }
 fclose(fp);
 return s;
}

//SEARCH FUNCTION
STU* search(STU *s) {
 int choice,flag=1;
 char dup[100];
 fp=fopen("student_info.txt","r");
 printf("Search using...\n1.ID\n2.Name\n3.Address\n4.DOB\n5.Mail\n6.Phone\n7.Course\n8.Branch\n");
 scanf("%d",&choice);
 switch(choice) { 
  case 1:{ printf("Enter the ID to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].ID)==0){
              flag=0; printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
         }
         if(flag==1){
            printf("ID not Found\n");
           } break;
        }         
  case 2:{ printf("Enter the Name to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].Name)==0) {
               flag=0; printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
          }
          if (flag==1){
             printf("Name not Found\n");
           } break;
         }         
  case 3:{ printf("Enter the Address to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].Address)==0){
               flag=0; printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
          }
           if (flag==1){
             printf("Address not Found\n");
           } break;
         }
  case 4:{ printf("Enter the DOB to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].DOB)==0) {
             flag=0; printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);    }
     }
           if (flag==1) {
             printf("DOB not Found\n");
           } break;
         }
  case 5:{ printf("Enter the Mail to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].Mail)==0) {
               flag=0; printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
           }
           if (flag==1){
             printf("Mail not Found\n");
           } break;
         }
  case 6:{ printf("Enter the Phone to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++)
           {
            if(strcmp(dup,s[i].Phone)==0) {
               flag=0;
printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
           }
           if (flag==1) {
             printf("Phone not Found\n");
           } break;
         }
  

case 7:{ printf("Enter the Course to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].Course)==0){
                 flag=0;
printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
           }
           if (flag==1) {
             printf("Course not Found\n");
           } break;
         }     
  case 8:{ printf("Enter the Branch to be searched\n");
           scanf("%s",dup);
           for(i=0;i<NE;i++) {
            if(strcmp(dup,s[i].Branch)==0){
                  flag=0;  printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].ID,s[i].Name,s[i].Address,s[i].DOB,s[i].Mail,s[i].Phone,s[i].Course,s[i].Branch);
            }
           }
           if (flag==1) {
             printf("Branch not Found\n");
           } break;
         }
  default:printf("Invalid Choice\n");
 }
}
//UPDATE FUNCTION
STU* update(STU *s) {
  char id[60],temp[100];
  int choice,flag=1;
  printf("Enter ID of Student to update\n");
  scanf("%s",id);
  for(i=0;i<NE;i++) {
    if(strcmp(id,s[i].ID)==0) {
      flag=0;
      printf("Update\n1.Name\n2.Address\n3.DOB\n4.Mail\n5.Phone\n6.Course\n7.Branch\n");
      scanf("%d",&choice);
      switch(choice){
      case 1:{ printf("Enter new Name\n");
               scanf("%s",temp);
               strcpy(s[i].Name,temp);
               break;
              }
      case 2:{ printf("Enter new Address\n");
               scanf("%s",temp);
               strcpy(s[i].Address,temp);
               break;
              }
      case 3:{ printf("Enter new DOB\n");
               scanf("%s",temp);
               strcpy(s[i].DOB,temp);
               break;
              }
      case 4:{ printf("Enter new Mail\n");
               scanf("%s",temp);
               strcpy(s[i].Mail,temp);
               break;
              }
      case 5:{ printf("Enter new Phone\n");
               scanf("%s",temp);
               strcpy(s[i].Phone,temp);
               break; }
      case 6:{ printf("Enter new Course\n");
               scanf("%s",temp);
               strcpy(s[i].Course,temp);
               break;
              }
      case 7:{ printf("Enter new Branch\n");
               scanf("%s",temp);
               strcpy(s[i].Branch,temp);
               break;
              }
      default: printf("Invalid Choice\n");             
      } return s;
     }
   }
  if(flag) {
   printf("ID not Found\n");
   return s;
   }
}

//DELETE FUNCTIONS
                      //To Copy the next items of the deleted elements
STU* adjust_del(STU *s,int pos)  {
  for(i=pos;i<=NE-1;i++) {
   strcpy((s+i)->ID,(s+i+1)->ID);
   strcpy((s+i)->Name,(s+i+1)->Name);
   strcpy((s+i)->Address,(s+i+1)->Address);
   strcpy((s+i)->DOB,(s+i+1)->DOB);
   strcpy((s+i)->Mail,(s+i+1)->Mail);
   strcpy((s+i)->Phone,(s+i+1)->Phone);
   strcpy((s+i)->Course,(s+i+1)->Course);
   strcpy((s+i)->Branch,(s+i+1)->Branch); } NE-- ;
  return s;
}
STU* delete(STU *s) {
 char temp[100];
 int choice,i=0,flag=1;
 printf("Delete using\n1.ID\n2.Name\n3.Address\n4.DOB\n5.Mail\n6.Phone\n7.Course\n8.Branch\n");
 scanf("%d",&choice);
 switch(choice) {
  case 1:{ printf("Enter Id\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].ID)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
         }
           if (flag==1) {
             printf("Invalid ID\n");
           } break;
         }
  case 2:{ printf("Enter Name\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++)  {
            if(strcmp(temp,s[i].Name)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1) {
             printf("Invalid Name\n");
           } break;
         }
  case 3:{ printf("Enter Address\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].Address)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1) {
             printf("Invalid Address\n");
           } break;
         }
  case 4:{ printf("Enter DOB\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].DOB)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1) {
             printf("Invalid DOB\n");
           } break;
         }
  case 5:{ printf("Enter Mail\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].Mail)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1){
             printf("Invalid Mail\n");
           } break;
         }
  case 6:{ printf("Enter Phone\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].Phone)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1) {
             printf("Invalid Phone\n");
           } break;
         }
  case 7:{ printf("Enter Course\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++)  {
            if(strcmp(temp,s[i].Course)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1){
             printf("Invalid Course\n");
           } break;
         }
  case 8:{ printf("Enter Branch\n");
           scanf("%s",temp);
           for(i=0;i<NE;i++) {
            if(strcmp(temp,s[i].Branch)==0) {
                  flag=0;
                  s=adjust_del(s,i);
                  return s;
            }
           }
           if (flag==1) {
             printf("Invalid Branch\n");
           } break;
         }
  default: printf("Invalid Choice\n");
  }  
}
void main() {
 int ch,flag=1,r;
 printf("STUDENT INFORMATION\n");
 printf("Enter the number of students:\n");
 scanf("%d",&NE);
 n=NE;
 STU *s;
 s=(STU *)malloc(sizeof(STU)*NE);
 for( ; ; ) {
  printf("Enter Choice:\n1.Insert\n2.Delete\n3.Search\n4.Update\n5.Display\n");
  scanf("%d",&ch);
  switch(ch) {
   case 1: { s=insert(s);
             s=struct_to_file(s);
             break;  }
   case 2: { s=delete(s);
             s=struct_to_file(s);
             break; }
   case 3: { s=search(s);
             break; }
   case 4: { s=update(s);
             s=struct_to_file(s);
             break; }
   case 5: { dis_attr();
             for(i=0;i<NE;i++) {
                display(s); }
                break; } 
   default: exit(0);
  }
 }
}
