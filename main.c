#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc,char *argv[]){
int id;
FILE *pipe;
pipe = popen("xinput | grep M575","r");
int len=0;
char path[5000];
fgets(path, 5000, pipe);
FILE *sensFile = fopen("/tmp/sens.txt","r+");
float sensivity;

if(sensFile == NULL){
    sensFile = fopen("/tmp/sens.txt","w+");
    sensivity=0.5;
    return 1;
}else {
fscanf(sensFile,"%f",&sensivity);

}

if(strlen(path)<80)
{
pipe = popen("xinput | grep M575 | awk '{print $6}' | cut -c4-6","r");  
fgets(path, 5000, pipe);
id = atoi(path);
}

 if (!(strcmp("up", argv[1])) && sensivity < 1.0) {
        sensivity += 0.05;
    }

    if (!(strcmp("down", argv[1])) && sensivity > -1.0) {
        sensivity -= 0.05;
    }

    if (sensivity > 1.0) {
        sensivity = 1.0;
    } else if (sensivity < -1.0) {
        sensivity = -1.0;
    }
rewind(sensFile);
fprintf(sensFile,"%.2f",sensivity);
char command[50];
sprintf(command,"xinput --set-prop %d 'libinput Accel Speed' %f",id,sensivity);
system(command);
    return 0;
}