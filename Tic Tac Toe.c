#include <stdio.h>
#include <stdlib.h>



//PROYEK TIC TAC TOE

//Compiler version gcc  6.3.0

int q,menang=0;
char giliran,kotak[9]={'1','2','3','4','5','6','7','8','9'};


void sistemgiliran()
  {
    int i,j,fase;
    
    //pembentukan fase dan giliran
    clrscr();
    for(i=1;i<10;i++)
     {
        sistemnilai();
        if(menang != 1)
        {
        gambar();
        fase=i%2;
        if (fase!=0)
        {
          giliran='X';
        }
        else 
        {
          giliran='O';
        }
        printf("Giliran pemain %c\n",giliran);
        sistemmain();
        }
        else
        {
        menang:
        gambar();
        printf("%c memenangkan permainan \n",giliran);
        goto selesai;
        }
      }
       gambar();
       printf("Permainan seri");
       selesai:
       printf("selesai");
  }

void gambar()
{
  printf("-------\n");
  printf("|%c|%c|%c|\n",kotak[0],kotak[1],kotak[2]);
  printf("-------\n");
  printf("|%c|%c|%c|\n",kotak[3],kotak[4],kotak[5]);
  printf("-------\n");
  printf("|%c|%c|%c|\n",kotak[6],kotak[7],kotak[8]);
  printf("-------\n");
}

void sistemmain()
{
  int p;
  
ulang:
  //menanyakan kotak yang ingin diisi
  printf("Mau isi kotak nomor berapa?");scanf("%i",&p);
  q=p-1;
  //pengisian kotak yang dipilih
  if (kotak[q] != 'X' && kotak[q] != 'O')
  {
  switch (p)
  {
  case 1 ... 9 :
  kotak[q]=giliran;
  break;
  
  default :
  printf("Masukkan angka yang ada di kotak\n");
  goto ulang;
  break;
  }
  }
  else
  {
  printf("Masukkan ke kotak yang belum diisi\n");
  goto ulang;
  }
  printf("\n____________Giliran selanjutnya__________________\n");}

void sistemnilai()
{
   //horizotal
   if(kotak[0] == kotak[1] && kotak[0] == kotak[2])
   {
    menang=1;  
   }
   else if(kotak[3] == kotak[4] && kotak[3] == kotak[5])  
   {
    menang=1;   
   }
   else if(kotak[6] == kotak[7] && kotak[6] == kotak[8])
   {
    menang=1;  
   }
   
   //vertikal
   if(kotak[0] == kotak[3] && kotak[0] == kotak[6])
   {
    menang=1;  
   }
   if(kotak[1] == kotak[4] && kotak[1] == kotak[7])
   {
    menang=1;  
   }
   if(kotak[2] == kotak[5] && kotak[2] == kotak[8])
   {
    menang=1;  
   }
   
   //diagonal
   if(kotak[0] == kotak[4] && kotak[0] == kotak[8])
   {
    menang=1;  
   }
   if(kotak[2] == kotak[4] && kotak[2] == kotak[6])
   {
    menang=1;  
   }
}

int main()
{
  printf("Tic Tac Toe \n");
  sistemgiliran();
  
  return 0;
}