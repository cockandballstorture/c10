#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int one();
int two();
int fri();
int main(){
	FILE *f;
	int a;
	int b;
	int c;
	int w[];
	f=fopen("C:cr.txt","r+b");
	fread(&a, sizeof(int*),1,f);
	scanf("%d",&a);
	switch(a){
	case 1:
		fread(&a, sizeof(int*),1,f);
	    w=one(a);
	    break;
	case 2:
		fread(&a, sizeof(int*),1,f);
		fread(&b, sizeof(int*),1,f);
	    w=two(a,b);
	    break;
	case 3:
		fread(&a, sizeof(int*),1,f);
		fread(&b, sizeof(int*),1,f);
		fread(&c, sizeof(int*),1,f);
		w=fri(a,b,c);
		break;
	default:
	 printf("no");
	}
}
int one(int a){
	int i;
	FILE *f;
	int p;
	int w[a];
	fpos_t *s;
	int e=1;
	s=&e;
	f=fopen("C:cr.txt","w+b");
	fsetpos(f,s);
	for (i=0;i<a;i++){
		fread(&p, sizeof(int*),1,f);
		w[i];
	}
	return w;
}
int two(int a,int b){
	int i,j;
		FILE *f;
		int p;
		int w[a][b];
		fpos_t *s;
		int t=2;
		s=&t;
		f=fopen("C:cr.txt","w+b");
		fsetpos(f,s);
		for (i=0;i<a;i++){
			for (j=0;j<b;j++){
			fread(&p, sizeof(int*),1,f);
			w[i][j]=p;
			}
}
		return w;
}
int fri(int a,int b,int c){
	int i,j,k;
			FILE *f;
			int p;
			int w[a][b][c];
			fpos_t *s;
			int t=3;
			s=&t;
			f=fopen("C:cr.txt","w+b");
			fsetpos(f,s);
			for (i=0;i<a;i++){
				for (j=0;j<b;j++){
					for (k=0;k<c;k++){
						fread(&p, sizeof(int*),1,f);
						w[i][j][k]=p;
					}
				}
			}
			return w;
}
