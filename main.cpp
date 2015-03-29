/*
 **************************************************************************
 * Copyright notice:                                                      *
 * Free use of the Bloom Filter Library is permitted under the guidelines *
 * and in accordance with the most current version of the Common Public   *
 * License.                                                               *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
 */

/*
 Description: This example demonstrates basic usage of the Bloom filter.
 Initially some values are inserted then they are subsequently
 queried, noting any false positives or errors.
 */

#include <fstream>
#include <iostream>
#include "libs/bloomFilter/bloom_filter.hpp"
#include "libs/bloomierFilter/BloomierFilter.h"
#include <math.h>
using namespace std;

class bloomBloomier
{

public:

    void instantiate(int n, float p){

        bloom_filter blmFilter = instBloom(n,p);

        initSignatureDatabase(blmFilter);

        std::map<std::string, int>* keyMap =  blmFilter.getKVs();

/*        long int j = keyMap->size();
        int m = (-j * std::log(0.01) / std::pow(log(2),2));
        int k = 0.7 * (m/n);
        int q = log(k/0.05);*/

//        int hash = 0; int m = 10; int k = 5; int q = 24;
//        map<string, int> mp; mp["abc"] = 10; mp["def"] = 20; mp["abd"] = 30;
//        vector<string> keys = {"abc", "def", "abd"};
//        auto bf = bloomier::BloomierFilter(hash, &mp, m, k, q);




    }

    //creates bloom filter
    bloom_filter instBloom(int n, float p){
        bloom_parameters parameters;

        // expected element count
        parameters.projected_element_count = n;

        // false probability allowance
        parameters.false_positive_probability = p; // 1 in 10000

        parameters.compute_optimal_parameters();

        bloom_filter filter(parameters);

        return filter;
    }

    int testFilter(bloom_filter filter){
        filter.getKVs();
    }

    //loads bloom filter
    void initSignatureDatabase(bloom_filter filter){
        std::ifstream keys;


        keys.open("/Users/Charlie/ClionProjects/BloomBloomier/db.txt");

        if (keys.is_open() == false) {
            std::cout << "not open";
        }

        std::string line;
        while( getline(keys, line) ) {
            int start = line.find(":");
            std::string substring = line.substr( start + 1, (start + 33) - (start) -1 );
            filter.insert(substring);

        }

    }
};

int main()
{
    std::vector<std::string> knownPatterns;

    bloomBloomier mechanism;
    mechanism.instantiate(3600000,0.01);

    return 0;
}

