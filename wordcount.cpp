#include<stdio.h>
#include<string.h>
int *getcharnum(char *filename,int *totalnum);

int main(){
	char file[30];
	int totalnum[3]={1,1,1};//行、字符、单词
	char control[5];
	char a[5]="-c";
	scanf("%s",control);
	printf("Input file name:");
	scanf("%s",file);
	if(getcharnum(file,totalnum)){
		if(strcmp(control,a)==0)
			printf("字符数%d",totalnum[1]);
		else
			printf("单词数%d",totalnum[2]);
	}
	else
		printf("Error!");
	return 0;
} 
int *getcharnum(char *file,int *totalnum){
	FILE *fp;
	char buffer[1003];
	int bufferlen;
	int i;
	char c;
	int islastblank=0;
	int charnum=0;
	int wordnum=0;
	if((fp=fopen(file,"rb"))==NULL){
		perror(file);
		return NULL;
	} 
	while(fgets(buffer,1003,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<buffer[i];i++){
			c=buffer[i];
			if(c==' '||c=='\t'){
				!islastblank && wordnum++;
				islastblank=1;
			}
			else if(c!='\n'&&c!='\r'){
				charnum++;
				islastblank=0;
			}
		}
		!islastblank && wordnum++;
		islastblank=1;
		totalnum[0]++;
		totalnum[1]+=charnum;
		totalnum[2]+=wordnum;
	}
	return totalnum; 
}
