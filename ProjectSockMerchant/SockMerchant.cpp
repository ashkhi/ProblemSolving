#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class SockMerchant
{
    private:
        int numberOfSocksInPile;
        int numberOfSocksPairs;
        vector<int>* socksPile;
        map<int, int>* pairCalculator;
        int maxDiffColors;
        int maxSocksInPile;

    public:
        SockMerchant();
        ~SockMerchant();

        int getNumberOfSocksInPile();
        void setNumberOfSocksInPile(int);

        int getNumberOfSocksPairs();
        void setNumberOfSocksPairs(int);

        vector<int>* getSocksPile();
        void setSocksPile(vector<int>*);

        map<int, int>* getPairCalulator();
        void addToPairCalculator(int);

        void calculatePairs();
};

SockMerchant::SockMerchant()
{
    maxDiffColors = 100;
    maxSocksInPile = 100;

    numberOfSocksInPile = 0;
    numberOfSocksPairs = 0;

    socksPile = new vector<int>();
    pairCalculator = new map<int, int>();
}

SockMerchant::~SockMerchant()
{
}

int SockMerchant::getNumberOfSocksInPile()
{
    return numberOfSocksInPile;
}

void SockMerchant::setNumberOfSocksInPile(int n)
{
    if (n < maxSocksInPile)
    {
        numberOfSocksInPile = n;
    }
    else
    {
        cout << "\nInput size is too big to handle" << endl;
    }
}

int SockMerchant::getNumberOfSocksPairs()
{
    return numberOfSocksPairs;
}

void SockMerchant::setNumberOfSocksPairs(int pairs)
{
    numberOfSocksPairs = pairs;
}

vector<int>* SockMerchant::getSocksPile()
{
    return socksPile;
}

void SockMerchant::setSocksPile(vector<int>* vect)
{
    if(vect)
    {
        for (int i=0; i<getNumberOfSocksInPile(); ++i)
        {
            socksPile->push_back(vect->at(i));
        }
    }
}

map<int, int>* SockMerchant::getPairCalulator()
{
    return pairCalculator;
}

void SockMerchant::addToPairCalculator(int sockColor)
{
    if (sockColor < maxDiffColors)
    {
        map<int, int>::iterator itr = pairCalculator->find(sockColor);
        if (itr != pairCalculator->end())
        {
            itr->second = itr->second + 1;
        }
        else
        {
            pairCalculator->insert(pair<int, int>(sockColor, 1));
        }
    }
    else
    {
        cout << "\nToo many socks colors to handle" << endl;
    }
}

void SockMerchant::calculatePairs()
{
    int numOfPairs = getNumberOfSocksPairs();
    map<int, int>::iterator itr;
    for (itr = getPairCalulator()->begin(); itr != getPairCalulator()->end(); ++itr)
    {
        numOfPairs = numOfPairs + (itr->second / 2);
    }
    setNumberOfSocksPairs(numOfPairs);
}

int main()
{
    int num;
    cout << "\nEnter number of socks : ";
    cin >> num;

    cout << "\nEnter socks input colors : ";
    vector<int>* input = new vector<int>(num);
    for (int i=0; i<num; ++i)
    {
        cin >> input->at(i);
    }

    SockMerchant* sm1 = new SockMerchant();

    sm1->setNumberOfSocksInPile(num);
    sm1->setSocksPile(input);

    for (int i=0; i<sm1->getSocksPile()->size(); ++i)
    {
        sm1->addToPairCalculator(sm1->getSocksPile()->at(i));
    }

    sm1->calculatePairs();

    cout << "\nTotal number of pairs in the pile are : " << sm1->getNumberOfSocksPairs() << endl;

    return 0;
}