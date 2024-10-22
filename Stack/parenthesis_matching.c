#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isMatch(char c1, char c2){
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '[' && c2 == ']') return true;
    if(c1 == '{' && c2 == '}') return true;
    return false;
}

void isBalanced(char s[]){
    int top = -1;

    for(int i=0; i<strlen(s); i++){
        if(top<0 || !isMatch(s[top], s[i])){
            top++;
            s[top] = s[i];
        }
        else{
            top--;
        }
    }

    if(top==-1){
        printf("Parantheses are Balanced");
    }
    else{
        printf("Parantheses are not Balanced");
    }
}

void main(){
    char s[] = "{()}[]";
    isBalanced(s);
}

// Refer GeeksForGeeks 2nd code on "Valid Parentheses in an Expression" page for explainantion