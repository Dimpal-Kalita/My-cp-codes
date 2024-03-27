#include <stdio.h>
#include <string.h>

void reverseCharacters(char* input1) {
    
    char* start = input1;
    char* end = input1;
    
    while (*end) {
        while (*end && *end != ' ') {
            end++;
        }
        
        char* wordStart = start;

        char ch= *wordStart;
        if(ch>='A' && ch<='Z'){
            *wordStart=ch-'A'+'a';
        }
        char* wordEnd = end - 1;
        ch= *wordEnd;
        if(ch>='a' && ch<='z'){
            *wordEnd=ch-'a'+'A';
        }
        while (wordStart < wordEnd) {
            char temp = *wordStart;
            *wordStart = *wordEnd;
            *wordEnd = temp;
            wordStart++;
            wordEnd--;
        }
        if (*end) {
            start = end + 1;
            end++;
        }
    }
}

int main() {
    char input[] = "are you sure you want to come to the party?";
    
    printf("Input string: %s\n", input);
    
    reverseCharacters(input);
    
    printf("Output string: %s\n", input);
    
    return 0;
}
