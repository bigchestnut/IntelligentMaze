#include <QVector>
#ifndef POPULATION_H
#define POPULATION_H
#define CROSSOVER_RATE 5
#define MUTATION_RATE 2
class MyPoint;
class Genome
{
public:
    Genome(int x,int y) ;
    Genome* crossover(Genome* dad);
    Genome* mutate();
    bool isRes();
    QVector<int> gen;
    void fit();
    int x;
    int y;
    int len;
    int fitness;
    MyPoint **maze;
};

class Population
{
public:
    Population();
    Population(int x, int y);
    bool evolution();
    int checkEnd();
    Genome* getResGen(int i);
    Genome *select();
private:
    bool timeOut;
    int num;
    QVector<Genome*> vector;
    void timeEnd();
};

#endif // POPULATION_H
