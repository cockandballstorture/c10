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
	int *c=a;
	p=(int*)malloc(a*sizeof(int));
	srand(time(NULL));
	for (i=0;i<a;i++){
	    p[i]=rand();
	  }
	f=fopen("C:cr.txt","w+b");
	c[1]=a;
	c[0]=1;
	fwrite(c[0], sizeof(int*),1,f);
	fwrite(c[1], sizeof(int*),1,f);
	for (i=0;i<a;i++){
		fwrite(p[i], sizeof(int*),1,f);
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
	int *c=a;
	p=(int*)malloc(a*b*sizeof(int));
	srand(time(NULL));
	for (j=0;j<a;j++){
		for (i=0;i<b;i++){
	        p[j*a+i]=rand();
		}
	  }
	f=fopen("C:cr.txt","w+b");
	c[2]=a;
	c[0]=2;
	c[1]=b;
	fwrite(c[0], sizeof(int*),1,f);
	fwrite(c[1], sizeof(int*),1,f);
	fwrite(c[2], sizeof(int*),1,f);
	for (j=0;j<a;j++){
			for (i=0;i<b;i++){
				fwrite(p[j*a+i], sizeof(int*),1,f);
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
	int *c=x;
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
	c[2]=x;
	c[0]=3;
	c[1]=y;
	c[2]=z;
	fwrite(c[0], sizeof(int*),1,f);
	fwrite(c[1], sizeof(int*),1,f);
	fwrite(c[2], sizeof(int*),1,f);
	fwrite(c[3], sizeof(int*),1,f);
	for (i = 0; i < x; i++) {
		    for (j = 0; j < x; j++) {
		    	fwrite(a[i][j], sizeof(int**),1,f);
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
