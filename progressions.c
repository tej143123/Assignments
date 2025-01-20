#include<stdio.h>
#include<math.h>

void find_ap_series(float a, float r){
	for(int i=0;i<n;i++){

		printf("%.2f\n", a + (i*r));

	}
}

void find_gp_series(float a, float r){
	for(int i=0;i<n;i++){

		printf("%.2f\n", a* pow(r,i));

	}

}

void find_hp_series(float a, float r){
	for(int i=0;i<n;i++){

		printf("%.2f\n", 1.0/(a + (i*r)));

	}


}


int main(){

	float a, r;
	int n;

	printf("Enter the first term : ");
	scanf("%f", &a);

	printf("Enter the common ratio : ");
	scanf("%f", &r);

	printf("Enter the number of terms : ");
	scanf("%d", &n);

	printf("The series of ap are : \n");

	find_ap_series(a, r);

	printf("The series of gp are : \n");

	find_gp_series(a, r);

	printf("The series of hp are :\n ");

	find_hp_series(a, r);

	return 0;

}
