#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/print_board.h"
#include "util/scrabble.h"

#define SIZE 15
#define NUM_WORDS 100

//Initializarea cu '.' a jocului
void init_board(char g_board[SIZE][SIZE]){

    for (int i = 0; i < 15; i++){

        for (int j = 0; j < 15; j++){

            g_board[i][j] = '.';

        }
    }
}

//Adauga cuvintul in tabla de joaca
void add_word(char g_board[SIZE][SIZE], int y, int x, int d, char word[SIZE]){
    
    int change_var;
    
    //In dependenta de directie memorez variabila care se va modifica
    if (d == 0){
        
        change_var = x;
    
    } else {
       
        change_var = y;
    
    }
    
    for (int i = change_var, k = 0; word[k] != '\0'; i++, k++){

        if (d == 0){
     
            g_board[y][i] = word[k];
     
        }else {
     
            g_board[i][x] = word[k];
     
        }
        
    }

}

void task_1(char g_board[SIZE][SIZE]){

    int num_intrari,x,y,d;
    char word[SIZE],user_input[255];

    fgets(user_input,5,stdin);
    fgets(user_input,5,stdin);
    num_intrari = atoi(user_input);

    for (int i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);

        add_word(g_board,y,x,d,word);

    }

    print_board(g_board);
       
}

//Calculeaza puncte fara bonus
int calc_puncte(char word[SIZE]){

                     // A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q, R,S,T,U,V,W,X,Y,Z  
    int val_litera[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int scor_player = 0;

    for (int k = 0; word[k] != '\0'; k++){

        scor_player = scor_player + val_litera[(int)((char)word[k]) - 65];

    }

return scor_player;

}

void task_2(){

    int num_intrari,x,y,d,scor_player1,scor_player2;
    char word[SIZE],user_input[255];

    scor_player1 = 0;
    scor_player2 = 0;

    fgets(user_input,5,stdin);
    fgets(user_input,5,stdin);
    num_intrari = atoi(user_input);

    for (int i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);

            if (i % 2 == 0){

                scor_player1 = scor_player1 + calc_puncte(word);

            }else {

                scor_player2 = scor_player2 + calc_puncte(word);

            }
        
    }

    fprintf(stdout,"Player 1: %d Points\n",scor_player1);
    fprintf(stdout,"Player 2: %d Points",scor_player2);
}

//Calculeaza bonusul pentru cuvintul word
int check_bonus(int y, int x, int d, char word[SIZE],char xx[3],char yy[3]){

    int change_var,bonus = 1;
    
    //Memorez variabila in functie de directie
    if (d == 0){
        
        change_var = x;
    
    } else {
       
        change_var = y;
    
    }

    for (int i = change_var, k = 0; word[k] != '\0'; i++, k++){

        if (d == 0){
            
            //Daca nu e 0 bonusul
            if (bonus_board[y][i] != 0 ){

                if ( bonus_board[y][i] == 1 ) {
                    
                    //Daca exista substringul xx in cuvintul word
                    if ( strstr(word,xx) != NULL ){
                    
                        bonus = bonus * 2;

                    }

                } else {

                    if ( strstr(word,yy) != NULL ){
                        
                        //Daca exista substringul yy in word, si e la sfirsit
                        if (strcmp(strstr(word,yy),yy) == 0 ){
                        
                            bonus = bonus * 3;
                        
                        }

                    }
                }

            }
            
     
        } else {
     
            if (bonus_board[i][x] != 0 ){

                if ( bonus_board[i][x] == 1 ) { 
                    
                    //Daca exista substringul xx in cuvintul word
                    if ( strstr(word,xx) != NULL ){
                    
                        bonus = bonus * 2;

                    }

                } else {

                    if ( strstr(word,yy) != NULL ){

                        //Daca exista substringul yy in word, si e la sfirsit
                        if (strcmp(strstr(word,yy),yy) == 0 ){
                            
                            bonus = bonus * 3;
                       
                        }
                    
                    }
                }

                  
            }      
     
        }
        
    }

    return bonus;

}

void task_3(){

    char xx[3], yy[3], word[SIZE],user_input[255];
    int i, num_intrari, x, y, d,scor_player1,scor_player2;
    int puncte;

    fgets(user_input,3,stdin);
    fgets(user_input,3,stdin);
    strcpy(xx,user_input);
    
    fgets(yy,3,stdin);
    fgets(yy,3,stdin);
    
    fgets(user_input,255,stdin);
    fgets(user_input,255,stdin);
    num_intrari = atoi(user_input);
    
    scor_player1 = 0;
    scor_player2 = 0;
    
    for (i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);
        
        check_bonus(y,x,d,word,xx,yy);

        if ( i % 2 == 0 ){
            
            puncte=calc_puncte(word);

            scor_player1 = scor_player1 + puncte*check_bonus(y,x,d,word,xx,yy);
            
        } else {

            puncte=calc_puncte(word);
            scor_player2 = scor_player2 + puncte*check_bonus(y,x,d,word,xx,yy);
            
        }
       
    }
    

    fprintf(stdout,"Player 1: %d Points\n",scor_player1);
    fprintf(stdout,"Player 2: %d Points",scor_player2);

}

