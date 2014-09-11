#include "windows.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s \
    on line %d\n", __FILE__, GetLastError(), api, __LINE__);}
#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)


//Funktionsprototypen
inline void setcolor(int textcolor,int backcolor);
int textcolor();/*returns current text color*/
int backcolor();/*returns current background color*/
int WIDTH();
 /* 
 
 5.11.13
 random
 
 
 
 
 Important note!
 
 
 char buf[500];
 snprintf(buf, sizeof buf, "Du hast %d punkte erreicht", intVariable);
 */
 
 
 


//BORLAND ERSATZ===================================================================================================
void gotoxy(short x, short y){
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y};
	
	SetConsoleCursorPosition(hStdout, position);
	return;
}

void writeToPos(const char* s, short x, short y){
	gotoxy(x,y);
	
	printf("%s",s);
	return;
}

void cls(){
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };    /* here's where we'll home the
                                        cursor */ 
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
    DWORD dwConSize;                 /* number of character cells in
                                        the current buffer */ 

    /* get the number of character cells in the current buffer */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "GetConsoleScreenBufferInfo" );
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    /* fill the entire screen with blanks */ 

    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
       dwConSize, coordScreen, &cCharsWritten );
    //PERR( bSuccess, "FillConsoleOutputCharacter" );

    /* get the current text attribute */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "ConsoleScreenBufferInfo" );

    /* now set the buffer's attributes accordingly */ 

    bSuccess = FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputAttribute" );

    /* put the cursor at (0, 0) */ 

    bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
    return;
 }
 
void sleep(long time){
 	Sleep(time);
 	return;
 }


//TABELLE FUNKTIONEN ================================================================================================
void draw_line(short column_width, short columns, short front_linebreak){
	int a;
	
	if(front_linebreak==1){
		printf("\n");
	}
	
	for (a = 0; a<=column_width*columns; a++){
		printf("-");
	}
	printf("\n");
}

void draw_number_field(int a, short first_column){
	int spaces = 4;
	int x;
	
	if (first_column==1)	
		printf("|");
	
	
	for (x = 0; x <= spaces; x++){
		printf(" ");
	}
	
	if (a < 100)
		printf(" ");
		if (a < 1000)
			printf(" ");
	
	printf("%i", a);
	for (x = 0; x <= spaces; x++){
		printf(" ");
	}	
	printf("|");
	return;
}

void draw_char_field(short length, char a, short first_column){
	int i;
	
	for (i = 1; i<=length/2; i++){
		printf(" ");
	}
	
	printf("%c", a);
	
	for (i = 1; i<=length/2; i++){
		printf(" ");
	}
	
	printf("|");
	return;
}



//MALFUNKTIONEN ====================================================================================================
 void drawFilledRect(short x_pos, short y_pos, short x_s, short y_s){
 	int x,y;

 	for (y = 0; y<y_s; y++){
 		gotoxy(x_pos-1, y_pos+y-1);
 		for (x = 0; x<x_s; x++){
 			
 			//gotoxy(x_pos, y_pos+y);
 			printf("%c", 219);
 			
 		} 		
 		
 	}
 	
 	return;
 }
 
 void drawRect(short x_pos, short y_pos, short width, short height){
 	int x,y,i,a;
	//x_pos -=1;
	y_pos -=1;
	
	gotoxy(x_pos, y_pos);
	for (x = 1;x<width;x++){
		printf("%c", 219);
	}
	
	gotoxy(x_pos, y_pos);
	for(y=1;y<=height;y++){
		printf("%c", 219);
		gotoxy(x_pos, y_pos+y);
	}
	
	gotoxy(x_pos+width-1, y_pos);
	for(y=1;y<=height;y++){
		printf("%c", 219);
		gotoxy(x_pos+width-1, y_pos+y);
	}
	
	gotoxy(x_pos, y_pos+height-1);
	for (x = 1;x<width;x++){
		printf("%c", 219);
	}
	gotoxy(x_pos+width, y_pos+height);
	
	
 	return; 		
 }
 
 
 void drawLine(int length, short character, unsigned short pos){
 	int XPos = 0;
	int i = 1;
 	switch(pos){
 		case 1:
		 	for (i = 1; i<=length; i++){
	 		printf("%c", character);
	 		}
		 break;
		 
		 case 2:
		 	XPos= WIDTH()/2-length/2;
		 	gotoxy(XPos, 1);
		 	for (i = 1; i<=length; i++){
	 			printf("%c", character);
	 		}
		 break;
		 
		 case 3:
		 	XPos= WIDTH()-length;
		 	gotoxy(XPos, 1);
		 	for (i = 1; i<=length; i++){
	 			printf("%c", character);
	 		}	
		 break;
		 
		 default:
		 	printf("Ungueltiger Parameter");
		 	
 	}

 	
	return;
 	
 }
 
//DATEIOPERATIONEN
/*short file_exists(const char * filename)
{
    if (FILE * file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}*/

//MATHEMATIK====================================================================================================
 int noname(int x, int y){
//Brüche
	  
	while(x!=y){
 		if (x>y){
 			x = x-y;
 		} else {
 			y = y-x;
 		}
 	}
 	

 	return x;
 }
 
 
 double fak(int x){
 	int i;
 	double y=1;
 	
 	for (i = 1; i<=x;i++ ){
 		y = y*i;
 		
 	}
 	
 	return y;
 }


 
 
 
//HILFSFUNKTIONEN====================================================================================================
void showAllASCII(){
	int i;
	for (i = 0; i<=255;i++){
		draw_line(13, 2, 1);
		draw_number_field(i, 1); draw_char_field(10, i, 1);
		
	}
} 

int WIDTH(){
	int width;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);
	
	width = csbi.srWindow.Right;
	width++;
	return width;
}

int HEIGHT(){
	int height;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);
	
	height = csbi.srWindow.Bottom;
	height++;
	return height;
}

int random(int number){
	srand(time(NULL));
	return rand()%number;
	
	
}



//FARBEN======================================================================
#ifndef _EKU_CONCOL
#define _EKU_CONCOL



short textcolorprotect=1;
/*doesn't let textcolor be the same as backgroung color if true*/

enum concol
{
	black=0,
	dark_blue=1,
	dark_green=2,
	dark_aqua,dark_cyan=3,
	dark_red=4,
	dark_purple=5,dark_pink=5,dark_magenta=5,
	dark_yellow=6,
	dark_white=7,
	gray=8,
	blue=9,
	green=10,
	aqua=11,cyan=11,
	red=12,
	purple=13,pink=13,magenta=13,
	yellow=14,
	white=15
};





//___________________________________________

int textcolor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(std_con_out,&csbi);
	int a=csbi.wAttributes;
	return a%16;
}

int backcolor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(std_con_out,&csbi);
	int a=csbi.wAttributes;
	return (a/16)%16;
}



 inline void setcolor(int textcol,int backcol)
{
	if(textcolorprotect)
	{if((textcol%16)==(backcol%16))textcol++;}
	textcol%=16;backcol%=16;
	unsigned short wAttributes= ((unsigned)backcol<<4)|(unsigned)textcol;
	SetConsoleTextAttribute(std_con_out, wAttributes);
}




//WINAPI ====================================================================================================

void easyOkMessageBox(char buf[], char titel[]){
	
	

	
	MessageBox(NULL, buf, titel,  MB_ICONINFORMATION | MB_OK );
	
	
}




#endif /*_EKU_CONCOL*/ 


