#include <stdio.h>
main(){
int balance, payment,tenure, totalmoths=0,i;
float irate, interest,sum=0, amountpaid;
FILE *fp;
  fp = fopen("/home/affine/emi_cal.txt","w+");
  printf("Enter the total amount: ");
  scanf("%d",&balance);
  fprintf(fp, "Pricipel amount: %d\n",balance );
  printf("\nEnter the payment: ");
  scanf("%d",&payment);
  fprintf(fp, "Monthly payment: %d\n",payment );
  printf("\nInterest Rate: ");
  scanf("%f",&irate);
    fprintf(fp, "Bank interest: %.0f\n",irate );
  printf("\nEnter Tenure in years: ");
  scanf("%d",&tenure);
    fprintf(fp, "Tenure in years: %d\n",tenure );
  float r ;
  r = irate/12;
  r = (r/100) +1;
  totalmoths = (tenure * 12);
  printf("Months\t  Balance\t\t\t  Interest \t\t\t Principel paid" );
  fprintf(fp, "Moths\t Balance\t\t Interest\t\t Principel paid" );
  for(i = 1; i<=totalmoths; i++){
    if(balance > 0){
      interest = (balance *r) -balance;
      amountpaid = payment - interest;
      balance = (balance * r) - payment;
      if(balance>0){
        printf("\n%d\t %d\t\t\t  %.2f\t\t\t %.2f",i,balance,interest,amountpaid);
        fprintf(fp,"\n%d\t %d\t\t\t  %.2f\t\t\t %.2f",i,balance,interest,amountpaid);
      }
      sum = sum + interest;
      if(i%12==0)
        printf("\n\t\t<----year---->\t\t");
    }
    else{
      i--;
      printf("\n\nTotalmoths paid: %d \t\t and total Interest: %.2f\n",i, sum );
      fprintf(fp,"\n\nTotalmoths paid: %d \t\t and total Interest: %.2f\n",i, sum);
      fclose(fp);
      return;
    }
  }
}
