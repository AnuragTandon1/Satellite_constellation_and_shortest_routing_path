#include<stdio.h>
#define rows 22
#define column 7
//Anurag Tandonś model for Different planes (plane-1 &2 for C2S and Risat-2B series Model) Dt 15.6.2023..

int main(){
  FILE *file;
int matrix[22][7];
int i,j;
 
// GS vis wrt to diff sats/planes
file = fopen("file.txt","r");

i=0;

while(!feof(file)){
for(j=0 ; j<column ;j++){
if(fscanf(file,"%d",&matrix[i][j])==EOF){
break;
}
}
i++;
if(i==rows){
break;
}
}
 
fclose(file);

printf("\t\tVisibility\n\n");
for(j=0 ; j<rows ;j++){
for(i=0 ; i<column ;i++){
printf("%d ",matrix[j][i]);
}
printf("\n");

}



/*

file = fopen("s0_visibility_file.txt","r");
i=0;
int distance0[3][7];
while(!feof(file)){
for(j=0 ; j<7 ;j++){
if(fscanf(file,"%d",&distance0[i][j])==EOF){
break;
}
}
i++;
if(i==3){
break;
}
}
fclose(file);
file = fopen("s1_visibility_file.txt","r");
i=0;
int distance1[3][7];
while(!feof(file)){
for(j=0 ; j<7 ;j++){
if(fscanf(file,"%d",&distance1[i][j])==EOF){
break;
}
}
i++;
if(i==3){
break;
}
}
fclose(file);
file = fopen("s2_visibility_file.txt","r");
i=0;
int distance2[3][7];
while(!feof(file)){
for(j=0 ; j<7 ;j++){
if(fscanf(file,"%d",&distance2[i][j])==EOF){
break;
}
}
i++;
if(i==3){
break;
}
}
fclose(file);
file = fopen("s3_visibility_file.txt","r");
i=0;
int distance3[3][7];
while(!feof(file)){
for(j=0 ; j<7 ;j++){
if(fscanf(file,"%d",&distance3[i][j])==EOF){
break;
}
}
i++;
if(i==3){
break;
}
}
fclose(file);
*/
int distance[7][7];
int p;
int q;
int sat=7;
for(p=0 ; p<sat ;p++){
for(q=0 ; q<sat ;q++){
if(p==q){
distance[p][q]=0;
}
else{
distance[p][q]=22222222;
}

}

}

int matrix2[24][7];
// inter / across sats/plane constellation..
file = fopen("vis.txt","r");
i=0;
// ro is the number of rows from the file..
int ro=24;
while(!feof(file)){
for(j=0 ; j<column ;j++){
if(fscanf(file,"%d",&matrix2[i][j])==EOF){
break;
}
}
i++;
if(i==ro){
break;
}
}
 
fclose(file);


for(i=0 ; i<ro ;i++){
for(j=0 ; j<column ;j++){
printf("%d\t",matrix2[i][j]);
}
printf("\n");
}




int nn;
int mn;
/*
nn=0;
for(mn =0 ; mn<4 ; mn++){
if(mn==distance0[nn][4]){
distance[0][mn]=(distance0[nn][5]+distance0[nn][6])/2;
nn++;
}
else{
distance[0][mn]=0;
}
}

nn=0;
for(mn =0 ; mn<4 ; mn++){
if(mn==distance1[nn][4]){
distance[1][mn]=(distance1[nn][5]+distance1[nn][6])/2;
nn++;
}
else{
distance[1][mn]=0;
}
}

nn=0;
for(mn =0 ; mn<4 ; mn++){
if(mn==distance2[nn][4]){
distance[2][mn]=(distance2[nn][5]+distance2[nn][6])/2;
nn++;
}
else{
distance[2][mn]=0;
}
}




nn=0;
for(mn =0 ; mn<4 ; mn++){
if(mn==distance3[nn][4]){
distance[3][mn]=(distance3[nn][5]+distance3[nn][6])/2;
nn++;
}
else{
distance[3][mn]=0;
}
}
*/
//initilasation of distnace matrix...[00, 11, 22,=0.0 and 01 02 other disminseion = infinite..that is your distance matrics..
printf("Link weightage matrix\n");
for(i=0 ; i<sat ;i++){
for(j=0 ; j<sat ;j++){
printf("%d\t",distance[i][j]);
}
printf("\n");
}





printf("******  *******\n");
int hour;
int min;
/Ask user to give his time..
printf("Enter the time( hour minutes)\n");
scanf("%d",&hour);

scanf("%d",&min);
int l;
int kkk;
//Matrix2 is across sats..with in bounds of time you will take..
//MAtrix dimension..unlimited you can asign..
//6 th col distnace is there ..
//distance matrix is refined with timely based intersat distance..

for(j=0 ; j<ro;j++){
 if((matrix2[j][2]*60)+matrix2[j][3]<=(hour*60)+min && (matrix2[j][4]*60)+matrix2[j][5]>=(hour*60)+min ){
distance[matrix2[j][0]][matrix2[j][1]]=matrix2[j][6];
}
}
// distance matrix is the wtage matrix..
printf("Link weightage matrix\n");
for(i=0 ; i<sat ;i++){
for(j=0 ; j<sat ;j++){
printf("%d\t",distance[i][j]);
}
printf("\n");
}

//kkk is the source sat vis to GS-1 and connecting to sats constellation..that is with in user given time based..at minute level..
for(l=0 ; l<rows ; l++){
  if((matrix[l][1]*60)+matrix[l][2]<=(hour*60)+min && (matrix[l][3]*60)+matrix[l][4]>=(hour*60)+min ){
kkk=matrix[l][0];
break;
}
}
l=kkk;

//algo start: Modify of Bell man for..AT..
//Source sat(l is source=kkk) to all other sats are infinite..
//initial condition for AT is to make 0 for diagonal  and infinite to non-diagonal..
//this info is stored in dist[]...7 rows.because of 7 sats this dimension is 7 dimension....

int dist[7];

for(i=0 ; i<sat ;i++){
if(i==l){
dist[i]=0;
}
else{
dist[i]=22222222;
}
}

//Ask user to give dest sat...
int a;
printf("Enter the satellite to which you want to send packet\n");
scanf("%d",&a);

//direct path means sat is vis to GS
//indirect path l!=a.
// k is iteration for sat-1 number times..
//next[] is modification to keep track of shortest path..
//dist is shortest dist collection from  distance[] as a overall..
// next[] is keeping track is new one in this algo..
//next[] dim of 0 to 7 are the sat-0 to sat-7 traverse path..

int next[7];
int k;
 if(l!=a){
for(k=0 ; k<sat-1 ; k++){
for(i=0 ; i<sat ;i++){
for(j=0 ; j<sat ;j++){
if(dist[i]+distance[i][j]<dist[j]){
dist[j]=dist[i]+distance[i][j];
next[j]=i;
}

}
}
//dist [] will store the link weitage and next[] will store the trace/ track..
printf("Routing Table %d\n",k);
printf("Sat  shortest_distance Next \n");
for(j=0 ; j<sat ;j++){

printf("%d           %d           %d\n",j,dist[j],next[j]);
}
printf("\n");

}
}
// l is src sat
// a is destination sat..p is also destination..
//earlier you picked up within  sats  distances..
 //now Picking up the distance from GS to source sat ..that is avg of min and max range with 1000 factor..
if(dist[a]<22222222){
printf("\n\n\n\n\t\t***********************OUTPUT***********************\n\n\n\n");
printf("TM recieved from satellite %d\n",l);
printf("CMD ececuted on satellite %d\n",a);
printf("Shortest path from ground station to satellite %d : %d units\n",a,dist[a]+(((matrix[l][5]+matrix[l][6])/2)/1000));
// p is GS to src sat distance..
p=a;

 int store[200];
 int gg=0;
//traversing backward and stoing path info into store []...

if(l!=a){
  store[gg]=p;
  gg++;
printf("%d<-",a);
while(next[p]!=l){
printf("%d<-",next[p]);
 store[gg]=next[p];
 gg++;

p=next[p];

}
 }

//l is src sat..
printf("%d<-Groundstation",l);
 store[gg]=l;
 gg++;
// aaa file is shortest path output from src to dest for givens user requirement..
 file =fopen("aaa.txt","w");
 fprintf(file ,"%d\n",gg);
 int d;
 for(d=gg-1 ; d>=0 ;d--){
   fprintf(file,"%d ",store[d]);

}
 fclose(file);
}

else{
//if is inifinite i.e.222222 then shortest path does not exist..
printf("Packet not sent");
 file =fopen("aaa.txt","w");
 fprintf(file ,"Packet not sent");
fclose(file);
}

return 0;
}



