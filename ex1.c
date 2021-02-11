#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void one();
void two();
void fri();
void main(){
	int a;
	scanf("%d",&a);
	switch(a){
	case 1:
	    one();
	    break;
	case 2:
	    two();
	    break;
	case 3:
		fri();
		break;
	default:
	 printf("no");
	}
}
void one(){
	int a,i;
	FILE *f;
	int *p;
	scanf("%d",&a);
	p=(int*)malloc(a*sizeof(int));
	srand(time(NULL));
	for (i=0;i<a;i++){
	    p[i]=rand();
	  }
	f=fopen("C:cr.txt","w+b");
	for (i=0;i<a;i++){
		fwrite(p+i, sizeof(int*),p[i],f);
	}
	fclose(f);
	free(p);
}
void two(){
	int a,i,j,b;
	FILE *f;
	int *p;
	scanf("%d",&a);
	scanf("%d",&b);
	p=(int*)malloc(a*b*sizeof(int));
	srand(time(NULL));
	for (j=0;j<a;j++){
		for (i=0;i<b;i++){
	        p[j*a+i]=rand();
		}
	  }
	f=fopen("C:cr.txt","w+b");
	for (j=0;j<a;j++){
			for (i=0;i<b;i++){
				fwrite(p+j*a+i, sizeof(int*),p[j*a+i],f);
			}
		  }
	fclose(f);
	free(p);
}
void fri(){
    int x,y,z;
    FILE *f;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
	int*** a = NULL;
	int* data;
	int** ptrs;
	int i, j, k, q;
	a = (int***) malloc(x * sizeof(int**) +x*y * sizeof(int*) +x*y*z * sizeof(int));

	ptrs = (int**) (a + x);
	data = (int*) (a + y + y*z);
	q = 0;
	srand(time(NULL));
	for (i = 0; i < x; i++) {
	    a[i] = ptrs + i*y;
	    for (j = 0; j < x; j++) {
	        a[i][j] = rand();
	    }
	}
	f=fopen("C:cr.txt","w+b");
	for (i = 0; i < x; i++) {
		    for (j = 0; j < x; j++) {
		    	fwrite(a+i*a+j, sizeof(int*),a[i][j],f);
		    }
		}
	for (i = 0; i < x; i++) {
		free(a[i]);
			    for (j = 0; j < x; j++) {
			    	free(a[i][j]);
			    }
			}
	fclose(f);
	free(a);
}