//Verifica daca am destul spatiu orizontal sau veritical pentru cuvint
int spatiu_liber(char g_board[SIZE][SIZE], int y, int x,int d,char word[SIZE]){
    
    int change_var, len=strlen(word);

    //Memorez variabila care se va modifica
    if (d == 0){
        
        change_var = x;
   
    } else {
        
        change_var = y;
    
    }

    //Verific daca va incapea in tabla si daca directia e valida
    if ((( change_var + len ) <= SIZE ) && ( d < 2 )){

        for (int i = change_var + 1, k = 1; word[k] != '\0'; k++, i++){
            
            if (d == 0){
                
                //Daca am intilnit o litera, vad daca am loc vertical
                if (g_board[y][i] != '.'){
                
                    d = spatiu_liber(g_board,y,x,1,word);
                    break;
                
                }

            }else {
                
                /*Daca intilnesc o litera pe vertical inseamna ca deja am 
                verificat pentru orizontal si nu am gasit spatiu si nu
                exista nici pe vertical deci cuvintul nu e bun*/
                if (g_board[i][x] != '.'){

                    return -1;

                }
            
            }
            
        }

    } else {
        
        //Daca nu a incaput pe orizontal verific, vertical
        if (d==0){
        
            d=spatiu_liber(g_board,y,x,1,word);
        
        }else {
        
            return -1;
        
        }
    
    }

    return d;

}

//Intoarce y,x,d,i(pozitia cuvintului in vectorul words) a cuvintului potrivit
int *f_word(char g_board[SIZE][SIZE],char u_w[NUM_WORDS][SIZE],int h){

    int i,k,p,d,semn = 0,brk_semn = 0;
    static int res[4] = {-1,-1,-1,-1};

    for ( i = 0; i < NUM_WORDS; i++ ){
        
        for ( k = 0; k < SIZE; k++ ){
            
            for ( p = 0; p < SIZE; p++ ){

                //Prima litera a cuvintului coincide cu vreo litera din tabla
                if ( words[i][0] == g_board[k][p] ){
                    
                    d = spatiu_liber(g_board,k,p,0,words[i]);

                    if (d != -1){

                        //Verific daca acest cuvint nu a fost folosit
                        for (int q = 0; q < h ; q++ ){

                            if ( strcmp(words[i],u_w[q]) == 0 ){

                                semn++;

                            }

                        }
                        
                        //Daca cuvintul nu a fost folosit
                        if (semn == 0){
                            
                            res[0] = k;
                            res[1] = p;
                            res[2] = d;
                            res[3] = i;

                            brk_semn++;
                            break;

                        }

                    }

                }

                if (brk_semn == 1){
                    
                    break;
                
                }

            }

            if (brk_semn == 1){

                break;
                
            }
        
        }
        
        if (brk_semn == 1){
        
            break;
        
        }
        
        semn = 0;
    
    }

    return res;

}

void task_4(char g_board[SIZE][SIZE]){

    char xx[3], yy[3], word[SIZE],user_input[255],used_w[SIZE][SIZE];
    int i, num_intrari, x, y, d,h = 0;
    int *res;


    fgets(user_input,3,stdin);
    fgets(user_input,3,stdin);
    strcpy(xx,user_input);
    
    fgets(yy,3,stdin);
    fgets(yy,3,stdin);
    
    fgets(user_input,255,stdin);
    fgets(user_input,255,stdin);
    num_intrari = atoi(user_input);
    
    for (i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);
        
        //Creez un vector cu cuvintele utilizate
        strcpy(used_w[h], word);    
        h++;
        
        add_word(g_board,y,x,d,word);

    }
   
    res=f_word(g_board,used_w,h);

    add_word(g_board,res[0],res[1],res[2],words[res[3]]);
    print_board(g_board);

}

//Intoarce y,x,d,i a cuvintului care imi da sorul cel mai mare
int *f_word_win(char g_board[SIZE][SIZE],char u_w[NUM_WORDS][SIZE],
                int h,char xx[3],char yy[3]){

    int i,k,p,d,semn = 0,bonus,punct;
    int max = -1;
    static int res[4] = {-1,-1,-1,-1};

    for ( i = 0; i < NUM_WORDS; i++ ){
        
        for ( k = 0; k < SIZE; k++ ){
            
            for ( p = 0; p < SIZE; p++ ){

                //Prima litera a cuvintului coincide cu vreo litera din tabla
                if ( words[i][0] == g_board[k][p] ){
                    
                    d = spatiu_liber(g_board,k,p,0,words[i]);

                    if (d != -1){

                        //Verific daca acest cuvint nu a fost folosit
                        for (int q = 0; q < h ; q++ ){

                            if ( strcmp(words[i],u_w[q]) == 0 ){

                                semn++;

                            }

                        }
                        
                        //Daca cuvintul nu a fost folosit
                        if (semn == 0){

                            punct = calc_puncte(words[i]);
                            bonus = check_bonus(k,p,d,words[i],xx,yy);

                            //Daca max e mai mic ca scorul obtinut
                            if (max < punct*bonus){
                                
                                max = punct*bonus;
                                res[0] = k;
                                res[1] = p;
                                res[2] = d;
                                res[3] = i;
                            
                            }

                        }

                    }

                }

            }

        }
        
        semn=0;
    
    }

    return res;

}

