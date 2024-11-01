using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <cstring>

void Keywordfunction(string lex);
void Identifierfunction(string lex);
void digitFunction(string lex);
void operandFunction(string lex);
void parenthesisFunction(string lex);
int isParenthesis(char buffer);
int isOperand(char buffer);
int isKeyword(char buffer);
int isDigit(char buffer);
int isAlphabet(char buffer);


int main()
{
string lexer;    
getline(cin, lexer);
int i=0,j=0 ;
string str;

if (lexer[i+j]=='i')
{
    j++;
    if (lexer[i+j]=='f')
    {
        j++;
        if ( (lexer[i+j]==' ') || (lexer[i+j]== '\t'))
        {
            j++;
            str=str+lexer[i]+lexer[i+j-2];
            Keywordfunction(str);
            str.clear();
            i=i+j;
            j=0;
        }else {while (lexer[i+j]!=' ')
        {
            j++;
        }
        for(int x=0 ; x<j ; x++){
                str=str+lexer[i+x];
            }
        Identifierfunction(str);
        str.clear();
        }
    }else {while (lexer[i+j]!=' ')
        {
            j++;
        }
        for(int x=0 ; x<j ; x++){
                str=str+lexer[i+x];
            }
        Identifierfunction(str);
        str.clear();
        }    
}

if (isAlphabet(lexer[i+j])== 1)
{
while (lexer[i+j]!=' ')
    { 
        j++;
    }
str.clear(); 
for(int x=0 ; x<j+1 ; x++) str=str+lexer[i+x];
        i=i+j;
        i++;
        j=0;
        Identifierfunction(str);
}

if (isDigit(lexer[i+j])== 1)
{
while (lexer[i+j]!=' ')
    {
        j++;
    }
str.clear(); 
for(int x=0 ; x<j ; x++) str=str+lexer[i+x];
        i=i+j;
        i++;
        j=0;
        digitFunction(str);
}

if (isOperand(lexer[i+j])== 1)
{
while (lexer[i+j]!=' ')
    {
        j++;
    }
str.clear(); 
for(int x=0 ; x<j ; x++) str=str+lexer[i+x];
        i=i+j;
        i++;
        j=0;
        operandFunction(str);
}

if (isParenthesis(lexer[i+j])== 1)
{
while (lexer[i+j]!=' ') j++;
    
str.clear(); 
for(int x=0 ; x<j ; x++) str=str+lexer[i+x];
        i=i+j;
        i++;
        j=0;
        parenthesisFunction(str);
}

cout<<"\ni= "<< i;
cout<<"\nj= "<< j;
return 0;
}//-------------end main-----------------------------


void Keywordfunction(string lex)
{
    cout <<"\n"<< lex << "\tkeyword"; 
}
void Identifierfunction(string lex)
{
    cout <<"\n"<< lex << "\tIdentifier"; 
}
void digitFunction(string lex)
{
    cout <<"\n"<< lex << "\tDigit"; 
}
int isAlphabet(char buffer)
{
char alph[27]= {'a','b','c','d','e','f','g','h','j','k',
'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int j ,flag = 0;
for( j = 0; j < 27; j++){
if(alph[j] == buffer){
flag = 1;
break;
}
}
return flag;
}
int isDigit(char buffer)
{
char alph[27]= {'1','2','3','4','5','6','7','8','9','0'};
int j ,flag = 0;
for( j = 0; j < 27; j++){
if(alph[j] == buffer){
flag = 1;
break;
}
}
return flag;
}
int isOperand(char buffer)
{
char alph[5]= {'-','+','*','/','='};
int j ,flag = 0;
for( j = 0; j < 5; j++){
if(alph[j] == buffer){
flag = 1;
break;
}
}
return flag;
}
void operandFunction(string lex)
{
    cout <<"\n"<< lex << "\tOperand"; 
}
int isParenthesis(char buffer)
{
char alph[4]= {')','(','[',']'};
int j ,flag = 0;
for( j = 0; j < 4; j++){
if(alph[j] == buffer){
flag = 1;
break;
}
}
return flag;
}
void parenthesisFunction(string lex)
{
    cout <<"\n"<< lex << "\tParenthesis"; 
}
