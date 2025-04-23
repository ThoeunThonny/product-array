#include <stdio.h>
#include<stdbool.h>
#include <string.h>
#include<stdlib.h>
int id_code[30],price[30],qty[30],i,j,op,size;
char name[30][30];
void input(){
	printf("Enter ID Of Product:");scanf("%d",&id_code[i]);
	printf("Enter Name Of Product:");scanf("%s", name[i]);
	printf("Enter Qty Of Produuct:");scanf("%d",&qty[i]);
	printf("Enter Price Of Product:");scanf("%d",&price[i]);
}
void header(){
	printf("ID\tName\tQTY\tPrice\n");
}
void output(){
	printf("%d\t%s\t%d\t%d $\n",id_code[i],name[i],qty[i],price[i]);
}
int main(){
	do{
		printf("=======Option Product=======\n");
		printf("||        1.Input         || \n");
		printf("||        2.Output        || \n");
		printf("||        3.Search        || \n");
		printf("||        4.Update        || \n");
		printf("||        5.Delete        || \n");
		printf("||        6.Exit          || \n");
		printf("============================\n");
		printf("Please You Chose One Option Of System:");scanf("%d",&op);
		switch(op){
			case 1:{
				printf("=========Input Product==========\n");
				printf("Enter Number Of Products:");scanf("%d",&size);
				for(i=0;i<size;i++)
				{
					printf("Product At Number %d\n",i+1);
					input();
				}
			}break;
			case 2:{
				printf("=========Output Product==========\n");
				header();
				for(i=0;i<size;i++)
				{
					output();
				}
			}break;
			case 3:{
				int searchid;
				bool check=true;
				printf("Enter The ID to Search Of Products:");scanf("%d",&searchid);
				printf("=====Search Products=======\n");
				header();
				for(i=0;i<size;i++){
					if(searchid==id_code[i]){
						output();
						printf("====================================\n");
						printf("|| Products Search Is Successfuly ||\n");
						printf("====================================\n");
						check=false;
					}
				}
				if(check){
						printf("=====================\n");
						printf("|| Products Is Not ||\n");
						printf("=====================\n");
				}
			}break;
			case 4:{
				bool check=true;
				char  update[30];
				printf("Enter Name Products To Update:");scanf("%s", update);
				for(i=0;i<size;i++){
					if(strcmp(update, name[i]) == 0){
						printf("======Update Product======\n");
						input();
						printf("====================================\n");
						printf("|| Products Update Is Successfuly ||\n");
						printf("====================================\n");
						check=false;
					}
				}
				if(check){
					printf("=====================\n");
					printf("|| Products Is Not ||\n");
					printf("=====================\n");
			}
			}break;
			case 5:{
				bool check=true;
				int deleteID;
				printf("Enter The ID To Delete Products:");scanf("%d",&deleteID);
				for(i=0;i<size;i++){
					if(deleteID==id_code[i]){
						for(j=i;j<size-1;j++){
							id_code[j]=id_code[j+1];
							strcpy(name[j],name[j+1]);
							qty[j]=qty[j+1];
							price[j]=price[j+1];
						}
						size--;
						printf("====================================\n");
						printf("|| Products Delete Is Successfuly ||\n");
						printf("====================================\n");
						check=false;
					}
				}
				if(check){
					printf("=====================\n");
					printf("|| Products Is Not ||\n");
					printf("=====================\n");
				}
			}break;
			case 6:{
				printf("Exit Program System.......!");
				exit(0);
			}
		}
		
	}while(op<7);
}