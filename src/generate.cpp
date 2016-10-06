/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file generate.cpp
 * @Synopsis Renerates randomly conected graphs (dense and sparse)
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-27
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

class Graphm{
    public:
        Graphm(int _numVertex);
        ~Graphm();
        void genDenseGraph();
        void genSparseGraph();
        void printSparse(int** matrixSparse);
        void printDense(int** matrixDense);

    private:
        void setZeros(int** _matrixDense);
        double randomWeights();
        int numVertex;
        int** matrixDense;
        int** matrixSparse;
        int numEdge;
        double weight;

};

Graphm::Graphm(int _numVertex){
    numVertex  = _numVertex;
    numEdge = 0;
    weight = 0.0;
    matrixDense = new int*[numVertex];
    matrixSparse = new int*[numVertex];
    for(int i = 0 ; i < numVertex ; i++){
        matrixDense[i] = new int[numVertex];
         matrixSparse[i] = new int[numVertex];
        for(int j = 0 ; j < numVertex ; j++){
            matrixDense[i][j] = 0;
            matrixSparse[i][j] = 0;
        }
    }

}
Graphm::~Graphm(){
    for(int i = 0 ; i < numVertex ; i++){
        delete[] matrixDense[i];
        delete[] matrixSparse[i];
    }
    delete[] matrixDense;
    delete[] matrixSparse;

}
void Graphm::setZeros(int** _matrixDense){
    for (int i = 0; i < numVertex; i++) {
		 for (int j = 0; j < numVertex; j++) {
			 if ((i == j) || (i < j)) {
			 	matrixDense[i][j] = 0;
			 }
		 }
	 }
}
/*
* Generates an undirected graph with edges of the order V^2(dense graph), where V is the number of vertices.
* Uses only one half of the adjecency matrix representation, for simple connection of vertices i.e any pair of vertices
* is joined by exactly one vertex.
*/
void Graphm::genDenseGraph(){
        srand(int(time(NULL)));
        for(int i = 0 ; i < numVertex ; i++){
            for(int j = 0; j < numVertex ; j++){

                matrixDense[i][j] = randomWeights();
            }

        }
       numEdge = 0.5*(pow(numVertex,2)-numVertex);
       setZeros(matrixDense);
       printDense(matrixDense);
}
/*
* Generates an undirected graph with edges of the order V(sparse graph), where V is the number of vertices.
* Uses only one half of the adjecency matrix representation, for simple connection of vertices i.e any pair of vertices
* is joined by exactly one vertex.
*/


void Graphm::genSparseGraph(){
     srand(int(time(NULL)));
    for(int i = 0 ; i < numVertex ; i++){
            for(int j = 0; j < numVertex ; j++){
                if((i-j)==1){
                    matrixSparse[i][j]= randomWeights();
                }
            }

        }
    matrixSparse[numVertex-1][0]=randomWeights();
    int c;

    double d= 0.3*numVertex;
    c=d;
    numEdge=numVertex + c;
    srand(int(time(NULL)));
    while(c !=0){

        int i= rand()%(numVertex-1) +1;
        int j= rand()%(numVertex-2) +0;

            if( i>j and i-j!=1 ){
                if(i==numVertex-1 and j ==0){}
                else if(matrixSparse[i][j]>0){
                    //do nothing
                }
                 else {

                matrixSparse[i][j]= randomWeights();


                c--;
                }
            }
        }


    printSparse(matrixSparse);
}
void Graphm::printSparse(int** matrixSparse){

     ofstream output;
     output.open("../../data/sparse.dat",ios::app);
     output << numVertex << endl;
     output << numEdge << endl;
    for(int i =0; i<numVertex; ++i){

        for(int j =0; j<numVertex; ++j){
            if (matrixSparse[i][j]==0){
                //do nothing
            }
           else{
                output<<i<<' '<<j<<' '<<matrixSparse[i][j]<<endl;
           }
        }
    }
output.close();
}
void Graphm::printDense(int** matrixDense){

     ofstream output;
     output.open("../../data/dense.dat",ios::app);
     output << numVertex << endl;
     output << numEdge << endl;

    for(int i =0; i<numVertex; ++i){

        for(int j =0; j<numVertex; ++j){
            if(i <=j){
            //do nothing
            }
            else{
                output<<i<<' '<<j<<' '<<matrixDense[i][j]<<endl;
            }
        }
    }
    output.close();
}


double Graphm::randomWeights(){

    weight = rand()%101 + 1;
    return weight;
}


int main()
{
    /* Profiling */
    // overall system time elapsed
    clock_t startTime = clock();

    int _numVertices = 0;
    srand(int(time(NULL)));
    for(_numVertices = 10; _numVertices <= 1000 ; _numVertices++ ){

        Graphm obj(_numVertices);
        obj.genDenseGraph();
        cout<<endl;
        obj.genSparseGraph();
    }

    /* Profiling end */
    cout << "Executable Runtime: " << double( clock() - startTime) / (double) CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Processing complete: created ../../data/dense.dat" << endl;
    cout << "Processing complete: created ../../data/dense.dat" << endl;

    return 0;
}
