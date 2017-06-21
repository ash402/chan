#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LINE_LEN = 51;
int numAdj = 0;
int numAct = 0;
int numAre = 0;


void getName(char *adjPnt, char *actPnt, char *arePnt, int numAdj, int numAct, int numAre, char *name);


int main(void){
	FILE* adj;
	FILE* act;
	FILE* are;
	int i = 0;
	int j = 0;

	char name[3*LINE_LEN];
	int NUM_TO_GEN = 20;
	srand(time(NULL));
	
	adj = fopen("adjectives.txt", "r");
	act = fopen("actions.txt", "r");
	are = fopen("areas.txt", "r");
	char adjList[50][LINE_LEN];
	char actList[50][LINE_LEN];
	char areList[50][LINE_LEN];
	while(!feof(adj)){
		fgets(adjList[i], LINE_LEN, adj);
		j = 0;
		while(adjList[i][j] != '\n'){
			j++;
		}
		adjList[i][j] = '\0';
		adjList[i][j+1] = ' ';
		i++;
	}
	numAdj = i;
	i = 0;
	while(!feof(act)){
		fgets(actList[i], LINE_LEN, act);
		j = 0;
		while(actList[i][j] != '\n'){
			j++;
		}
		actList[i][j] = '\0';
		actList[i][j+1] = ' ';		
		i++;
	}
	numAct = i;
	i = 0;
	while(!feof(are)){
		fgets(areList[i], LINE_LEN, are);
		j = 0;
		while(areList[i][j] != '\n'){
			j++;
		}
		areList[i][j] = '\0';
		areList[i][j+1] = ' ';
		i++;
	}
	numAre = i;
	fclose(adj);
	fclose(act);
	fclose(are);
	
	//printf("numadj: %d\tnumAct: %d\tnumAre: %d\n", numAdj, numAct, numAre);
	/*for(i = 0; i < numAdj; i++){
		printf("%d: %s\n", i, adjList[i]);
	}
	for(i = 0; i < numAct; i++){
		printf("%d: %s\n", i, actList[i]);
	}
	for(i = 0; i < numAre; i++){
		printf("%d: %s\n", i, areList[i]);
	}*/
	
	for(i = 0; i < NUM_TO_GEN; i++){
		getName(*adjList, *actList, *areList, numAdj, numAct, numAre, name);
		printf("%s\n", name);
	}
	
	
	
}

void getName(char *adjPnt, char *actPnt, char *arePnt, int numAdj, int numAct, int numAre, char *name){
	char adj[LINE_LEN];
	char act[LINE_LEN];
	char are[LINE_LEN];
	int adjPick, actPick, arePick;
	//char ret[3 * LINE_LEN];

	adjPick = rand() % numAdj;
	actPick = rand() % numAct;
	arePick = rand() % numAre;
	//printf("AdjPick: %d\tactPick: %d\tarePick: %d\n", adjPick, actPick, arePick);
	
	sprintf(adj, &adjPnt[adjPick*LINE_LEN]);
	sprintf(act, &actPnt[actPick*LINE_LEN]);
	sprintf(are, &arePnt[arePick*LINE_LEN]);
	
	//printf("Adj: %s\tact: %s\tare: %s\n", adj, act, are);
	
	
	sprintf(name, "%s %s %s", adj, act, are);
	//return *ret;
}