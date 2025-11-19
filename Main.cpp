/*
This is a simple console application project created in group because we was ordered to build a problem solving software by our programming lecturer. 
So, the idea is to change real-world bakery buying and ordering service to online and digital. the system we built we named it "SWEET" or 
in amharic term "TAFFACHi" because if we develop this system in future using more complex programming language and we wanna join this types of jop
in the future and we will use our system be successfull.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>


///Logic Functions

   /// Update & Insert Function
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

     /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

    ///Delete & Count Function
void deletefood(int serial);
int countitem();




///extra design Function

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);


        ///START Structure Here

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

   ///Global Type 
   
typedef struct Node node ;

node *head, *list;

int main(){

	system("title Sweet Bakery And Ordering System");
	system("mode con: cols=98 lines=58");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	
	/// List of our service
	
	 head = NULL;
 	 insertfirst(5,"Birthday Cakes",90,400.100);
 	 insertend(6,"Wedding Cakes",70,500.125);
 	 insertend(7,"Usual Cakes",65,300.60);
 	 insertend(1,"Normal Dabo",110,10.60);
 	 insertend(8,"Diffo Dabo",50,150.38);
 	 insertend(3,"Ambasha",30,18.18);
 	 insertend(4,"Donnat",60,30.60);
 	 insertend(2,"Sanbusa",45,15.30);
 	 insertend(9,"3L Milk",20,180.20);



	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");

/// Admin choice setting

			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice== 12345678){



				node *temp;

				temp = list;

				adminchoise:

				cls();  br(3); pre(4); echo(">>>> Admin Panel <<<<   \n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add An Item \n\n");Sleep(250);pre(4);
				printf(" 4. Delete An Item \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Item List \n\n");Sleep(250);pre(4);
				printf(" 6. Item Counter \n\n");Sleep(250);pre(4);
				printf(" 7. Backup System\n\n");Sleep(250);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your From 1-0: ");
				Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d",&adminchoise);

				if(adminchoise==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.1f  \n",totalmoney);

					Sleep(2000);

					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){

						cls();  br(3); pre(4);

						printf(" _________________________________________________________________________\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("--------------------------------------------------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.1f |\n",cardno[z],cardmoney[z]);pre(4);
						    printf("--------------------------------------------------------------------\n");pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					printf("No Credit Card History\n");}
					Sleep(1500);
					goto adminchoise;
				}

/// Food Adding

				else if(adminchoise==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      printf(" Enter Bakery Item Name :  ");

					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					printf(" Enter Item Quantity :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
					br(2);pre(4);  printf(" Enter Item Serial No :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf(" The Item Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  printf(" Enter Item Price :  ");fflush(stdin);

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Submitting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


	insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Adding Item  Successfull.......\n");

					Sleep(2000);

					goto adminchoise;

				}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No Of The Item To Delete: ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);



					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						printf("Item Counting ");
						printf(" %d ",cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					printf("Total Item is --> %d  \n",citem); Sleep(2000);
					goto adminchoise;

				}

                        ///Backuping  System
                        
				else if(adminchoise==7){


					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr,"Total Cash Today : %0.1f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ----------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------------ %0.1f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successfull..."); Sleep(1500);



					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){

					cls();br(2);pre(2);
					ccolor(26);
					printf("\n\t\t"); ccolor(240);
					printf("________________________________________________________________________"); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("|    Order No.   |     Item Name       |   Quantity   |   Selling Price |"); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("------------------------------------------------------------------------"); ccolor(26);
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;



				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Thanks For Using Our System. \n\t\t\tMade By Esubalew Bego \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);

		}

	}
	/// Choice of Service and Quantity
	
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choice From List: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		printf("Enter Item Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4);  printf("Chosen item %s its price is %0.1f  \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		///Service Buying Method
		
		printf("1. Confirm To Buy This \n\n");pre(4);
		printf("2. Back To Item List \n\n");
		printf("Press 1 To Confirm And 2 To Back To list: ");

		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);
			printf(" 1. Cash ");
			br(2);pre(4);
            printf(" 2. Credit Card\n");
            printf("Select Method Of Payment 1 - 2: ");
			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);

/// Cash Option
			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  printf("===> THANK YOU <===");
				br(2);pre(4);  printf("Item Ordered Successfully ...");
				br(2);pre(4);  printf("1. Do You Want Another Sweet ? ");
				br(2);pre(4);  printf("2. Main Menu \n");
				br(2);pre(4);   printf("Select: ");
				psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				cls();middle1();pre(4); printf("Enter Your Card No : ");

				fflush(stdin);   scanf("%d",&card_number[c]);



				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  printf("Enter Your Card PIN [We Will Never Save Your PIN] : ");

				fflush(stdin);     scanf("%d",&pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  printf("Payment Successfull...");
				br(2);pre(4);    printf("1. Do You Want Another Sweet ? ");
				br(2);pre(4);    printf("2. Main Menu \n");
				br(2);pre(4);   printf("select: ");
				psmenu2:
				int ps_menu2;

				scanf("%d",&ps_menu2);

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu2;}

			}

			else{

				br(2);pre(4);   printf("Enter Choice from List : ");

				goto payment;


			}


		}    ///END Confirm Y/y



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			br(2);pre(4);    printf("Enter Choice from List : ");

			goto confirm;


		}  ///end confirm


	}  ///end get food choice if line


	else{

		br(2);pre(4);  echo("Please Choose From List "); br(2); Sleep(300);

		goto foodlist;

	}  ///end get food choice
}

/// Clearing Style

void cls(){

	system("cls");

}

void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}

/// Displaying Main Menu List
void main_menu(){

	cls();
	br(5); pre(3); echo(">> 1. Customer Choice"); Sleep(400);
	br(2); pre(3); echo(">> 2. Admin Panel Choice"); Sleep(400);
	br(2); pre(3); echo(">> 3. Exits From The System");  Sleep(400);
	br(2); pre(3); echo("In Here you Will Find The Sweetest Of Sweetest Things For Sure !");  Sleep(400);

	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	//    free(temp);
}

/// Food Deleting Choice

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);

		}
		else{
			printf("\n\n\n\n\t\t\tItem Not Found\n"); Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);

		head = temp ;

		list=head;
	}
}

///Food Updating Choice

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

}

/// Food List

void foodlist(){

	ccolor(0);

	printf("\n\t\t"); ccolor(240);
	printf("______________________________________________________________________________");ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("|  Item No.  |    Item Name    |   Price Of Single  | All We Have In Our Place ");ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("------------------------------------------------------------------------------");ccolor(26);

	node *temp;

	temp = list;

	while(temp != NULL){

		ccolor(26);


		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |      %s      |     %0.1f     |       %d       |",temp->data,temp->foodname, temp->price, temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("------------------------------------------------------------------------------");


		temp = temp->next ;

		Sleep(100);

	}

	ccolor(26);

	//  free(temp);

}

/// Order Viewing

void order_view(int order, int quantity, int or_no){



	ccolor(26);

	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){

		ccolor(26);

		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |      %s      |     %0.1f     |       %d       |",or_no,temp->foodname,quantity,temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("----------------------------------------------------------------------");

		Sleep(100);

	}

	ccolor(26);

}

/// Coloring 
void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

}


///HERE PRINTF STYLE FUNCTION

void pwellcome(){
	ccolor(26);

	char welcome[50] = "WELCOME";
	char welcome2[50] = "TO";
	char welcome3[50] = "SWEET BAKERY AND";
	char welcome4[50] = "ORDERING SYSTEM";
		
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
	ccolor(26);

}
/// Loading Like Animation

void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}
/// Backup Loader
void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(120+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}


void middle1(void){

	printf("\n\n\n\n\n\n\n");
}

void middtab1(void){
	printf("\t\t\t\t\t");
}
