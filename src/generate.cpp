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
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <time.h>

#ifndef Graphm_h
#define Graphm_h

class Graphm{
public:
    Graphm(int _numVertex);
    void genDenseGraph(int maximum);
    void genSparseGraph(int maximum);
    void printSparse(int** matrixSparse);
    void printDense(int** matrixDense);
    double randomWeights(int maximum);
    void setZeros(int** _matrixDense);
    ~Graphm();
private:
    int** matrixDense;
    int** matrixSparse;
    int numVertex;
    int numEdge;
    double weight;
};

#endif /* Graphm_h */

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
* Generates an undirected graph with edges of the order V^2(dense graph), where V
* is the number of vertices.
* Uses only one half of the adjecency matrix representation, for simple connection
* of vertices i.e any pair of vertices is joined by exactly one vertex.
*/

void Graphm::genDenseGraph(int maximum){
        srand(int(time(NULL)));
        for(int i = 0 ; i < numVertex ; i++){
            for(int j = 0; j < numVertex ; j++){

                matrixDense[i][j] = randomWeights(maximum);
            }

        }
       numEdge = 0.5*(pow(numVertex,2)-numVertex);
       setZeros(matrixDense);
       printDense(matrixDense);
}

/*
* Generates an undirected graph with edges of the order V(sparse graph), where V
* is the number of vertices.
* Uses only one half of the adjecency matrix representation, for simple connection
* of vertices i.e any pair of vertices is joined by exactly one vertex.
*/
void Graphm::genSparseGraph(int maximum){
     srand(int(time(NULL)));
    for(int i = 0 ; i < numVertex ; i++){
            for(int j = 0; j < numVertex ; j++){
                if((i-j)==1){
                    matrixSparse[i][j]= randomWeights(maximum);
                }
            }
        }
    matrixSparse[numVertex-1][0]=randomWeights(maximum);
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
                matrixSparse[i][j]= randomWeights(maximum);
                c--;
                }
            }
        }
    printSparse(matrixSparse);
}

void Graphm::printSparse(int** matrixSparse){
    std::ofstream output;
    output.open("../../data/sparse.dat",std::ios::app);
    output << numVertex << std::endl;
    output << numEdge << std::endl;
    for(int i =0; i<numVertex; ++i){
        for(int j =0; j<numVertex; ++j){
            if (matrixSparse[i][j]==0){
                //do nothing
            }
           else{
               output << i << ' ' << j << ' ' << matrixSparse[i][j] << std::endl;
           }
        }
    }
output.close();
}

void Graphm::printDense(int** matrixDense){
    std::ofstream output;
    output.open("../../data/dense.dat",std::ios::app);
    output << numVertex << std::endl;
    output << numEdge << std::endl;
    for(int i =0; i<numVertex; ++i){
        for(int j =0; j<numVertex; ++j){
            if(i <=j){
            //do nothing
            }
            else{
                output << i << ' ' << j << ' ' << matrixDense[i][j] << std::endl;
            }
        }
    }
    output.close();
}

double Graphm::randomWeights(int maximum){
    weight = rand()%maximum + 1;
    return weight;
}

Graphm::~Graphm(){
    for(int i = 0 ; i < numVertex ; i++){
        delete[] matrixDense[i];
        delete[] matrixSparse[i];
    }
    delete[] matrixDense;
    delete[] matrixSparse;
}

//-------------------------------------------------------------------------------

void progressBar(int percent){
    std::string bar;
    for(int i = 0; i < 50; i++){
        if( i < (percent/2)){
            bar.replace(i,1,"=");
        }else if( i == (percent/2)){
            bar.replace(i,1,">");
        }else{
            bar.replace(i,1," ");
        }
    }
    std::cout<< "\r" "[" << bar << "] ";
    std::cout.width( 3 );
    std::cout<< percent << "%     " << std::flush;
}

//------------------------------------------------------------------------------

/////////////////////////
// MAIN
/////////////////////////

int main(int argc, char* argv[]){


    /* Profiling */
    // overall system time elapsed
    clock_t startTime = clock();

    /* Variable Declarations */
    // Start is the beginning array length. No point in calculating zero size array
    // Skip is the default number of array sizes to skip when incrementing, if the
    // optional second command line argument is not provided.
    int max_num;
    int start = 10;
    int steps = 1;
    int weight_range = 100;

    // Check that input argument for maximum size of array input length is provided
    // as the first command line argument (this is also the number of iterations)

    if (argc < 2) {
        std::string error_str = " MAX_ARRAY_SIZE <ITERATION_SKIP_SIZE>";
        std::cerr << "Error: Usage requires argument: " << argv[0] << error_str << std::endl;
        return 1;
    }

    // convert input argument to integer
    // the value might be larger than a single char, so cast/stream the number
    std::istringstream ss(argv[1]);
    if (!(ss >> max_num)){
        std::cerr << "Invalid number of iterations" << argv[1] << '\n';
        return 1;
    }

    // optional skip/step window of array lengths iterations
    if (argc > 2) {
        std::istringstream ss_steps(argv[2]);
        if ((!(ss_steps >> steps))||(steps < 1)||(steps > max_num)){
            std::cerr << "Invalid number of steps " << argv[2] << '\n';
            return 1;
        }
    }

    srand(int(time(NULL)));
    std::cout << "Generating " << (max_num-start)/steps + 1 << " graphs "<< std::endl;
    for (int i = start; i <= max_num; i+=steps){
        Graphm obj(i);
        obj.genDenseGraph(weight_range);
        obj.genSparseGraph(weight_range);
        progressBar((i*100)/max_num);
        //std::cout << i << "/" << max_num << std::endl;
    }

    /* Profiling end */
    std::cout << std::endl << std::flush;
    std::cout << "Executable Runtime: " << double( clock() - startTime) / (double) CLOCKS_PER_SEC << " seconds." << std::endl;
    std::cout << "Processing complete: created ../../data/dense.dat" << std::endl;
    std::cout << "Processing complete: created ../../data/sparse.dat" << std::endl;

    return 0;
}