void task_5(char g_board[SIZE][SIZE]){

    char xx[3], yy[3], word[SIZE],user_input[255],used_w[NUM_WORDS][SIZE];
    int i, num_intrari, x, y, d,h=0,scor_player1=0,scor_player2=0;
    int max_scor, punct, bonus, *res, count=0;;


    fgets(user_input,3,stdin);
    fgets(user_input,3,stdin);
    strcpy(xx,user_input);
    
    fgets(yy,3,stdin);
    fgets(yy,3,stdin);
    
    fgets(user_input,255,stdin);
    fgets(user_input,255,stdin);
    num_intrari = atoi(user_input); 

    for (i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);
        
        //vectroul cu cuvinte utilizate
        strcpy(used_w[h], word);
        h++;

        if (i % 2 == 0){
            
            punct = calc_puncte(word);
            scor_player1 = scor_player1 + punct*check_bonus(y,x,d,word,xx,yy);

        } else {

            punct = calc_puncte(word);
            scor_player2 = scor_player2 + punct*check_bonus(y,x,d,word,xx,yy);

        }
        

        add_word(g_board,y,x,d,word);

    }
    
    //gasesc primul cuvint bun
    res = f_word_win(g_board,used_w,h,xx,yy);
    max_scor = -1;
    
    // Verific de 2 ori 
    while ( count < 2 ){
        
        count++;
        
        punct = calc_puncte(words[res[3]]);
        bonus = check_bonus(res[0],res[1],res[2],words[res[3]],xx,yy);
        
        if (max_scor <= punct*bonus){
            
            max_scor = punct*bonus;
            y=res[0];
            x=res[1];
            d=res[2];
            strcpy(word,words[res[3]]);

        }

        //Adaug cuvintul utilizat in vectorul cu cuvinte utilizate
        strcpy(used_w[h],words[res[3]]);
        h++;
        
        //trec la urmatorul cuvint
        res = f_word_win(g_board,used_w,h,xx,yy);

    }

    max_scor = max_scor+scor_player2;
    
    if (max_scor >= scor_player1){

    
        add_word(g_board,y,x,d,word);
        print_board(g_board);
    
    } else {

        fprintf(stdout,"Fail!");
    
    }
    
}

void task_6(char g_board[SIZE][SIZE]){
    char xx[3], yy[3], word[SIZE],user_input[255],used_w[NUM_WORDS][SIZE];
    int i, num_intrari, x, y, d,h=0,scor_player1=0,scor_player2=0;
    int punct, bonus, *res;


    fgets(user_input,3,stdin);
    fgets(user_input,3,stdin);
    strcpy(xx,user_input);
    
    fgets(yy,3,stdin);
    fgets(yy,3,stdin);
    
    fgets(user_input,255,stdin);
    fgets(user_input,255,stdin);
    num_intrari = atoi(user_input); 

    for (i = 0; i < num_intrari; i++){

        fgets(user_input,255,stdin);
        sscanf(user_input,"%d %d %d %s",&y,&x,&d,word);

        //vectroul cu cuvinte utilizate
        strcpy(used_w[h], word);
        h++;

        add_word(g_board,y,x,d,word);

        punct = calc_puncte(word);
        scor_player1 = scor_player1 + punct*check_bonus(y,x,d,word,xx,yy);

        //Cauta cuvintul cu scor maxim
        res=f_word_win(g_board,used_w,h,xx,yy);

        add_word(g_board,res[0],res[1],res[2],words[res[3]]);
        
        strcpy(used_w[h],words[res[3]]);
        h++;

        punct=calc_puncte(words[res[3]]);
        bonus=check_bonus(res[0],res[1],res[2],words[res[3]],xx,yy);

        scor_player2 = scor_player2 + punct*bonus;

        

    }

    print_board(g_board);

    if (scor_player1 >= scor_player2){

        fprintf(stdout,"Player 1 Won!");

    } else {
        
        fprintf(stdout,"Player 2 Won!");
    
    }
    
}

int main(){
    
    int task_numbre;
    char buffer[3],g_board[SIZE][SIZE];
    
    fgets(buffer,2,stdin);
    task_numbre = atoi(buffer);

    init_board(g_board);

    switch (task_numbre){
    
    case 0:
        
        print_board(g_board);
        break;
    
    case 1:
        
        task_1(g_board);
        break;

    case 2:
        
        task_2();
        break; 

    case 3:
        
        task_3();
        break;

    case 4:
        
        task_4(g_board);
        break;
    
    case 5:
        
        task_5(g_board);
        break;

    case 6:
        
        task_6(g_board);
        break;

    default:
        break;
    }
    
    return 0;
}