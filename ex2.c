#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int* one();
int** two();
int*** fri();
int main(){
	FILE *f;
	int a,i,j;
	int b;
	int c;
	int *p;
	int **q;
	int ***k;
	f=fopen("C:cr.txt","r+b");
	fread(&a, sizeof(int*),1,f);
	switch(a){
	case 1:
		fread(&a, sizeof(int*),1,f);
	    p=one(a);
	    free(p);
	    break;
	case 2:
		fread(&a, sizeof(int*),1,f);
		fread(&b, sizeof(int*),1,f);
	    q=two(a,b);
	    for (i = 0; i < a; i++) {
	            free(p[i]);
	        }
	    free(p);
	    break;
	case 3:
		fread(&a, sizeof(int*),1,f);
		fread(&b, sizeof(int*),1,f);
		fread(&c, sizeof(int*),1,f);
		k=fri(a,b,c);
		for (i = 0; i < b; i++) {
		        for (i = 0; i < c; i++) {
		                free(p[i][j]);
		        }
		        free(p[i]);
		    }
		free(p);
		break;
	default:
	 printf("no");
	}
}
int* one(int a){
	int i;
	FILE *f;
	int p;
	int *q;
	q=(int*)malloc(a*sizeof(int));
	fpos_t *s;
	int e=1;
	s=&e;
	f=fopen("C:cr.txt","w+b");
	fsetpos(f,s);
	for (i=0;i<a;i++){
		fread(&p, sizeof(int*),1,f);
		q[i]=p;
	}
	return(q);
}
int** two(int a,int b){
	int i,j;
		FILE *f;
		int p;
		int **q;
		fpos_t *s;
		int t=2;
		s=&t;
		f=fopen("C:cr.txt","w+b");
		fsetpos(f,s);
		q=(int**)malloc(a*sizeof(int*));
		for (i=0;i<a;i++){
			q[i] = (int*) malloc(b * sizeof(int));
			for (j=0;j<b;j++){
			fread(&p, sizeof(int*),1,f);
			q[i][j]=p;
			}
}
		return (q);
}
int*** fri(int a,int b,int c){
	int i,j,k;
			FILE *f;
			int p;
			int ***q;
			fpos_t *s;
			int t=3;
			s=&t;
			f=fopen("C:cr.txt","w+b");
			fsetpos(f,s);
			q=(int***)malloc(a*sizeof(int*));
			for (i=0;i<a;i++){
				q[i]=(int**)malloc(b*sizeof(int*));
				for (j=0;j<b;j++){
					q[i][j]=(int*)malloc(c*sizeof(int));
					for (k=0;k<c;k++){
						fread(&p, sizeof(int*),1,f);
						q[i][j][k]=p;
					}
				}
			}
			return (q);
}
