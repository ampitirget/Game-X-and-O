//Emali: amp.it.ir.go@gmail.com
//Github: ampitirget
//Amir Mohamad
#include <iostream>
#include <conio.h>
using namespace std;

char map[9] = {'1','2','3','4','5','6','7','8','9',};// map
char noobat = 'o';// o and x 
/* map game
 _____________
 | 1 | 2 | 3 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 7 | 8 | 9 |
 -------------
*/

 int mapmomo (char a ,char b ,char c);
void Playing ();
 int barsegm ();


// !>>>>>>**********************>>>>>>  0 = adamh , 1 = ja por shod , 2 = o bord , 3 = x bord <<<<<<**********************<<<<<<!
// barsi adamh dashtan baze



main(){
	system("title x and o");
	system("color 37");
	int ctrl;
	while(1){
	{
 	for(int i=0;i<=8;i++){
	 if(i%3==0)
	 cout<<"\n -------------"<<"\n | ";
 	
 	cout<<map[i]<<" | ";
	}
	
 	cout<<"\n ------------- \n\n";
	}
	
	Playing();
	ctrl=barsegm();
	if(ctrl)
	{
	if (ctrl==1){
	cout<<"Severe equal";
	break;}
	else if(ctrl==2){
	cout<<"Player ( o ) won";
	break;}
	else if(ctrl==3){
	cout<<"Player ( X ) won";
	break;}
	}
	}
	
	for(int i=0;i<=8;i++){
	 if(i%3==0)
	 cout<<"\n -------------"<<"\n | ";
 	
 	cout<<map[i]<<" | ";
	}
	
 	cout<<"\n -------------"<<endl;
 	cout<<"\n\t*--------------*\n\t| amir mohamad |\n\t*--------------*\n\tEmali: amp.it.ir.go@gmail.com\n\tGithub: ampitirget";
 	getch();
	}

int mapmomo (char a ,char b ,char c){
	if ((a=='X'||a=='o')&&a==b&&b==c)
	return 1;
	else
	return 0;
}

void Playing (){
	int  vorodi;// makan mord nazar ba in sabt meshvad
   do{
   cout<<"player ( "<<noobat/*nshan DHNDEy in Kh Ki bayd bazi konh*/<<" ) Please enter 1<->9 An empty place :\n ";
	cin>>vorodi;
	system("cls");// sfha ra pak mikonh
	}while ( map [vorodi-1] == 'X' || map [vorodi-1] == 'o' );
	
	map[vorodi-1 /*Array ha az [0] shro mishan*/ ]=noobat;
	
	//in if bary in hst K noobat Bazi Kon h ro dorst bkonh
	if(noobat=='o')
	noobat='X';
	else
	noobat='o';
}

int barsegm (){
	
	/*ol goy amtyz mazi
	1,2,3 _ 4,5,6 _ 7,8,9
	1,4,7 _ 2,5,8 _ 3,6,9
	,   1,5,6 _ 3,5,7
	*/
	
	// 1
	if ( mapmomo(map[0],map[1],map[2]) || mapmomo(map[0],map[3],map[6]) || mapmomo(map[0],map[4],map[8]) )
	if (map[0]=='o')
	return 2;
	else
	return 3;
	// 1\
	
	// 5
	if ( mapmomo(map[3],map[4],map[5]) || mapmomo(map[1],map[4],map[7]) || mapmomo(map[2],map[4],map[6]) )
	if (map[4]=='o')
	return 2;
	else
	return 3;
	// 5\
	
	// 9
	if ( mapmomo(map[6],map[7],map[8]) || mapmomo(map[2],map[5],map[8]) )
	if (map[8]=='o')
	return 2;
	else
	return 3;
	// 9\
	
	
    for(int i=0;i<=8;i++)
	if (map[i]!='X'&&map[i]!='o')
 	break;
	else if (i==8)
	return 1;
	
	
	return 0;
	}